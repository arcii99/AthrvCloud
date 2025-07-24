//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRENGTH 100
#define MIN_STRENGTH 0

int main() {
  int signal_strength = 0;

  while(1) {
    printf("Please enter the current Wi-Fi signal strength (0-100): ");
    scanf("%d", &signal_strength);

    if(signal_strength < MIN_STRENGTH || signal_strength > MAX_STRENGTH) {
      printf("Invalid signal strength. Please try again.\n");
    } else {
      break;
    }
  }

  printf("Analyzing signal strength...\n");
  
  if(signal_strength >= 80) {
    printf("Signal strength is excellent!\n");
  } else if(signal_strength >= 60) {
    printf("Signal strength is good.\n");
  } else if(signal_strength >= 40) {
    printf("Signal strength is fair.\n");
  } else if(signal_strength >= 20) {
    printf("Signal strength is poor.\n");
  } else {
    printf("Signal strength is very poor.\n");
  }

  return 0;
}