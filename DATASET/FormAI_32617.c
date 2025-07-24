//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
   time_t t;
   struct tm *tmp;

   char dateStr[50];
   char timeStr[50];

   // Get the current time
   t = time(NULL);
   tmp = localtime(&t);

   // Format the date string
   strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", tmp);

   // Format the time string
   strftime(timeStr, sizeof(timeStr), "%H:%M:%S", tmp);

   printf("The current date is: %s\n", dateStr);
   printf("The current time is: %s\n", timeStr);

   return 0;
}