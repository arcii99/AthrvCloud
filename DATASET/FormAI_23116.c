//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0

int main() {
  int signal_strength = 0;
  
  // get the signal strength from the user
  printf("Please enter the Wi-Fi signal strength (between 0 and 100): ");
  scanf("%d", &signal_strength);
  
  // check if the signal is within range
  if (signal_strength < MIN_SIGNAL || signal_strength > MAX_SIGNAL) {
    printf("Invalid signal strength value. Please enter a number between 0 and 100.\n");
    return 1;
  }
  
  // analyze the signal strength
  if (signal_strength >= 80) {
    printf("The Wi-Fi signal is very strong!\n");
  } else if (signal_strength >= 60) {
    printf("The Wi-Fi signal is strong.\n");
  } else if (signal_strength >= 40) {
    printf("The Wi-Fi signal is moderate.\n");
  } else {
    printf("The Wi-Fi signal is weak.\n");
  }
  
  return 0;
}