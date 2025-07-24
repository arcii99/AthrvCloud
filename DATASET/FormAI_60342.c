//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
   struct rusage usage;
   struct timeval start, end;
   int cpu_time_used;

   getrusage(RUSAGE_SELF, &usage);
   start = usage.ru_utime;

   // Perform CPU intensive task - in this case, nested for loops
   for (int i = 0; i < 1000000; i++) {
      for (int j = 0; j < 1000; j++) {
        //Some Operation
      }
   }

   // Calculate time elapsed
   getrusage(RUSAGE_SELF, &usage);
   end = usage.ru_utime;
   cpu_time_used = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;

   printf("CPU time used: %d microseconds\n", cpu_time_used);
   return 0;
}