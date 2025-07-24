//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int speed, rand_num;

   printf("Welcome to the C Internet Speed Test\n");
   printf("Press Enter to start the test.\n");
   getchar();

   // generate random number from 10-100 to simulate internet speed
   srand(time(NULL)); // seed the random number generator
   rand_num = rand() % 91 + 10; // generate random number between 10 - 100
   printf("Testing your internet speed...\n");
   printf("Your internet speed is %d Mbps.\n", rand_num);

   // determine the quality of the internet speed
   if (rand_num < 20) {
      printf("Your internet speed is extremely slow. Please contact your internet service provider.\n");
   }
   else if (rand_num < 50) {
      printf("Your internet speed is slow. Consider upgrading your internet package.\n");
   }
   else if (rand_num < 80) {
      printf("Your internet speed is good. You can consider streaming HD videos.\n");
   }
   else {
      printf("Your internet speed is excellent. You can enjoy HD streaming with ease.\n");
   }

   return 0;
}