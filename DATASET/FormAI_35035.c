//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <sys/times.h>
#include <unistd.h>

int main(){
   struct tms cpu_usage;
   int t;
   clock_t t1, t2;
   t1 = times(&cpu_usage); 
   while(t<50000000){
      t++;
   }
   t2 = times(&cpu_usage);
   double cpu_time_used = (double) (t2 - t1) / sysconf(_SC_CLK_TCK);
   printf("CPU time used: %f\n", cpu_time_used);
   return 0;
}