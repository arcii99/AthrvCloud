//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char target) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", source, target);
    return;
  }
  
  printf("Whoa, this is going to be an interesting challenge!\n");
  
  tower_of_hanoi(n - 1, source, target, auxiliary);
  
  printf("Move disk %d from %c to %c\n", n, source, target);
  
  tower_of_hanoi(n - 1, auxiliary, source, target);
  
  printf("Wow, we did it! That was impressive!\n");
}

int main() {
  int num_disks = 5; // Let's start with 5 disks
  char source = 'A';
  char auxiliary = 'B';
  char target = 'C';
  
  printf("Welcome to the Tower of Hanoi program! Today, we'll be solving it with %d disks!\n", num_disks);
  
  tower_of_hanoi(num_disks, source, auxiliary, target);
  
  printf("That was fun! Let's do it again sometime!\n");
  
  return 0;
}