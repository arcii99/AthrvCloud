//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   while(1) {
      FILE* file = fopen("/proc/meminfo", "r");
      char line[256];
      int memTotal = 0;
      int memFree = 0;
      int memBuffers = 0;
      int memCached = 0;
      int memUsage = 0;

      while(fgets(line, sizeof(line), file)){
         if(sscanf(line, "MemTotal: %d kB", &memTotal) == 1){
            continue;
         } else if(sscanf(line, "MemFree: %d kB", &memFree) == 1){
            continue;
         } else if(sscanf(line, "Buffers: %d kB", &memBuffers) == 1){
            continue;
         } else if(sscanf(line, "Cached: %d kB", &memCached) == 1){
            break;
         }
      }
      fclose(file);
      memUsage = memTotal - memFree - memBuffers - memCached;

      printf("\n--------------\n");
      printf("RAM Usage:\n");
      printf("Total Memory: %d kB\n", memTotal);
      printf("Free Memory: %d kB\n", memFree);
      printf("Buffer Memory: %d kB\n", memBuffers);
      printf("Cached Memory: %d kB\n", memCached);
      printf("RAM Usage: %d kB\n", memUsage);
      printf("--------------\n");

      sleep(1);
   }
   return 0;
}