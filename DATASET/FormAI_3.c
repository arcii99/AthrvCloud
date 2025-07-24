//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int signal_strength;
  srand(time(0)); // set seed for randomization

  printf("Welcome to the Wi-Fi Signal Strength Analyzer\n");
  printf("Scanning for Wi-Fi signals...\n\n");

  // simulate scanning for signals
  for (int i = 0; i < 10; i++) {
    printf("Scanning...\n");
    signal_strength = rand() % 101; // generate random signal strength from 0 to 100
    printf("Signal strength: %d%%\n", signal_strength);
    if (signal_strength >= 70) {
      printf("Signal strength is strong.\n");
    } else if (signal_strength >= 40) {
      printf("Signal strength is moderate.\n");
    } else {
      printf("Signal strength is weak.\n");
    }
    printf("\n");
  }

  printf("Analysis complete.\n");

  return 0;
}