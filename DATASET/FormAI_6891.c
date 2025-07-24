//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {

   int signal_strength[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   int sum, average, min_value, max_value, i;

   // Calculate Sum
   sum = 0;
   for(i = 0; i < 10; i++) {
      sum += signal_strength[i];
   }

   // Calculate Average
   average = sum / 10;
   
   // Calculate Min and Max
   min_value = signal_strength[0];
   max_value = signal_strength[0];
   for(i = 1; i < 10; i++) {
      if(signal_strength[i] < min_value) {
         min_value = signal_strength[i];
      }
      else if(signal_strength[i] > max_value) {
         max_value = signal_strength[i];
      }
   }
   
   // Display Results
   printf("C Wi-Fi Signal Strength Analyzer\n");
   printf("================================\n");
   printf("Signal Strength Values: ");
   for(i = 0; i < 10; i++) {
      printf("%d ", signal_strength[i]);
   }
   printf("\n");
   printf("Average Signal Strength: %d\n", average);
   printf("Minimum Signal Strength: %d\n", min_value);
   printf("Maximum Signal Strength: %d\n", max_value);

   return 0;
}