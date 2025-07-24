//FormAI DATASET v1.0 Category: System event logger ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "event_log.txt"

/* Function to log events to the file */
void log_event(char* event) {
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);
   FILE* log_file = fopen(LOG_FILE, "a");
   fprintf(log_file, "%d/%02d/%02d %02d:%02d:%02d - %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, event);
   fclose(log_file);
}

int main() {
   log_event("Application started");

   /* Sample event */
   int a = 10, b = 20;
   if (a < b) {
      log_event("a is less than b");
   } else {
      log_event("b is less than or equal to a");
   }

   log_event("Application exited");

   return 0;
}