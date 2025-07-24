//FormAI DATASET v1.0 Category: Date and time ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

void printCurrentTime(){
   time_t currentTime;
   struct tm *localTime;

   time( &currentTime );
   localTime = localtime( &currentTime );

   printf( "Current Time: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec );
}

void printCurrentDate(){
   time_t currentTime;
   struct tm *localTime;
   char dateString[MAX_STRING_LENGTH];

   time( &currentTime );
   localTime = localtime( &currentTime );

   strftime(dateString, MAX_STRING_LENGTH, "%A %d %B %Y", localTime);
   printf( "Current Date: %s\n", dateString);
}

int main()
{
   printCurrentDate();
   printCurrentTime();
   
   // Adding 10 days to current date
   time_t currentTime;
   struct tm *localTime;
   char dateString[MAX_STRING_LENGTH];

   time( &currentTime );
   localTime = localtime( &currentTime );

   localTime->tm_mday += 10;
   mktime(localTime);

   strftime(dateString, MAX_STRING_LENGTH, "%A %d %B %Y", localTime);
   printf( "Current Date + 10 days: %s\n", dateString);

   return 0;
}