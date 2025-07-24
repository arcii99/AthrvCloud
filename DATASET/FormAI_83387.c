//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice, ghost_choice, i;
  int alive = 1;
  srand(time(NULL));

  printf("Welcome to the Haunted House Simulator!\n");
  printf("You have entered a spooky old house, and you don't know what's inside.\n");
  printf("Choose your movement: \n 1. Go to the left \n 2. Go to the right \n");

  while (alive) {
    printf("\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    // randomly choose a room and determine ghost presence
    ghost_choice = rand() % 2 + 1;
    if (ghost_choice == choice) {
      printf("\nA ghost appears and kills you. Game over.\n");
      break;
    }
    else {
      printf("\nYou enter the room safely. What would you like to do now?\n");
      printf("1. Search the room\n");
      printf("2. Move to another room\n");

      scanf("%d", &choice);

      if (choice == 1) {
        printf("\nYou search the room for clues. You find a key!\n");
        printf("1. Go to the next room\n");
        printf("2. Go back to the previous room\n");
        scanf("%d", &choice);
        continue;
      }
      else {
        printf("\nYou move to another room.\n");
        continue;
      }
    }
  }

  return 0;
}