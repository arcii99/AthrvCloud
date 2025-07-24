//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>

void tower_of_hanoi(int n, char from_peg, char to_peg, char aux_peg) {
  if (n == 1) {
    printf("\nMove disk 1 from peg %c to peg %c", from_peg, to_peg);
    return;
  }
  tower_of_hanoi(n-1, from_peg, aux_peg, to_peg);
  printf("\nMove disk %d from peg %c to peg %c", n, from_peg, to_peg);
  tower_of_hanoi(n-1, aux_peg, to_peg, from_peg);
}

int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);
  tower_of_hanoi(n, 'A', 'C', 'B');
  return 0;
}