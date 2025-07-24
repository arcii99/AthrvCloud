//FormAI DATASET v1.0 Category: Date and time ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t currentTime;
   struct tm *localTime;

   time( &currentTime );                   // Get the current time
   localTime = localtime( &currentTime );  // Convert the current time to the local time

   int day   = localTime->tm_mday;
   int month = localTime->tm_mon + 1;
   int year  = localTime->tm_year + 1900;
   int hour  = localTime->tm_hour;
   int min   = localTime->tm_min;
   int sec   = localTime->tm_sec;

   printf("Today's date and time is: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, min, sec);

   // You can also print out the day of the week in a more creative way
   switch(localTime->tm_wday) {
      case 0:
         printf("It's Sunday! A day to relax :)\n");
         break;
      case 1:
         printf("It's Monday! Time to get back to work!\n");
         break;
      case 2:
         printf("It's Tuesday! Only 3 more days left!\n");
         break;
      case 3:
         printf("It's Wednesday! Hump day, halfway through the week!\n");
         break;
      case 4:
         printf("It's Thursday! One more day until the weekend!\n");
         break;
      case 5:
         printf("It's Friday! Finally, the weekend is here!\n");
         break;
      case 6:
         printf("It's Saturday! Time to enjoy the weekend :)\n");
         break;
   }

   return 0;
}