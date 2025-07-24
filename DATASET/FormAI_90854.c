//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   printf("Welcome to Website Uptime Monitor!\n");
   printf("Enter the website URL you would like to monitor:\n");

   char url[100];
   fgets(url, 100, stdin); // Get user input for URL
   
   while(1) // Infinite loop to check the website status periodically
   {
      printf("Checking website status...\n");
      int response = system(url); // Send a ping to website URL
      if(response == -1) {
         printf("Error: URL not found\n");
      } else if(response == 0) {
         printf("Website is up!\n");
      } else {
         printf("Website is down.\n");
      }
      sleep(60); // Wait 60 seconds before checking status again
   }
   return 0;
}