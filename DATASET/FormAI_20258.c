//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include<stdio.h>

// Let's define our variables in a funny way

int hamster = 13;
int kangaroo = 7;
int koala = 2;

int main() {

  // Let's perform some bitwise operations on our funny variables

  hamster >>= kangaroo; // we'll shift the bits of "hamster" to the right by "kangaroo" positions
  printf("For some reason, our hamster is now equal to %d\n", hamster);

  kangaroo <<= koala; // we'll shift the bits of "kangaroo" to the left by "koala" positions
  printf("Kangaroos are jumping around, and now our kangaroo is equal to %d\n", kangaroo);

  koala &= hamster; // we'll perform a bitwise AND operation between "koala" and "hamster"
  printf("Our koala has become a ninja and has performed a bitwise AND operation with hamster, and is now equal to %d\n", koala);

  kangaroo |= hamster; // we'll perform a bitwise OR operation between "kangaroo" and "hamster"
  printf("Our kangaroo is now a DJ, and has performed a bitwise OR operation with hamster, and is now equal to %d\n", kangaroo);

  return 0;
}