//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   srand(time(NULL)); // seed for random number generator

   int download_speed = rand() % 200; // generate a random download speed between 0 and 200 Mbps
   int upload_speed = rand() % 100; // generate a random upload speed between 0 and 100 Mbps

   printf("Welcome to the Internet Speed Test!\n");
   printf("Your download speed is %d Mbps\n", download_speed);
   printf("Your upload speed is %d Mbps\n", upload_speed);

   if (download_speed >= 100) {
      printf("Congratulations! Your download speed is excellent!\n");
   } 
   else if (download_speed >= 50) {
      printf("Your download speed is good, but could be faster.\n");
   }
   else {
      printf("Sorry, your download speed is not great. Please contact your Internet Service Provider.\n");
   }

   if (upload_speed >= 50) {
      printf("Your upload speed is good!\n");
   }
   else {
      printf("Sorry, your upload speed could be faster. Please contact your ISP.\n");
   }

   return 0;
}