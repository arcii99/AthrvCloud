//FormAI DATASET v1.0 Category: System event logger ; Style: calm
#include <stdio.h>
#include <time.h>
#include <string.h>

// Function to log events
void logEvent(char* eventType, char* eventMessage) {
   // Get current time
   time_t curTime;
   time(&curTime);

   // Convert time to string format
   char timeStr[32];
   strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localtime(&curTime));

   // Create log entry string
   char logEntry[256];
   sprintf(logEntry, "[%s] %s: %s\n", timeStr, eventType, eventMessage);
   
   // Print log entry
   printf("%s", logEntry);

   // Write log entry to file
   FILE* logFile;
   logFile = fopen("logfile.txt", "a");
   
   if (logFile == NULL) {
      printf("Failed to open log file for writing!\n");
   } else {
      fprintf(logFile, "%s", logEntry);
      fclose(logFile);
   }
}

int main() {
   // Log startup event
   logEvent("INFO", "Program started.");

   // Simulate some events
   logEvent("WARN", "File not found.");
   logEvent("ERROR", "Invalid input detected.");
   logEvent("INFO", "Processing complete.");

   // Log shutdown event
   logEvent("INFO", "Program shutdown.");

   return 0;
}