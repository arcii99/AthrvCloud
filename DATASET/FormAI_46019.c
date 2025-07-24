//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){
  //declaring variables
  int num_of_planets, num_of_aliens, civilization_level, invasion_odds;
  double technological_advancement, habitability_factor, military_strength;
  srand(time(NULL)); //seeding the random number generator with time
  
  //taking user input for number of planets
  printf("Enter the number of planets in the galaxy: ");
  scanf("%d", &num_of_planets);
  
  //taking user input for civilization level of aliens
  printf("\nEnter the civilization level of aliens (between 1-10): ");
  scanf("%d", &civilization_level);
  
  //taking user input for technological advancement of aliens
  printf("\nEnter the technological advancement of aliens (between 0.0-10.0): ");
  scanf("%lf", &technological_advancement);
  
  //taking user input for habitability factor of planets
  printf("\nEnter the average habitability factor of planets (between 0.0-10.0): ");
  scanf("%lf", &habitability_factor);
  
  //calculating the total number of aliens in the galaxy
  num_of_aliens = pow(num_of_planets, 2.0) * civilization_level * technological_advancement;
  
  //calculating the military strength of aliens
  military_strength = pow(civilization_level, 2.0) * technological_advancement;
  
  //calculating the invasion odds
  invasion_odds = (int)((double)military_strength * (1.0 - habitability_factor) / (double)num_of_aliens * 1000);
  
  //printing the invasion odds
  printf("\nThe probability of an alien invasion is %d in 1000", invasion_odds);
  
  return 0;
}