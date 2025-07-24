//FormAI DATASET v1.0 Category: Audio processing ; Style: calm
/* A program that applies a low-pass filter to an audio file in order to decrease high-frequency noise and improve overall sound quality */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 44100 // number of samples per second
#define FREQ_CUTOFF 2000 // cutoff frequency for low-pass filter in Hz
#define FILTER_ORDER 5 // order of the butterworth filter

int main() {
  FILE *input_file; // pointer to the input audio file
  FILE *output_file; // pointer to the output audio file
  short input[NUM_SAMPLES]; // input audio samples
  short output[NUM_SAMPLES]; // output audio samples
  double b[FILTER_ORDER+1]; // forward coefficients of the butterworth filter
  double a[FILTER_ORDER+1]; // feedback coefficients of the butterworth filter
  double filter_freq = FREQ_CUTOFF / (0.5 * NUM_SAMPLES); // filter frequency normalized to the Nyquist rate
  double filter_scale = tan(M_PI * filter_freq); // scaling factor to convert frequency response to analog domain
  double x[FILTER_ORDER+1] = {0}; // input sample history
  double y[FILTER_ORDER+1] = {0}; // output sample history
  int i, j;
  
  // open the input and output audio files
  input_file = fopen("input.wav", "rb");
  output_file = fopen("output.wav", "wb");
  
  // calculate the butterworth filter coefficients
  for (i = 0; i <= FILTER_ORDER; i++) {
    b[i] = pow(filter_scale, FILTER_ORDER - i) * pow(-1, i); // forward coefficents
    a[i] = 0; // feedback coefficients initally set to zero
  }
  
  a[0] = b[0]; // set the feedback coefficient for y[0]
  for (i = 1; i <= FILTER_ORDER; i++) {
    for (j = i; j <= FILTER_ORDER; j++) {
      a[j] += b[i] * a[j-i]; // calculate the feedback coefficients recursively
    }
  }
  
  // process the audio samples using the butterworth filter
  while (fread(input, sizeof(short), NUM_SAMPLES, input_file) == NUM_SAMPLES) {
    for (i = 0; i < NUM_SAMPLES; i++) {
      x[0] = input[i] / 32767.0; // normalize input sample to range [-1, 1]
      y[0] = b[0] * x[0]; // apply forward filter coefficients to input sample
      
      for (j = 1; j <= FILTER_ORDER; j++) {
        y[0] += b[j] * x[j] - a[j] * y[j]; // apply forward and feedback coefficients to input and output history
      }
      
      // update input and output history
      for (j = FILTER_ORDER; j >= 1; j--) {
        x[j] = x[j-1];
        y[j] = y[j-1];
      }
      
      output[i] = y[0] * 32767.0; // denormalize output sample to range [-32767, 32767]
    }
    
    fwrite(output, sizeof(short), NUM_SAMPLES, output_file); // write filtered samples to output file
  }
  
  // close the input and output audio files
  fclose(input_file);
  fclose(output_file);
  
  return 0;
}