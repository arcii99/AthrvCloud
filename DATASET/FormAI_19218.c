//FormAI DATASET v1.0 Category: Digital signal processing ; Style: immersive
#include <stdio.h>
#include <math.h>

// Immersive style DSP example program
int main() {
   float pi = 3.1415926535;

   // Generate a 1 kHz sine wave signal
   int sample_rate = 44100;
   float frequency = 1000.0;
   float amplitude = 0.5;
   float rel_time = 0.0;
   int num_samples = 44100;
   float signal[num_samples];
   int i;
   for (i = 0; i < num_samples; i++) {
      rel_time = (float)i / (float)sample_rate;
      signal[i] = sin(2 * pi * frequency * rel_time) * amplitude;
   }

   // Apply a low-pass FIR filter with cutoff frequency of 500 Hz
   float cutoff_freq = 500.0;
   float cutoff_norm = cutoff_freq / (float)sample_rate;
   int filter_len = 51;
   float filter_coeff[filter_len];
   float norm_sum = 0.0;
   for (i = 0; i < filter_len; i++) {
      filter_coeff[i] = sin(2 * pi * cutoff_norm * (float)(i - (filter_len - 1) / 2)) / (pi * (float)(i - (filter_len - 1) / 2));
      norm_sum += filter_coeff[i];
   }
   for (i = 0; i < filter_len; i++) {
      filter_coeff[i] /= norm_sum;
   }
   float filtered_signal[num_samples];
   int j;
   for (i = 0; i < num_samples; i++) {
      filtered_signal[i] = 0.0;
      for (j = 0; j < filter_len; j++) {
         if (i - j < 0) {
            filtered_signal[i] += filter_coeff[j] * signal[0];
         } else {
            filtered_signal[i] += filter_coeff[j] * signal[i-j];
         }
      }
   }

   // Apply a decimation factor of 4
   int decimation_factor = 4;
   float decimated_signal[num_samples / decimation_factor];
   int k;
   for (i = 0, k = 0; i < num_samples / decimation_factor; i++, k += decimation_factor) {
      decimated_signal[i] = filtered_signal[k];
   }

   // Print the initial and processed signals for comparison
   printf("Initial signal:\n");
   for (i = 0; i < num_samples; i++) {
      printf("%.5f\n", signal[i]);
   }
   printf("\nFiltered and decimated signal:\n");
   for (i = 0; i < num_samples / decimation_factor; i++) {
      printf("%.5f\n", decimated_signal[i]);
   }

   return 0;
}