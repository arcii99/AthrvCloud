//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <time.h>

#define HEIGHT 24
#define WIDTH 80
#define PADDLE_LEN 5
#define BALL_X_MAX WIDTH - 3
#define BALL_Y_MAX HEIGHT - 2
#define INIT_BALL_X BALL_X_MAX / 2
#define INIT_BALL_Y BALL_Y_MAX / 2

#define SLEEP_TIME 50000

int ball_dir_x, ball_dir_y;
int ball_x, ball_y;
int paddle1_x, paddle1_y; // player paddle position
int paddle2_x, paddle2_y; // AI paddle position
int score1, score2;
int quit;

int kbhit() {
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

void setup() {
  ball_x = INIT_BALL_X;
  ball_y = INIT_BALL_Y;

  score1 = 0;
  score2 = 0;

  ball_dir_x = -1 + 2 * (rand() % 2);
  ball_dir_y = -1;

  paddle1_x = WIDTH / 2 - 3;
  paddle2_x = WIDTH / 2 - 3;

  paddle1_y = HEIGHT - 2;
  paddle2_y = 1;
}

void draw() {
  int i, j;

  system("clear");

  // draw top border
  for (i = 0; i < WIDTH; i++) {
    printf("#");
  }
  printf("\n");

  // draw playing field
  for (i = 0; i < HEIGHT - 2; i++) {
    printf("|");

    for (j = 0; j < WIDTH - 2; j++) {
      if (i == ball_y && j == ball_x) {
        printf("O");
        continue;
      }

      if (i == paddle1_y && j >= paddle1_x && j < paddle1_x + PADDLE_LEN) {
        printf("="); // player paddle
        continue;
      }

      if (i == paddle2_y && j >= paddle2_x && j < paddle2_x + PADDLE_LEN) {
        printf("="); // AI paddle
        continue;
      }

      printf(" ");
    }

    printf("|\n");
  }

  // draw bottom border
  for (i = 0; i < WIDTH; i++) {
    printf("#");
  }
  printf("\n");

  printf("Score: %d - %d\n", score1, score2);
}

void input() {
  if (kbhit()) {
    char c = getchar();

    if (c == 'a' && paddle1_x > 0) {
      paddle1_x--;
    }

    if (c == 'd' && paddle1_x < WIDTH - 1 - PADDLE_LEN) {
      paddle1_x++;
    }

    if (c == 'q') {
      quit = 1;
    }
  }
}

void logic() {
  // move ball
  ball_x += ball_dir_x;
  ball_y += ball_dir_y;

  // bounce ball off walls and paddles
  if (ball_x < 1) {
    ball_x = 1;
    ball_dir_x = -ball_dir_x;
  }

  if (ball_x > BALL_X_MAX) {
    ball_x = BALL_X_MAX;
    ball_dir_x = -ball_dir_x;
  }

  if (ball_y < 1) {
    ball_y = 1;
    ball_dir_y = -ball_dir_y;
  }

  if (ball_y > BALL_Y_MAX) {
    ball_y = BALL_Y_MAX;
    ball_dir_y = -ball_dir_y;

    // check if ball is missed by player paddle
    if (ball_x < paddle1_x || ball_x >= paddle1_x + PADDLE_LEN) {
      score2++;
      setup();
    }
  }

  // move AI paddle
  if (ball_y < paddle2_y && paddle2_x > 0) {
    paddle2_x--;
  }

  if (ball_y < paddle2_y && paddle2_x < WIDTH - 1 - PADDLE_LEN) {
    paddle2_x++;
  }

  // bounce ball off AI paddle
  if (ball_x > paddle2_x - 1 && ball_x <= paddle2_x + PADDLE_LEN &&
      ball_y == paddle2_y - 1) {
    ball_dir_y = -ball_dir_y;
  }

  // check if ball is missed by AI paddle
  if (ball_y == BALL_Y_MAX && ball_x >= paddle1_x && ball_x < paddle1_x + PADDLE_LEN) {
    score1++;
    setup();
  }
}

int main() {
  srand(time(NULL));

  signal(SIGINT, SIG_IGN);

  struct timespec ts = {0, SLEEP_TIME};

  setup();

  while (!quit) {
    draw();
    input();
    logic();

    nanosleep(&ts, NULL);
  }

  return 0;
}