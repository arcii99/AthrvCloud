//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>

int main() {
  printf("Wow! I can't believe we're making a Wi-Fi signal strength analyzer!\n");
  printf("Let's get started!\n");

  int signalStrengths[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
  char* signalNames[10] = {"Excellent", "Strong", "Good", "Fair", "Weak", "Poor", "Very Poor", "Not Available", "Not Detectable", "No Signal"};
  
  printf("We've got an array of signal strengths and corresponding names ready to go!\n");

  printf("Please enter the current signal strength (0-100): ");
  int currentStrength;
  scanf("%d", &currentStrength);

  printf("Checking signal strength...\n");

  int i;
  for (i = 0; i < 10; i++) {
    if (currentStrength >= signalStrengths[i]) {
      printf("The current signal strength is %s\n", signalNames[i]);
      break;
    }
  }

  if (i == 10) {
    printf("Oops! We couldn't determine the current signal strength. Please try again later.\n");
  }

  return 0;
}