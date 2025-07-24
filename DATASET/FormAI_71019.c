//FormAI DATASET v1.0 Category: Audio processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512
#define PI 3.14159265358979323846

double lfo_frequency = 2.0;
double lfo_amplitude = 0.25;
double lfo_phase = 0.0;

double oscillator_frequency = 440.0;
double oscillator_amplitude = 0.5;
double oscillator_phase = 0.0;

int main() {
  double buffer[BUFFER_SIZE];
  double lfo_increment = (lfo_frequency / SAMPLE_RATE) * 2 * PI;
  double oscillator_increment = (oscillator_frequency / SAMPLE_RATE) * 2 * PI;

  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < BUFFER_SIZE; j++) {
      double lfo_sample = sin(lfo_phase) * lfo_amplitude;
      lfo_phase += lfo_increment;
      if (lfo_phase >= 2 * PI) {
        lfo_phase -= 2 * PI;
      }

      double oscillator_sample = sin(oscillator_phase) * oscillator_amplitude;
      oscillator_phase += oscillator_increment;
      if (oscillator_phase >= 2 * PI) {
        oscillator_phase -= 2 * PI;
      }

      buffer[j] = lfo_sample * oscillator_sample;
    }
    fwrite(buffer, sizeof(double), BUFFER_SIZE, stdout);
  }

  return 0;
}