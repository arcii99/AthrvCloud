//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main() {
   time_t currentTime;
   struct tm *localTime;
   char timeString[80];

   // Get current time
   currentTime = time(NULL);

   // Convert to local time format
   localTime = localtime(&currentTime);

   // Format the time string
   strftime(timeString, 80, "%Y-%m-%d %H:%M:%S", localTime);

   // Print the time string
   printf("%s\n", timeString);

   return 0;
}