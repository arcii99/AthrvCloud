//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>

#define INTERVAL 1

// Function to get CPU usage
float get_cpu_percentage() 
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    struct timeval *start_time = &(usage.ru_utime);
    struct timeval *stop_time = &(usage.ru_stime);
    float seconds = stop_time->tv_sec - start_time->tv_sec + (stop_time->tv_usec - start_time->tv_usec) / (float)1e6;
    float cpu_percentage = 100 * seconds / INTERVAL;
    return cpu_percentage;
}

int main()
{
   float cpu_percentage;
   printf("Starting CPU Usage monitor...\n");
   while(1)
   {
      cpu_percentage = get_cpu_percentage();
      printf("CPU Usage: %.2f%%\n", cpu_percentage);
      sleep(INTERVAL);
   }
   return 0;
}