//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for game
#define WIDTH 20
#define HEIGHT 10
#define ALIEN_FREQ 5
#define SHIP_SPEED 2

// Define struct for game objects
typedef struct {
  int x;
  int y;
} Object;

// Function declarations
void print_board(Object ship, Object* aliens, Object* shots);
void update_ship(Object* ship, int direction);
void update_aliens(Object* aliens, Object* shots);
void update_shots(Object* shots);
void fire_shot(Object* shots, Object ship);
Object create_object(int x, int y);
void init_aliens(Object* aliens);
void move_aliens(Object* aliens, int direction);
int random_int(int range);

int main() {
  // Initialize game objects and variables
  Object ship = create_object(9, 9);
  Object aliens[ALIEN_FREQ * WIDTH];
  init_aliens(aliens);
  Object shots[ALIEN_FREQ * WIDTH];
  int direction = 1;
  int gameOver = 0;
  srand(time(NULL));
  
  // Main game loop
  while (!gameOver) {
    // Update game objects
    int input = getchar();
    if (input == 'a') {
      update_ship(&ship, -SHIP_SPEED);
    } else if (input == 'd') {
      update_ship(&ship, SHIP_SPEED);
    } else if (input == ' ') {
      fire_shot(shots, ship);
    }
    move_aliens(aliens, direction);
    update_aliens(aliens, shots);
    update_shots(shots);
  
    // Check for game over condition
    if (ship.y == 0) {
      gameOver = 1;
    } else {
      // Print game board
      system("clear"); // Clear console
      print_board(ship, aliens, shots);
      usleep(100000); // Sleep for 100 milliseconds
    }
  }
  
  // Print game over message
  printf("\n\nGame over!\n");
  return 0;
}

// Print game board
void print_board(Object ship, Object* aliens, Object* shots) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int isShip = (x == ship.x && y == ship.y);
      int isAlien = 0;
      int isShot = 0;
      for (int i = 0; i < ALIEN_FREQ * WIDTH; i++) {
        if (x == aliens[i].x && y == aliens[i].y) {
          isAlien = 1;
        }
        if (shots[i].x == x && shots[i].y == y) {
          isShot = 1;
        }
      }
      if (isShip) {
        printf("X");
      } else if (isAlien) {
        printf("*");
      } else if (isShot) {
        printf("|");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Update ship position
void update_ship(Object* ship, int direction) {
  ship->x += direction;
  if (ship->x < 0) {
    ship->x = 0;
  } else if (ship->x >= WIDTH) {
    ship->x = WIDTH - 1;
  }
}

// Update aliens position and firing
void update_aliens(Object* aliens, Object* shots) {
  for (int i = 0; i < ALIEN_FREQ * WIDTH; i++) {
    if (aliens[i].y >= HEIGHT) {
      aliens[i].y = random_int(-HEIGHT);
    }
    if (shots[i].y == aliens[i].y && shots[i].x == aliens[i].x) {
      aliens[i].y = random_int(-HEIGHT);
      shots[i] = create_object(-1, -1);
    }
  }
}

// Update shot position
void update_shots(Object* shots) {
  for (int i = 0; i < ALIEN_FREQ * WIDTH; i++) {
    if (shots[i].y >= 0) {
      shots[i].y--;
    }
  }
}

// Fire a shot
void fire_shot(Object* shots, Object ship) {
  for (int i = 0; i < ALIEN_FREQ * WIDTH; i++) {
    if (shots[i].y < 0) {
      shots[i].x = ship.x;
      shots[i].y = ship.y - 1;
      break;
    }
  }
}

// Create a game object
Object create_object(int x, int y) {
  Object obj;
  obj.x = x;
  obj.y = y;
  return obj;
}

// Initialize aliens position
void init_aliens(Object* aliens) {
  for (int y = 0; y < ALIEN_FREQ; y++) {
    for (int x = 0; x < WIDTH; x++) {
      aliens[x + y * WIDTH] = create_object(x, -y);
    }
  }
}

// Move aliens horizontally
void move_aliens(Object* aliens, int direction) {
  for (int i = 0; i < ALIEN_FREQ * WIDTH; i++) {
    aliens[i].x += direction;
    if (aliens[i].x < 0 || aliens[i].x >= WIDTH) {
      direction = -direction;
      for (int j = 0; j < ALIEN_FREQ * WIDTH; j++) {
        aliens[j].y--;
      }
      break;
    }
  }
}

// Generate a random integer in range
int random_int(int range) {
  return rand() % range;
}