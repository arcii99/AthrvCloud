//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
  int *arr;
  int i, j;
  struct rusage usage;
  printf("Starting memory usage monitoring...\n");
  while (1) {
    arr = malloc(1024 * 1024 * 10);
    for (i = 0; i < 1024 * 1024 * 10; i++) {
      arr[i] = i;
    }
    getrusage(RUSAGE_SELF, &usage);
    printf("Memory usage: %ld MB\n", ((usage.ru_maxrss / 1024) / 1024));
    sleep(1);
  }
  return 0;
}