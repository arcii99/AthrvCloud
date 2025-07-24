//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 30
#define HEIGHT 20
#define PADDLE_LEN 4
#define AI_PADDLE 2

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

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int randInRange(int range) {
  return rand() % range;
}

void clearScreen() {
  printf("\033[2J\033[1;1H");
}

void printArena(char arena[HEIGHT][WIDTH]) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      printf("%c", arena[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(0));
  char arena[HEIGHT][WIDTH];
  int ballPos[2] = {HEIGHT/2, WIDTH/2};
  int ballVel[2] = {1, 1};
  int player1Pos = HEIGHT/2 - PADDLE_LEN/2;
  int player2Pos = HEIGHT/2 - PADDLE_LEN/2;
  int player1Score = 0, player2Score = 0;
  int gameOn = 1, aiRand = 0, aiMove = 0;

  int i, j;

  // initialize arena
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (j == 0 || j == WIDTH - 1) {
        arena[i][j] = '|';
      } else if (i == 0 || i == HEIGHT - 1) {
        arena[i][j] = '-';
      } else {
        arena[i][j] = ' ';
      }
    }
  }

  while (gameOn) {
    clearScreen();

    // move players
    if (kbhit()) {
      char key = getchar();
      if (key == 'a' && player1Pos > 1) {
        player1Pos--;
      }
      if (key == 'z' && player1Pos < HEIGHT - PADDLE_LEN - 1) {
        player1Pos++;
      }
    }

    // move AI paddle
    aiRand = randInRange(3) - 1;
    aiMove = player2Pos + aiRand;
    if (aiMove < 1) {
      player2Pos = 1;
    } else if (aiMove > HEIGHT - PADDLE_LEN - 1) {
      player2Pos = HEIGHT - PADDLE_LEN - 1;
    } else {
      player2Pos = aiMove;
    }
    
    // move ball
    ballPos[0] += ballVel[0];
    ballPos[1] += ballVel[1];

    // bounce ball off walls
    if (ballPos[0] == 1 || ballPos[0] == HEIGHT - 2) {
      ballVel[0] = -ballVel[0];
    }

    // handle scoring
    if (ballPos[1] == 1) {
      player2Score++;
      ballPos[0] = HEIGHT/2;
      ballPos[1] = WIDTH/2;
      ballVel[0] = randInRange(3) - 1;
      ballVel[1] = randInRange(2)*2 - 1;
    } else if (ballPos[1] == WIDTH - 2) {
      player1Score++;
      ballPos[0] = HEIGHT/2;
      ballPos[1] = WIDTH/2;
      ballVel[0] = randInRange(3) - 1;
      ballVel[1] = randInRange(2)*2 - 1;
    }

    // bounce ball off paddles
    if (ballPos[1] == 2) {
      if (ballPos[0] >= player1Pos && ballPos[0] <= player1Pos + PADDLE_LEN) {
        ballVel[1] = -ballVel[1];
      }
    } else if (ballPos[1] == WIDTH - 3) {
      if (ballPos[0] >= player2Pos && ballPos[0] <= player2Pos + PADDLE_LEN) {
        ballVel[1] = -ballVel[1];
      }
    }

    // update arena
    for (i = 0; i < HEIGHT; i++) {
      for (j = 0; j < WIDTH; j++) {
        arena[i][j] = ' ';
      }
    }
    for (i = player1Pos; i < player1Pos + PADDLE_LEN; i++) {
      arena[i][1] = '|';
    }
    for (i = player2Pos; i < player2Pos + PADDLE_LEN; i++) {
      arena[i][WIDTH - 2] = '|';
    }
    arena[ballPos[0]][ballPos[1]] = 'O';

    printArena(arena);
    printf("Player 1: %d\n", player1Score);
    printf("Player 2: %d\n", player2Score);
    usleep(10000);
  }

  return 0;
}