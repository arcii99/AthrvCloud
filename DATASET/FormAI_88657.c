//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>

// Function to move disks recursively
void moveDisks(int num_disks, char source, char destination, char aux) {

  // If there is only one disk
  if (num_disks == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
    return;
  }

  // Move (n-1) disks from source to aux, using dest as an aux
  moveDisks(num_disks-1, source, aux, destination);

  // Move the last disk from source to dest
  printf("Move disk %d from %c to %c\n", num_disks, source, destination);

  // Move the (n-1) disks from aux to dest, using source as an aux
  moveDisks(num_disks-1, aux, destination, source);
}

int main() {

  // Number of disks
  int num_disks;

  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  // Call the function to move disks from source to destination
  moveDisks(num_disks, 'A', 'C', 'B');

  return 0;
}