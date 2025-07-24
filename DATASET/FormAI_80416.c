//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define SHIP_SIZE 3

// Function to generate a random number
int rand_num(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to draw the game board
void draw_board(int ship_pos, int bullet_pos) {
  int i, j;
  for (i=0; i<HEIGHT; i++) {
    for (j=0; j<WIDTH; j++) {
      if (i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1) {
        printf("#");
      } else if (j == ship_pos && i == HEIGHT-2) {
        printf("W");
      } else if (j == bullet_pos && i == HEIGHT-3) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Function to move the ship left or right
int move_ship(int curr_pos, char move) {
  if (move == 'l' && curr_pos > 1) {
    curr_pos--;
  } else if (move == 'r' && curr_pos < WIDTH-SHIP_SIZE) {
    curr_pos++;
  }
  return curr_pos;
}

// Function to move the bullet up one row
int move_bullet(int curr_pos) {
  if (curr_pos > 1) {
    curr_pos--;
  } else {
    curr_pos = -1;
  }
  return curr_pos;
}

// Function to check if the ship and bullet collide
int check_collide(int ship_pos, int bullet_pos) {
  if (ship_pos <= bullet_pos && ship_pos+SHIP_SIZE-1 >= bullet_pos) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char move;
  int ship_pos = WIDTH/2;
  int bullet_pos = -1;
  int alien_pos = rand_num(1, WIDTH-SHIP_SIZE-1);

  srand(time(NULL));

  while (1) {
    // Clear the screen
    system("clear");

    // Draw the board and check for a collision
    draw_board(ship_pos, bullet_pos);
    if (check_collide(ship_pos, bullet_pos) == 1) {
      printf("GAME OVER\n");
      break;
    }

    // Move the alien and generate a new one if it reaches the bottom
    alien_pos = move_bullet(alien_pos);
    if (alien_pos == -1) {
      alien_pos = rand_num(1, WIDTH-SHIP_SIZE-1);
    }

    // Get user input and move the ship
    printf("Use 'l' and 'r' to move the ship, 'f' to fire: ");
    scanf(" %c", &move);
    ship_pos = move_ship(ship_pos, move);

    // Fire the bullet if 'f' is pressed and there is not already a bullet
    if (move == 'f' && bullet_pos == -1) {
      bullet_pos = ship_pos+SHIP_SIZE/2;
    }

    // Move the bullet and reset it if it reaches the top
    bullet_pos = move_bullet(bullet_pos);
    if (bullet_pos == -1) {
      bullet_pos = -1;
    }
  }

  return 0;
}