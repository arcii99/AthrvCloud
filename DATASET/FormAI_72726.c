//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 70
#define HEIGHT 20
#define PADDLE_HEIGHT 3
#define BALL_RADIUS 1

#define PLAYER1 '1'
#define PLAYER2 '2'
#define AI_PLAYER 'C'
#define BALL 'O'
#define WALL '&'
#define PADDLE '|'

typedef struct Point {
  int x;
  int y;
} Point;

typedef struct Paddle {
  Point position;
  int length;
} Paddle;

typedef struct Ball {
  Point position;
  Point velocity;
} Ball;

typedef struct GameState {
  char board[HEIGHT][WIDTH + 1];
  Paddle player1;
  Paddle player2;
  Paddle aiPlayer;
  Ball ball;
  int player1Score;
  int player2Score;
  int aiPlayerScore;
} GameState;

void clearScreen() {
  printf("\033[H\033[2J");
}

void printBoard(GameState* gameState) {
  clearScreen();
  for (int i = 0; i < HEIGHT; i++) {
    printf("%s\n", gameState->board[i]);
  }
  printf("Player 1: %d\n", gameState->player1Score);
  printf("Player 2: %d\n", gameState->player2Score);
  printf("AI Player: %d\n", gameState->aiPlayerScore);
}

void initializeBoard(GameState* gameState) {
  memset(gameState->board, ' ', sizeof(gameState->board));
  for (int i = 0; i < HEIGHT; i++) {
    gameState->board[i][0] = WALL;
    gameState->board[i][WIDTH - 1] = WALL;
  }
  for (int i = 0; i < WIDTH; i++) {
    gameState->board[0][i] = WALL;
    gameState->board[HEIGHT - 1][i] = WALL;
  }

  int paddleOffset = PADDLE_HEIGHT / 2;
  gameState->player1.position.x = 2;
  gameState->player1.position.y = HEIGHT / 2 - paddleOffset;
  gameState->player1.length = PADDLE_HEIGHT;

  gameState->player2.position.x = WIDTH - 3;
  gameState->player2.position.y = HEIGHT / 2 - paddleOffset;
  gameState->player2.length = PADDLE_HEIGHT;

  gameState->aiPlayer.position.x = WIDTH / 2;
  gameState->aiPlayer.position.y = HEIGHT - 3;
  gameState->aiPlayer.length = PADDLE_HEIGHT;

  gameState->ball.position.x = WIDTH / 2;
  gameState->ball.position.y = HEIGHT / 2;
  gameState->ball.velocity.x = (rand() % 2 == 0) ? -1 : 1;
  gameState->ball.velocity.y = (rand() % 2 == 0) ? -1 : 1;
}

void updateBoard(GameState* gameState) {
  int aiMove = 0;
  if (gameState->ball.velocity.y == 1 && gameState->ball.position.y >= HEIGHT / 2) {
    int ballDistanceFromAi = abs(gameState->aiPlayer.position.x - gameState->ball.position.x);
    if (ballDistanceFromAi > 1) {
      aiMove = (gameState->aiPlayer.position.x < gameState->ball.position.x) ? 1 : -1;
    }
  }
  gameState->aiPlayer.position.x += aiMove;

  // Update ball position
  int newX = gameState->ball.position.x + gameState->ball.velocity.x;
  int newY = gameState->ball.position.y + gameState->ball.velocity.y;

  // Check if ball hits wall
  if (newX <= 0 || newX >= WIDTH - 1) {
    gameState->ball.velocity.x = -gameState->ball.velocity.x;
  }
  if (newY <= 0) {
    gameState->ball.velocity.y = -gameState->ball.velocity.y;
    gameState->player2Score++;
    gameState->ball.position.x = WIDTH / 2;
    gameState->ball.position.y = HEIGHT / 2;
    gameState->ball.velocity.x = (rand() % 2 == 0) ? -1 : 1;
    gameState->ball.velocity.y = (rand() % 2 == 0) ? -1 : 1;
    return;
  }
  if (newY >= HEIGHT - 1) {
    gameState->ball.velocity.y = -gameState->ball.velocity.y;
    gameState->player1Score++;
    gameState->ball.position.x = WIDTH / 2;
    gameState->ball.position.y = HEIGHT / 2;
    gameState->ball.velocity.x = (rand() % 2 == 0) ? -1 : 1;
    gameState->ball.velocity.y = (rand() % 2 == 0) ? -1 : 1;
    return;
  }

  // Check if ball hits paddle
  Point ballTop = {newX, newY - BALL_RADIUS};
  Point ballBottom = {newX, newY + BALL_RADIUS};
  if (ballTop.x >= gameState->player1.position.x &&
      ballTop.x <= gameState->player1.position.x + 1 &&
      ballTop.y >= gameState->player1.position.y &&
      ballTop.y <= gameState->player1.position.y + gameState->player1.length - 1) {
    gameState->ball.velocity.x = -gameState->ball.velocity.x;
  }
  if (ballBottom.x >= gameState->player1.position.x &&
      ballBottom.x <= gameState->player1.position.x + 1 &&
      ballBottom.y >= gameState->player1.position.y &&
      ballBottom.y <= gameState->player1.position.y + gameState->player1.length - 1) {
    gameState->ball.velocity.x = -gameState->ball.velocity.x;
  }
  if (ballTop.x >= gameState->player2.position.x - 1 &&
      ballTop.x <= gameState->player2.position.x &&
      ballTop.y >= gameState->player2.position.y &&
      ballTop.y <= gameState->player2.position.y + gameState->player2.length - 1) {
    gameState->ball.velocity.x = -gameState->ball.velocity.x;
  }
  if (ballBottom.x >= gameState->player2.position.x - 1 &&
      ballBottom.x <= gameState->player2.position.x &&
      ballBottom.y >= gameState->player2.position.y &&
      ballBottom.y <= gameState->player2.position.y + gameState->player2.length - 1) {
    gameState->ball.velocity.x = -gameState->ball.velocity.x;
  }
  if (ballTop.x >= gameState->aiPlayer.position.x &&
      ballTop.x <= gameState->aiPlayer.position.x + 1 &&
      ballTop.y >= gameState->aiPlayer.position.y &&
      ballTop.y <= gameState->aiPlayer.position.y + gameState->aiPlayer.length - 1) {
    gameState->ball.velocity.x = -gameState->ball.velocity.x;
    gameState->ball.velocity.y = -gameState->ball.velocity.y;
    gameState->aiPlayerScore++;
  }
  if (ballBottom.x >= gameState->aiPlayer.position.x &&
      ballBottom.x <= gameState->aiPlayer.position.x + 1 &&
      ballBottom.y >= gameState->aiPlayer.position.y &&
      ballBottom.y <= gameState->aiPlayer.position.y + gameState->aiPlayer.length - 1) {
    gameState->ball.velocity.x = -gameState->ball.velocity.x;
    gameState->ball.velocity.y = -gameState->ball.velocity.y;
    gameState->aiPlayerScore++;
  }

  gameState->ball.position.x = newX;
  gameState->ball.position.y = newY;
}

void renderGameElements(GameState* gameState) {
  // Render player1 paddle
  for (int i = 0; i < gameState->player1.length; i++) {
    gameState->board[gameState->player1.position.y + i][gameState->player1.position.x] = PADDLE;
  }

  // Render player2 paddle
  for (int i = 0; i < gameState->player2.length; i++) {
    gameState->board[gameState->player2.position.y + i][gameState->player2.position.x] = PADDLE;
  }

  // Render aiPlayer paddle
  for (int i = 0; i < gameState->aiPlayer.length; i++) {
    gameState->board[gameState->aiPlayer.position.y + i][gameState->aiPlayer.position.x] = PADDLE;
  }

  // Render ball
  gameState->board[gameState->ball.position.y][gameState->ball.position.x] = BALL;
}

int main() {
  srand(time(NULL));
  GameState gameState;
  initializeBoard(&gameState);
  while (true) {
    printBoard(&gameState);
    updateBoard(&gameState);
    renderGameElements(&gameState);
  }
  return 0;
}