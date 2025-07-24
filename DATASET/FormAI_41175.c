//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 1000
#define BIT_DEPTH 16
#define AMPLITUDE ((1 << (BIT_DEPTH - 1)) - 1)

double paranoid_filter(double x) {
  static double y1 = 0;
  static double y2 = 0;
  static double x1 = 0;
  static double x2 = 0;
  static double a1 = 0.01;
  static double a2 = 0.01;

  // Paranoid filter coefficients
  const double b0 = 0.2;
  const double b1 = 0.7;
  const double b2 = 0.15;

  // Calculate output
  double y = b0 * x + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;

  // Save state for next iteration
  x2 = x1;
  x1 = x;
  y2 = y1;
  y1 = y;

  return y;
}

int main() {
  // Generate sinusoid signal
  double frequency_rad = 2 * M_PI * FREQUENCY / SAMPLE_RATE;
  double phase = 0;
  double signal_1[SAMPLE_RATE];
  double signal_2[SAMPLE_RATE];
  for (int i = 0; i < SAMPLE_RATE; i++) {
    signal_1[i] = AMPLITUDE * sin(phase);
    signal_2[i] = AMPLITUDE * sin(phase + M_PI / 2);
    phase += frequency_rad;
    if (phase > 2 * M_PI) {
      phase -= 2 * M_PI;
    }
  }

  // Apply paranoid filter to signal
  double output_1[SAMPLE_RATE];
  double output_2[SAMPLE_RATE];
  for (int i = 0; i < SAMPLE_RATE; i++) {
    output_1[i] = paranoid_filter(signal_1[i]);
    output_2[i] = paranoid_filter(signal_2[i]);
  }

  // Write output to file
  FILE* fp = fopen("paranoid_output.pcm", "wb");
  for (int i = 0; i < SAMPLE_RATE; i++) {
    int16_t sample_1 = (int16_t)output_1[i];
    int16_t sample_2 = (int16_t)output_2[i];
    fwrite(&sample_1, sizeof(sample_1), 1, fp);
    fwrite(&sample_2, sizeof(sample_2), 1, fp);
  }
  fclose(fp);

  return 0;
}