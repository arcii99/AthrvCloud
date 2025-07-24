//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm * time_info;
   char time_string[50];

   // Print the current time
   time(&current_time);
   time_info = localtime(&current_time);
   strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
   printf("Current Time: %s\n", time_string);

   // Set some random time in the past and future
   srand(time(NULL));
   int rand_year = rand() % 100 + 1900;
   int rand_month = rand() % 12 + 1;
   int rand_day = rand() % 28 + 1; // Assume all months have 28 days
   int rand_hour = rand() % 24;
   int rand_minute = rand() % 60;
   int rand_second = rand() % 60;

   printf("Random Time in the Past: %d-%02d-%02d %02d:%02d:%02d\n", rand_year, rand_month, rand_day, rand_hour, rand_minute, rand_second);

   time_info->tm_year = rand_year - 1900;
   time_info->tm_mon = rand_month - 1;
   time_info->tm_mday = rand_day;
   time_info->tm_hour = rand_hour;
   time_info->tm_min = rand_minute;
   time_info->tm_sec = rand_second;

   time_t past_time = mktime(time_info);

   // Print the time travel result
   difftime(current_time, past_time) > 0 ? printf("You have traveled %f seconds into the future!\n", difftime(current_time, past_time)) :
   printf("You have traveled %f seconds into the past!\n", difftime(current_time, past_time));

   time_info = localtime(&past_time);
   strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
   printf("Time Travel Destination Time: %s\n", time_string);

   return 0;
}