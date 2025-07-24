//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr;
  unsigned long int size = 1024 * 1024 * 1024; // 1GB

  ptr = (int*) malloc(size); // allocate memory

  if (ptr == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  printf("Memory allocated successfully.\n");

  while (1) {
    unsigned long int used = 0;
    FILE *fp;
    char buffer[1024];

    fp = fopen("/proc/meminfo", "r"); // read memory information

    if (fp == NULL) {
      printf("Error reading memory usage.\n");
      exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
      if (sscanf(buffer, "MemTotal: %lu kB", &used) == 1) {
        break;
      }
    }

    fclose(fp);

    used = (used * 1024) - (size * sizeof(int)); // calculate used memory

    printf("Used memory: %lu bytes.\n", used);

    sleep(1); // wait for 1 second
  }

  free(ptr); // free memory

  return 0;
}