//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>

// function to move disks between towers
void moveDisk(char from, char to, int disk) {
  printf("Move disk %d from tower %c to tower %c\n", disk, from, to);
}

// function to solve Tower of Hanoi problem
void towerOfHanoi(int numDisks, char source, char temp, char dest) {
  if(numDisks == 1) {
    moveDisk(source, dest, numDisks);
    return;
  }
  towerOfHanoi(numDisks-1, source, dest, temp);
  moveDisk(source, dest, numDisks);
  towerOfHanoi(numDisks-1, temp, source, dest);
}

int main() {
  int numDisks;
  
  printf("Welcome to the Tower of Hanoi game!\n");
  printf("Please enter the number of disks: ");
  scanf("%d", &numDisks);
  
  // user validation
  if(numDisks <= 0) {
    printf("Invalid input! Number of disks must be greater than 0\n");
    return 0;
  }
  
  // game instructions
  printf("Instructions:\n");
  printf("Tower A is the source tower\n");
  printf("Tower B is the temporary tower\n");
  printf("Tower C is the destination tower\n");
  printf("The objective of the game is to move all the disks from tower A to tower C\n");
  printf("You can only move one disk at a time and no larger disk can be on top of a smaller disk\n");
  
  // starting game
  printf("\nStarting game...\n");
  towerOfHanoi(numDisks, 'A', 'B', 'C');
  printf("\nCongratulations! You have completed the Tower of Hanoi game!\n");
  
  return 0;
}