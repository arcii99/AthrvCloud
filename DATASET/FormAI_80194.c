//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_bags = 20;
  int baggage_claim = 0;
  
  printf("Welcome to the Airport Baggage Handling Simulation!\n");
  printf("There are %d bags waiting to be claimed at Baggage Claim %d.\n", num_bags, baggage_claim);
  
  for (int i = 0; i < num_bags; i++) {
    printf("Bag number %d is being loaded onto the conveyor belt at the departure gate.\n", i+1);
  }
  
  printf("\n\n");
  printf("Congratulations! You have successfully loaded all %d bags onto the conveyor belt.\n", num_bags);
  printf("Now, it's time to sit back, relax, and let the baggage handling system do its magic!\n");
  printf("But wait... what's this?!\n");
  
  int random_bag = rand() % num_bags + 1;
  
  printf("Bag number %d has been misplaced and needs to be rerouted. Looks like someone's vacation just got a little more adventurous!\n", random_bag);
  
  for (int i = random_bag - 1; i < num_bags - 1; i++) {
    printf("Bag number %d is moving down the conveyor belt...\n", i+1);
    printf("Bag number %d is moving up the airplane belt...\n", i+2);
  }
  
  printf("\n\n");
  printf("Phew! We've successfully rerouted bag number %d. All bags are now heading to Baggage Claim %d.\n", random_bag, baggage_claim);
  
  for (int i = 0; i < num_bags; i++) {
    printf("Bag number %d is being unloaded from the conveyor belt at Baggage Claim %d.\n", i+1, baggage_claim);
  }
  
  printf("\n\n");
  printf("Thanks for using our baggage handling system! We hope you had a pleasant flight and we apologize for any unexpected adventures.\n");
  
  return 0;
}