//FormAI DATASET v1.0 Category: Digital signal processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
   int len, i, j;
   printf("Enter the length of the input signal: ");
   scanf("%d", &len);

   int signals[len], output[len];
   printf("Enter the signal values: ");
   for(i = 0; i < len; i++) {
      scanf("%d", &signals[i]);
   }

   for(i = 0; i < len; i++) {
      output[i] = 0;
      for(j = 0; j <= i; j++) {
         output[i] += signals[j];
      }
   }

   printf("The input signal was: ");
   for(i = 0; i < len; i++) {
      printf("%d ", signals[i]);
   }

   printf("\nThe output signal is: ");
   for(i = 0; i < len; i++) {
      printf("%d ", output[i]);
   }

   printf("\n");
   return 0;
}