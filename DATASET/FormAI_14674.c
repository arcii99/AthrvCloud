//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_SHOTS 10
#define MAX_ALIENS 30

enum Direction { LEFT, RIGHT, UP, DOWN };

typedef struct { int x, y; } Point;

typedef struct {
  Point position;
  bool active;
} Shot;

typedef struct {
  Point position;
  enum Direction direction;
  bool active;
} Alien;

typedef struct { int score, level; } GameStatus;

typedef struct {
  Point position;
  int lives;
} Player;

static struct termios original_termios;

void reset_terminal_mode() {
  tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
}

void set_conio_terminal_mode() {
  struct termios new_termios;

  tcgetattr(STDIN_FILENO, &original_termios);
  atexit(reset_terminal_mode);

  new_termios = original_termios;
  new_termios.c_lflag &= ~(ECHO | ICANON);
  new_termios.c_cc[VMIN] = 0;
  new_termios.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

char get_key() {
  char c;
  fd_set set;
  struct timeval timeout;

  FD_ZERO(&set);
  FD_SET(STDIN_FILENO, &set);

  timeout.tv_sec = 0;
  timeout.tv_usec = 0;

  select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);
  if (FD_ISSET(STDIN_FILENO, &set)) {
    c = getchar();
  } else {
    c = '\0';
  }

  return c;
}

void print_spaces(int num) {
  for (int i = 0; i < num; ++i) {
    printf(" ");
  }
}

void print_alien(Alien *alien) {
  printf("A");
}

void print_player(Player *player) {
  printf("V");
}

void print_shot(Shot *shot) {
  printf("|");
}

void print_game_status(GameStatus *status) {
  printf("Score: %d    Level: %d\n", status->score, status->level);
}

void init_shots(Shot shots[]) {
  for (int i = 0; i < MAX_SHOTS; ++i) {
    shots[i].active = false;
  }
}

void init_aliens(Alien aliens[]) {
  for (int i = 0; i < MAX_ALIENS; ++i) {
    aliens[i].active = false;
  }
}

void init_game_status(GameStatus *status) {
  status->score = 0;
  status->level = 1;
}

void init_player(Player *player) {
  player->position.x = WIDTH / 2;
  player->position.y = HEIGHT - 2;
  player->lives = 3;
}

void move_alien(Alien *alien, Point *delta) {
  alien->position.x += delta->x;
  alien->position.y += delta->y;
}

void move_player(Player *player, char direction) {
  if (direction == 'a' && player->position.x > 0) {
    --player->position.x;
  } else if (direction == 'd' && player->position.x < WIDTH - 1) {
    ++player->position.x;
  }
}

void move_shot(Shot *shot, Point *delta) {
  shot->position.x += delta->x;
  shot->position.y += delta->y;
}

bool fire_shot(Shot shots[], Point point) {
  for (int i = 0; i < MAX_SHOTS; ++i) {
    if (!shots[i].active) {
      shots[i].position = point;
      shots[i].active = true;
      return true;
    }
  }

  return false;
}

bool aliens_at_bottom(Alien aliens[]) {
  for (int i = 0; i < MAX_ALIENS; ++i) {
    if (aliens[i].active && aliens[i].position.y >= HEIGHT - 3) {
      return true;
    }
  }

  return false;
}

bool aliens_destroyed(Alien aliens[]) {
  for (int i = 0; i < MAX_ALIENS; ++i) {
    if (aliens[i].active) {
      return false;
    }
  }

  return true;
}

bool collision(Point a, Point b) {
  return a.x == b.x && a.y == b.y;
}

void update_game_state(Player *player, Alien aliens[], Shot shots[], GameStatus *status, char key) {
  Point shot_delta = { 0, -1 };
  Point alien_delta = { 1, 0 };

  switch (key) {
    case ' ':
      fire_shot(shots, player->position);
      break;

    case 'a':
    case 'd':
      move_player(player, key);
      break;
  }

  for (int i = 0; i < MAX_ALIENS; ++i) {
    if (aliens[i].active) {
      move_alien(&aliens[i], &alien_delta);
    }
  }

  for (int i = 0; i < MAX_SHOTS; ++i) {
    if (shots[i].active) {
      move_shot(&shots[i], &shot_delta);
    }
  }

  for (int i = 0; i < MAX_SHOTS; ++i) {
    if (shots[i].active) {
      for (int j = 0; j < MAX_ALIENS; ++j) {
        if (aliens[j].active && collision(shots[i].position, aliens[j].position)) {
          shots[i].active = false;
          aliens[j].active = false;
          status->score += 10;
        }
      }
    }
  }

  for (int i = 0; i < MAX_ALIENS; ++i) {
    if (aliens[i].active && collision(aliens[i].position, player->position)) {
      player->lives -= 1;
      aliens[i].active = false;
      if (player->lives <= 0) {
        printf("\nGame Over!\n");
        exit(0);
      }
    }
  }

  if (aliens_at_bottom(aliens)) {
    printf("\nGame Over!\n");
    exit(0);
  }

  if (aliens_destroyed(aliens)) {
    init_aliens(aliens);
    status->level += 1;
  }
}

void draw_game_board(Player *player, Alien aliens[], Shot shots[], GameStatus *status) {
  for (int i = 0; i < HEIGHT; ++i) {
    print_spaces(WIDTH);
    printf("\n");
  }

  for (int i = 0; i < MAX_SHOTS; ++i) {
    if (shots[i].active) {
      print_spaces(shots[i].position.x);
      print_shot(&shots[i]);
      printf("\n");
    }
  }

  for (int i = 0; i < MAX_ALIENS; ++i) {
    if (aliens[i].active) {
      print_spaces(aliens[i].position.x);
      print_alien(&aliens[i]);
      printf("\n");
    }
  }

  print_spaces(player->position.x);
  print_player(player);
  printf("\n");

  print_game_status(status);
}

int main() {
  char key;
  Player player;
  Alien aliens[MAX_ALIENS];
  Shot shots[MAX_SHOTS];
  GameStatus status;
  set_conio_terminal_mode();
  init_shots(shots);
  init_game_status(&status);
  srand(time(NULL));

  while (true) {
    key = get_key();
    draw_game_board(&player, aliens, shots, &status);
    update_game_state(&player, aliens, shots, &status, key);
    usleep(50000);
  }

  return 0;
}