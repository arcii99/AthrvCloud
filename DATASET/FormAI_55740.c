//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

void moveTower(int n, char from, char to, char aux);
// Function prototype for moveTower

int main() {
  int n;
  printf("Welcome to the Tower of Hanoi Game!\n");
  printf("How many disks would you like to play with?\n");
  scanf("%d", &n); // User inputs the number of disks to use

  printf("\n");

  moveTower(n, 'A', 'B', 'C'); // Call moveTower function

  printf("Congratulations! You've won the Tower of Hanoi Game! You're a superstar!\n");

  return 0;
}

void moveTower(int n, char from, char to, char aux) {
  if(n == 1) { // Base case: If there is only one disk, move it to the destination peg
    printf("Move disk 1 from peg %c to peg %c.\n", from, to);
    return;
  }

  moveTower(n-1, from, aux, to); // Recursively move n-1 disks from the "from" peg to the "auxiliary" peg

  printf("Move disk %d from peg %c to peg %c.\n", n, from, to); // Move the largest disk from the "from" peg to the "to" peg

  moveTower(n-1, aux, to, from); // Recursively move the n-1 disks from the "auxiliary" peg to the "to" peg
}