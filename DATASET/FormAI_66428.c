//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

void report_current_ram_usage() {
  int who = RUSAGE_SELF;
  struct rusage usage;
  getrusage(who, &usage);
  printf("RAM usage: %ld KB\n", usage.ru_maxrss);
}

int main() {
  srand(time(NULL));
  int* big_array = malloc(100000000 * sizeof(int)); // Allocate 100MB of memory
  for (int i = 0; i < 100000000; i++) {
    big_array[i] = rand(); // Fill the array with random numbers
  }
  report_current_ram_usage();
  sleep(5); // Wait for a while to allow system to update RAM usage
  report_current_ram_usage();
  free(big_array); // Free the memory allocated for the array
  return 0;
}