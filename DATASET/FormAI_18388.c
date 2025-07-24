//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int win = rand() % 2; // randomly choose if the player will win or lose
  int rooms = 0; // keep track of how many rooms the player has explored
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are trapped in a haunted house and must find your way out.\n");
  while (rooms < 5) { // the player must explore at least 5 rooms to win
    printf("You enter room %d\n", rooms+1);
    int ghost = rand() % 2; // randomly choose if there is a ghost in the room
    int trap = rand() % 2; // randomly choose if there is a trap in the room
    if (ghost) {
      printf("You encounter a ghost!\n");
      if (win) { // if the player will win
        printf("You use your amulet to defeat the ghost and continue on.\n");
      } else { // if the player will lose
        printf("You try to run away but the ghost catches you and kills you.\n");
        printf("Game Over.\n");
        return 0; // exit the program
      }
    }
    if (trap) {
      printf("You fall into a trap!\n");
      if (win) { // if the player will win
        printf("You use your amulet to teleport out of the trap and continue on.\n");
      } else { // if the player will lose
        printf("You try to escape the trap but are caught by a hidden monster.\n");
        printf("Game Over.\n");
        return 0; // exit the program
      }
    }
    printf("You discover a key to the next room and continue on.\n");
    rooms++; // increase the number of explored rooms
  }
  printf("Congratulations! You have escaped the haunted house!\n");
  return 0;
}