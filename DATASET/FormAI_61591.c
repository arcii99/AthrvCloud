//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  printf("Welcome to the Evolution Simulator!\n");
  printf("Here we will simulate the evolution of organisms over time.\n");
  printf("First, let's create our first organism.\n");

  char organism[10] = {'C', 'o', 'd', 'y', '\0'};
  int traits[5] = {rand()%10, rand()%10, rand()%10, rand()%10, rand()%10};

  printf("Our first organism is called %s and has the following traits:\n", organism);
  printf("Trait 1: %d\nTrait 2: %d\nTrait 3: %d\nTrait 4: %d\nTrait 5: %d\n\n", traits[0], traits[1], traits[2], traits[3], traits[4]);

  printf("Now let's simulate the organism's life.\n");

  for(int i = 0; i < 10; i++) {
    int mutation = rand()%5;
    int new_trait = rand()%10;
    traits[mutation] = new_trait;

    printf("Year %d: %s evolved. Trait %d mutated to %d.\n", i+1, organism, mutation+1, new_trait);
    printf("Traits now are: \nTrait 1: %d\nTrait 2: %d\nTrait 3: %d\nTrait 4: %d\nTrait 5: %d\n\n", traits[0], traits[1], traits[2], traits[3], traits[4]);
  }

  printf("After 10 years, %s has evolved into a new organism with the following traits:\n", organism);
  printf("Trait 1: %d\nTrait 2: %d\nTrait 3: %d\nTrait 4: %d\nTrait 5: %d\n", traits[0], traits[1], traits[2], traits[3], traits[4]);

  return 0;
}