//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 60 /* Width of game board */
#define HEIGHT 20 /* Height of game board */
#define PADDLE_WIDTH 7 /* Width of paddle */
#define BALL_SPEED 75000 /* Speed of ball movement */
#define PADDLE_SPEED 1 /* Speed of paddle movement */
#define BRICK_ROWS 4 /* Rows of bricks */
#define BRICK_COLS 10 /* Columns of bricks */
#define NUM_BRICKS (BRICK_ROWS * BRICK_COLS) /* Total number of bricks */

enum direction { LEFT, UP_LEFT, RIGHT, UP_RIGHT };

struct ball {
  int x, y;
  enum direction dir;
};

struct paddle {
  int x, y;
};

struct brick {
  int x, y;
  int destroyed;
};

int getch(void) {
  struct termios oldt,
                 newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

void clear_screen(void) {
  printf("\033[2J\033[H");
}

void draw_board(struct ball ball, struct paddle paddle, struct brick bricks[NUM_BRICKS]) {
  int i, j;
  char board[HEIGHT][WIDTH];
  /* Initialize board array */
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      if(i == 0 || j == 0 || i == HEIGHT-1 || j == WIDTH-1) {
        board[i][j] = '#';
      } else {
        board[i][j] = ' ';
      }
    }
  }
  /* Draw bricks */
  for(i = 0; i < NUM_BRICKS; i++) {
    if(!bricks[i].destroyed) {
      board[bricks[i].y][bricks[i].x] = '|';
    }
  }
  /* Draw paddle */
  for(i = 0; i < PADDLE_WIDTH; i++) {
    board[paddle.y][paddle.x + i] = '=';
  }
  /* Draw ball */
  board[ball.y][ball.x] = 'o';
  /* Print board array */
  for(i = 0; i < HEIGHT; i++) {
    for(j = 0; j < WIDTH; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

void move_ball(struct ball *ball, struct paddle paddle, struct brick bricks[NUM_BRICKS]) {
  int i;
  /* Check for collision with walls */
  if(ball->x == 1 || ball->x == WIDTH - 2) {
    if(ball->dir == LEFT) {
      ball->dir = RIGHT;
    } else {
      ball->dir = LEFT;
    }
  } else if(ball->y == 1) {
    if(ball->dir == UP_LEFT) {
      ball->dir = UP_RIGHT;
    } else {
      ball->dir = RIGHT;
    }
  } else if(ball->y == HEIGHT - 2) {
    /* Game over */
    exit(0);
  }
  /* Check for collision with paddle */
  if(ball->y == paddle.y - 1 && ball->x >= paddle.x && ball->x <= paddle.x + PADDLE_WIDTH - 1) {
    if(ball->dir == UP_RIGHT) {
      ball->dir = UP_LEFT;
    } else {
      ball->dir = LEFT;
    }
  }
  /* Check for collision with bricks */
  for(i = 0; i < NUM_BRICKS; i++) {
    if(!bricks[i].destroyed && ball->y == bricks[i].y && ball->x == bricks[i].x) {
      if(ball->dir == UP_LEFT) {
        ball->dir = UP_RIGHT;
      } else {
        ball->dir = RIGHT;
      }
      bricks[i].destroyed = 1;
    }
  }
  /* Move ball */
  switch(ball->dir) {
    case LEFT:
      ball->x--;
      break;
    case UP_LEFT:
      ball->x--;
      ball->y--;
      break;
    case RIGHT:
      ball->x++;
      break;
    case UP_RIGHT:
      ball->x++;
      ball->y--;
      break;
  }
  usleep(BALL_SPEED);
}

void move_paddle(struct paddle *paddle) {
  char ch = getch();
  if(ch == 'a' && paddle->x > 1) {
    paddle->x -= PADDLE_SPEED;
  } else if(ch == 'd' && paddle->x < WIDTH - PADDLE_WIDTH - 1) {
    paddle->x += PADDLE_SPEED;
  }
}

int main(void) {
  struct ball ball = {WIDTH / 2, HEIGHT / 2, UP_LEFT};
  struct paddle paddle = {WIDTH / 2 - PADDLE_WIDTH / 2, HEIGHT - 2};
  struct brick bricks[NUM_BRICKS];
  int i, j;
  /* Initialize random number generator */
  srand(time(NULL));
  /* Initialize bricks */
  for(i = 0; i < BRICK_ROWS; i++) {
    for(j = 0; j < BRICK_COLS; j++) {
      bricks[i * BRICK_COLS + j].x = j * 6 + 2;
      bricks[i * BRICK_COLS + j].y = i + 2;
      bricks[i * BRICK_COLS + j].destroyed = 0;
    }
  }
  /* Main game loop */
  while(1) {
    clear_screen();
    draw_board(ball, paddle, bricks);
    move_paddle(&paddle);
    move_ball(&ball, paddle, bricks);
  }
  return 0;
}