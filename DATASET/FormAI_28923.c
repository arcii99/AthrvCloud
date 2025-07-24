//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL)); // seed the random number generator
  
  // greet the user with a cheerful message
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("We're here to make predictions, but don't worry too much.\n");
  printf("Life is beautiful, even with a probability of alien invasion :)\n");
  
  // get user input on various factors affecting the probability of invasion
  int num_of_planets, num_of_minor_deities, num_of_finger_snaps;
  printf("How many planets are in our solar system?\n");
  scanf("%d", &num_of_planets);
  printf("How many minor deities are currently in existence?\n");
  scanf("%d", &num_of_minor_deities);
  printf("How many times have you snapped your fingers in the last minute?\n");
  scanf("%d", &num_of_finger_snaps);
  
  // calculate invasion probability based on user input and a random factor
  float inv_prob = (float)num_of_planets * 5.0 + (float)num_of_minor_deities * 10.0 - (float)num_of_finger_snaps * 2.0 + rand() % 11;
  inv_prob /= 100.0; // scale down to a fraction between 0.0 and 1.0
  
  // generate a cheerful message to display the calculated probability
  char message[100];
  if (inv_prob < 0.25) {
    sprintf(message, "Based on our calculations, the probability of alien invasion is only %.2f%%! You're safe :)", inv_prob * 100.0);
  } else if (inv_prob < 0.5) {
    sprintf(message, "Based on our calculations, the probability of alien invasion is %.2f%%. Just keep a watchful eye ;)", inv_prob * 100.0);
  } else if (inv_prob < 0.75) {
    sprintf(message, "Based on our calculations, the probability of alien invasion is %.2f%%. You might want to start preparing now :|", inv_prob * 100.0);
  } else {
    sprintf(message, "Based on our calculations, the probability of alien invasion is %.2f%%! Brace yourselves, they're coming D:", inv_prob * 100.0);
  }
  
  // display the cheerful message to the user
  printf("%s\n", message);
  
  // return 0 to indicate successful completion of program
  return 0;
}