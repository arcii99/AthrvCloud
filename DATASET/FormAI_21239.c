//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
   int downloadSpeed, uploadSpeed;
   double totalTime;
   
   printf("Welcome to the Internet Speed Test Application!\n");
   printf("This application will test your internet speed. Please wait...\n\n");

   // Simulating the speed test
   srand(time(NULL));
   downloadSpeed = rand() % 100 + 1; // Generates a random download speed between 1 to 100 Mbps
   uploadSpeed = rand() % 50 + 1; // Generates a random upload speed between 1 to 50 Mbps
   totalTime = (double) rand() / RAND_MAX * 1.5 + 2; // Generates a random total time between 2 to 3.5 seconds
   
   printf("Speed Test Complete!\n");
   printf("Download Speed: %d Mbps\n", downloadSpeed);
   printf("Upload Speed: %d Mbps\n", uploadSpeed);
   printf("Total Time: %.2f seconds\n\n", totalTime);

   // Determining the internet speed category
   if (downloadSpeed >= 80 && uploadSpeed >= 40) 
   {
      printf("Category: High-speed internet\n");
      printf("Your internet speed is excellent!\n");
   } 
   else if (downloadSpeed >= 50 && uploadSpeed >= 20) 
   {
      printf("Category: Moderate-speed internet\n");
      printf("Your internet speed is good enough for most browsing and streaming!\n");
   } 
   else 
   {
      printf("Category: Low-speed internet\n");
      printf("Your internet speed may be too slow for some activities. Consider upgrading your internet plan.\n");
   }

   return 0;
}