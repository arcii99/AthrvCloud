//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 3
#define PADDLE_DISTANCE_FROM_SIDE 3
#define BALL_SIZE 2

int main() {
  char ch = ' ';

  // hide the cursor
  printf("\e[?25l");

  // do not wait for input
  system("stty -echo");
  system("stty cbreak");

  // move the cursor to the top left corner
  printf("\e[1;1H");

  // set the initial positions of the paddles and the ball
  int paddle1_x = PADDLE_DISTANCE_FROM_SIDE;
  int paddle1_y = 10;
  int paddle2_x = 81 - PADDLE_DISTANCE_FROM_SIDE - PADDLE_WIDTH;
  int paddle2_y = 10;
  int ball_x = 40;
  int ball_y = 12;

  // set the initial directions of the ball
  int ball_x_direction = 1;
  int ball_y_direction = 1;

  // clear the screen
  printf("\e[2J");

  // move the cursor to the top left corner
  printf("\e[1;1H");

  // print the paddles and the ball
  for (int i = 0; i < PADDLE_HEIGHT; i++) {
    // print the left paddle
    for (int j = 0; j < PADDLE_WIDTH; j++) {
      printf("\e[%d;%dH|", paddle1_y + i, paddle1_x + j);
    }

    // print the right paddle
    for (int j = 0; j < PADDLE_WIDTH; j++) {
      printf("\e[%d;%dH|", paddle2_y + i, paddle2_x + j);
    }

    // print the ball
    printf("\e[%d;%dHO", ball_y + i, ball_x);
  }

  // loop until the player quits
  while (ch != 'q') {
    // get the player's input
    ch = getchar();

    // move the paddles
    if (ch == 'w') {
      paddle1_y--;
      paddle2_y--;
    }
    else if (ch == 's') {
      paddle1_y++;
      paddle2_y++;
    }

    // move the ball
    ball_x += ball_x_direction;
    ball_y += ball_y_direction;

    // reverse the direction of the ball if it hits the top or bottom wall
    if (ball_y == 1 || ball_y == 23) {
      ball_y_direction = -ball_y_direction;
    }

    // reverse the direction of the ball if it hits the left or right paddle
    if ((ball_x == paddle1_x + PADDLE_WIDTH && ball_y >= paddle1_y && ball_y <= paddle1_y + PADDLE_HEIGHT) ||
        (ball_x == paddle2_x && ball_y >= paddle2_y && ball_y <= paddle2_y + PADDLE_HEIGHT)) {
      ball_x_direction = -ball_x_direction;
    }

    // game over if the ball hits the left or right wall
    if (ball_x == 1 || ball_x == 80 - BALL_SIZE + 1) {
      printf("\e[2;1HGAME OVER!\n");
      break;
    }

    // clear the old paddles and ball
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
      // clear the left paddle
      for (int j = 0; j < PADDLE_WIDTH; j++) {
        printf("\e[%d;%dH ", paddle1_y + i, paddle1_x + j);
      }

      // clear the right paddle
      for (int j = 0; j < PADDLE_WIDTH; j++) {
        printf("\e[%d;%dH ", paddle2_y + i, paddle2_x + j);
      }

      // clear the ball
      printf("\e[%d;%dH ", ball_y + i, ball_x);
    }

    // update the paddles and ball
    if (ball_x_direction > 0) {
      // move the AI paddle
      if (ball_y > paddle2_y + PADDLE_HEIGHT / 2) {
        paddle2_y++;
      }
      else if (ball_y < paddle2_y + PADDLE_HEIGHT / 2) {
        paddle2_y--;
      }
    }
    else {
      // move the human paddle
      if (ch == 'w') {
        paddle1_y--;
      }
      else if (ch == 's') {
        paddle1_y++;
      }
    }

    // print the new paddles and ball
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
      // print the left paddle
      for (int j = 0; j < PADDLE_WIDTH; j++) {
        printf("\e[%d;%dH|", paddle1_y + i, paddle1_x + j);
      }

      // print the right paddle
      for (int j = 0; j < PADDLE_WIDTH; j++) {
        printf("\e[%d;%dH|", paddle2_y + i, paddle2_x + j);
      }

      // print the ball
      printf("\e[%d;%dHO", ball_y + i, ball_x);
    }

    // move the cursor to the bottom right corner
    printf("\e[24;80H");
  }

  // show the cursor
  printf("\e[?25h");

  // restore the original input settings
  system("stty sane");

  return 0;
}