//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define Wi-Fi signal strength random range
#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 1

// Define paranoia threshold
#define PARANOIA_THRESHOLD 50

int main()
{
  // Variable initialization
  srand(time(NULL));
  int signal_strength = 0;
  int iterations = 0;
  int paranoid_iterations = 0;

  // Welcome message
  printf("Wi-Fi Signal Strength Analyzer\n\n");

  // Loop until user ends program
  while (1)
  {
    // Generate random signal strength
    signal_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;

    // Print signal strength
    printf("Signal Strength: %d\n", signal_strength);

    // Check if signal strength is below paranoia threshold
    if (signal_strength < PARANOIA_THRESHOLD)
    {
      // Increase paranoid iterations counter
      paranoid_iterations++;

      // Print paranoid message
      printf("ALERT: SIGNAL STRENGTH BELOW PARANOIA THRESHOLD!\n");

      // Wait a second before continuing
      sleep(1);
    }

    // Increase iterations counter
    iterations++;

    // Check if it's time to print the paranoia statistics
    if (iterations % 10 == 0)
    {
      // Print paranoia statistics
      printf("\n======= PARANOIA STATISTICS =======\n");
      printf("Total Iterations: %d\n", iterations);
      printf("Paranoid Iterations: %d\n", paranoid_iterations);
      printf("Paranoia Percentage: %.2f%%\n", (float)paranoid_iterations / iterations * 100);
      printf("===================================\n\n");
    }

    // Wait a second before generating next signal strength
    sleep(1);
  }

  // End program
  return 0;
}