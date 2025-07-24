//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: excited
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 50
#define HEIGHT 20
#define PAD_WIDTH 5
#define BLOCK_WIDTH 5
#define BLOCK_HEIGHT 3

char board[HEIGHT][WIDTH];
int ballx, bally, bxdir, bydir;
int padpos;

// Initialize the board
void init() {
  int i, j;
  for (i=0; i<HEIGHT; i++) {
    for (j=0; j<WIDTH; j++) {
      if (j<BLOCK_WIDTH && i<BLOCK_HEIGHT) {
        board[i][j] = '*';
      } else {
        board[i][j] = ' ';
      }
    }
  }
  ballx = WIDTH/2;
  bally = HEIGHT/2;
  bxdir = 1;
  bydir = 1;
  padpos = WIDTH/2;
}

// Move the ball
void moveBall() {
  if (board[bally+bydir][ballx+bxdir]=='*') {
    board[bally+bydir][ballx+bxdir] = ' ';
    bydir = -bydir;
  } else {
    board[bally][ballx] = ' ';
    ballx += bxdir;
    bally += bydir;
    board[bally][ballx] = 'O';
  }
  if (ballx==0 || ballx==WIDTH-1) {
    bxdir = -bxdir;
  }
  if (bally==0) {
    bydir = -bydir;
  } else if (bally==HEIGHT-1) {
    printf("\nGame Over!\n");
    exit(0);
  }
}

// Move the paddle
void movePad(char dir) {
  if (dir=='L' && padpos>0) {
    board[HEIGHT-1][padpos+PAD_WIDTH-1] = ' ';
    padpos--;
    board[HEIGHT-1][padpos] = '_';
  } else if (dir=='R' && padpos+PAD_WIDTH<WIDTH) {
    board[HEIGHT-1][padpos] = ' ';
    padpos++;
    board[HEIGHT-1][padpos+PAD_WIDTH-1] = '_';
  }
}

// Set the termios flags for non-blocking input
void nonblock(int state) {
  struct termios ttystate;
  tcgetattr(STDIN_FILENO, &ttystate);
  if (state==1) {
    ttystate.c_lflag &= ~(ICANON | ECHO);
    ttystate.c_cc[VMIN] = 0;
  } else {
    ttystate.c_lflag |= ICANON | ECHO;
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int main() {
  init();
  nonblock(1);
  char c;
  while (1) {
    system("clear");
    int i, j;
    for (i=0; i<HEIGHT; i++) {
      for (j=0; j<WIDTH; j++) {
        printf("%c", board[i][j]);
      }
      printf("\n");
    }
    if (read(STDIN_FILENO, &c, 1)==1) {
      if (c=='q') {
        nonblock(0);
        printf("\nExiting...\n");
        exit(0);
      } else if (c=='a') {
        movePad('L');
      } else if (c=='d') {
        movePad('R');
      }
    }
    moveBall();
    usleep(100000);
  }
  nonblock(0);
  return 0;
}