//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GHOSTS 5

typedef struct {
  int id;
  int num_ghosts;
  int num_items;
} Room;

typedef struct {
  int id;
} Ghost;

int main() {
  // Set up random seed
  srand(time(NULL));

  // Create rooms
  Room rooms[MAX_ROOMS];
  for (int i = 0; i < MAX_ROOMS; i++) {
    rooms[i].id = i + 1;
    rooms[i].num_ghosts = 0;
    rooms[i].num_items = 0;
  }

  // Place ghosts and items randomly in rooms
  Ghost ghosts[MAX_GHOSTS];
  int num_ghosts_placed = 0;
  for (int i = 0; i < MAX_ROOMS; i++) {
    int num_ghosts = rand() % 3;
    rooms[i].num_ghosts = num_ghosts;

    for (int j = 0; j < num_ghosts; j++) {
      Ghost ghost;
      ghost.id = num_ghosts_placed + 1;
      ghosts[num_ghosts_placed] = ghost;
      num_ghosts_placed++;
    }

    int num_items = rand() % 2;
    rooms[i].num_items = num_items;
  }

  // Main game loop
  int current_room = 1;
  while (1) {
    printf("You are in room %d\n", current_room);

    // Check if room has any items
    if (rooms[current_room - 1].num_items > 0) {
      printf("You found an item!\n");
      rooms[current_room - 1].num_items--;
    }

    // Check if room has any ghosts
    if (rooms[current_room - 1].num_ghosts > 0) {
      printf("Oh no, there's a ghost!\n");
      rooms[current_room - 1].num_ghosts--;
      int random_move = rand() % MAX_ROOMS + 1;
      printf("The ghost takes you to room %d\n", random_move);
      current_room = random_move;
    } else {
      // Get user input to move to another room
      printf("Where do you want to go next? ");
      int choice;
      scanf("%d", &choice);

      // Check if choice is valid
      if (choice < 1 || choice > MAX_ROOMS) {
        printf("Invalid choice, try again.\n");
      } else {
        current_room = choice;
      }
    }

    // Check if player found all items and won the game
    int total_items = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
      total_items += rooms[i].num_items;
    }
    if (total_items == 0) {
      printf("Congratulations, you found all the items and won the game!\n");
      break;
    }
  }

  return 0;
}