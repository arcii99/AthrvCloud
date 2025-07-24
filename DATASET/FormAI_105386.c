//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int mem_used = 0;
   int mem_total = 0;
   FILE* fp;
   char* line = NULL;
   size_t len = 0;

   fp = fopen("/proc/meminfo", "r");
   if (fp == NULL) {
      perror("Error opening file");
      return -1;
   }

   while (getline(&line, &len, fp) != -1) {
      char* token = strtok(line, ":");
      if (strcmp(token, "MemTotal") == 0) {
         token = strtok(NULL, " ");
         mem_total = atoi(token);
      }
      if (strcmp(token, "MemAvailable") == 0) {
         token = strtok(NULL, " ");
         mem_used = mem_total - atoi(token);
      }
   }

   printf("RAM Used: %d MB\n", mem_used / 1024);
   printf("RAM Total: %d MB\n", mem_total / 1024);

   fclose(fp);
   if (line) {
      free(line);
   }

   return 0;
}