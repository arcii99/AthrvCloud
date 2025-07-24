//FormAI DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {

   // Open the log file for reading
   FILE *fp;
   char filename[] = "server.log";
   fp = fopen(filename, "r");

   // Check if the file was successfully opened
   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   // Counters for each log level
   int info_count = 0;
   int warning_count = 0;
   int error_count = 0;

   // Loop over each line in the file
   char line[256];
   while (fgets(line, sizeof(line), fp)) {
      
      // Check if the line contains an info message
      if (strstr(line, "[INFO]") != NULL) {
         info_count++;
      }
      
      // Check if the line contains a warning message
      else if (strstr(line, "[WARNING]") != NULL) {
         warning_count++;
      }
      
      // Check if the line contains an error message
      else if (strstr(line, "[ERROR]") != NULL) {
         error_count++;
      }
   }

   // Print the results
   printf("Log Analysis Results:\n");
   printf("- Info messages: %d\n", info_count);
   printf("- Warning messages: %d\n", warning_count);
   printf("- Error messages: %d\n", error_count);

   // Close the log file
   fclose(fp);

   return 0;
}