//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>

void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
  if (disks == 1) {
    printf("Move disk 1 from %c to %c.\n", source, destination);
    return;
  }
  towerOfHanoi(disks - 1, source, destination, auxiliary);
  printf("Move disk %d from %c to %c.\n", disks, source, destination);
  towerOfHanoi(disks - 1, auxiliary, source, destination);
}

int main() {
  int numDisks = 4;
  printf("Tower of Hanoi for %d disks:\n", numDisks);
  towerOfHanoi(numDisks, 'A', 'B', 'C');
  return 0;
}