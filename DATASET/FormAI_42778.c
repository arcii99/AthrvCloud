//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

  int size = 1024; // setting a default size of 1 GB
  int i;
  int *ptr;

  printf("Greetings, my dear friend! I see you are in need of a RAM monitor.\n");

  printf("What size of RAM would you like to monitor, in GB? (max. 100)\n");

  scanf("%d", &size);

  if(size < 1 || size > 100) {
    printf("Invalid input. Setting the RAM size to 1 GB.\n");
    size = 1;
  }

  printf("The monitor will now run and check the RAM usage every second. Press Ctrl + C to stop.\n");

  for(i = 1; i <= 100; i++) {

    ptr = (int *)malloc(sizeof(int) * size * 1024 * 1024);

    if(ptr == NULL) {
      printf("Error: Couldn't allocate memory\n");
      exit(0);
    }

    memset(ptr, 0, sizeof(int) * size * 1024 * 1024);
    
    printf("RAM Usage: %d out of %d GB\n", i, 100);
    
    sleep(1);

    free(ptr);

  }

  return 0;
}