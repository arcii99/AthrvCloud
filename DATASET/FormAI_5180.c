//FormAI DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to hold the event information
struct EventLog {
   char* eventName;
   char* eventDescription;
   time_t eventTime;
};

int main() {

   // Initialize the event log array
   struct EventLog eventLogArray[100];
   int eventIndex = 0;

   // Define a function to add events to the log
   void addEvent(char* eventName, char* eventDescription) {
      time_t currentTime = time(NULL);
      eventLogArray[eventIndex].eventName = eventName;
      eventLogArray[eventIndex].eventDescription = eventDescription;
      eventLogArray[eventIndex].eventTime = currentTime;
      eventIndex++;
   }

   // Define some sample events to log
   addEvent("Login Attempt", "An attempt was made to log in to the system.");
   addEvent("File Deleted", "A file was deleted from the system.");
   addEvent("File Downloaded", "A file was downloaded from the system.");

   // Define a function to print the event log
   void printEventLog() {
      printf("Event Log:\n");
      for(int i = 0; i < eventIndex; i++) {
         printf("%s\n", eventLogArray[i].eventName);
         printf("%s\n", eventLogArray[i].eventDescription);
         printf("%s\n", ctime(&eventLogArray[i].eventTime));
      }
   }

   // Print the event log
   printEventLog();

   // Return 0 to indicate successful program completion
   return 0;
}