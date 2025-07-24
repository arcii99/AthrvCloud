//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Cyberpunk style console opening
  printf("WELCOME TO ALIEN INVASION PROBABILITY CALCULATOR 2.0\n");
  printf("ENTERING SECURITY MODE...\n");
  printf("HACKING INTO MILITARY DATABASE...\n");
  printf("ACCESS GRANTED.\n");

  // Seed RNG
  srand(time(NULL));

  // Randomly generate alien invasion probability
  float probability = (float) (rand() % 101);
  printf("\nALIEN INVASION PROBABILITY: %.2f%%\n", probability);

  // Determine level of danger based on probability
  printf("DETERMINING LEVEL OF DANGER...\n");
  if (probability < 25) {
    printf("LOW DANGER.\n");
  } else if (probability < 50) {
    printf("MEDIUM DANGER.\n");
  } else if (probability < 75) {
    printf("HIGH DANGER.\n");
  } else {
    printf("EXTREME DANGER.\n");
  }

  // Determine recommended action based on level of danger
  printf("RECOMMENDED ACTION:\n");
  if (probability < 25) {
    printf("NO ACTION NECESSARY.\n");
  } else if (probability < 50) {
    printf("PREPARE FOR POSSIBLE INVASION.\n");
  } else if (probability < 75) {
    printf("EVACUATE IMMEDIATELY.\n");
  } else {
    printf("INITIATE PLANETARY DEFENSE SYSTEMS.\n");
  }

  printf("\nEXECUTING SELF-DESTRUCT PROTOCOL...\n");
  printf("THANK YOU FOR USING ALIEN INVASION PROBABILITY CALCULATOR 2.0\n");

  return 0;
}