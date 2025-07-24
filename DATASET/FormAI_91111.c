//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main()
{
     struct sysinfo si;
     int percent_cpu_usage;

     while(1) {
          if(sysinfo(&si) != 0) {
               perror("sysinfo");
               exit(1);
          }

          percent_cpu_usage = (100 * (si.totalram - si.freeram)) / si.totalram;

          printf("CPU Usage: %d%%\n", percent_cpu_usage);

          sleep(1);
     }

     return 0;
}