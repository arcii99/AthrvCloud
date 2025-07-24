//FormAI DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>

int main() {
  printf("_______   _______   __       __   __     __   _______\n");  
  printf("|       | |       | |  |     |  | |  |   |  | |       |\n");  
  printf("|  _____| |    ___| |  |     |  | |  |   |  | |  _____|\n");  
  printf("| |_____  |   |___  |  |     |  | |  |   |  | | |_____\n");  
  printf("|_____  | |    ___| |  |___  |  | |  |___|  | |_____  |\n");  
  printf(" _____| | |   |___  |______| |__| |________|  _____| |\n");  
  printf("|_______| |_______|                                |\n");  

  int x, y;
  int width = 40;
  int height = 20;
  
  int ball_x = width / 2;
  int ball_y = height / 2;

  int ball_vx = 1;
  int ball_vy = 1;

  int left_paddle_y = height / 2;
  int right_paddle_y = height / 2;
  
  char display[height][width];

  // initialize display
  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      if (x == 0 || x == width - 1) {
        display[y][x] = '|';
      } else if (y == 0 || y == height - 1) {
        display[y][x] = '-';
      } else {
        display[y][x] = ' ';
      }
    }
  }

  while (1) {
    // update ball position
    ball_x += ball_vx;
    ball_y += ball_vy;

    // check for collisions with walls
    if (ball_y == 1 || ball_y == height - 2) {
      ball_vy = -ball_vy;
    }
    if (ball_x == 1) {
      printf("Right Wins!\n");
      break;
    }
    if (ball_x == width - 2) {
      printf("Left Wins!\n");
      break;
    }

    // check for collisions with paddles
    if (ball_x == 2 && ball_y >= left_paddle_y - 1 && ball_y <= left_paddle_y + 1) {
      ball_vx = -ball_vx;
    }
    if (ball_x == width - 3 && ball_y >= right_paddle_y - 1 && ball_y <= right_paddle_y + 1) {
      ball_vx = -ball_vx;
    }

    // update paddle positions
    if (left_paddle_y > ball_y) {
      left_paddle_y--;
    } else if (left_paddle_y < ball_y) {
      left_paddle_y++;
    }

    if (right_paddle_y > ball_y) {
      right_paddle_y--;
    } else if (right_paddle_y < ball_y) {
      right_paddle_y++;
    }

    // update display
    for (y = 0; y < height; y++) {
      for (x = 0; x < width; x++) {
        if (x == 0 || x == width - 1) {
          display[y][x] = '|';
        } else if (y == 0 || y == height - 1) {
          display[y][x] = '-';
        } else if (x == 2 && (y == left_paddle_y - 1 || y == left_paddle_y || y == left_paddle_y + 1)) {
          display[y][x] = '#';
        } else if (x == width - 3 && (y == right_paddle_y - 1 || y == right_paddle_y || y == right_paddle_y + 1)) {
          display[y][x] = '#';
        } else if (x == ball_x && y == ball_y) {
          display[y][x] = '*';
        } else {
          display[y][x] = ' ';
        }
      }
    }

    // print display
    printf("\033[2J\033[1;1H"); // clears the terminal and sets the cursor to 0,0
    for (y = 0; y < height; y++) {
      for (x = 0; x < width; x++) {
        putchar(display[y][x]);
      }
      putchar('\n');
    }

    // delay
    usleep(5000);
  }

  return 0;
}