//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multivariable
#include <stdio.h>

int main() {
   int year = 2022;
   int month = 1;
   int day = 1;
   
   printf("Welcome to the Time Travel Simulator!\n");
   printf("You are currently in the year %d, month %d, day %d.\n", year, month, day);
   
   // Let's fast forward to the year 2050
   year = 2050;
   
   printf("It is now the year %d.\n", year);
   
   // Let's go back in time to the year 1990
   year = 1990;
   month = 10;
   day = 23;
   
   printf("You have traveled back in time to %d/%d/%d.\n", month, day, year);
   
   // Let's go to a specific date and time in the future
   year = 2030;
   month = 12;
   day = 31;
   int hour = 23;
   int minute = 59;
   int second = 59;
   
   printf("You have traveled to %d/%d/%d at %02d:%02d:%02d!\n", month, day, year, hour, minute, second);
   
   // Let's go back to the present day
   year = 2022;
   month = 1;
   day = 1;
   
   printf("You have returned to the present day %d/%d/%d.\n", month, day, year);
   
   return 0;
}