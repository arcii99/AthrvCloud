//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int invasion_probability = rand() % 101; // generate random invasion probability

  printf("Welcome to the Alien Invasion Probability Calculator.\n");
  printf("Calculating probability of alien invasion... \n");
  printf("The probability of a current alien invasion is %d%%.\n", invasion_probability);

  if (invasion_probability >= 50) {
    printf("WARNING: The probability of alien invasion is high. Take necessary precautions.\n");
  } else {
    printf("No immediate threat of alien invasion. However, remain vigilant.\n");
  }

  printf("Press any key to exit.\n");
  getchar();
  
  return 0;
}