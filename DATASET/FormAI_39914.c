//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(void) {
  char* memory = (char*) malloc(1048576 * sizeof(char));
  memset(memory, 0, 1048576);

  int i = 0;
  while(1) {
    memory[rand() % 1048576] = 'A';
    printf("Current memory usage: %d\n", ++i);

    if(i == 100000) {
      printf("Initiating cleanup...\n");
      memset(memory, 0, 1048576);
      printf("Done!\n");

      i = 0;
    }

    sleep(1);
  }

  return 0;
}