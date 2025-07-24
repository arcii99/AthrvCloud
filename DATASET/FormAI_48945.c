//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

typedef struct Brick {
  int x, y;
  int width, height;
  int hitpoints;
} Brick;

void draw_brick(Brick* b) {
  printf("\033[%d;%dH", b->y, b->x);
  printf("\033[48;5;%dm\033[38;5;%dm", b->hitpoints + 10, b->hitpoints + 10);
  for (int i = 0; i < b->height; ++i) {
    printf("\033[%d;%dH", b->y + i, b->x);
    for (int j = 0; j < b->width; ++j) {
      putchar(' ');
    }
  }
  printf("\033[0m");
}

int main() {
  srand(time(NULL));

  Brick bricks[6];
  for (int i = 0; i < 6; ++i) {
    bricks[i].x = rand() % (WIDTH - 4) + 2;
    bricks[i].y = rand() % (HEIGHT - 10) + 2;
    bricks[i].width = rand() % 5 + 3;
    bricks[i].height = rand() % 2 + 1;
    bricks[i].hitpoints = rand() % 6 + 1;
  }

  int ballx = rand() % WIDTH + 1;
  int bally = HEIGHT - 3;
  int ballvx = 1;
  int ballvy = -1;

  while (1) {
    printf("\033[2J");
    printf("\033[H");
    for (int i = 0; i < 6; ++i) {
      draw_brick(&bricks[i]);
    }
    printf("\033[%d;%dH", bally, ballx);
    putchar('O');
    fflush(stdout);

    if (ballx + ballvx >= WIDTH || ballx + ballvx <= 0) {
      ballvx = -ballvx;
    }
    if (bally + ballvy <= 0) {
      ballvy = -ballvy;
    }
    if (bally + ballvy >= HEIGHT - 1) {
      break;
    }

    for (int i = 0; i < 6; ++i) {
      if (bricks[i].hitpoints > 0 && ballx >= bricks[i].x && ballx <= bricks[i].x + bricks[i].width && bally >= bricks[i].y && bally <= bricks[i].y + bricks[i].height) {
        bricks[i].hitpoints -= 1;
        ballvy = -ballvy;
        if (bricks[i].hitpoints == 0) {
          printf("\033[%d;%dH", bricks[i].y, bricks[i].x);
          putchar(' ');
          fflush(stdout);
        }
      }
    }

    ballx += ballvx;
    bally += ballvy;
    usleep(50000);
  }

  printf("\033[%d;0H", HEIGHT + 1);
  return 0;
}