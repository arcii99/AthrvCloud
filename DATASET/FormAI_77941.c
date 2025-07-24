//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Declare functions
void printLocation(int location);
void printIntro();
void game();

int main() {
  // Print introduction and start the game
  printIntro();
  game();

  return 0;
}

// Print the introduction to the game
void printIntro() {
  printf("\nWelcome to Visionary World!\n");
  printf("This is a text-based adventure game where you are the main character.\n");
  printf("In this game, you will explore different locations, meet different characters, and make decisions that will impact the story.\n");
  printf("Your goal is to find the Visionary Crystal, a powerful artifact that can grant unlimited power to its owner.\n");
  printf("Good luck on your journey!\n\n");
}

// Print the location and its description
void printLocation(int location) {
  printf("\nLocation %d\n", location);
  
  switch(location) {
    case 1:
      printf("You are in the Forest of Enchantment.\n");
      printf("The trees are tall and the air is thick with mist.\n");
      break;
    case 2:
      printf("You are in the City of Technology.\n");
      printf("The buildings are tall and made of gleaming metal.\n");
      break;
    case 3:
      printf("You are in the Desert of Solitude.\n");
      printf("The sand stretches as far as the eye can see.\n");
      break;
    case 4:
      printf("You are in the Mountains of Peril.\n");
      printf("The rugged terrain is treacherous and the winds are howling.\n");
      break;
    default:
      printf("Error: invalid location\n");
      exit(1);
  }
}

// Main game loop
void game() {
  // Initialize game variables
  int location = 1;
  char input[MAX_LENGTH];

  while(1) { // Game loop
    printLocation(location);
    printf("Where do you want to go? (north/east/south/west): ");
    fgets(input, MAX_LENGTH, stdin);

    // Parse user input
    if(strncmp(input, "north", 5) == 0) {
      if(location == 1) {
        printf("You cannot go that way.\n");
      } else if(location == 2) {
        printf("You are now in the Forest of Enchantment.\n");
        location = 1;
      } else if(location == 3) {
        printf("You cannot go that way.\n");
      } else if(location == 4) {
        printf("You are now in the City of Technology.\n");
        location = 2;
      }
    } else if(strncmp(input, "east", 4) == 0) {
      if(location == 1) {
        printf("You are now in the Desert of Solitude.\n");
        location = 3;
      } else if(location == 2) {
        printf("You cannot go that way.\n");
      } else if(location == 3) {
        printf("You are now in the Mountains of Peril.\n");
        location = 4;
      } else if(location == 4) {
        printf("You cannot go that way.\n");
      }
    } else if(strncmp(input, "south", 5) == 0) {
      if(location == 1) {
        printf("You are now in the City of Technology.\n");
        location = 2;
      } else if(location == 2) {
        printf("You are now in the Forest of Enchantment.\n");
        location = 1;
      } else if(location == 3) {
        printf("You cannot go that way.\n");
      } else if(location == 4) {
        printf("You cannot go that way.\n");
      }
    } else if(strncmp(input, "west", 4) == 0) {
      if(location == 1) {
        printf("You cannot go that way.\n");
      } else if(location == 2) {
        printf("You are now in the Forest of Enchantment.\n");
        location = 1;
      } else if(location == 3) {
        printf("You are now in the City of Technology.\n");
        location = 2;
      } else if(location == 4) {
        printf("You cannot go that way.\n");
      }
    } else {
      printf("Invalid input. Please try again.\n");
    }

    // Check if player has reached the end of the game
    if(location == 2) { // The Visionary Crystal is in the City of Technology
      printf("\nCongratulations! You have found the Visionary Crystal.\n");
      printf("You have unlocked unlimited power!\n");
      break;
    }
  }
}