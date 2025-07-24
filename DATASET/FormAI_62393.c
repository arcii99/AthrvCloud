//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main() {

  //create a sine wave with amplitude, frequency and phase shift
  double amplitude = 1.0;
  double frequency = 100.0;
  double phase_shift = PI/4.0;

  double sample_rate = 44100.0;
  double duration = 1.0;

  //create an array of samples for the sine wave
  int num_samples = (int)(duration * sample_rate);
  double *samples = (double*) malloc(sizeof(double) * num_samples);

  for(int i=0; i<num_samples; i++) {
     double t = i/sample_rate;
     samples[i] = amplitude * sin(2*PI*frequency*t + phase_shift);
  }

  //apply a lowpass filter to the sine wave 
  double cutoff_frequency = 500.0;
  double resonance = 0.5;

  double pi_over_sr = PI/sample_rate;
  double alpha = sin(pi_over_sr*cutoff_frequency)/(2.0*resonance);

  double b0 = (1.0 - cos(pi_over_sr*cutoff_frequency))/2.0;
  double b1 = 1.0 - cos(pi_over_sr*cutoff_frequency);
  double b2 = (1.0 - cos(pi_over_sr*cutoff_frequency))/2.0;
  double a1 = -2.0*cos(pi_over_sr*cutoff_frequency)*(1.0 - alpha);
  double a2 = (1.0 - alpha)*(1.0 - alpha);

  double yn1 = 0.0;
  double yn2 = 0.0;
  double xn1 = 0.0;
  double xn2 = 0.0;

  for(int i=0; i<num_samples; i++) {
    double yn = (b0/samples[i]) + (b1/samples[i-1]) + (b2/samples[i-2]) - (a1/yn1) - (a2/yn2);
    yn2 = yn1;
    yn1 = yn;
    xn2 = xn1;
    xn1 = samples[i];
    samples[i] = yn;
  }

  //write the filtered waveform to a file
  FILE *output_file = fopen("output.wav", "wb");
  fwrite(samples, sizeof(double), num_samples, output_file);
  fclose(output_file);

  free(samples);

  return 0;
}