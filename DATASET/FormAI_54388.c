//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_HEIGHT 5
#define INITIAL_SPEED 50000

// Define the structure of the ball
typedef struct {
  int x, y, dx, dy;
} Ball;

// Define the structure of each paddle
typedef struct {
  int x, y, score;
} Paddle;

// Function to draw the ball at its current position
void draw_ball(Ball ball) {
  printf("\033[%d;%dH@", ball.y, ball.x);
  fflush(stdout);
}

// Function to erase the ball from its previous position
void erase_ball(Ball ball) {
  printf("\033[%d;%dH ", ball.y, ball.x);
  fflush(stdout);
}

// Function to draw a paddle at its current position
void draw_paddle(Paddle paddle, char c) {
  int i;
  for (i = 0; i < PADDLE_HEIGHT; i++) {
    printf("\033[%d;%dH%c", paddle.y+i, paddle.x, c);
  }
  fflush(stdout);
}

// Function to erase a paddle from its previous position
void erase_paddle(Paddle paddle) {
  int i;
  for (i = 0; i < PADDLE_HEIGHT; i++) {
    printf("\033[%d;%dH ", paddle.y+i, paddle.x);
  }
  fflush(stdout);
}

// Function to move the ball according to its current direction
void move_ball(Ball *ball) {
  erase_ball(*ball);
  ball->x += ball->dx;
  ball->y += ball->dy;
  draw_ball(*ball);
}

// Function to move the human player's paddle based on keyboard input
void move_paddle(Paddle *paddle) {
  int c = getchar();
  erase_paddle(*paddle);
  if (c == 'w' && paddle->y > 1) {
    paddle->y--;
  } else if (c == 's' && paddle->y < HEIGHT - PADDLE_HEIGHT) {
    paddle->y++;
  }
  draw_paddle(*paddle, '|');
}

// Function to move the AI opponent's paddle based on the current position of the ball
void move_ai_paddle(Paddle *paddle, Ball ball) {
  erase_paddle(*paddle);
  if (ball.y < paddle->y + PADDLE_HEIGHT/2 && paddle->y > 1) {
    paddle->y--;
  } else if (ball.y > paddle->y + PADDLE_HEIGHT/2 && paddle->y < HEIGHT - PADDLE_HEIGHT) {
    paddle->y++;
  }
  draw_paddle(*paddle, '#');
}

// Function to check for and handle collisions between the ball and the walls or paddles
void handle_collisions(Ball *ball, Paddle *human, Paddle *ai, int *speed) {
  // Check for collision with walls
  if (ball->y == 1 || ball->y == HEIGHT) {
    ball->dy *= -1;
  }

  // Check for collision with human paddle
  if (ball->x == human->x + 1 && ball->y >= human->y && ball->y <= human->y + PADDLE_HEIGHT - 1) {
    ball->dx *= -1;
    *speed -= 1000;
  } else if (ball->x == human->x) {
    // Ball missed human paddle
    ai->score++;
    printf("\033[2;1HHuman: %d  AI: %d\n", human->score, ai->score);
    fflush(stdout);
    ball->x = human->x + 1;
    ball->y = human->y + PADDLE_HEIGHT/2;
    ball->dx *= -1;
    ball->dy = 0;
    usleep(1000000);
    draw_ball(*ball);
    *speed = INITIAL_SPEED;
    return;
  }

  // Check for collision with AI paddle
  if (ball->x == ai->x - 1 && ball->y >= ai->y && ball->y <= ai->y + PADDLE_HEIGHT - 1) {
    ball->dx *= -1;
    *speed -= 1000;
  } else if (ball->x == ai->x) {
    // Ball missed AI paddle
    human->score++;
    printf("\033[2;1HHuman: %d  AI: %d\n", human->score, ai->score);
    fflush(stdout);
    ball->x = ai->x - 1;
    ball->y = ai->y + PADDLE_HEIGHT/2;
    ball->dx *= -1;
    ball->dy = 0;
    usleep(1000000);
    draw_ball(*ball);
    *speed = INITIAL_SPEED;
    return;
  }
}

int main() {
  // Set up game board
  system("clear");
  printf("\033[%d;%dH╔══════════════════════════════════════╗", 1, 1);
  printf("\033[%d;%dH║                                          ║", 2, 1);
  printf("\033[%d;%dH║                                          ║", 3, 1);
  printf("\033[%d;%dH╚══════════════════════════════════════╝", HEIGHT, 1);
  printf("\033[%d;%dHTerminal Pong", 1, WIDTH/2-6);
  printf("\033[%d;%dHHuman: 0  AI: 0", 2, 1);
  fflush(stdout);

  // Set up ball and paddles
  srand(time(NULL));
  Ball ball = {WIDTH/2, HEIGHT/2, rand() % 2 ? 1 : -1, rand() % 3 - 1};
  Paddle human = {3, HEIGHT/2 - PADDLE_HEIGHT/2, 0};
  Paddle ai = {WIDTH - 4, HEIGHT/2 - PADDLE_HEIGHT/2, 0};

  // Set up keyboard input
  struct termios orig_termios, new_termios;
  tcgetattr(STDIN_FILENO, &orig_termios);
  new_termios = orig_termios;
  new_termios.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
  fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

  // Set up game loop
  int speed = INITIAL_SPEED;
  while (1) {
    // Move ball and paddles
    usleep(speed);
    move_ball(&ball);
    move_ai_paddle(&ai, ball);
    if (ball.dx > 0) {
      move_paddle(&human);
    }

    // Check for collisions
    handle_collisions(&ball, &human, &ai, &speed);
  }

  // Restore keyboard settings
  tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
  fcntl(STDIN_FILENO, F_SETFL, 0);

  return 0;
}