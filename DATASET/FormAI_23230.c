//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int alien_ships, destroy_chance, survival_chance;
  srand(time(0)); //initialize random seed

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Enter the number of alien ships detected in our solar system:");
  scanf("%d", &alien_ships);

  printf("\nCalculating probability of destruction...\n");

  //calculate chance of destruction based on number of alien ships
  if (alien_ships <= 10){
    destroy_chance = rand() % 50 + 1; //1-50%
  }
  else if (alien_ships <= 20){
    destroy_chance = rand() % 70 + 1; //1-70%
  }
  else {
    destroy_chance = rand() % 90 + 1; //1-90%
  }

  printf("Probability of total destruction: %d%%\n", destroy_chance);

  //calculate chance of survival based on destruction chance
  survival_chance = 100 - destroy_chance;

  printf("Probability of survival: %d%%\n", survival_chance);

  printf("\nThank you for using the Alien Invasion Probability Calculator!\n");

  return 0;
}