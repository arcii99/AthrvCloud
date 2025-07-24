//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
  struct rusage usage;
  struct timeval start, end;

  getrusage(RUSAGE_SELF, &usage);
  start = usage.ru_utime;

  while(1) {
    sleep(1);

    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;

    long int cpu_time = (end.tv_sec-start.tv_sec)*1000000L + end.tv_usec-start.tv_usec;

    printf("CPU time used: %ld\n", cpu_time);
  }

  return 0;
}