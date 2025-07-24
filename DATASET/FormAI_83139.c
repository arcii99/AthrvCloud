//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
   struct sysinfo memInfo;
   long long total_Ram;
   long long free_Ram;

   while(1) {
       sysinfo(&memInfo);
       total_Ram = memInfo.totalram;
       total_Ram *= memInfo.mem_unit;
       free_Ram = memInfo.freeram;
       free_Ram *= memInfo.mem_unit;
       long long used_Ram = total_Ram - free_Ram;

       // Output RAM usage
       printf("Total RAM: %lld MB, Used RAM: %lld MB, Free RAM: %lld MB\n", 
              total_Ram / 1024 / 1024, used_Ram / 1024 / 1024, free_Ram / 1024 / 1024);

       sleep(5); // Wait for 5 seconds
   }
   return 0;
}