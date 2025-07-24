//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(0));
   
   // Generate random signal strengths
   int signals[10];
   for (int i = 0; i < 10; i++) {
      signals[i] = rand() % 101;
   }
   
   // Print out the signal strengths
   printf("Wi-Fi Signal Strength\n");
   printf("---------------------\n");
   for (int i = 0; i < 10; i++) {
      printf("Signal %d: %d%%\n", i+1, signals[i]);
   }
   printf("\n");
   
   // Determine the average signal strength
   int sum = 0;
   for (int i = 0; i < 10; i++) {
      sum += signals[i];
   }
   int average = sum / 10;
   
   // Determine the percentage of strong signals
   int strongCount = 0;
   for (int i = 0; i < 10; i++) {
      if (signals[i] >= 70) {
         strongCount++;
      }
   }
   int strongPercent = (strongCount * 100) / 10;
   
   // Determine the percentage of weak signals
   int weakCount = 0;
   for (int i = 0; i < 10; i++) {
      if (signals[i] < 30) {
         weakCount++;
      }
   }
   int weakPercent = (weakCount * 100) / 10;
   
   // Print out the summary
   printf("Summary\n");
   printf("-------\n");
   printf("Average Signal Strength: %d%%\n", average);
   printf("Percentage of Strong Signals: %d%%\n", strongPercent);
   printf("Percentage of Weak Signals: %d%%\n", weakPercent);
   
   return 0;
}