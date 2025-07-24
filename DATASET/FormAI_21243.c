//FormAI DATASET v1.0 Category: Audio processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define MAX_SAMPLES 441000

typedef struct {
   short left;
   short right;
} Sample;

Sample buffer[MAX_SAMPLES];

void process_audio_data(Sample *samples, int num_samples) {
   // Your audio processing code here
   for (int i = 0; i < num_samples; i++) {
      // Process left and right channels independently
      samples[i].left *= 0.5;
      samples[i].right *= 0.5;
   }
}

int main(void) {
   // Generate a sine wave for testing
   double frequency = 440;
   double amplitude = 32767 * 0.5;
   double phase = 0;

   for (int i = 0; i < MAX_SAMPLES; i++) {
      double time = (double) i / SAMPLE_RATE;
      double sample = amplitude * sin(2 * M_PI * frequency * time + phase);
      buffer[i].left = sample;
      buffer[i].right = sample;
   }

   // Process the audio data
   process_audio_data(buffer, MAX_SAMPLES);

   // Write the output to a WAV file
   FILE *file = fopen("output.wav", "wb");
   int num_samples_written = fwrite(buffer, sizeof(Sample), MAX_SAMPLES, file);
   fclose(file);

   printf("Processed %d samples.\n", num_samples_written);

   return 0;
}