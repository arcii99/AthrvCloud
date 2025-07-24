//FormAI DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 2048

#define PI 3.14159265358979323846

int main() {
   float frequency = 440; // initialize frequency to 440 Hz (A4)
   float phase = 0;
   float amplitude = 0.5;
   
   float buffer[BUFFER_SIZE];
   int i;

   for (i = 0; i < BUFFER_SIZE; i++) {
      buffer[i] = amplitude * sin(2 * PI * frequency * (float)i / (float)SAMPLE_RATE + phase);
   }

   // write the buffer to a WAV file
   FILE *wav_file = fopen("output.wav", "wb");
   fwrite(&buffer, sizeof(buffer), 1, wav_file);
   fclose(wav_file);

   printf("WAV file written successfully.\n");

   return 0;
}