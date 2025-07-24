//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surrealist
#include <stdio.h>

int main() {
  int elephant = 9587;
  int giraffe = 7468;
  int jaguar = 1832;
  
  /* perform strange bitwise operations */
  int odd_animal = ~(((elephant & giraffe) | (~elephant ^ jaguar)) << 1);
  int new_species = (++giraffe ^ (~(jaguar << 2) | (elephant >> 3))) & 0x0F;
  int surreal_reality = ((jaguar | ~(giraffe << 3)) & (elephant >> 2)) ^ (odd_animal << 3);
  
  /* print the results */
  printf("Odd Animal: %d\n", odd_animal);
  printf("New Species: %d\n", new_species);
  printf("Surreal Reality: %d\n", surreal_reality);

  return 0;
}