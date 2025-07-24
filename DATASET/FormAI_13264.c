//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: scientific
// Space Invaders Game Clone Program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40
#define LEFT_LIMIT 1
#define RIGHT_LIMIT SCREEN_WIDTH - 2
#define TOP_LIMIT 1
#define BOTTOM_LIMIT SCREEN_HEIGHT - 2

// Structures
struct Point {
  int x;
  int y;
};

struct SpaceShip {
  struct Point position;
  int health;
};

struct Enemy {
  struct Point position;
  int health;
  bool alive;
};

// Function Prototypes
void draw_screen(struct SpaceShip player, struct Enemy enemies[], int num_enemies, int score);
void move_player(struct SpaceShip* player, char direction);
void spawn_enemies(struct Enemy enemies[], int num_enemies);
void move_enemies(struct Enemy enemies[], int num_enemies);
void shoot_enemy(struct Enemy* enemy);
bool check_enemies_alive(struct Enemy enemies[], int num_enemies);
void update_score(int* score, int level);
void game_over();

// Main Function
int main() {
  srand(time(NULL)); // Initialize random seed
  char player_move;
  int level = 1, score = 0, enemy_speed = 1;
  const int num_enemies = 20;
  struct SpaceShip player = { {SCREEN_WIDTH/2, SCREEN_HEIGHT - 2}, 3 };
  struct Enemy enemies[num_enemies];
  spawn_enemies(enemies, num_enemies);
  bool game_running = true;
  
  while(game_running) {
    draw_screen(player, enemies, num_enemies, score);
    player_move = getchar();
    move_player(&player, player_move);
    move_enemies(enemies, num_enemies);
    
    // Enemy Shooting
    int enemy_shot_index = rand() % num_enemies;
    if(enemies[enemy_shot_index].alive) {
      shoot_enemy(&enemies[enemy_shot_index]);
    }
    
    // Game over condition
    if(player.health <= 0 || !check_enemies_alive(enemies, num_enemies)) {
      game_running = false;
      break;
    }
    
    // Level complete condition
    if(score >= level * 50) {
      level++;
      enemy_speed++;
      update_score(&score, level);
    }
  }
  
  draw_screen(player, enemies, num_enemies, score);
  game_over();
  return 0;
}

// Function Definitions
void draw_screen(struct SpaceShip player, struct Enemy enemies[], int num_enemies, int score) {
  printf("\033[2J"); // Clear screen command
  printf("\033[%d;%dH", 1, 1); // Move cursor to top-left of screen
  printf("Score: %d\n", score);
  printf("Health: %d\n", player.health);
  
  // Draw player
  printf("\033[%d;%dH", player.position.y, player.position.x);
  printf("^");
  
  // Draw enemies
  for(int i = 0; i < num_enemies; i++) {
    if(enemies[i].alive) {
      printf("\033[%d;%dH", enemies[i].position.y, enemies[i].position.x);
      printf("O");
    }
  }
  
  fflush(stdout); // Flush output to terminal
}

void move_player(struct SpaceShip* player, char direction) {
  switch(direction) {
    case 'a':
    case 'A':
      if(player->position.x > LEFT_LIMIT)
        player->position.x--;
      break;
    case 'd':
    case 'D':
      if(player->position.x < RIGHT_LIMIT)
        player->position.x++;
      break;
    default:
      break;
  }
}

void spawn_enemies(struct Enemy enemies[], int num_enemies) {
  int x_pos = 5, y_pos = 3;
  for(int i = 0; i < num_enemies; i++) {
    enemies[i].position.x = x_pos;
    enemies[i].position.y = y_pos;
    enemies[i].health = 1;
    enemies[i].alive = true;
    x_pos += 5;
    if(x_pos > RIGHT_LIMIT) {
      x_pos = 5;
      y_pos += 2;
    }
  }
}

void move_enemies(struct Enemy enemies[], int num_enemies) {
  for(int i = 0; i < num_enemies; i++) {
    if(enemies[i].alive) {
      enemies[i].position.y++;
      if(enemies[i].position.y >= BOTTOM_LIMIT) {
        enemies[i].alive = false;
      }
    }
  }
}

void shoot_enemy(struct Enemy* enemy) {
  enemy->health--;
  if(enemy->health <= 0) {
    enemy->alive = false;
  }
}

bool check_enemies_alive(struct Enemy enemies[], int num_enemies) {
  for(int i = 0; i < num_enemies; i++) {
    if(enemies[i].alive) {
      return true;
    }
  }
  return false;
}

void update_score(int* score, int level) {
  *score += level * 10;
}

void game_over() {
  printf("\033[%d;%dH", SCREEN_HEIGHT/2, SCREEN_WIDTH/2 - 5);
  printf("Game Over!");
}