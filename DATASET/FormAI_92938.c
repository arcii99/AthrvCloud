//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate random signal strength
int generateSignal() {
  return (rand() % 101);
}

// Function to check if the signal is strong enough
bool isSignalStrong(int signalStrength) {
  return signalStrength >= 50;
}

// Function to print out the signal strength bar
void printSignalBar(int signalStrength) {
  for (int i = 0; i < signalStrength / 10; i++) {
    printf("|");
  }
  printf("\n");
}

int main() {
  srand(time(NULL));  // Seed the random number generator
  
  int signalStrength = generateSignal();
  printf("Wi-Fi Signal Strength Analyzer\n\n");
  printf("Signal Strength: %d%%\n", signalStrength);
  printSignalBar(signalStrength);
  
  if (isSignalStrong(signalStrength)) {
    printf("Signal strength is good. You can browse the internet.\n");
  } else {
    printf("Signal strength is too weak. Please try again later.\n");
  }
  
  return 0;
}