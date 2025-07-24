//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t now;
   struct tm *timeinfo;

   now = time(NULL);
   timeinfo = localtime(&now);

   char filename[100];
   sprintf(filename, "event_log_%04d%02d%02d.txt",
           timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);

   FILE *fp = fopen(filename, "a");
   if (fp == NULL) {
      printf("Error opening file\n");
      exit(1);
   }

   fprintf(fp, "System event occurred on %d/%d/%d at %d:%d:%d\n",
           timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
           timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

   fclose(fp);

   return 0;
}