//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int generateRandom(int min, int max) {
  int num = (rand() % (max - min + 1)) + min;
  return num;
}

void main() {
  printf("Welcome to the Bouncing Ball game!\n");

  // Setting up game board
  int board[10][10] = {0};
  int ballX = 4;
  int ballY = 4;
  board[ballY][ballX] = 1;

  // Creating variables for game
  int score = 0;
  int difficulty = 1;
  int lives = 3;
  int numBlocks = 10;
  int blocks[10][2];

  srand(time(NULL));

  // Generating random blocks in game board
  for (int i = 0; i < numBlocks; i++) {
    int blockX = generateRandom(1, 8);
    int blockY = generateRandom(1, 8);
    board[blockY][blockX] = 2;
    blocks[i][0] = blockX;
    blocks[i][1] = blockY;
  }

  // Game loop
  while (lives > 0) {
    // Outputting game board
    for (int y = 0; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        if (board[y][x] == 0) {
          printf(".");
        } else if (board[y][x] == 1) {
          printf("O");
        } else if (board[y][x] == 2) {
          printf("X");
        }
      }
      printf("\n");
    }

    // Moving ball
    board[ballY][ballX] = 0;
    ballY--;
    board[ballY][ballX] = 1;

    // Checking if ball hit block
    for (int i = 0; i < numBlocks; i++) {
      if (ballX == blocks[i][0] && ballY == blocks[i][1]) {
        blocks[i][0] = -1;
        blocks[i][1] = -1;
        score++;
        numBlocks--;
        break;
      }
    }

    // Checking if ball hit wall
    if (ballY == 0) {
      lives--;
      printf("You lost a life! Lives left:%d\n", lives);
      ballY = 9;
    }

    // Checking if player has won
    if (numBlocks == 0) {
      printf("You won! Final Score:%d\n", score);
      break;
    }

    // Increasing difficulty
    if (score % 10 == 0 && score != 0 && difficulty < 5) {
      printf("Difficulty increased!\n");
      difficulty++;
    }

    // Delaying game loop to simulate animation
    switch (difficulty) {
      case 1:
        usleep(150000);
        break;
      case 2:
        usleep(125000);
        break;
      case 3:
        usleep(100000);
        break;
      case 4:
        usleep(75000);
        break;
      case 5:
        usleep(50000);
        break;
    }

    // Clearing console
    system("clear");
  }

  printf("Game Over!\n");
}