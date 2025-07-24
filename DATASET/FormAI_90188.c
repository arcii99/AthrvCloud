//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: innovative
#include<stdio.h>
#include<string.h>

void wifiSignalStrengthAnalyzer(char signalStrength[]) {
  if(strcmp(signalStrength,"excellent")==0) {
    printf("Signal Strength is excellent. Enjoy uninterrupted browsing.\n");
  } else if(strcmp(signalStrength,"good")==0) {
    printf("Signal Strength is good. You may experience occasional buffering.\n");
  } else if(strcmp(signalStrength,"fair")==0) {
    printf("Signal Strength is fair. You may experience slow browsing speeds.\n");
  } else if(strcmp(signalStrength,"weak")==0) {
    printf("Signal Strength is weak. It's recommended to move closer to the router.\n");
  } else {
    printf("Invalid signal strength. Please enter a valid signal strength.\n");
  }
}

int main() {
  char signalStrength[15];
  printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
  printf("Enter the signal strength (excellent,good,fair,weak): ");
  scanf("%s",signalStrength);
  wifiSignalStrengthAnalyzer(signalStrength);
  return 0;
}