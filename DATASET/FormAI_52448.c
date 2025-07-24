//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //seed the random number generator with current time
  int probability = rand() % 101; //generate a random number between 0 and 100

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Calculating probability...\n\n");

  //animate the probability calculation process
  printf("   5%% ");
  for(int i = 0; i < 5; i++) {
    printf("#");
    fflush(stdout); //flush the output buffer to ensure the animation is smooth
    sleep(1); //wait for 1 second
  }
  printf("\n  25%% ");
  for(int i = 0; i < 25; i++) {
    printf("#");
    fflush(stdout);
    sleep(1);
  }
  printf("\n  50%% ");
  for(int i = 0; i < 50; i++) {
    printf("#");
    fflush(stdout);
    sleep(1);
  }
  printf("\n  75%% ");
  for(int i = 0; i < 75; i++) {
    printf("#");
    fflush(stdout);
    sleep(1);
  }
  printf("\n 100%% ");
  for(int i = 0; i < 5; i++) {
    printf("#");
    fflush(stdout);
    sleep(1);
  }

  printf("\n\nThe probability of an alien invasion is %d%%.\n", probability);

  if(probability > 50) {
    printf("It seems like we have a high chance of being invaded by extraterrestrial beings.\n");
    printf("We need to act fast and prepare our defense measures!\n");
  } else {
    printf("Phew, it looks like the probability of an invasion is low.\n");
    printf("But we should still maintain our vigilance and take necessary precautions.\n");
  }

  return 0;
}