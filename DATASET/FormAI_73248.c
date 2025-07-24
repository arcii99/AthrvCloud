//FormAI DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   FILE *fp;
   time_t rawtime;
   struct tm * timeinfo;
   char event[100];
   char date[20];

   fp = fopen("event_log.txt", "a"); // open the file in append mode

   if (fp == NULL) {
      printf("Cannot open file! Program exiting...\n"); // if file cannot be opened, print error message and exit program
      exit(1);
   }

   printf("Enter the event you want to log:\n");
   scanf("%s", event);

   time(&rawtime); // get current time
   timeinfo = localtime(&rawtime); // convert to struct tm format
   strftime(date, 20, "%Y-%m-%d %H:%M:%S", timeinfo); // format date as string

   fprintf(fp, "%s: %s\n", date, event); // write log entry to file

   printf("Event successfully logged!\n");

   fclose(fp); // close the file

   return 0;
}