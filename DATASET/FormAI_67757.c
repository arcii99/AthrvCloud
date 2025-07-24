//FormAI DATASET v1.0 Category: System event logger ; Style: minimalist
#include <stdio.h>
#include <time.h>

int main() {
   time_t current_time;
   char* c_time_string;
   
   FILE *fp;

   fp = fopen("system_events.log", "a+");
   
   if (fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   // Get the current time and log it into the file
   current_time = time(NULL);
   c_time_string = ctime(&current_time);

   fprintf(fp, "System event: Program starts at %s\n", c_time_string);
   
   int i, j;
   for (i = 0; i < 10; i++) {
      
      for (j = 0; j < 5; j++) {
         // Log each event
         fprintf(fp, "System event: Running task %d, sub-task %d at %s\n", i, j, c_time_string);
      }
      
      // Log that the task is complete
      fprintf(fp, "System event: Task %d completed at %s\n", i, c_time_string);
   }
   
   // Close the file when program completes
   fprintf(fp, "System event: Program completes at %s\n", c_time_string);
   fclose(fp);

   return 0;
}