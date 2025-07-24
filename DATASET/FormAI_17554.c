//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>

// function to determine signal strength
void signalStrength(int dbm) {
  if (dbm >= -50) {
    printf("Signal strength: Excellent\n");
  } else if (dbm >= -60) {
    printf("Signal strength: Good\n");
  } else if (dbm >= -70) {
    printf("Signal strength: Fair\n");
  } else if (dbm >= -80) {
    printf("Signal strength: Poor\n");
  } else {
    printf("Signal strength: Very Poor\n");
  }
}

int main() {
  // array to store strength values
  int strength[5] = {-65, -80, -40, -75, -85};

  printf("Wi-Fi signal strengths:\n");

  // loop through array and call signal strength function
  for (int i = 0; i < 5; i++) {
    printf("%d dBm, ", strength[i]);
    signalStrength(strength[i]);
  }

  return 0;
}