#include <stdio.h>

void *nextAlignedAddress(void *faddr, size_t size) {
  size_t addr = (size_t) faddr;
  printf("%ld\n", addr);
  if (addr % size == 0) {
    return faddr;
  } else{
    return (void *)(addr + (size - addr % size));
  }
}


int main() {
  void *p;
  if (1 != scanf("%llx", (long long unsigned int *) &p)) {
    printf("Failed to read a hexadecimal number for the pointer!");
    return 1;
  }
  size_t size;
  if (1 != scanf("%lu", &size)) {
    printf("Failed to read an unsigned number for the size!");
    return 1;
  }
  printf("Start of free memory address is: %p\n", p);
  printf("So next %lu size aligned address is: %p\n", size, nextAlignedAddress(p, size));
}
