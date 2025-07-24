//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 80
#define HEIGHT 30
#define PADDLE_WIDTH 5

// function to get keyboard input
int kbhit(void) {
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

  if(ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

// function to initialize the paddle in the middle of the screen
void init_paddle(int paddle[], int paddle_width) {
  for (int i = 0; i < paddle_width; i++) {
    paddle[i] = (WIDTH / 2) - (paddle_width / 2) + i;
  }
}

// function to draw the paddle on the screen
void draw_paddle(int paddle[], int paddle_width, char screen[][WIDTH]) {
  for (int i = 0; i < paddle_width; i++) {
    screen[HEIGHT - 2][paddle[i]] = '=';
  }
}

// function to move the paddle left
void move_paddle_left(int paddle[]) {
  if (paddle[0] > 0) {
    for (int i = 0; i < PADDLE_WIDTH; i++) {
      paddle[i]--;
    }
  }
}

// function to move the paddle right
void move_paddle_right(int paddle[]) {
  if (paddle[PADDLE_WIDTH - 1] < WIDTH - 1) {
    for (int i = 0; i < PADDLE_WIDTH; i++) {
      paddle[i]++;
    }
  }
}

// function to initialize the ball at the top of the screen
void init_ball(int ball[]) {
  ball[0] = WIDTH / 2;
  ball[1] = 2;
}

// function to draw the ball on the screen
void draw_ball(int ball[], char screen[][WIDTH]) {
  screen[ball[1]][ball[0]] = '@';
}

// function to move the ball
void move_ball(int ball[], int x_direction, int y_direction) {
  ball[0] += x_direction;
  ball[1] += y_direction;
}

// function to check for collision with the paddle
bool check_paddle_collision(int ball[], int paddle[]) {
  if (ball[1] == HEIGHT - 2) {
    for (int i = 0; i < PADDLE_WIDTH; i++) {
      if (ball[0] == paddle[i]) {
        return true;
      }
    }
  }
  return false;
}

// function to check for collision with the walls
int check_wall_collision(int ball[], int x_direction, int y_direction) {
  int result = 0;
  if (ball[0] == 0 && x_direction == -1) {
    result = 1; // hit left wall
  } else if (ball[0] == WIDTH - 1 && x_direction == 1) {
    result = 2; // hit right wall
  } else if (ball[1] == 0) {
    result = 3; // hit top wall
  } else if (ball[1] == HEIGHT - 1) {
    result = 4; // hit bottom wall (lose game)
  }
  if (result != 0) {
    move_ball(ball, -x_direction, -y_direction);
  }
  return result;
}

int main() {
  // initialize game variables
  char screen[HEIGHT][WIDTH];
  int paddle[PADDLE_WIDTH];
  int ball[2]; // x, y coordinates of ball
  int x_direction = 1;
  int y_direction = 1;
  int score = 0;
  bool game_over = false;
  int ch;

  // initialize paddle and ball
  init_paddle(paddle, PADDLE_WIDTH);
  init_ball(ball);

  // initialize screen with spaces
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      screen[i][j] = ' ';
    }
  }

  // draw starting screen
  draw_paddle(paddle, PADDLE_WIDTH, screen);
  draw_ball(ball, screen);
  printf("\033[2J"); // clear screen
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", screen[i][j]);
    }
    printf("\n");
  }
  printf("Use left and right arrow keys to move paddle.\n");

  // main game loop
  while (!game_over) {
    // move paddle if left or right arrow key is pressed
    if (kbhit()) {
      ch = getchar();
      switch (ch) {
        case 68:
          move_paddle_left(paddle);
          break;
        case 67:
          move_paddle_right(paddle);
          break;
      }
    }

    // move ball and check for collisions
    int collision_result = check_wall_collision(ball, x_direction, y_direction);
    if (collision_result != 0) {
      if (collision_result == 2 || collision_result == 1) {
        x_direction *= -1;
      } else if (collision_result == 3) {
        y_direction *= -1;
      } else if (collision_result == 4) {
        game_over = true;
        printf("\033[2J"); // clear screen
        printf("Game over! You scored %d points.\n", score);
      }
    } else if (check_paddle_collision(ball, paddle)) { // hit paddle
      y_direction *= -1;
      score++;
    }
    move_ball(ball, x_direction, y_direction);

    // update screen
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        screen[i][j] = ' ';
      }
    }
    draw_paddle(paddle, PADDLE_WIDTH, screen);
    draw_ball(ball, screen);
    printf("\033[0;0H"); // move cursor to top left corner of screen
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        printf("%c", screen[i][j]);
      }
      printf("\n");
    }
    printf("Score: %d\n", score);

    usleep(100000); // sleep for a short time to slow down game
  }

  return 0;
}