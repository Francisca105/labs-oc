#ifndef SIMPLECACHE_H
#define SIMPLECACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "Cache.h"

void resetTime();

uint32_t getTime();

uint32_t get_bits(uint32_t);

/****************  RAM memory (byte addressable) ***************/
void accessDRAM(uint32_t, uint8_t *, uint32_t);

/*********************** Cache *************************/

void initCache();
void accessL1(uint32_t, uint8_t *, uint32_t);
void accessL2(uint32_t, uint8_t *, uint32_t);

typedef struct CacheLineL1 {
  uint8_t Valid;
  uint8_t Dirty;
  uint32_t Tag;
} CacheLineL1;

typedef struct CacheLineL2 {
  uint8_t Valid[2];
  uint8_t Dirty[2];
  uint32_t Tag[2];
  uint32_t Access_time[2];
} CacheLineL2;

typedef struct CacheL1 {
  uint32_t init;
  CacheLineL1 line[L1_SIZE/BLOCK_SIZE];
} CacheL1;

typedef struct CacheL2 {
  uint32_t init;
  CacheLineL2 line[L2_SIZE/BLOCK_SIZE/2];
} CacheL2;

/*********************** Interfaces *************************/

void read(uint32_t, uint8_t *);

void write(uint32_t, uint8_t *);

#endif