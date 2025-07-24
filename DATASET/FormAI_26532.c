//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  int signalStrength, numReadings, totalStrength = 0;
  float avgStrength;
  
  // Get user input
  printf("Enter the number of readings: ");
  scanf("%d", &numReadings);
  
  // Get signal strengths and calculate total
  for (int i=1; i<=numReadings; i++) {
    printf("Enter signal strength #%d (out of 100): ", i);
    scanf("%d", &signalStrength);
    totalStrength += signalStrength;
  }
  
  // Calculate average strength
  avgStrength = (float) totalStrength / numReadings;
  
  // Print results
  printf("\nAverage signal strength: %.2f\n", avgStrength);
  if (avgStrength >= 70) {
    printf("Signal strength is strong\n");
  } else if (avgStrength >= 50) {
    printf("Signal strength is moderate\n");
  } else {
    printf("Signal strength is weak\n");
  }
  
  return 0;
}