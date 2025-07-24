//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, mem, curr;
  printf("Welcome to the Happy RAM Usage Monitor! Let's get started!\n\n");

  printf("Enter the amount of memory to monitor (in MB): ");
  scanf("%d", &mem);

  printf("\nMonitoring RAM usage...\n\n");

  while(1) {
    curr = rand() % (mem + 1);

    printf("Current RAM usage: %dMB [", curr);

    for(i = 0; i < curr; i++) {
      printf("*");
    }
    
    for(j = 0; j < mem - curr; j++) {
      printf("-");
    }

    printf("]\n");

    if (curr == mem) {
      printf("Memory is full! Do something about it!\n");
    }

    printf("\nPress ENTER to continue monitoring...\n");
    getchar();
  }

  return 0;
}