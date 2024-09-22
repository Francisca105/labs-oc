#include "SimpleCache.h"

uint8_t L1Cache[L1_SIZE];
uint8_t L2Cache[L2_SIZE];
uint8_t DRAM[DRAM_SIZE];
uint32_t time;
Cache SimpleCache;

/**************** Time Manipulation ***************/
void resetTime() { time = 0; }

uint32_t getTime() { return time; }

/****************  RAM memory (byte addressable) ***************/
void accessDRAM(uint32_t address, uint8_t *data, uint32_t mode) {

  if (address >= DRAM_SIZE - BLOCK_SIZE + 1)
    exit(-1);

  if (mode == MODE_READ) {
    memcpy(data, &(DRAM[address]), BLOCK_SIZE);
    time += DRAM_READ_TIME;
  }

  if (mode == MODE_WRITE) {
    memcpy(&(DRAM[address]), data, BLOCK_SIZE);
    time += DRAM_WRITE_TIME;
  }
}

/*********************** L1 cache *************************/

void initCache() { SimpleCache.init = 0; }

void accessL1(uint32_t address, uint8_t *data, uint32_t mode) {

  uint32_t index, Tag, offset, MemAddress;
  uint8_t TempBlock[BLOCK_SIZE];

  /* init cache */
  if (SimpleCache.init == 0) {
    for (int i = 0; i < L1_SIZE / BLOCK_SIZE; i++) {
      SimpleCache.lines[i].Valid = 0;
    }
    SimpleCache.init = 1;
  }

  uint32_t offset_bits = get_bits(BLOCK_SIZE);  // log2(BLOCK_SIZE) to calculate the number of bits for offset
  uint32_t index_bits = get_bits(L1_SIZE / BLOCK_SIZE);  // log2(L1_SIZE / BLOCK_SIZE) to calculate the number of bits for index
  uint32_t word_bits = get_bits(WORD_SIZE);  // log2(WORD_SIZE) to calculate the number of bits for each byte in a word
  
  uint32_t offset_mask = (1ULL << offset_bits) - 1;  
  uint32_t index_mask = (1ULL << index_bits) - 1;
  
  offset = address & offset_mask;  
  index = (address >> offset_bits) & index_mask;
  Tag = address >> (offset_bits + index_bits); 

  MemAddress = address >> offset_bits; 
  MemAddress = MemAddress << offset_bits; // address of the block in memory (first position of the block)

  CacheLine *Line = &SimpleCache.lines[index];

  /* access Cache*/

  if (!Line->Valid || Line->Tag != Tag) {         // if block not present - miss
    accessDRAM(MemAddress, TempBlock, MODE_READ); // get new block from DRAM

    if ((Line->Valid) && (Line->Dirty)) { // line has dirty block
      MemAddress = (Line->Tag << index_bits) | index;
      MemAddress = MemAddress << offset_bits; // get address of the block in memory
      accessDRAM(MemAddress, &(L1Cache[index * BLOCK_SIZE]), MODE_WRITE); // then write back old block
    }

    memcpy(&(L1Cache[index * BLOCK_SIZE]), TempBlock,
           BLOCK_SIZE); // copy new block to cache line
    Line->Valid = 1;
    Line->Tag = Tag;
    Line->Dirty = 0;
  } // if miss, then replaced with the correct block

  offset = offset >> word_bits;
  offset = offset << word_bits; // cache is word addressable

  if (mode == MODE_READ) {    // read data from cache line
    memcpy(data, &(L1Cache[index*BLOCK_SIZE + offset]), WORD_SIZE);
    time += L1_READ_TIME;
  }

  if (mode == MODE_WRITE) { // write data from cache line
    memcpy(&(L1Cache[index*BLOCK_SIZE + offset]), data, WORD_SIZE);
    time += L1_WRITE_TIME;
    Line->Dirty = 1;
  }
}

/*********************** Interfaces *************************/

void read(uint32_t address, uint8_t *data) {
  accessL1(address, data, MODE_READ);
}

void write(uint32_t address, uint8_t *data) {
  accessL1(address, data, MODE_WRITE);
}

/*********************** Helper Functions *************************/

// Function to get the number of bits required to address a given number of bytes
uint32_t get_bits(uint32_t bytes) {
  uint32_t bits = 0;
  while (bytes > 1) {
    bytes = bytes >> 1; // right shift by 1 (divides by 2)
    bits++; // increment the bit count
  }
  return bits;
}
