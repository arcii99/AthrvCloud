//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // seed the random number generator with current time
   int download_speed = rand() % 101; // generate a random download speed between 0 and 100
   int upload_speed = rand() % 101; // generate a random upload speed between 0 and 100
   
   printf("Welcome to the Internet Speed Test!\n");
   printf("Calculating your download and upload speeds...\n");
   // simulate a loading bar to make it more interactive and engaging
   for (int i = 0; i <= 20; i++) {
      printf("[");
      for (int j = 0; j < i; j++) {
         printf("=");
      }
      for (int k = i; k < 20; k++) {
         printf(" ");
      }
      printf("] %d%%\r", i*5);
      fflush(stdout);
      // delay the program for a short period of time to make it more realistic
      struct timespec delay;
      delay.tv_sec = 0;
      delay.tv_nsec = 250000000; // 0.25 second
      nanosleep(&delay, NULL);
   }
   printf("\n");
   // display the results to the user
   printf("Download speed: %d Mbps\n", download_speed);
   printf("Upload speed: %d Mbps\n", upload_speed);
   // provide a recommendation based on the download speed
   if (download_speed >= 50) {
      printf("Congratulations! Your download speed is excellent.\n");
   } else if (download_speed >= 25) {
      printf("Your download speed is good.\n");
   } else {
      printf("Your download speed is poor. Consider upgrading your internet plan.\n");
   }
   // thank the user for using the application
   printf("Thank you for using the Internet Speed Test! Goodbye.\n");
   return 0;
}