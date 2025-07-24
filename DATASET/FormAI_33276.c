//FormAI DATASET v1.0 Category: Audio processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 44100
#define PI 3.14159265358979323846

int main() {
  FILE* input_file = fopen("input.wav", "rb");
  fseek(input_file, 44, SEEK_SET); // skip header

  FILE* output_file = fopen("output.wav", "wb");
  char header[44];
  fread(header, 1, 44, input_file);
  fwrite(header, 1, 44, output_file);

  double amplitude = 1.0;
  double frequency = 440.0;
  double phase = 0.0;

  double c_major_scale[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};
  int note_index = 0;

  int i;
  for (i = 0; i < SAMPLING_RATE; i++) {
    double time = (double)i / SAMPLING_RATE;
    double sample = amplitude * sin(2.0 * PI * frequency * time + phase);

    // apply effect
    sample *= (1.0 - fabs(time - 0.5)) * 2.0;

    fwrite(&sample, sizeof(sample), 1, output_file);

    // change note every 0.5 seconds
    if (i % (SAMPLING_RATE / 2) == 0) {
      note_index = (note_index + 1) % 7;
      frequency = c_major_scale[note_index];
      amplitude = 1.0;
      phase = 0.0;
    }

    amplitude -= 1.0 / SAMPLING_RATE; // fade out
    phase += 2.0 * PI * frequency / SAMPLING_RATE; // phase shift
  }

  fclose(output_file);
  fclose(input_file);

  printf("Audio processing completed successfully.\n");

  return 0;
}