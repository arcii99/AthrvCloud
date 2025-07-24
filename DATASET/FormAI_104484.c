//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>

void hanoi(int numDiscs, int start, int aux, int end);

int main() {
  int numDiscs = 5; // change the number of discs as desired
  int start = 1, aux = 2, end = 3;

  printf("The Tower of Hanoi post-apocalyptic edition:\n\n");
  printf("You have %d metal rods, each with varying sizes.\n", numDiscs);
  printf("The world has ended and you need to move all the rods from Rod %d to Rod %d.\n", start, end);
  printf("You can only move one rod at a time and you can only stack a smaller rod on top of a larger one.\n");
  printf("Good luck survivor.\n\n");

  hanoi(numDiscs, start, aux, end);

  printf("\nYou did it, survivor. You successfully moved all the metal rods to Rod %d.\n", end);

  return 0;
}

void hanoi(int numDiscs, int start, int aux, int end) {
  if (numDiscs > 0) {
    hanoi(numDiscs - 1, start, end, aux);
    printf("Moving metal rod from Rod %d to Rod %d.\n", start, end);
    hanoi(numDiscs - 1, aux, start, end);
  }
}