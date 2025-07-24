//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void move(int n, int source, int aux, int destination) {
  if (n > 0) {
    move(n - 1, source, destination, aux);
    printf("Move disk %d from tower %d to tower %d.\n", n, source, destination);
    move(n - 1, aux, source, destination);
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Please specify the number of disks.\n");
    return 1;
  }
  int n = atoi(argv[1]);
  if (n < 1) {
    printf("Please enter a positive integer.\n");
    return 1;
  }
  printf("Solving Tower of Hanoi problem for %d disks.\n", n);
  move(n, 1, 2, 3);
  return 0;
}