//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// function definition for Tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
  int num_disks;
  
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  // call the function to solve Tower of Hanoi problem
  tower_of_hanoi(num_disks, 'A', 'C', 'B');

  return 0;
}

// function to solve Tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Move (n-1) disks from from_rod to aux_rod using to_rod as auxiliary
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // Move (n-1) disks from aux_rod to to_rod using from_rod as auxiliary
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}