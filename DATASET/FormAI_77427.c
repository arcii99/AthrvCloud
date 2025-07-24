//FormAI DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <time.h>

int main()
{
   time_t current_time;
   char* c_time_string;

   /* Obtain current time. */
   current_time = time(NULL);

   /* Convert to local time format. */
   c_time_string = ctime(&current_time);

   /* Print to log file. */
   FILE *log_file = fopen("system_log.txt", "a");
   fprintf(log_file, "System event occurred at: %s\n", c_time_string);
   fclose(log_file);

   printf("System event logged successfully.\n");

   return 0;
}