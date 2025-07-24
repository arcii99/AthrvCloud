//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>

#define SAMPLE_RATE 44100

//function to generate a sine wave at frequency f for duration t
void generateSineWave(float f, int t) {
  int i;
  float sample = 0;
  float increment = f * 2 * 3.14159265359 / SAMPLE_RATE;
  
  for(i = 0; i < t * SAMPLE_RATE; i++) {
    sample = sin(i * increment);
    printf("%f ", sample);
  }
}

int main() {
  float frequency;
  int duration;

  printf("Please enter the frequency (Hz) of the sine wave: ");
  scanf("%f", &frequency);

  printf("Please enter the duration (seconds) of the sine wave: ");
  scanf("%d", &duration);

  printf("Generating sine wave...\n");

  //call function to generate sine wave
  generateSineWave(frequency, duration);

  printf("\nSine wave generated successfully.");

  return 0;
}