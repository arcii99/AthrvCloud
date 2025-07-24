//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>

int main() {
   int year;

   printf("Welcome to the Time Travel Simulator!\n");

   printf("Enter a year: ");
   scanf("%d", &year);

   // check if year is before 1800
   if (year < 1800) {
      printf("Sorry, we don't have the technology to travel back that far.\n");
   }
   // check if year is after current year
   else if (year > 2021) {
      printf("Sorry, we can't travel to the future yet.\n");
   }
   else {
      printf("Preparing to travel to %d...\n", year);

      // travel through time by printing out each year
      for (int i = 2021; i <= year; i++) {
         printf("%d\n", i);
      }

      printf("Arrived at destination year %d. Enjoy your time travel experience!\n", year);
   }

   return 0;
}