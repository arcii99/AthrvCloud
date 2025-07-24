//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#define SLEEP_TIME 1 // Time interval for CPU monitoring in seconds
int main() {
   struct rusage usage;
   unsigned long last_system_time = 0, last_user_time = 0;
   unsigned long system_time, user_time;
   double cpu_usage;
   while(1) { // Keep monitoring CPU usage
       if(getrusage(RUSAGE_SELF, &usage) != 0) {
           fprintf(stderr, "Error: Failed to get CPU usage.\n");
           continue;
       }
       system_time = usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec;
       user_time = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;
       if(last_system_time != 0 || last_user_time != 0) {
           cpu_usage = ((double)(system_time + user_time - last_system_time - last_user_time)) /
                       (double)(SLEEP_TIME * 10000);
           printf("CPU usage: %.2f%%\n", cpu_usage);
       }
       last_system_time = system_time;
       last_user_time = user_time;
       sleep(SLEEP_TIME); // Wait for next interval
   }
   return 0;
}