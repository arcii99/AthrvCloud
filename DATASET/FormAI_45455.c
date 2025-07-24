//FormAI DATASET v1.0 Category: Digital signal processing ; Style: inquisitive
#include <stdio.h>
#define N 20

int main() {
   int signal[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
   int i, j, k, sum, average;

   // Print the original signal
   printf("Original Signal: ");
   for (i = 0; i < N; i++) {
      printf("%d ", signal[i]);
   }
   printf("\n");

   // Moving average filter
   int filtered_signal[N];
   for (i = 0; i < N; i++) {
      sum = 0;
      k = 0;
      for (j = i-4; j <= i; j++) {
         if (j >= 0) {
            sum += signal[j];
            k++;
         }
      }
      filtered_signal[i] = sum / k;
   }

   // Print the filtered signal
   printf("Filtered Signal: ");
   for (i = 0; i < N; i++) {
      printf("%d ", filtered_signal[i]);
   }
   printf("\n");

   return 0;
}