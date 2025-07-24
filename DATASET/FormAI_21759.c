//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main()
{
   // get current date and time using time() function
   time_t current_time;
   time(&current_time);

   // convert current time to local time
   struct tm *local_time = localtime(&current_time);

   // print local time in a human-readable format
   printf("Current date and time: %s\n", asctime(local_time));

   return 0;
}