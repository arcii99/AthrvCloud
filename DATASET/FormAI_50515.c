//FormAI DATASET v1.0 Category: Date and time ; Style: inquisitive
#include <stdio.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm *time_info;
   char time_string[50];
   
   time(&current_time);
   time_info = localtime(&current_time);

   strftime(time_string, sizeof(time_string), "%A %B %d %Y %H:%M:%S", time_info);

   printf("Current date and time is: %s\n", time_string);

   // Asking user for input
   char response;
   printf("Do you want to know more? (y/n) ");
   scanf(" %c", &response);

   // Check user response
   if (response == 'y' || response == 'Y') {

      // Adding 3 days to the current date
      time_info->tm_mday += 3;
      mktime(time_info);

      strftime(time_string, sizeof(time_string), "After 3 days it will be %A %B %d %Y %H:%M:%S", time_info);
      printf("%s\n", time_string);

      // Finding the duration between two dates
      struct tm new_year = { 0 };
      double seconds;
      new_year.tm_hour = 0; 
      new_year.tm_min = 0;
      new_year.tm_sec = 0;
      new_year.tm_year = time_info->tm_year; 
      new_year.tm_mon = 0; 
      new_year.tm_mday = 1;

      seconds = difftime(mktime(time_info), mktime(&new_year)); 

      printf("It has been %f seconds since the start of the year.\n", seconds);
   } else {
      printf("Thank you for using this program!\n");
   }
   return 0;
}