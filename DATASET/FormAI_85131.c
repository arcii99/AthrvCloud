//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define BOARD_WIDTH 70
#define BOARD_HEIGHT 20
#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 2
#define BULLET_WIDTH 1
#define BULLET_HEIGHT 1
#define ENEMY_WIDTH 4
#define ENEMY_HEIGHT 2

struct termios orig_termios;

void disable_raw_mode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disable_raw_mode);

  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

struct bullet {
  int x;
  int y;
  int active;
};

struct player {
  int x;
  int y;
  int score;
};

struct enemy {
  int x;
  int y;
  int direction;
  int active;
};

void print_board(char board[][BOARD_WIDTH]) {
  system("clear");
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

void initialize_board(char board[][BOARD_WIDTH]) {
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      if (j == 0 || j == BOARD_WIDTH-1 || i == 0 || i == BOARD_HEIGHT-1) {
        board[i][j] = '#';
      } else {
        board[i][j] = ' ';
      }
    }
  }
}

void initialize_player(struct player *p) {
  p->x = BOARD_WIDTH/2 - PLAYER_WIDTH/2;
  p->y = BOARD_HEIGHT - PLAYER_HEIGHT - 1;
  p->score = 0;
}

void print_player(char board[][BOARD_WIDTH], struct player *p) {
  for (int i = 0; i < PLAYER_HEIGHT; i++) {
    for (int j = 0; j < PLAYER_WIDTH; j++) {
      board[p->y + i][p->x + j] = '=';
    }
  }
}

struct bullet initialize_bullet(struct player *p) {
  struct bullet b;
  b.x = p->x + PLAYER_WIDTH/2 - BULLET_WIDTH/2;
  b.y = p->y - 1;
  b.active = 1;
  return b;
}

void print_bullets(char board[][BOARD_WIDTH], struct bullet bullets[]) {
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      if (board[i][j] == '-') {
        board[i][j] = ' ';
      }
    }
  }

  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      for (int k = 0; k < 50; k++) {
        if (bullets[k].active && bullets[k].x == j && bullets[k].y == i) {
          board[i][j] = '-';
        }
      }
    }
  }
}

void move_bullets(struct bullet bullets[]) {
  for (int i = 0; i < 50; i++) {
    if (bullets[i].active) {
      bullets[i].y--;
      if (bullets[i].y <= 0) {
        bullets[i].active = 0;
      }
    }
  }
}

int initialize_enemies(struct enemy enemies[][10]) {
  srand(time(NULL));
  int count = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      struct enemy e;
      e.x = j*ENEMY_WIDTH + 1;
      e.y = i*ENEMY_HEIGHT + 2;
      e.direction = 1;
      e.active = 1;
      enemies[i][j] = e;
      count++;
    }
  }
  return count;
}

void print_enemies(char board[][BOARD_WIDTH], struct enemy enemies[][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      if (enemies[i][j].active) {
        for (int k = 0; k < ENEMY_HEIGHT; k++) {
          for (int l = 0; l < ENEMY_WIDTH; l++) {
            if (i == 0) {
              board[enemies[i][j].y + k][enemies[i][j].x + l] = '*';
            } else if (i == 1 || i == 2) {
              if (l == 0 || l == 3) {
                board[enemies[i][j].y + k][enemies[i][j].x + l] = '*';
              } else {
                board[enemies[i][j].y + k][enemies[i][j].x + l] = '#';
              }
            } else {
              if (l == 1 || l == 2) {
                board[enemies[i][j].y + k][enemies[i][j].x + l] = '#';
              } else {
                board[enemies[i][j].y + k][enemies[i][j].x + l] = '*';
              }
            }
          }
        }
      }
    }
  }
}

int move_enemies(struct enemy enemies[][10]) {
  int lowest_row = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      if (enemies[i][j].active) {
        if (enemies[i][j].x <= 1 || enemies[i][j].x >= BOARD_WIDTH - ENEMY_WIDTH - 1) {
          for (int k = 0; k < 5; k++) {
            for (int l = 0; l < 10; l++) {
              enemies[k][l].direction = -enemies[k][l].direction;
              enemies[k][l].y++;
            }
          }
          return 1;
        } else {
          enemies[i][j].x += enemies[i][j].direction;
          if (enemies[i][j].y >= lowest_row) {
            lowest_row = enemies[i][j].y;
          }
        }
      }
    }
  }
  return lowest_row;
}

int check_collisions(struct bullet bullets[], struct enemy enemies[][10]) {
  int score = 0;
  for (int i = 0; i < 50; i++) {
    if (bullets[i].active) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 10; k++) {
          if (enemies[j][k].active && bullets[i].y == enemies[j][k].y + ENEMY_HEIGHT-1 && bullets[i].x >= enemies[j][k].x && bullets[i].x < enemies[j][k].x + ENEMY_WIDTH) {
            bullets[i].active = 0;
            enemies[j][k].active = 0;
            score++;
          }
        }
      }
    }
  }
  return score;
}

int check_player_collision(struct player *p, struct enemy enemies[][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      if (enemies[i][j].active && p->y <= enemies[i][j].y + ENEMY_HEIGHT-1 && p->x + PLAYER_WIDTH-1 >= enemies[i][j].x && p->x <= enemies[i][j].x + ENEMY_WIDTH-1) {
        return 1;
      }
    }
  }
  return 0;
}

void print_score(struct player *p) {
  printf("Score: %d\n", p->score);
}

int get_key_pressed() {
  fd_set set;
  struct timeval timeout = {0, 0};

  FD_ZERO(&set);
  FD_SET(STDIN_FILENO, &set);

  int rv = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);
  if(rv == -1) {
    return -1;
  } else if(rv == 0) {
    return -2;
  } else {
    char c;
    read(STDIN_FILENO, &c, 1);
    return c;
  }
}

int main() {
  enable_raw_mode();

  char board[BOARD_HEIGHT][BOARD_WIDTH];
  initialize_board(board);

  struct player p;
  initialize_player(&p);

  struct bullet bullets[50];
  for (int i = 0; i < 50; i++) {
    bullets[i].active = 0;
  }

  struct enemy enemies[5][10];
  int enemy_count = initialize_enemies(enemies);

  int game_over = 0;
  int count = 0;
  while (!game_over) {
    print_board(board);
    if (count % 2 == 0) {
      int key = get_key_pressed();
      if (key == 'a' && p.x > 1) {
        p.x--;
      } else if (key == 'd' && p.x < BOARD_WIDTH - PLAYER_WIDTH - 1) {
        p.x++;
      } else if (key == ' ') {
        for (int i = 0; i < 50; i++) {
          if (!bullets[i].active) {
            bullets[i] = initialize_bullet(&p);
            break;
          }
        }
      }
    }

    print_player(board, &p);
    print_bullets(board, bullets);
    move_bullets(bullets);
    print_enemies(board, enemies);

    if (count % 10 == 0) {
      int lowest_row = move_enemies(enemies);
      if (lowest_row >= p.y) {
        game_over = 1;
      }
    }

    p.score += check_collisions(bullets, enemies);

    print_score(&p);

    if (check_player_collision(&p, enemies)) {
      game_over = 1;
    }

    count++;
    usleep(16667);
  }

  printf("Game Over!\n");

  disable_raw_mode();

  return 0;
}