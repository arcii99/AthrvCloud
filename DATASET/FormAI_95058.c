//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <time.h>

int main() {
   time_t presentTime = time(NULL);
   struct tm *currentTime = localtime(&presentTime);

   printf("Welcome to the Time Travel Simulator!\n");
   printf("At the sound of the tone, the time will be:\n");
   printf("%s", asctime(currentTime));
   
   // Let's go back in time!
   int yearsTravelled = 10;
   printf("\nSetting the Time Travel Machine to go back %d years...\n", yearsTravelled);
   presentTime -= (yearsTravelled * 365 * 24 * 60 * 60);
   currentTime = localtime(&presentTime);
   printf("\nThe Time Travel Machine has arrived! You are now in %d CE.\n", currentTime->tm_year + 1900);

   // Let's go forward in time!
   int daysTravelled = 100;
   printf("\nSetting the Time Travel Machine to go forward %d days...\n", daysTravelled);
   presentTime += (daysTravelled * 24 * 60 * 60);
   currentTime = localtime(&presentTime);
   printf("\nThe Time Travel Machine has arrived! You are now in the year %d. It is %s", currentTime->tm_year + 1900, asctime(currentTime));

   printf("\nThank you for using the Time Travel Simulator!\n");

   return 0;
}