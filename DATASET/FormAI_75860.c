//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ephemeral
#include <stdio.h> 

int main() { 
   
   int signal[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
   int i, j, k;
   
   printf("Original Signal: ");
   
   for(i = 0; i < 10; i++) {
      printf("%d ", signal[i]);
   }
   
   //Low Pass Filter
   int coefficients1[3] = {-1, 2, -1};
   int output1[10] = {0};
   
   for(i = 1; i < 9; i++) {
      output1[i] = (coefficients1[0] * signal[i-1]) + (coefficients1[1] * signal[i]) + (coefficients1[2] * signal[i+1]);
   }
   
   printf("\nFiltered Signal (Low Pass Filter): ");
   
   for(i = 0; i < 10; i++) {
      printf("%d ", output1[i]);
   }
   
   //High Pass Filter
   int coefficients2[3] = {-1, -2, 1};
   int output2[10] = {0};
   
   for(i = 1; i < 9; i++) {
      output2[i] = (coefficients2[0] * signal[i-1]) + (coefficients2[1] * signal[i]) + (coefficients2[2] * signal[i+1]);
   }
   
   printf("\nFiltered Signal (High Pass Filter): ");
   
   for(i = 0; i < 10; i++) {
      printf("%d ", output2[i]);
   }
   
   //Sample and Hold
   int output3[10] = {0};
   
   for(i = 0; i < 10; i++) {
      for(j = 0; j < 10; j++) {
         output3[i] = signal[j];
      }
   }
   
   printf("\nSampled Signal (Sample and Hold): ");
   
   for(i = 0; i < 10; i++) {
      printf("%d ", output3[i]);
   }
   
   //Decimation
   int output4[5] = {0};
   k = 0;
   
   for(i = 0; i < 10; i = i + 2) {
      output4[k] = signal[i];
      k++;
   }
   
   printf("\nDecimated Signal: ");
   
   for(i = 0; i < 5; i++) {
      printf("%d ", output4[i]);
   }
   
   return 0; 
}