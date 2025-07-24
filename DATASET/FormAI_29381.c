//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the signal strength based on the RSSI value
double calculateSignalStrength(int rssi) {
  double value = ((double)abs(rssi) - 59) / (10 * 2.0);
  double signalStrength = pow(10, value);
  return signalStrength;
}

int main() {
  int signalStrengths[] = {-20, -50, -70, -80, -90};
  int numStrengths = sizeof(signalStrengths) / sizeof(int);

  // Shape shifting starts
  printf("Welcome to the Wi-Fi Signal Strength Analyzer\n");
  printf("Enter the RSSI value for the Wi-Fi network you want to analyze: ");
  int rssi;
  scanf("%d", &rssi);

  // Check if the RSSI value is within range
  if (rssi >= -20) {
    printf("Wow, you're basically standing on the router!\n");
  } else if (rssi >= -50) {
    printf("Excellent signal strength!\n");
  } else if (rssi >= -70) {
    printf("Good signal strength\n");
  } else if (rssi >= -80) {
    printf("Decent signal strength\n");
  } else if (rssi >= -90) {
    printf("Poor signal strength\n");
  } else {
    printf("No signal detected\n");
  }

  // Calculate the signal strength in percentage and display the result
  double signalStrength = calculateSignalStrength(rssi);
  int signalPercent = (int)(signalStrength * 100);
  printf("Signal strength as percentage: %d%%\n", signalPercent);

  // Determine the closest signal strength from our list
  int closestStrength = signalStrengths[0];
  int smallestDifference = abs(signalStrength - closestStrength);
  for (int i = 1; i < numStrengths; i++) {
    int difference = abs(signalStrength - signalStrengths[i]);
    if (difference < smallestDifference) {
      closestStrength = signalStrengths[i];
      smallestDifference = difference;
    }
  }

  // Shape shifting continues
  if (closestStrength >= -20) {
    printf("The Wi-Fi signal strength is almost perfect!\n");
  } else if (closestStrength >= -50) {
    printf("The Wi-Fi signal strength is excellent!\n");
  } else if (closestStrength >= -70) {
    printf("The Wi-Fi signal strength is good\n");
  } else if (closestStrength >= -80) {
    printf("The Wi-Fi signal strength is decent\n");
  } else if (closestStrength >= -90) {
    printf("The Wi-Fi signal strength is poor\n");
  } else {
    printf("No signal detected\n");
  }

  // End of program
  printf("Thank you for using the Wi-Fi Signal Strength Analyzer\n");
  return 0;
}