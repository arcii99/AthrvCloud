//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(void) {
   FILE *fp;
   char buffer[BUFSIZE];
   char pattern[32] = "MemTotal:";
   char *match;
   unsigned long memtotal, memfree, memusage;
   int scans;

   while (1) {
       fp = fopen("/proc/meminfo", "r");
       if (fp == NULL) {
           perror("Error opening /proc/meminfo! ");
           exit(EXIT_FAILURE);
       }
       scans = 0;
       while (scans < 2) {
           if (fgets(buffer, BUFSIZE, fp) == NULL) {
               if (feof(fp)) {
                   printf("EOF before matching \"%s\"\n", pattern);
               } else {
                   printf("Error reading from /proc/meminfo!\n");
               }
               fclose(fp);
               exit(EXIT_FAILURE);
           }
           match = strstr(buffer, pattern);
           if (match != NULL) {
               scans++;
               sscanf(buffer, "%*s %lu", &memtotal);
               if (scans == 1) {
                   pattern[8] = 'F';
               } else {
                   sscanf(buffer, "%*s %lu", &memfree);
               }
           }
       }
       fclose(fp);
       
       memusage = memtotal - memfree;
       printf("Total Memory: %lu kB, Free Memory: %lu kB, Used Memory: %lu kB\n", memtotal, memfree, memusage);
       
       usleep(500000);
   }
   
   return 0;
}