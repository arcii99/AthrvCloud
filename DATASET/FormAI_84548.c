//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t t = time(NULL);
   struct tm *tm = localtime(&t); // get current time in local timezone
   
   // print current date and time
   printf("Current date and time: %s", asctime(tm));

   // set a specific date and time
   struct tm birthday = {0};
   birthday.tm_year = 95; // 1995
   birthday.tm_mon = 8; // September
   birthday.tm_mday = 5; // 5th
   birthday.tm_hour = 12;
   birthday.tm_min = 0;
   birthday.tm_sec = 0;
   
   time_t birthday_time = mktime(&birthday); // convert to time_t
   struct tm *birthday_tm = localtime(&birthday_time);

   // print the specific date and time
   printf("My birthday is on %s", asctime(birthday_tm));

   // calculate time difference between current time and specified time
   double diff = difftime(birthday_time, t);
   printf("Time until my next birthday: %.0lf seconds\n", diff);

   return 0;
}