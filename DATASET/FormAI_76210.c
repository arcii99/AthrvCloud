//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   time_t current_time;
   
   // Get the current time
   time(&current_time);

   // Extract the year, month, and day from the current time
   struct tm * time_info;
   time_info = localtime(&current_time);
   
   // Prompt the user for a year to travel to
   printf("Enter a year to travel to: ");
   int year;
   scanf("%d", &year);
   
   // Calculate the number of years between the current year and the target year
   int years_to_travel = abs(time_info->tm_year + 1900 - year);
   
   // Check if the target year is in the past or the future
   if(time_info->tm_year + 1900 < year){
      printf("Traveling to the future...\n");
   } else {
      printf("Traveling to the past...\n");
   }
   
   // Wait for a few seconds to simulate time travel
   printf("Hold on tight...\n\n");
   sleep(3);
   
   // Update the current time to the target year
   time_info->tm_year = year - 1900;
   current_time = mktime(time_info);

   // Print the new date and time
   printf("Welcome to %d!\n", year);
   printf("Today's date is %d/%d/%d\n", time_info->tm_mon+1, time_info->tm_mday, time_info->tm_year+1900);
   
   // Calculate the number of years travelled
   printf("You have travelled %d years.\n", years_to_travel);
   
   return 0;
}