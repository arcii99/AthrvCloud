//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include <stdio.h>

void towerOfHanoi(int n, char source, char temp, char destination) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
    return;
  }
  towerOfHanoi(n-1, source, destination, temp);
  printf("Move disk %d from %c to %c\n", n, source, destination);
  towerOfHanoi(n-1, temp, source, destination);
}

int main() {
  printf("Welcome to the Tower of Hanoi Game!\n");
  printf("How many disks do you want to play with?\n");
  int n;
  scanf("%d", &n);

  if (n <= 0) {
    printf("Oops! You didn't enter a valid number of disks\n");
    return 0;
  }

  char source = 'A';
  char temp = 'B';
  char destination = 'C';

  printf("Okay! Let's start game with %d disks\n", n);
  towerOfHanoi(n, source, temp, destination);

  printf("Congratulations! You won the game!\n");
  return 0;
}