//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: puzzling
#include <stdio.h>

int main() {
  int signalStrength;
  printf("Enter the signal strength (0-100): ");
  scanf("%d", &signalStrength);
  
  if (signalStrength < 0 || signalStrength > 100) {
    printf("Invalid signal strength!");
    return 0;
  }
  
  printf("Signal strength: %d\n", signalStrength);
  
  if (signalStrength <= 20) {
    printf("Signal strength is very weak.\n");
  } else if (signalStrength <= 40) {
    printf("Signal strength is weak.\n");
  } else if (signalStrength <= 60) {
    printf("Signal strength is moderate.\n");
  } else if (signalStrength <= 80) {
    printf("Signal strength is strong.\n");
  } else {
    printf("Signal strength is very strong.\n");
  }

  return 0;
}