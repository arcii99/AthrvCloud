//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include <stdio.h>

void cheer() {
  printf("Hooray!\n");
}

int main() {
  int signal_strength;
  
  printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
  printf("\n");
  printf("Please enter the current signal strength in dBm: ");
  
  scanf("%d", &signal_strength);
  
  if (signal_strength >= -50) {
    printf("Wow, your signal strength is amazing!\n");
    cheer();
  }
  else if (signal_strength >= -70) {
    printf("Your signal strength is pretty good!\n");
    cheer();
  }
  else if (signal_strength >= -80) {
    printf("Your signal strength is okay, but could be better.\n");
  }
  else {
    printf("Your signal strength is too low, you may experience connection issues.\n");
  }
  
  printf("\n");
  printf("Thanks for using the Wi-Fi Signal Strength Analyzer!\n");
  
  return 0;
}