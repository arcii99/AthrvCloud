//FormAI DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <time.h>

int main() {
   time_t now = time(0);
   char* time_string = ctime(&now);
   FILE* log_file = fopen("event_log.txt", "a");  // Open log file in append mode

   fprintf(log_file, "--------------------------------\n");
   fprintf(log_file, "System Event: Error\n");
   fprintf(log_file, "Time: %s", time_string);
   fprintf(log_file, "Error Code: %d\n", 404);
   fprintf(log_file, "Error Message: %s\n", "Page not found");
   fprintf(log_file, "--------------------------------\n");

   fclose(log_file);  // Always close the file after writing to it
   return 0;
}