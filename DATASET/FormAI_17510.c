//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 10
#define SIGNAL_SAMPLE_SIZE 10

int main() {

  // Seed random number generator
  srand(time(NULL));

  // Initialize array to hold signal strengths
  int signal_strengths[SIGNAL_SAMPLE_SIZE];

  // Populate array with random signal strengths
  for(int i = 0; i < SIGNAL_SAMPLE_SIZE; i++) {
    signal_strengths[i] = (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
  }

  // Calculate average signal strength
  int sum = 0;
  for(int i = 0; i < SIGNAL_SAMPLE_SIZE; i++) {
    sum += signal_strengths[i];
  }
  int average_signal_strength = sum / SIGNAL_SAMPLE_SIZE;

  // Print out signal strengths and average
  printf("Signal Strengths: ");
  for(int i = 0; i < SIGNAL_SAMPLE_SIZE; i++) {
    printf("%d ", signal_strengths[i]);
  }
  printf("\nAverage Signal Strength: %d\n", average_signal_strength);

  // Determine signal quality
  if(average_signal_strength >= 80) {
    printf("Excellent Signal Quality\n");
  } else if(average_signal_strength >= 60) {
    printf("Good Signal Quality\n");
  } else if(average_signal_strength >= 40) {
    printf("Fair Signal Quality\n");
  } else {
    printf("Poor Signal Quality\n");
  }

  return 0;
}