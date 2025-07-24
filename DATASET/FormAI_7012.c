//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define CPU_INDEX 0

int main()
{
  struct sysinfo sys_info;
  unsigned long long prev_total_time = 0, prev_idle_time = 0;
  
  while(1)
  {
    if(sysinfo(&sys_info) != 0)
    {
      printf("Unable to get system information\n");
      exit(EXIT_FAILURE);
    }
    
    unsigned long long total_time = sys_info.loads[CPU_INDEX];
    unsigned long long idle_time = sys_info.loads[3];
    
    if(prev_total_time != 0)
    {
      //calculate the cpu usage percent and print it
      double cpu_usage = ((total_time - prev_total_time) -
                      (idle_time - prev_idle_time)) /
                      (double)(total_time - prev_total_time) * 100.0;
      
      printf("CPU Usage: %f%%\n", cpu_usage);
    }
    
    prev_total_time = total_time;
    prev_idle_time = idle_time;
    
    //wait for one second
    sleep(1);
  }
  return 0;
}