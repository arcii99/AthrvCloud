//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>

// function prototypes
void tower_of_hanoi(int n, char source, char dest, char temp);
void move_disk(char from, char to);

int main() {
  int n;
  
  printf("Enter the number of disks:\n");
  scanf("%d", &n);
  
  if(n <= 0) {
    printf("The number of disks should be greater than zero.\n");
    return 1;
  }
  
  tower_of_hanoi(n, 'A', 'C', 'B');
  
  return 0;
}

// function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int n, char source, char dest, char temp) {
  if(n == 1) {
    move_disk(source, dest);
    return;
  }
  
  tower_of_hanoi(n-1, source, temp, dest);
  move_disk(source, dest);
  tower_of_hanoi(n-1, temp, dest, source);
}

// function to move a disk from one peg to another
void move_disk(char from, char to) {
  static int count = 0; // keeps track of how many disks have been moved
  
  printf("%d. Move disk from %c to %c\n", ++count, from, to);
}