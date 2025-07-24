//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: thoughtful
#include <stdio.h>

#define MAX_SSID_LENGTH 32

// Function to calculate RSSI values
int calculateRSSI(int signalStrength) {
  int rssi = 0; // dBm
  if (signalStrength == 0) {
    rssi = -100;
  } else {
    rssi = (int)(10 * log10(signalStrength) - 46.0);
  }
  return rssi;
}

// Function to print the Wi-Fi networks and their RSSI values
void printNetworks(char **SSIDs, int numNetworks, int *signalStrengths) {
  printf("Wi-Fi Networks:\n");
  for (int i = 0; i < numNetworks; i++) {
    printf("%s: %d dBm\n", SSIDs[i], calculateRSSI(signalStrengths[i]));
  }
  printf("\n");
}

int main() {
  int numNetworks = 4;
  char *SSIDs[numNetworks];
  int signalStrengths[numNetworks];

  // Initialization of SSID and signal strength values
  SSIDs[0] = "Network1";
  signalStrengths[0] = -60;
  SSIDs[1] = "Network2";
  signalStrengths[1] = -75;
  SSIDs[2] = "Network3";
  signalStrengths[2] = -80;
  SSIDs[3] = "Network4";
  signalStrengths[3] = -90;

  // Print the Wi-Fi networks and their RSSI values
  printNetworks(SSIDs, numNetworks, signalStrengths);

  return 0;
}