//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initialize random seed
  int strength = rand() % 100; // Generate random signal strength value
  
  printf("Welcome to the Wi-Fi Signal Strength Analyzer! \n");
  printf("Your current Wi-Fi signal strength is: %d%% \n", strength);
  
  if (strength > 80) {
    printf("Wow, your Wi-Fi signal strength is amazing! You must be living in the router room! \n");
  } else if (strength > 60) {
    printf("Your Wi-Fi signal strength is pretty good, but you might want to move closer to the router if you're downloading anything big. \n");
  } else if (strength > 40) {
    printf("Things are starting to SlowLoris with your Wi-Fi signal strength. Maybe it's time to reset your router? \n");
  } else {
    printf("Oh no, your Wi-Fi signal strength is weaker than a kitten's meow. Time to call your internet service provider! \n");
  }
  
  return 0;
}