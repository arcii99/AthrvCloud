//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
   // Initializing the Seed for Random Number Generation
   srand(time(NULL));
   
   // Alien Arrival Probability (Assuming 30 Days in a Month)
   float arrivalProb = (float)rand() / (float)RAND_MAX;
   
   // Alien Invasion Probability calculation (based on Arrival Probability)
   float invasionProb = arrivalProb * 0.8;
   
   // Displaying the Results
   printf("Based on current calculations, the probability of alien invasion is %.2f%%.", invasionProb * 100 );
   
   // Checking if the Invasion Probability is High or Low
   if(invasionProb > 0.5) {
      printf("\nAlien invasion is highly probable. Please take necessary precautions.");   
   } else {
      printf("\nAlien invasion is relatively low. However, it never hurts to be prepared.");   
   }
   
   return 0;
}