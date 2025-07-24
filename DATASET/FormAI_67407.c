//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Declaring variables
  int signal_strength, i;
  srand(time(0));
  
  // Generating a random signal strength between -100 to 0 dbm
  signal_strength = rand() % 101 - 100;

  // Analyzing the signal strength and displaying the appropriate message
  if(signal_strength >= -30) {
    printf("Signal strength: %d dBm\n", signal_strength);
    printf("You are in an excellent signal strength zone!\n");
  }
  else if(signal_strength >= -67) {
    printf("Signal strength: %d dBm\n", signal_strength);
    printf("You are in a good signal strength zone.\n");
  }
  else if(signal_strength >= -70) {
    printf("Signal strength: %d dBm\n", signal_strength);
    printf("You are in a fair signal strength zone.\n");
  }
  else if(signal_strength >= -80) {
    printf("Signal strength: %d dBm\n", signal_strength);
    printf("You are in a poor signal strength zone.\n");
  }
  else {
    printf("Signal strength: %d dBm\n", signal_strength);
    printf("You are in a very poor signal strength zone. Please move to a different location.\n");
  }

  return 0;
}