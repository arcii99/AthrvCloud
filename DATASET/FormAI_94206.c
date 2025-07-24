//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30

typedef struct {
  int x;
  int y;
} Paddle;

typedef struct {
  int x;
  int y;
  int dirX;
  int dirY;
} Ball;

void draw(Paddle p1, Paddle p2, Ball ball) {
  int i, j;
  system("clear");
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      if (j == 0 || j == WIDTH-1) {
        printf("|");
      }
      else if (i == ball.y && j == ball.x) {
        printf("*");
      }
      else if (i == p1.y && j == p1.x) {
        printf("|");
      }
      else if (i == p2.y && j == p2.x) {
        printf("|");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void moveBall(Ball *ball) {
  int x = ball->x;
  int y = ball->y;
  int dirX = ball->dirX;
  int dirY = ball->dirY;

  x = x + dirX;
  y = y + dirY;

  // Ball hits ceiling or floor
  if (y == 0 || y == HEIGHT-1) {
    dirY = -dirY;
  }

  ball->x = x;
  ball->y = y;
  ball->dirX = dirX;
  ball->dirY = dirY;
}

void moveAIPaddle(Paddle *paddle, Ball *ball) {
  int paddleMiddle = paddle->y + 2;
  int ballMiddle = ball->y;
  int diff = ballMiddle - paddleMiddle;
  if (diff < 0) {
    paddle->y = paddle->y - 1;
  }
  else if (diff > 0) {
    paddle->y = paddle->y + 1;
  }
}

int checkCollision(Paddle p1, Paddle p2, Ball ball) {
  // Check if ball hits a paddle
  if (ball.x == p1.x && ball.y > p1.y && ball.y < p1.y+4) {
    return 1;
  }
  else if (ball.x == p2.x && ball.y > p2.y && ball.y < p2.y+4) {
    return 2;
  }
  return 0;
}

int main() {
  srand(time(NULL));
  Paddle p1 = {.x=1, .y=HEIGHT/2-2};
  Paddle p2 = {.x=WIDTH-2, .y=HEIGHT/2-2};
  Ball ball = {.x=WIDTH/2, .y=HEIGHT/2, .dirX=rand()%2==0?-1:1, .dirY=rand()%2==0?-1:1};

  while(1) {
    // Draw game board
    draw(p1, p2, ball);

    // Move ball
    moveBall(&ball);

    // Move AI paddle
    moveAIPaddle(&p2, &ball);

    // Check collision with paddles
    int collision = checkCollision(p1, p2, ball);
    if (collision == 1 || collision == 2) {
      ball.dirX = -ball.dirX;
    }

    // Check if ball hits walls
    if (ball.x == 0 || ball.x == WIDTH-1) {
      printf("Game Over\n");
      break;
    }

    // Sleep for 0.1 second
    usleep(100000);
  }

  return 0;
}