//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
   int strength = 0;
   printf("Starting Wi-Fi Analyzer...\n\n");

   srand(time(NULL)); // seed random number generator

   for (int i = 0; i < 10; i++) {
       strength = rand() % 100; // generate a random number between 0-99 for signal strength
       printf("Signal strength: %d%%\n", strength);

       if (strength >= 80) {
           printf("Signal strength is excellent!\n\n");
       } else if (strength >= 60) {
           printf("Signal strength is good.\n\n");
       } else if (strength >= 40) {
           printf("Signal strength is fair.\n\n");
       } else {
           printf("Signal strength is poor.\n\n");
       }

       sleep(1); // wait for 1 second before generating the next signal strength
   }

   printf("Wi-Fi Analyzer has finished analyzing the Wi-Fi signals.\n");

   return 0;
}