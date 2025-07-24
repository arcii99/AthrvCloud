//FormAI DATASET v1.0 Category: Date and time ; Style: shocked
#include <stdio.h>
#include <time.h>

int main()
{
   time_t current_time;
   struct tm *local_time;
   
   time(&current_time);
   local_time = localtime(&current_time);
   
   int day = local_time->tm_mday;
   int month = local_time->tm_mon + 1;
   int year = local_time->tm_year + 1900;
   int hour = local_time->tm_hour;
   int min  = local_time->tm_min;
   int sec  = local_time->tm_sec;

   printf("Current Date and Time:\n");
   printf("%02d/%02d/%d %02d:%02d:%02d\n", day, month, year, hour, min, sec);

   // add 24 hours
   current_time += 24 * 60 * 60;
   local_time = localtime(&current_time);

   day = local_time->tm_mday;
   month = local_time->tm_mon + 1;
   year = local_time->tm_year + 1900;
   hour = local_time->tm_hour;
   min  = local_time->tm_min;
   sec  = local_time->tm_sec;

   printf("Same time tomorrow:\n");
   printf("%02d/%02d/%d %02d:%02d:%02d\n", day, month, year, hour, min, sec);

   return 0;
}