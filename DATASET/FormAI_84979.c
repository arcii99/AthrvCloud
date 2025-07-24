//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
   printf("Welcome to the Surrealist Website Uptime Monitor!\n");
   printf("Enter the website URL: ");
   char website[50];
   scanf("%s", website);
   printf("\n");
   printf("Checking for uptime status of website: %s\n", website);
   printf("Please wait while we connect you to the surrealist network...\n");
   printf("\n");
   float random_num = rand() % 100;
   bool is_online = random_num > 50 ? true : false;
   if (is_online) {
      printf("Status: The website is currently online! (This may or may not be a dream...)\n");
   } else {
      printf("Status: The website is currently offline, as all digital entities are in the land of the surreal...\n");
   }
   return 0;
}