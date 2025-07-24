//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Global variables
bool game_over = false;
int player_score = 0;
int ai_score = 0;
int ball_x = 10;
int ball_y = 10;
int ball_dir_x = -1;
int ball_dir_y = 0;
int player_paddle_y = 8;
int ai_paddle_y = 8;
int ai_difficulty = 10; // 1-10, 10 being the hardest

// Keyboard input handling for non-blocking getch()
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

// AI opponent movement logic
void ai_move() {
  int middle = 0;
  switch (ai_difficulty) {
    case 1:
      middle = rand() % 3 - 1;
      break;
    case 2:
      middle = rand() % 5 - 2;
      break;
    case 3:
      middle = rand() % 7 - 3;
      break;
    case 4:
      middle = rand() % 9 - 4;
      break;
    case 5:
      middle = rand() % 11 - 5;
      break;
    case 6:
      middle = rand() % 13 - 6;
      break;
    case 7:
      middle = rand() % 15 - 7;
      break;
    case 8:
      middle = rand() % 17 - 8;
      break;
    case 9:
      middle = rand() % 19 - 9;
      break;
    case 10:
      middle = rand() % 21 - 10;
      break;
  }

  if (ai_paddle_y + middle > ball_y) {
    ai_paddle_y--;
  }

  if (ai_paddle_y + middle < ball_y) {
    ai_paddle_y++;
  }
}

// Draw ball, paddles, and scores
void draw() {
  printf("\033[H");
  
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 60; j++) {
      if (i == ball_y && j == ball_x) {
        printf("O");
      } else if (i == player_paddle_y && j < 3) {
        printf("|");
      } else if (i == player_paddle_y && j == 3) {
        printf("<");
      } else if (i == player_paddle_y && j > 3 && j < 8) {
        printf("-");
      } else if (i == player_paddle_y && j == 8) {
        printf(">");
      } else if (i == player_paddle_y && j > 8) {
        printf("|");
      } else if (i == ai_paddle_y && j <= 57 && j > 53) {
        printf("|");
      } else if (i == ai_paddle_y && j == 53) {
        printf(">");
      } else if (i == ai_paddle_y && j < 53 && j > 48) {
        printf("-");
      } else if (i == ai_paddle_y && j == 48) {
        printf("<");
      } else if (i == ai_paddle_y && j < 48) {
        printf("|");
      } else if (i == 0 || i == 19 || j == 0 || j == 59) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  printf("Player Score: %d\t\tAI Score: %d\n", player_score, ai_score);
}

// Handle keyboard input from user
void input() {
  if (kbhit()) {
    char c = getchar();

    if (c == 'w' && player_paddle_y > 1) {
      player_paddle_y--;
    }

    if (c == 's' && player_paddle_y < 16) {
      player_paddle_y++;
    }

    if (c == 'q') {
      game_over = true;
    }
  }
}

// Move ball based on its direction
void move() {
  ball_x += ball_dir_x;
  ball_y += ball_dir_y;

  // Check for collision with walls and paddles
  if (ball_y == 1 || ball_y == 18) {
    ball_dir_y *= -1;
  }

  if (ball_x == 2 && ball_y >= player_paddle_y && ball_y <= player_paddle_y + 4) {
    ball_dir_x *= -1;
  }

  if (ball_x == 57 && ball_y >= ai_paddle_y && ball_y <= ai_paddle_y + 4) {
    ball_dir_x *= -1;
  }

  // Increase AI difficulty over time
  if (ball_x % 10 == 0 && ai_difficulty < 10) {
    ai_difficulty++;
  }

  // Check for scoring
  if (ball_x == 0 || ball_x == 59) {
    if (ball_x == 0) {
      ai_score++;
    } else {
      player_score++;
    }

    ball_x = 29;
    ball_y = 10;

    ball_dir_x *= -1;
    ball_dir_y = rand() % 3 - 1;
  }
}

// Main game loop
int main() {
  srand(time(NULL));

  while (!game_over) {
    draw();
    input(); 
    move();
    ai_move();

    usleep(100000);
  }

  return 0;
}