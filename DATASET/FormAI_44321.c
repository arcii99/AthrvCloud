//FormAI DATASET v1.0 Category: Digital signal processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {

   //define the input signal as an array
   int signal[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   
   //define the filter coefficients as an array
   double filter[5] = {0.1, 0.2, 0.3, 0.2, 0.1};
   
   //define variables for the signal length and filter length
   int signal_length = sizeof(signal)/sizeof(int);
   int filter_length = sizeof(filter)/sizeof(double);
   
   //define variables for the temporary sum and the output signal
   double temp_sum;
   double output[signal_length - filter_length + 1];
   
   //loop through the signal and apply the filter
   for (int i = 0; i <= signal_length - filter_length; i++) {
      temp_sum = 0;
      for (int j = 0; j < filter_length; j++) {
         temp_sum += signal[i+j] * filter[j];
      }
      output[i] = temp_sum;
   }
   
   //output the original signal and the filtered signal
   printf("Original Signal: ");
   for (int i = 0; i < signal_length; i++) {
      printf("%d ", signal[i]);
   }
   printf("\n");
   
   printf("Filtered Signal: ");
   for (int i = 0; i < sizeof(output)/sizeof(double); i++) {
      printf("%.2f ", output[i]);
   }
   printf("\n");

   return 0;
}