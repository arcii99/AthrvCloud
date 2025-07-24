//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   int download_speed, upload_speed;
   int min_download_speed = 10; //minimum download speed
   int max_download_speed = 100; //maximum download speed
   int min_upload_speed = 5; //minimum upload speed
   int max_upload_speed = 50; //maximum upload speed

   srand(time(NULL)); //seed the random number generator with time

   //generate random download and upload speeds within the given range
   download_speed = (rand() % (max_download_speed - min_download_speed + 1)) + min_download_speed;
   upload_speed = (rand() % (max_upload_speed - min_upload_speed + 1)) + min_upload_speed;

   printf("Welcome to the Internet Speed Test Application!\n\n");
   printf("Testing your internet connection...\n\n");
   printf("Your download speed is %d Mbps.\n", download_speed);
   printf("Your upload speed is %d Mbps.\n\n", upload_speed);

   //determine internet connection quality based on download and upload speeds
   if (download_speed >= 50 && upload_speed >= 25) {
      printf("Your internet connection is excellent!\n");
   } else if (download_speed >= 25 && upload_speed >= 10) {
      printf("Your internet connection is good.\n");
   } else if (download_speed >= 10 && upload_speed >= 5) {
      printf("Your internet connection is average.\n");
   } else {
      printf("Your internet connection is poor.\n");
   }

   printf("\nThank you for using our Internet Speed Test Application!\n");

   return 0;
}