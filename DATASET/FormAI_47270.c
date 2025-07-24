//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h> 
#include <sys/resource.h>

int main(void) {
   struct rusage usage;
   double cpu_time_used;
   
   while(1) {
       getrusage(RUSAGE_SELF, &usage);
       cpu_time_used = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * 1000.0 + (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000.0;
       printf("CPU usage: %f ms\n", cpu_time_used);
       usleep(1000); // wait for 1 millisecond to minimize CPU usage by the program itself
   }

   return 0;
}