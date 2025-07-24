//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {

  struct rusage usage;
  int sample_ms = 500;
  while(1) { // loop indefinitely
    if(getrusage(RUSAGE_SELF, &usage) != 0) {
      printf("Error with getrusage\n");
      return 1;
    }
    double cpu_usage_percent = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec + (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0) * 100 / (double) sample_ms;
    printf("CPU Usage: %.2f%%\n", cpu_usage_percent);
    usleep(sample_ms * 1000);
  }
  
  return 0;
}