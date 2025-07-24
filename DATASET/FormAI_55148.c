//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   srand(time(NULL)); //seed value for random number generator
   int cpu_usage = 0;
   int i = 0;
   
   while(i < 50) { //loop 50 times

      cpu_usage = rand() % 101; //generate random CPU usage percentage between 0 and 100
      printf("Current CPU Usage: %d%%\n", cpu_usage);

      if(cpu_usage >= 80) { //if CPU usage is 80% or higher
         printf("WARNING: High CPU Usage Detected!\n");
      }

      i++;
      usleep(100000); //wait for 100 milliseconds
   }

   printf("CPU usage monitor completed successfully.\n");

   return 0;
}