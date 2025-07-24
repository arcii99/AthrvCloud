//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the RAM Usage Monitor!\n\n");

  printf("Press Enter to start monitoring, or type 'Q' to quit.\n");

  char choice = getchar();

  if(choice == 'Q') {
    printf("Sad to see you go. Bye-bye!\n");
    return 0;
  }

  printf("Monitoring started...\n");

  while(1) {
    int* ptr = (int*)malloc(sizeof(int)*10000000);
    printf("Allocated 10000000 bytes of memory.\n");

    char response = getchar();

    if(response == 'Q') {
      printf("Stopping monitor...\n");
      return 0;
    }

    free(ptr);
    printf("Deallocated memory.\n");
  }

  return 0;
}