//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
/* The Adventure of the Digital Signal Processing */
#include <stdio.h>

int main() {
   int signal_array[] = {5, -10, 15, -20, 25, -30, 35, -40};
   int num_samples = sizeof(signal_array)/sizeof(int);
   int i;

   printf("The original signal:\n");
   for(i = 0; i < num_samples; i++) {
      printf("%d ", signal_array[i]);
   }
   printf("\n");

   // Remove the DC offset
   int dc_offset = signal_array[0];
   for(i = 0; i < num_samples; i++) {
      signal_array[i] -= dc_offset;
   }
   printf("Signal with DC offset removed:\n");
   for(i = 0; i < num_samples; i++) {
      printf("%d ", signal_array[i]);
   }
   printf("\n");

   // Apply a low-pass filter
   for(i = 1; i < num_samples; i++) {
      signal_array[i] = (signal_array[i-1] + signal_array[i]) / 2;
   }
   printf("Signal after low-pass filter:\n");
   for(i = 0; i < num_samples; i++) {
      printf("%d ", signal_array[i]);
   }
   printf("\n");

   // Apply a high-pass filter
   for(i = 1; i < num_samples; i++) {
      signal_array[i] = signal_array[i] - signal_array[i-1];
   }
   printf("Signal after high-pass filter:\n");
   for(i = 0; i < num_samples; i++) {
      printf("%d ", signal_array[i]);
   }
   printf("\n");

   // Apply an amplification factor
   int amp_factor = 2;
   for(i = 0; i < num_samples; i++) {
      signal_array[i] *= amp_factor;
   }
   printf("Signal after amplification:\n");
   for(i = 0; i < num_samples; i++) {
      printf("%d ", signal_array[i]);
   }
   printf("\n");

   return 0;
}