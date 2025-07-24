//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
   struct sysinfo info;
   unsigned long long prev_totalram = 0; // previous total RAM usage
   while (1) { // continuously monitor RAM usage
      sysinfo(&info); // get system info
      unsigned long long totalram = (info.totalram * info.mem_unit)/(1<<30); // calculate total RAM usage in GB
 
      if (totalram != prev_totalram) { // RAM usage has changed
         if (totalram > prev_totalram) {
            printf("RAM usage increased by %llu GB.\n", totalram - prev_totalram);
         } else {
            printf("RAM usage decreased by %llu GB.\n", prev_totalram - totalram);
         }
         prev_totalram = totalram; // update previous RAM usage
      }
 
      sleep(1); // wait a second before checking again
   }
   return 0;
}