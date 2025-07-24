//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int x = 69; //Nice

  printf("Before bitwise operations, x is: %d\n", x);

  // Let's shuffle the bits

  int y = x << 4;
  int z = x >> 3;

  // Now let's do some counting

  int ones = count_ones(x);
  int zeros = count_zeros(x);

  // Let's do some logical comparisons

  if (x & y) {
    printf("x and y have overlap :| \n");
  } else {
    printf("x and y have no overlap :) \n");
  }

  if (y | z) {
    printf("y and z have some overlap :| \n");
  } else {
    printf("y and z have no overlap :) \n");
  }

  if (!(x ^ y)) {
    printf("x and y are identical :) \n");
  } else {
    printf("x and y are different :| \n");
  }

  // And finally, let's randomize everything

  int random_mask = rand() % 128;

  x ^= random_mask;
  y ^= random_mask;
  z ^= random_mask;

  printf("After random XOR with mask %d, x is: %d\n", random_mask, x);
  printf("After random XOR with mask %d, y is: %d\n", random_mask, y);
  printf("After random XOR with mask %d, z is: %d\n", random_mask, z);

  return 0;

}

// Helper function to count number of set bits
int count_ones(int n) {
  int count = 0;
  while (n) {
    count++;
    n &= (n - 1);
  }
  return count;
}

// Helper function to count number of unset bits
int count_zeros(int n) {
  int count = 0;
  while (n) {
    count += !(n & 1);
    n >>= 1;
  }
  return count;
}