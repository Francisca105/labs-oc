#include "../code/4.1/L1Cache.h"

// Checks if the program is safe from out of bounds memory acess

int main() {

  resetTime();
  initCache();

  int i = 0, value;
  write(i, (unsigned char *)(&i));
  printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());

  read(i, (unsigned char *)(&value));
  printf("Read; Address %d; Value %d; Time %d\n", i, value, getTime());

  i = DRAM_SIZE - 1;
  write(i, (unsigned char *)(&i));
  printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());

  read(i, (unsigned char *)(&value));
  printf("Read; Address %d; Value %d; Time %d\n", i, value, getTime());

  i = DRAM_SIZE;
  write(i, (unsigned char *)(&i));
  printf("Write; Address %d; Value %d; Time %d\n", i, i, getTime());

  read(i, (unsigned char *)(&value));
  printf("Read; Address %d; Value %d; Time %d\n", i, value, getTime());
  
  return 0;
}