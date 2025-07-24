//FormAI DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Initialization
  srand(time(NULL));
  int room = 1;
  int solved = 0;

  // Introduction
  printf("Welcome to the Cryptic Quest!\n");
  printf("You have entered a mysterious dungeon and must find the treasure hidden within.\n");
  printf("To do so you must solve a series of puzzles and overcome various obstacles.\n");
  printf("Good luck!\n\n");
  
  while (room < 6 && !solved) {
    // Room description
    switch(room) {
      case 1:
        printf("You enter a dark room with a single torch on the wall.\n");
        break;
      case 2:
        printf("You climb a narrow staircase and find yourself in a locked chamber.\n");
        break;
      case 3:
        printf("You enter a circular room filled with mirrors.\n");
        break;
      case 4:
        printf("You step into a room with a giant chess board on the floor.\n");
        break;
      case 5:
        printf("You find yourself in a shadowy room with a stone pedestal in the center.\n");
        break;
    }
    
    // Puzzle/challenge
    switch(room) {
      case 1:
        // TODO: Add puzzle for room 1
        break;
      case 2:
        // TODO: Add puzzle for room 2
        break;
      case 3:
        // TODO: Add puzzle for room 3
        break;
      case 4:
        // TODO: Add puzzle for room 4
        break;
      case 5:
        // TODO: Add puzzle for room 5
        break;
    }
    
    // Move to next room or end game
    if (solved) {
      printf("You have solved the puzzle and found the treasure! Congratulations!\n");
    } else if (room < 5) {
      printf("You have solved the puzzle for this room. Moving on to the next...\n\n");
      room++;
    } else {
      printf("You have reached the final room, but it is locked. You failed to solve the final puzzle and must start over.\n");
      room = 1;
    }
  }
  
  return 0;
}