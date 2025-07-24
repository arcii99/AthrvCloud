//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 15
#define BOARD_HEIGHT 10
#define PACMAN 'C'
#define GHOST 'O'
#define FOOD '.'
#define SUPERFOOD 'o'
#define WALL '-'

int score = 0;
int lives = 3;
int super_mode = 0;
char board[BOARD_HEIGHT][BOARD_WIDTH];
int pacman_x, pacman_y;
int ghost_x, ghost_y;

void init_board() {
  int i, j;
  for (i = 0; i < BOARD_HEIGHT; i++) {
    for (j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = FOOD;
    }
  }

  board[4][1] = WALL;
  board[4][2] = WALL;
  board[4][3] = WALL;
  board[4][5] = WALL;
  board[4][6] = WALL;
  board[4][7] = WALL;
  board[4][9] = WALL;
  board[4][10] = WALL;
  board[4][11] = WALL;

  board[2][4] = WALL;
  board[3][4] = WALL;
  board[5][4] = WALL;
  board[6][4] = WALL;
  board[7][4] = WALL;
  board[8][4] = WALL;
  board[9][4] = WALL;

  board[6][8] = SUPERFOOD;

  srand(time(NULL));
  pacman_x = rand() % BOARD_WIDTH;
  pacman_y = rand() % BOARD_HEIGHT;
  while(board[pacman_y][pacman_x] == WALL) {
    pacman_x = rand() % BOARD_WIDTH;
    pacman_y = rand() % BOARD_HEIGHT;
  }

  ghost_x = rand() % BOARD_WIDTH;
  ghost_y = rand() % BOARD_HEIGHT;
  while(board[ghost_y][ghost_x] == WALL || (ghost_x == pacman_x && ghost_y == pacman_y)) {
    ghost_x = rand() % BOARD_WIDTH;
    ghost_y = rand() % BOARD_HEIGHT;
  }

  board[pacman_y][pacman_x] = PACMAN;
  board[ghost_y][ghost_x] = GHOST;
}

void print_board() {
	int i, j;
  printf("\n");
  for (i = 0; i < BOARD_HEIGHT; i++) {
    for (j = 0; j < BOARD_WIDTH; j++) {
            printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("\nScore: %d  Lives: %d\n", score, lives);
}

void move_ghost() {
  if (super_mode) {
    return;
  }

  if (ghost_x < pacman_x && board[ghost_y][ghost_x+1] != WALL) {
    board[ghost_y][ghost_x] = FOOD;
    ghost_x++;
  } else if (ghost_x > pacman_x && board[ghost_y][ghost_x-1] != WALL) {
    board[ghost_y][ghost_x] = FOOD;
    ghost_x--;
  } else if (ghost_y < pacman_y && board[ghost_y+1][ghost_x] != WALL) {
    board[ghost_y][ghost_x] = FOOD;
    ghost_y++;
  } else if (ghost_y > pacman_y && board[ghost_y-1][ghost_x] != WALL) {
    board[ghost_y][ghost_x] = FOOD;
    ghost_y--;
  }

  if (ghost_x == pacman_x && ghost_y == pacman_y) {
    lives--;
    if (lives > 0) {
      printf("\nYou got eaten by a ghost! You have %d lives left.\n", lives);
      init_board();
    } else {
      printf("\nYou lost all your lives! Game over.\n");
      exit(0);
    }
  } else {
    board[ghost_y][ghost_x] = GHOST;
  }
}

void move_pacman(char direction) {
  switch(direction) {
    case 'w':
      if (pacman_y > 0 && board[pacman_y-1][pacman_x] != WALL) {
        board[pacman_y][pacman_x] = FOOD;
        pacman_y--;
      }
      break;
    case 'a':
      if (pacman_x > 0 && board[pacman_y][pacman_x-1] != WALL) {
        board[pacman_y][pacman_x] = FOOD;
        pacman_x--;
      }
      break;
    case 's':
      if (pacman_y < BOARD_HEIGHT-1 && board[pacman_y+1][pacman_x] != WALL) {
        board[pacman_y][pacman_x] = FOOD;
        pacman_y++;
      }
      break;
    case 'd':
      if (pacman_x < BOARD_WIDTH-1 && board[pacman_y][pacman_x+1] != WALL) {
        board[pacman_y][pacman_x] = FOOD;
        pacman_x++;
      }
      break;
    default:
      break;
  }

  if (board[pacman_y][pacman_x] == FOOD) {
    score += 10;
  } else if (board[pacman_y][pacman_x] == SUPERFOOD) {
    super_mode = 1;
    score += 50;
  }

  if (board[pacman_y][pacman_x] == SUPERFOOD || board[pacman_y][pacman_x] == FOOD) {
    board[pacman_y][pacman_x] = PACMAN;
  }

  if (score >= 500) {
    printf("\nCongratulations, you won the game!\n");
    exit(0);
  }
}

int main() {
  char direction;
  printf("\nWelcome to Pac-Man!\n");
  printf("Move using 'w', 'a', 's', and 'd' keys.\n");
  printf("Avoid the ghosts and eat all the food.\n");
  printf("Super food will make you invincible for a short time.\n\n");
  init_board();
  while(1) {
    print_board();
    fflush(stdin);
    printf("Enter a move: ");
    direction = getchar();
    move_pacman(direction);
    move_ghost();
    if (super_mode) {
      printf("\nYou're in super mode! The ghosts fear you.\n");
      super_mode--;
      if (super_mode == 0) {
        printf("\nSuper mode ended.\n");
      }
    }
  }
  return 0;
}