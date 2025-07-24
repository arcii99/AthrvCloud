//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   int present_year, time_interval;
   int future_year, past_year, random_year;

   // Setup random number generator
   srand(time(NULL));

   // Get present year and time interval from user
   printf("Enter the present year: ");
   scanf("%d", &present_year);
   printf("Enter the time interval to travel (in years): ");
   scanf("%d", &time_interval);

   // Calculate future year
   future_year = present_year + time_interval;
   printf("You are travelling %d years into the future.\n", time_interval);
   printf("You arrive in the year %d.\n", future_year);

   // Calculate past year
   past_year = present_year - time_interval;
   printf("You are travelling %d years into the past.\n", time_interval);
   printf("You arrive in the year %d.\n", past_year);

   // Random time travel
   random_year = rand() % (2*time_interval+1) - time_interval + present_year;
   printf("You are randomly time travelling.\n");
   if(random_year > present_year) {
      printf("You are travelling %d years into the future.\n", random_year-present_year);
   } else if(random_year < present_year) {
      printf("You are travelling %d years into the past.\n", present_year-random_year);
   } else {
      printf("You are staying in the present year.\n");
   }
   printf("You arrive in the year %d.\n", random_year);
   
   return 0;
}