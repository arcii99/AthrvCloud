//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

   srand(time(NULL)); // seed the random number generator with the current time

   int num_planets = rand() % 100; // randomly generate a number of planets (up to 100)
   printf("There are %d planets in this galaxy.\n", num_planets);

   float planet_habitable_prob = (float) rand() / RAND_MAX; // generate a probability that a planet is habitable (range 0.0 to 1.0)
   printf("The probability that any given planet is habitable is %.2f.\n", planet_habitable_prob);

   int num_habitable = num_planets * planet_habitable_prob; // calculate the number of habitable planets
   printf("There are approximately %d habitable planets in this galaxy.\n", num_habitable);

   float alien_life_prob = (float) rand() / RAND_MAX; // generate a probability that alien life exists on a habitable planet (range 0.0 to 1.0)
   printf("The probability that alien life exists on any given habitable planet is %.2f.\n", alien_life_prob);

   int num_with_life = num_habitable * alien_life_prob; // calculate the number of habitable planets with alien life
   printf("There are approximately %d habitable planets in this galaxy with alien life.\n\n", num_with_life);

   float invasion_prob = (float) num_with_life / num_habitable; // calculate the probability that any habitable planet with alien life will invade Earth
   printf("Based on these probabilities, the probability of an alien invasion is %.2f.\n", invasion_prob);

   printf("\nRemember, this is just a simulation. Please don't panic!\n");

   return 0;
}