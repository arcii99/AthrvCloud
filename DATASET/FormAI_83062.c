//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
  printf("Welcome to the CPU Usage Monitor. Press Ctrl+C to exit.\n");

  while (1) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) != 0) {
      perror("Error in getrusage");
      exit(EXIT_FAILURE);
    }

    printf("CPU usage: %ld.%06ld seconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    puts(" "); /* Some whitespace for added style */

    sleep(1); /* Wait a second before checking again */
  }

  return 0;
}