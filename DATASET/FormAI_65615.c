//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
   struct sysinfo mem_info;
   long int free_memory;

   while(1) {
       if(sysinfo(&mem_info) == -1) {
           perror("sysinfo"); // error handling
           exit(EXIT_FAILURE);
       }
       free_memory = mem_info.freeram / 1024;
       printf("Free memory: %ldMB\n", free_memory);
       sleep(1);
   }
   return 0;
}