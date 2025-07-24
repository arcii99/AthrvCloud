//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

  float distance, alien_speed, invasion_probability;
  
  printf("Enter the distance between Earth and the alien planet (in light years): ");
  scanf("%f", &distance);
  
  printf("Enter the speed of the aliens' spacecraft (in miles per second): ");
  scanf("%f", &alien_speed);
  
  srand(time(NULL));
  
  int alien_count = rand() % 10001; // Assume no more than 10,000 aliens
  
  float duration = distance * 365 * 24 * 3600 / (alien_speed * 186282); // Convert distance and speed to seconds
  
  if (duration > 150) { // If it takes longer than 150 years, the aliens will never make it to Earth
    printf("The aliens will never make it to Earth.\n");
  } else {  
    invasion_probability = 1 - pow((1 - (1.0 / alien_count)), (1.0 / duration));
    
    printf("Based on the distance, alien speed, and number of aliens, the probability of an alien invasion is %f.\n", invasion_probability);
  }
  
  return 0;
}