//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <time.h>

int main() {
   time_t currentTime = time(NULL);
   struct tm *timeStruct = localtime(&currentTime);

   printf("Current time is: %02d:%02d:%02d on %02d/%02d/%04d\n\n", timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec, timeStruct->tm_mon+1, timeStruct->tm_mday, timeStruct->tm_year+1900);

   printf("Welcome to the Time Travel Simulator!\n\n");
   printf("Enter a number of years to travel: ");
   int years;
   scanf("%d", &years);

   printf("\nYou have chosen to travel %d years into the", years);
   if (years < 0) {
      printf(" past.\n");
   }
   else {
      printf(" future.\n");
   }

   // Calculate future or past date
   struct tm travelTime = *timeStruct;
   travelTime.tm_year += years;
   mktime(&travelTime);

   printf("\nYou have arrived at: %02d:%02d:%02d on %02d/%02d/%04d\n", travelTime.tm_hour, travelTime.tm_min, travelTime.tm_sec, travelTime.tm_mon+1, travelTime.tm_mday, travelTime.tm_year+1900);

   return 0;
}