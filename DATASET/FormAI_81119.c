//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include<stdio.h>

void moveDisk(int n, char start, char end, char auxiliary){
  if (n == 1){
    printf("\n Move disk from rod %c to rod %c", start, end);
    return;
  }

  moveDisk(n-1, start, auxiliary, end);
  printf("\n Move disk from rod %c to rod %c", start, end);
  moveDisk(n-1, auxiliary, end, start);
}

int main(){
  int disks;
  printf("Enter the number of disks: ");
  scanf("%d", &disks);
  printf("The steps to solve Tower of Hanoi problem with %d disks are:\n", disks);
  moveDisk(disks, 'A', 'C', 'B');
  return 0;
}