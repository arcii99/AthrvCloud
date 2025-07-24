//FormAI DATASET v1.0 Category: Date and time ; Style: complex
#include <stdio.h>
#include <time.h>

int main() {
   time_t current_time = time(NULL);
   struct tm *local_time = localtime(&current_time);

   int hour = local_time->tm_hour;
   int minute = local_time->tm_min;
   int second = local_time->tm_sec;
   int day = local_time->tm_mday;
   int month = local_time->tm_mon + 1;
   int year = local_time->tm_year + 1900;

   printf("Current date and time: %02d/%02d/%d %02d:%02d:%02d\n", day, month, year, hour, minute, second);

   return 0;
}