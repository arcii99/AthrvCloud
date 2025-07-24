//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
  if(n == 1) {
    printf("\nMove disk 1 from %c to %c", source, destination);
    return;
  }

  towerOfHanoi(n - 1, source, destination, auxiliary);
  printf("\nMove disk %d from %c to %c", n, source, destination);
  towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
  int n = 4;
  towerOfHanoi(n, 'A', 'B', 'C');
  
  return 0;
}