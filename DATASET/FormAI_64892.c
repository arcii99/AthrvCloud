//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate Wi-Fi signal strength */
int calculateSignalStrength(int signalStrength) {
  if(signalStrength >= -50) {
    printf("Perfect signal strength\n");
  } else if(signalStrength >= -60) {
    printf("Good signal strength\n");
  } else if(signalStrength >= -70) {
    printf("Fair signal strength\n");
  } else if(signalStrength >= -80) {
    printf("Poor signal strength\n");
  } else {
    printf("No signal\n");
  }
  return 0;
}

int main() {
  /* Sample data */
  int signals[5] = {-45, -60, -75, -83, -95};
  int i;

  /* Loop through sample data and display signal strengths */
  for(i = 0; i < 5; i++) {
    printf("Signal strength for signal %d: ", i+1);
    calculateSignalStrength(signals[i]);
  }

  return 0;
}