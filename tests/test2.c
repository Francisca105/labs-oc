#include "../code/4.1/L1Cache.h"

#define offset_bits 6
#define index_bits 8

// Checks if is there any problem with alignment and if a block is placed on cache on full extent

// The output might seem strange but those leaps between stored data happen because when a write -
// or read for that matter - happens, it is written a full aligned word on the memory, meaning
// only the last value will stay stored
// Despite the memory being theoretically byte addressable, ensuring the data alignment makes it
// so that in reality it is only word addressable

int main() {

  resetTime();
  initCache();

  int i, value;

  for (i = 0; i < BLOCK_SIZE; i++) {
    write(i, (unsigned char *)(&i));
    printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());
  }

  write(i, (unsigned char *)(&i));
  printf("\nWrite 1 byte after the end of the block\n");
  printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());
  printf("Confirmed that block ended due to necessity of going to the main memory\n");

  i = 1 << (offset_bits + index_bits);
  write(i, (unsigned char *)(&i));
  printf("\nWrite; Address %d; Value %d; Time %d\n", i, i, getTime());
  printf("Replaced the block\n\n");

  for (i = 0; i < BLOCK_SIZE; i++) {
    read(i, (unsigned char *)(&value));
    printf("Read; Address %d; Value %d; Time %d\n", i, value, getTime());
  }
  
  return 0;
}