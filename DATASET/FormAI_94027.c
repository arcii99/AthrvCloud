//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>

int main() {
  // Title of program
  printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");

  // Variable declaration
  int signalStrength;

  // User input
  printf("Please enter the signal strength of the Wi-Fi connection (in dBm): ");
  scanf("%d", &signalStrength);

  // Signal strength analysis
  if(signalStrength < -70) {
    printf("Excellent signal strength!\n");
  } else if(signalStrength < -50) {
    printf("Good signal strength!\n");
  } else if(signalStrength < -30) {
    printf("Fair signal strength.\n");
  } else {
    printf("Poor signal strength. Please try moving closer to the router.\n");
  }

  // End of program
  printf("Thank you for using Wi-Fi Signal Strength Analyzer!\n");

  return 0;
}