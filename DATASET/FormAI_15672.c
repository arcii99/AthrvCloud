//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");

  // Initialize random number generator with current time as seed
  srand(time(NULL));

  int signal_strength = rand() % 100 + 1;

  printf("Your current signal strength is %d%%\n", signal_strength);

  if (signal_strength > 80) {
    printf("Wow, your Wi-Fi strength is so strong, it could power a rocket ship to Mars!\n");
  } else if (signal_strength > 60) {
    printf("Your Wi-Fi signal is pretty strong, but it could use a little boost.\n");
  } else if (signal_strength > 40) {
    printf("Your Wi-Fi signal is mediocre... kind of like cold coffee that's been sitting out for too long.\n");
  } else {
    printf("Yikes, your Wi-Fi signal is weaker than a limp noodle. Time to call your internet provider.\n");
  }

  printf("Thank you for using the Wi-Fi Signal Strength Analyzer!\n");

  return 0;
}