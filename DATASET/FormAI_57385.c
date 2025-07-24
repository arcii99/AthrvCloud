//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define ALIEN_COUNT 50

int alien_x[ALIEN_COUNT], alien_y[ALIEN_COUNT];
int player_x, player_y;
bool game_over = false;

void init_board();
void draw_board();
void update_player(char direction);
void update_aliens();
bool are_aliens_all_destroyed();

int main() {
  srand(time(NULL));  // seed randomizer
  init_board();
  while (!game_over) {
    draw_board();
    char input;
    printf("Enter direction (l/r): ");
    scanf("%c", &input);
    fflush(stdin);  // clear input buffer
    update_player(input);
    update_aliens();
    if (are_aliens_all_destroyed()) {
      printf("Congratulations, you have defeated all aliens!\n");
      game_over = true;
    }
  }
  return 0;
}

// Initialize board with player at bottom center and aliens randomly
void init_board() {
  player_x = COLS/2;
  player_y = ROWS-1;
  for (int i = 0; i < ALIEN_COUNT; i++) {
    alien_x[i] = rand() % COLS;
    alien_y[i] = rand() % ROWS;
  }
}

// Draw board with player, aliens, and border
void draw_board() {
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLS; x++) {
      if (y == player_y && x == player_x) {
        printf("P");
      } else if (x == 0 || x == COLS-1 || y == 0 || y == ROWS-1) {
        printf("X");
      } else {
        bool is_alien = false;
        for (int i = 0; i < ALIEN_COUNT; i++) {
          if (alien_x[i] == x && alien_y[i] == y) {
            printf("A");
            is_alien = true;
            break;
          }
        }
        if (!is_alien) {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

// Move player left or right
void update_player(char direction) {
  if (direction == 'l') {
    player_x--;
  } else if (direction == 'r') {
    player_x++;
  }
  // Check if player hit border
  if (player_x < 1) {
    player_x = 1;
  } else if (player_x >= COLS-1) {
    player_x = COLS-2;
  }
  // Check if player hit alien
  for (int i = 0; i < ALIEN_COUNT; i++) {
    if (alien_x[i] == player_x && alien_y[i] == player_y) {
      printf("Game over, you were defeated by an alien!\n");
      game_over = true;
    }
  }
}

// Move aliens randomly
void update_aliens() {
  for (int i = 0; i < ALIEN_COUNT; i++) {
    // Remove alien if hit by player
    if (alien_x[i] == player_x && alien_y[i] == player_y-1) {
      alien_x[i] = -1;
      alien_y[i] = -1;
      continue;
    }
    // Move alien randomly
    int dir = rand() % 3 - 1;
    alien_x[i] += dir;
    alien_y[i]++;    
    // Check if alien hit player or hit wall
    if (alien_x[i] == player_x && alien_y[i] == player_y) {
      printf("Game over, you were defeated by an alien!\n");
      game_over = true;
    }
    if (alien_x[i] < 1 || alien_x[i] >= COLS-1 || alien_y[i] >= ROWS-1) {
      alien_x[i] = -1;
      alien_y[i] = -1;
    }
  }
}

// Determine if all aliens are destroyed
bool are_aliens_all_destroyed() {
  for (int i = 0; i < ALIEN_COUNT; i++) {
    if (alien_x[i] != -1 && alien_y[i] != -1) {
      return false;
    }
  }
  return true;
}