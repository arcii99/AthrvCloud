//FormAI DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Seed random number generator with current time

  printf("Welcome to the Weather Simulator!\n");
  
  // Define weather conditions and probabilities
  char* weather[] = {"Clear", "Sunny", "Cloudy", "Rainy", "Windy", "Snowy"};
  int probs[] = {40, 50, 30, 20, 10, 5};

  // Begin weather simulation loop
  while (1) {
    // Generate random number between 0 and 99
    int rand_num = rand() % 100;
    
    // Check weather condition based on probability
    if (rand_num < probs[0]) {
      printf("The weather today is: %s\n", weather[0]);
    } else if (rand_num < (probs[0] + probs[1])) {
      printf("The weather today is: %s\n", weather[1]);
    } else if (rand_num < (probs[0] + probs[1] + probs[2])) {
      printf("The weather today is: %s\n", weather[2]);
    } else if (rand_num < (probs[0] + probs[1] + probs[2] + probs[3])) {
      printf("The weather today is: %s\n", weather[3]);
    } else if (rand_num < (probs[0] + probs[1] + probs[2] + probs[3] + probs[4])) {
      printf("The weather today is: %s\n", weather[4]);
    } else {
      printf("The weather today is: %s\n", weather[5]);
    }

    printf("-----------------------------------\n");
    printf("Press Enter to see tomorrow's weather\n");
    
    // Wait for user to press Enter
    while(getchar() != '\n');
  }
  
  return 0;
}