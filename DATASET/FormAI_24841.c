//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>

int main() {
  printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
  
  int signal_strength = 0;

  printf("Please enter the Wi-Fi signal strength (0-100): ");
  scanf("%d", &signal_strength);

  if (signal_strength > 100 || signal_strength < 0) {
    printf("Invalid input. Signal strength range is 0-100.\n");
    return 0;
  }

  if (signal_strength >= 90) {
    printf("Signal strength is excellent!\n");
  } 
  else if (signal_strength >= 70) {
    printf("Signal strength is good.\n");
  } 
  else if (signal_strength >= 50) {
    printf("Signal strength is average.\n");
  } 
  else if (signal_strength >= 30) {
    printf("Signal strength is poor.\n");
  } 
  else {
    printf("Signal strength is very poor. You may experience connectivity issues.\n");
  }

  printf("Thank you for using Wi-Fi Signal Strength Analyzer!\n");

  return 0;
}