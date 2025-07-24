//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

typedef struct {
  int x, y;
} Position;

typedef struct {
  Position pos;
  int health, attack;
} Entity;

typedef struct {
  Position pos;
  char enemyChar;
  int health, attack;
} Enemy;

typedef struct {
  char map[HEIGHT][WIDTH];
  Entity player;
  Enemy enemies[10];
  int numEnemies;
} GameState;

// Generating a random position
Position randPos() {
  Position pos = {rand() % WIDTH, rand() % HEIGHT};
  return pos;
}

// Moving entity function
void moveEntity(Entity* entity, int x, int y) {
  entity->pos.x += x;
  entity->pos.y += y;
}

// Check if the entity is colliding with another entity
int isColliding(Entity *entity, Entity *otherEntity) {
  if (entity->pos.x == otherEntity->pos.x && entity->pos.y == otherEntity->pos.y) {
    return 1;
  }

  return 0;
}

// Initializes the game state
void init(GameState* state) {
  // Set map to all empty spaces
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      state->map[i][j] = ' ';
    }
  }

  // Add player at random position
  state->player.pos = randPos();
  state->player.health = 5;
  state->player.attack = 1;

  // Add enemies to random positions
  state->numEnemies = 3 + (rand() % 8);

  for (int i = 0; i < state->numEnemies; i++) {
    Enemy enemy;
    enemy.health = 2;
    enemy.attack = 1;
    enemy.enemyChar = 'e';
    enemy.pos = randPos();
    state->enemies[i] = enemy;
  }
}

// Draw the game state
void draw(GameState* state) {
  // Clear console
  system("clear");

  // Draw map
  printf(" ");
  for (int i = 0; i < WIDTH; i++) {
    printf("_");
  }

  printf("\n");

  for (int i = 0; i < HEIGHT; i++) {
    printf("|");

    for (int j = 0; j < WIDTH; j++) {
      if (state->player.pos.x == j && state->player.pos.y == i) {
        printf("@");
      } else {
        int enemyDrawn = 0;

        for (int k = 0; k < state->numEnemies; k++) {
          if (state->enemies[k].pos.x == j && state->enemies[k].pos.y == i) {
            printf("%c", state->enemies[k].enemyChar);
            enemyDrawn = 1;

            break;
          }
        }

        if (!enemyDrawn) {
          printf("%c", state->map[i][j]);
        }
      }
    }

    printf("|\n");
  }

  printf(" ");
  for (int i = 0; i < WIDTH; i++) {
    printf("-");
  }

  printf("\n");

  // Draw player stats
  printf("HP: %d\n", state->player.health);
  printf("Attack: %d\n", state->player.attack);
  printf("Number of enemies: %d\n", state->numEnemies);
}

// Move player function
void movePlayer(GameState* state, int x, int y) {
  int newX = state->player.pos.x + x;
  int newY = state->player.pos.y + y;

  // Check if move is out of bounds
  if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
    return;
  }

  // Check if move is colliding with enemy
  for (int i = 0; i < state->numEnemies; i++) {
    Enemy* enemy = &state->enemies[i];

    if (isColliding(&state->player, enemy)) {
      state->player.health -= enemy->attack;

      if (state->player.health <= 0) {
        printf("You died!\n");
        exit(0);
      }

      return;
    }
  }

  // Update player position
  moveEntity(&state->player, x, y);
}

// Move enemies function
void moveEnemies(GameState* state) {
  for (int i = 0; i < state->numEnemies; i++) {
    Enemy* enemy = &state->enemies[i];

    // Calculate direction
    int dirX = 0;
    int dirY = 0;

    if (state->player.pos.x < enemy->pos.x) {
      dirX = -1;
    } else if (state->player.pos.x > enemy->pos.x) {
      dirX = 1;
    }

    if (state->player.pos.y < enemy->pos.y) {
      dirY = -1;
    } else if (state->player.pos.y > enemy->pos.y) {
      dirY = 1;
    }

    // Check if move is out of bounds
    int newX = enemy->pos.x + dirX;
    int newY = enemy->pos.y + dirY;

    if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
      continue;
    }

    // Check if move is colliding with player
    if (isColliding(&state->player, enemy)) {
      state->player.health -= enemy->attack;

      if (state->player.health <= 0) {
        printf("You died!\n");
        exit(0);
      }

      continue;
    }

    // Check if move is colliding with another enemy
    int enemyCollision = 0;

    for (int j = 0; j < state->numEnemies; j++) {
      if (i == j) {
        continue;
      }

      if (isColliding(enemy, &state->enemies[j])) {
        enemyCollision = 1;
        break;
      }
    }

    if (enemyCollision) {
      continue;
    }

    // Update enemy position
    moveEntity(enemy, dirX, dirY);
  }
}

// Main function
int main() {
  // Seed random number generator
  srand(time(NULL));

  // Initialize game state
  GameState state;
  init(&state);

  // Main game loop
  while (1) {
    // Draw game state
    draw(&state);

    // Move enemies
    moveEnemies(&state);

    // Get player input
    char input = getchar();

    switch (input) {
      case 'w': movePlayer(&state, 0, -1); break;
      case 'a': movePlayer(&state, -1, 0); break;
      case 's': movePlayer(&state, 0, 1); break;
      case 'd': movePlayer(&state, 1, 0); break;
    }
  }

  return 0;
}