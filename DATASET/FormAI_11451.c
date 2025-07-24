//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
void hanoi(int num, char from, char to, char aux) {
  if (num == 1) {
    printf("\nMove disk 1 from rod %c to rod %c", from, to);
    return;
  }
  hanoi(num-1, from, aux, to);
  printf("\nMove disk %d from rod %c to rod %c", num, from, to);
  hanoi(num-1, aux, to, from);
}
int main() {
  int num = 3; // Number of disks
  hanoi(num, 'A', 'C', 'B'); // A, B and C are the rods
  return 0;
}