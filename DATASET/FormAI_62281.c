//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include<stdio.h>
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
  if(n == 0) {
    return;
  }
  towerOfHanoi(n-1, source, auxiliary, destination);
  printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
  towerOfHanoi(n-1, auxiliary, destination, source);
}
int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);
  printf("Steps to solve the Tower of Hanoi problem : \n");
  towerOfHanoi(n, 'A', 'C', 'B');
  return 0;
}