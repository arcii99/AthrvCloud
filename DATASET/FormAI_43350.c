//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 6

int main() {
  int rooms[ROOMS][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}; // Initialize all rooms to be unvisited and have no items
  int player_room = 0; // Start the player in room 0
  int ghost_room = 0; // Start the ghost in room 0

  srand(time(NULL)); // Seed the random number generator with the current time

  printf("Welcome to the Haunted House Simulator!\n");

  while (1) {
    printf("\nYou are in room %d.\n", player_room);

    if (player_room == ghost_room) {
      printf("You feel a chill down your spine as a ghost suddenly appears in front of you!\n");
      printf("Game Over.\n");
      break;
    }

    if (rooms[player_room][0] == 0 && rand() % 2 == 0) {
      printf("You found a key in this room!\n");
      rooms[player_room][0] = 1; // Mark this room as having been visited and having a key
    }

    if (rooms[player_room][1] == 0 && rand() % 2 == 0) {
      printf("You found a flashlight in this room!\n");
      rooms[player_room][1] = 1; // Mark this room as having been visited and having a flashlight
    }

    int action = -1;

    while (action < 1 || action > 4) {
      printf("What do you want to do?\n");
      printf("1. Go to the next room.\n");
      printf("2. Use the key to unlock a door.\n");
      printf("3. Use the flashlight to see in the dark.\n");
      printf("4. Quit the game.\n");
      scanf("%d", &action);
    }

    if (action == 1) {
      if (player_room == ROOMS - 1) {
        printf("You found the exit! Congratulations, you win!\n");
        break;
      } else {
        player_room++;
        printf("You go to room %d.\n", player_room);
      }
    } else if (action == 2) {
      if (rooms[player_room][0] == 1 && player_room != 0) {
        printf("You use the key to unlock the door to room %d.\n", player_room - 1);
        player_room--;
      } else {
        printf("You don't have a key, or you are at the first room.\n");
      }
    } else if (action == 3) {
      if (rooms[player_room][1] == 1) {
        printf("You use the flashlight and can see in the dark for a while.\n");
      } else {
        printf("You don't have a flashlight.\n");
      }
    } else if (action == 4) {
      printf("Thanks for playing!\n");
      break;
    }

    if (ghost_room == player_room - 1) {
      ghost_room--;
    } else if (ghost_room == player_room + 1) {
      ghost_room++;
    } else {
      int movement = rand() % 2;
      if (movement == 0) {
        ghost_room--;
      } else {
        ghost_room++;
      }
    }

    printf("The ghost is in room %d.\n", ghost_room);
  }

  return 0;
}