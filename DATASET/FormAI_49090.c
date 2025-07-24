//FormAI DATASET v1.0 Category: Digital signal processing ; Style: futuristic
#include <stdio.h>

int main() {
  int sample_rate = 48000; // define sample rate
  int num_samples = 1000; // define number of samples
  int frequency = 1000; // define frequency
  float theta = 2 * 3.14159265358979323846 * frequency / sample_rate; // calculate theta

  int i;
  float sine[num_samples];

  // generate sine wave
  for (i = 0; i < num_samples; i++) {
    sine[i] = sin(i * theta);
  }

  // apply low pass filter
  int coef_length = 10; // define filter coefficient length
  float coef[coef_length]; // define filter coefficient array
  for (i = 0; i < coef_length; i++) {
    if (i % 2 == 0) { // alternate coefficients between positive and negative
      coef[i] = 2.0 / (i * 3.14159265358979323846) * sin(i * 3.14159265358979323846 / 2.0);
    } else {
      coef[i] = 0;
    }
  }

  float filtered[num_samples]; // define filtered signal array

  for (i = 0; i < num_samples - coef_length; i++) {
    float sum = 0;
    int j;
    for (j = 0; j < coef_length; j++) {
      sum += sine[i+j] * coef[j];
    }
    filtered[i] = sum;
  }

  // print filtered signal values
  printf("Filtered Signal Values:\n");
  for (i = 0; i < num_samples - coef_length; i++) {
    printf("%f\n", filtered[i]);
  }

  return 0;
}