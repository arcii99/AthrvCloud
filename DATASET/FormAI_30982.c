//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
  struct rusage usage;
  int i = 0;
  
  while (i < 50) {
    if (getrusage(RUSAGE_SELF, &usage) != 0) {
      perror("getrusage");
      exit(EXIT_FAILURE);
    }
    
    printf("CPU Usage: %ld.%ld%%\n", usage.ru_utime.tv_sec * 100 / 1, usage.ru_utime.tv_usec / 10000);
    
    i++;
    usleep(500000);
  }
  
  return 0;
}