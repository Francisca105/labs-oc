#include "../code/4.2/L2Cache.h"

#define offset_bits 6
#define index_bits 8

// Checks if L2 Cache is used whenever possible instead of main memory

int main() {

  resetTime();
  initCache();

  int i = 0, value;
  write(i, (unsigned char *)(&i));
  printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());

  read(i, (unsigned char *)(&value));
  printf("Read; Address %d; Value %d; Time %d\n", i, value, getTime());

  int t1 = DRAM_READ_TIME + L2_READ_TIME + L1_WRITE_TIME + L1_READ_TIME;
  printf("Time = DRAM_READ_TIME + L2_READ_TIME + L1_WRITE_TIME + L1_READ_TIME = %d\n\n", t1);

  i = 1 << (offset_bits + index_bits);
  write(i, (unsigned char *)(&i));
  printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());

  read(i, (unsigned char *)(&value));
  printf("Read; Address %d; Value %d; Time %d\n", i, value, getTime());

  int t2 = t1 + DRAM_READ_TIME + L2_READ_TIME + L2_WRITE_TIME + L1_WRITE_TIME + L1_READ_TIME;
  printf("Time = Time + DRAM_READ_TIME + L2_READ_TIME + L2_WRITE_TIME + L1_WRITE_TIME + L1_READ_TIME = %d\n\n", t2);

  i = 0;
  write(i, (unsigned char *)(&i));
  printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());

  read(i, (unsigned char *)(&value));
  printf("Read; Address %d; Value %d; Time %d\n", i, value, getTime());

  int t3 = t2 + L2_READ_TIME + L2_WRITE_TIME + L1_WRITE_TIME + L1_READ_TIME;
  printf("Time = Time + L2_READ_TIME + L2_WRITE_TIME + L1_WRITE_TIME + L1_READ_TIME = %d\n", t3);
  
  return 0;
}