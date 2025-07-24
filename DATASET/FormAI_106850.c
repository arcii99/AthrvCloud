//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
void move(int, char, char, char);
int main() {
  int num;
  printf("Enter the number of disks: ");
  scanf("%d", &num);
  printf("The sequence of moves involved in the Tower of Hanoi are:\n");
  move(num, 'A', 'C', 'B');
  return 0;
}
void move(int num, char frompeg, char topeg, char auxpeg) {
  if (num == 1) {
    printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);
    return;
  }
  move(num - 1, frompeg, auxpeg, topeg);
  printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
  move(num - 1, auxpeg, topeg, frompeg);
}