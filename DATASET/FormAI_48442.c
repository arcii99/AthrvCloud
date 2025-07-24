//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
  struct rusage usage;
  int count = 0;

  printf("Welcome to the CPU Usage Monitor!\n");
  printf("Press CTRL+C to exit.\n\n");

  while(1) {
    if(getrusage(RUSAGE_SELF, &usage) == -1) {
      perror("getrusage");
      exit(1);
    }

    printf("CPU Usage: %ld microseconds\n", (usage.ru_utime.tv_sec * 1000000) + usage.ru_utime.tv_usec);

    count++;

    if(count % 10 == 0) {
      printf("\nYou have been monitoring your CPU usage for %d seconds.\n", count);
    }

    usleep(100000);
  }

  return 0;
}