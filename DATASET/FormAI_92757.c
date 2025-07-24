//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int wifi_strength;
  srand(time(NULL)); // seed for random number generator
  wifi_strength = rand() % 101; // generate a random number between 0 and 100
  if (wifi_strength < 50)
    printf("The Wi-Fi signal strength is weak with a strength of %d%%.\n", wifi_strength);
  else if (wifi_strength < 75)
    printf("The Wi-Fi signal strength is average with a strength of %d%%.\n", wifi_strength);
  else
    printf("The Wi-Fi signal strength is strong with a strength of %d%%.\n", wifi_strength);
  return 0;
}