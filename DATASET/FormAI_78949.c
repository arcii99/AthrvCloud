//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // Initializing variables to hold signal strength and network name
  int signal_strength = 0;
  char network_name[20];

  // Prompting user to enter the name of the network and signal strength
  printf("Please enter the name of the network: ");
  scanf("%s", network_name);

  printf("Please enter the signal strength for %s: ", network_name);
  scanf("%d", &signal_strength);

  // Checking if signal strength is within normal range
  if(signal_strength >= -50 && signal_strength < 0) {
    printf("Signal strength for %s is EXCELLENT!\n", network_name);
  } else if(signal_strength >= -70 && signal_strength < -50) {
    printf("Signal strength for %s is GOOD.\n", network_name);
  } else if(signal_strength >= -80 && signal_strength < -70) {
    printf("Signal strength for %s is FAIR.\n", network_name);
  } else if(signal_strength >= -100 && signal_strength < -80) {
    printf("Signal strength for %s is POOR.\n", network_name);
  } else {
    printf("Invalid signal strength for %s.\n", network_name);
  }

  return 0;
}