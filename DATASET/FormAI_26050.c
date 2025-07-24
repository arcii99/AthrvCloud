//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

char screen[SCREEN_WIDTH * SCREEN_HEIGHT];

enum Direction {LEFT, RIGHT};

struct Player {
  int x, y;
} player;

struct Enemy {
  int x, y;
  bool alive;
} enemies[SCREEN_WIDTH];

int score = 0;

void init() {
  srand(time(NULL));
  player.x = SCREEN_WIDTH / 2;
  player.y = SCREEN_HEIGHT - 1;

  for (int i = 0; i < SCREEN_WIDTH; i++) {
    enemies[i].x = i;
    enemies[i].y = 0;
    enemies[i].alive = true;
  }
}

void draw_player() {
  screen[player.y * SCREEN_WIDTH + player.x] = 'P';
}

void draw_enemies() {
  for (int i = 0; i < SCREEN_WIDTH; i++) {
    if (enemies[i].alive) {
      screen[enemies[i].y * SCREEN_WIDTH + enemies[i].x] = 'E';
    }
  }
}

void draw_screen() {
  system("clear");
  for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
    if (i % SCREEN_WIDTH == 0) {
      printf("\n");
    }
    printf("%c", screen[i]);
  }
  printf("\nScore: %d", score);
}

void move_player(enum Direction direction) {
  if (direction == LEFT) {
    player.x--;
  } else if (direction == RIGHT) {
    player.x++;
  }
  if (player.x < 0) {
    player.x = 0;
  } else if (player.x >= SCREEN_WIDTH) {
    player.x = SCREEN_WIDTH - 1;
  }
}

void move_enemies() {
  for (int i = 0; i < SCREEN_WIDTH; i++) {
    if (enemies[i].alive) {
      enemies[i].y++;
      if (enemies[i].y == player.y && enemies[i].x == player.x) {
        printf("\n\nRomeo: Oh my dear Juliet, I'm hit!\nJuliet: No, my love! Stay with me...\n\nGAME OVER\n\n");
        exit(0);
      } else if (enemies[i].y >= SCREEN_HEIGHT) {
        enemies[i].alive = false;
      }
    }
  }
}

bool check_win() {
  int alive_count = 0;
  for (int i = 0; i < SCREEN_WIDTH; i++) {
    if (enemies[i].alive) {
      alive_count++;
    }
  }
  return alive_count == 0;
}

int main() {
  init();
  draw_player();

  while (1) {
    char input = getchar();
    if (input == 'a' || input == 'A') {
      move_player(LEFT);
    } else if (input == 'd' || input == 'D') {
      move_player(RIGHT);
    }

    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
      screen[i] = ' ';
    }

    draw_player();
    draw_enemies();
    draw_screen();
    move_enemies();
    score++;

    if (check_win()) {
      printf("\n\nRomeo: My love, we did it! The enemy is vanquished!\nJuliet: Oh Romeo, I knew we could do it!\nFinal score: %d", score);
      return 0;
    }
  }

  return 0;
}