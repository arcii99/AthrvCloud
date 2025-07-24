//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int year, current_year;
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);

   current_year = tm.tm_year + 1900; // get current year

   printf("Welcome to the time travel simulator\n");
   printf("Enter a year you wish to travel to: ");
   scanf("%d", &year);

   if (year > current_year) {
      printf("Sorry, time travel to the future is not possible\n");
      return 1;
   }

   printf("WELCOME TO THE YEAR %d!\n", year);
   printf("Press any key to return to present day\n");
   getchar(); // flush input buffer
   getchar();

   printf("You have returned to the present day of %d\n", current_year);
   
   return 0;
}