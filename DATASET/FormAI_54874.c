//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed for random numbers
  int num_ghosts = rand() % 4 + 1; // Generate number of ghosts in the house (between 1 and 4)
  int num_doors = rand() % 3 + 1; // Generate number of doors in the house (between 1 and 3)
  
  printf("Welcome to the haunted house simulator!\n");
  printf("There are %d ghosts and %d doors in the house.\n", num_ghosts, num_doors);
  
  int current_room = 1; // Player starts in room 1
  while(current_room <= num_doors) { // Loop until player reaches the last door
    printf("You are in room %d.\n", current_room);
    int choice;
    do {
      printf("Which door do you choose? (1-%d): ", num_doors);
      scanf("%d", &choice);
    } while(choice < 1 || choice > num_doors); // Make sure player chooses a valid door
    if(choice == current_room) { // Player chooses the door to the same room
      printf("You cannot go through this door!\n");
    } else if(rand() % num_ghosts == 0) { // Ghost appears (probability 1/num_ghosts)
      printf("You encountered a ghost! Game over.\n");
      return 0; // Game ends
    } else { // Player successfully goes through the door
      printf("You entered room %d.\n", choice);
      current_room = choice;
    }
  }
  printf("Congratulations! You have successfully escaped from the haunted house.\n");
  return 0;
}