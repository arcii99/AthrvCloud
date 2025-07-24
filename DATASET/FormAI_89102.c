//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define MEGABYTE 1024*1024

int main() {
   struct sysinfo sys_info;
   unsigned long long total_ram;

   while(1) {
      if (sysinfo(&sys_info) != 0)
         printf("Error: unable to get system statistics\n");

      // Total RAM in kilobytes
      total_ram = sys_info.totalram / 1024;

      // Convert to megabytes for readability
      printf("Total RAM: %lld MB\n", total_ram / MEGABYTE);

      // Free RAM in kilobytes
      printf("Free RAM: %lld MB\n", (sys_info.freeram / 1024) / MEGABYTE);

      // Used RAM in kilobytes
      printf("Used RAM: %lld MB\n", (total_ram - (sys_info.freeram / 1024)) / MEGABYTE);

      // Sleep for a second to prevent overwhelming resources
      sleep(1);
   }

   return 0;
}