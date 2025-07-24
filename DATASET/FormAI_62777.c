//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the dungeon
#define ROWS 10
#define COLS 20

// Declare the dungeon as a 2D char array
char dungeon[ROWS][COLS];

// Define a struct for the player character
struct Player {
  int x;
  int y;
  int health;
};

// Declare a function to generate the dungeon
void generate_dungeon() {
  // Seed the random number generator
  srand(time(NULL));
  // Loop through each cell in the dungeon
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Generate a random number between 0 and 1
      int r = rand() % 2;
      // If the number is 0, set the cell to a wall, otherwise set it to a floor
      dungeon[i][j] = r == 0 ? '#' : '.';
    }
  }
}

// Declare a function to print the dungeon
void print_dungeon() {
  // Loop through each cell in the dungeon
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Print the cell
      printf("%c", dungeon[i][j]);
    }
    // Print a newline character to move to the next row
    printf("\n");
  }
}

// Declare a function to place the player character in the dungeon
void place_player(struct Player *player) {
  // Loop through each cell in the dungeon
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // If the cell is a floor, place the player there
      if (dungeon[i][j] == '.') {
        player->x = j;
        player->y = i;
        player->health = 100;
        return;
      }
    }
  }
}

// Declare a function to move the player character
void move_player(struct Player *player, char direction) {
  // Calculate the new position of the player based on the direction
  int new_x = player->x;
  int new_y = player->y;
  switch (direction) {
    case 'a':
      new_x--;
      break;
    case 'd':
      new_x++;
      break;
    case 'w':
      new_y--;
      break;
    case 's':
      new_y++;
      break;
    default:
      return;
  }
  // If the new position is a wall, do nothing
  if (dungeon[new_y][new_x] == '#') {
    return;
  }
  // Otherwise, move the player to the new position
  player->x = new_x;
  player->y = new_y;
}

// Declare a function to handle the player's turn
void player_turn(struct Player *player) {
  // Print the dungeon and the player's status
  print_dungeon();
  printf("Health: %d\n", player->health);
  // Prompt the player for their move
  printf("Enter a direction (a, d, w, s): ");
  char direction;
  scanf(" %c", &direction);
  // Move the player in the chosen direction
  move_player(player, direction);
}

int main() {
  // Generate the dungeon
  generate_dungeon();
  // Create the player character
  struct Player player;
  // Place the player in the dungeon
  place_player(&player);
  // Game loop
  while (player.health > 0) {
    // Handle the player's turn
    player_turn(&player);
  }
  // Game over
  printf("Game over!\n");
  return 0;
}