//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   // Initialize random number generator
   srand(time(0));

   // Generate download speed between 1 and 100 Mbps
   int download_speed = (rand() % 100) + 1;

   // Generate upload speed between 1 and 50 Mbps
   int upload_speed = (rand() % 50) + 1;

   printf("Welcome to the Internet Speed Test!\n\n");
   printf("Testing download speed... %d Mbps\n", download_speed);
   printf("Testing upload speed... %d Mbps\n\n", upload_speed);

   // Determine internet speed quality based on download speed
   if (download_speed >= 75)
   {
      printf("Wow, you have an excellent internet connection!\n");
   }
   else if (download_speed >= 50 && download_speed < 75)
   {
      printf("Your internet connection is good, but could be faster.\n");
   }
   else if (download_speed >= 25 && download_speed < 50)
   {
      printf("Your internet connection is average.\n");
   }
   else
   {
      printf("Your internet connection is slow.\n");
   }

   return 0;
}