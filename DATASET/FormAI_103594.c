//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include<stdio.h>

void tower_of_hanoi(int num_disks, char source_rod, char destination_rod, char auxiliary_rod) {
  if(num_disks == 1) {
    printf("\n Move disk 1 from rod %c to rod %c", source_rod, destination_rod);
    return;
  }

  tower_of_hanoi(num_disks - 1, source_rod, auxiliary_rod, destination_rod);
  printf("\n Move disk %d from rod %c to rod %c", num_disks, source_rod, destination_rod);
  tower_of_hanoi(num_disks - 1, auxiliary_rod, destination_rod, source_rod);
}

int main() {
  int num_disks = 3; // can change the number of disks
  printf("\n------Tower of Hanoi------\n");
  printf("\nNumber of disks: %d\n", num_disks);
  tower_of_hanoi(num_disks, 'A', 'C', 'B');
  printf("\n");
  return 0;
}