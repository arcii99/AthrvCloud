//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: minimalist
#include <stdio.h>

void move(int source, int dest) {
  printf("Move disc from tower %d to tower %d\n", source, dest);
}

void hanoi(int n, int source, int dest, int tmp) {
  if (n == 1) {
    move(source, dest);
  }
  else {
    hanoi(n-1, source, tmp, dest);
    move(source, dest);
    hanoi(n-1, tmp, dest, source);
  }
}

int main() {
  int n = 4;
  printf("Solving Tower of Hanoi for %d discs:\n", n);
  hanoi(n, 1, 3, 2);
  return 0;
}