//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));              // seeding random number generator
  int signal_strength = -100;     // initial signal strength
  int num_readings = 5;           // number of signal strength readings
  
  printf("Wi-Fi Signal Strength Analyzer\n\n");
  
  for (int i = 0; i < num_readings; i++) {
    // simulate receiving a new signal strength reading
    int new_reading = signal_strength + rand() % 21 - 10;  // random number between -10 and 10
    if (new_reading > 0) {
      signal_strength = new_reading;    // update signal strength if new reading is positive
    }
    printf("Reading %d: Signal Strength = %d dBm\n", i+1, signal_strength);
  }
  
  printf("\nAnalysis:");
  if (signal_strength > -70) {
    printf("\n  Strong Signal");
  } else if (signal_strength > -80) {
    printf("\n  Decent Signal");
  } else if (signal_strength > -90) {
    printf("\n  Weak Signal");
  } else {
    printf("\n  Poor Signal");
  }
  
  return 0;
}