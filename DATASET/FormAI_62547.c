//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
   int uptime_hours;
   char website[50];
   char website_status[10];
   time_t current_time;

   printf("Welcome to the Website Uptime Monitor!\n");

   printf("Please enter the website URL you want to monitor (max 50 characters):\n");
   scanf("%s", website);

   printf("Please enter the uptime in hours you want to monitor the website:\n");
   scanf("%d", &uptime_hours);

   printf("The program will now monitor the website %s for %d hours...\n", website, uptime_hours);

   time(&current_time);
   printf("The current time is: %s", ctime(&current_time));

   while(uptime_hours > 0){
        printf("Checking website %s...\n", website);

        // Do the actual checking and set the website status
        // Default value is "down" if no response is received within 5 seconds
        // Otherwise, set it to "up"
        strcpy(website_status, "down");

        printf("The website status is: %s\n", website_status);

        time(&current_time);
        printf("Current Time: %s", ctime(&current_time));

        printf("Waiting for 1 hour before checking again...\n", website);
        uptime_hours--;
        sleep(3600);
   }

   printf("The website %s has been monitored for %d hours.\n", website, uptime_hours);

   return 0;
}