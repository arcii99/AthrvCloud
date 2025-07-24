//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define INVADERS 3
#define PLAYER_SIZE 1
#define BULLET_SIZE 1

int player_pos = 0; // Player position
int bullet_pos = -1;
int invaders[INVADERS] = {1, 3, 4}; // Initial position of invader array
int move_left = 1;
int score = 0;
int game_over = 0;
int board[ROWS][COLS];

void init_board() {
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      board[i][j] = 0;
    }
  }
  for(i = 0; i < INVADERS; i++) {
    board[0][invaders[i]] = 1;
  }
}

void display_board() {
  int i, j;
  for(i = 0; i < ROWS; i++) {
    for(j = 0; j < COLS; j++) {
      if(board[i][j] == 0) {
        printf(" ");
      } else if(board[i][j] == PLAYER_SIZE) {
        printf("^");
      } else if(board[i][j] == BULLET_SIZE) {
        printf("|");
      } else if(board[i][j] == INVADERS) {
        printf("#");
      } 
    }
    printf("\n");
  }
}

void move_player(char direction) {
  if(direction == 'L') {
    if(player_pos > 0) {
      board[ROWS-1][player_pos] = 0;
      player_pos--;
      board[ROWS-1][player_pos] = PLAYER_SIZE;
    }
  } else if(direction == 'R') {
    if(player_pos < COLS-1) {
      board[ROWS-1][player_pos] = 0;
      player_pos++;
      board[ROWS-1][player_pos] = PLAYER_SIZE;
    }
  }
}

void move_bullet() {
  board[ROWS-1][bullet_pos] = 0;
  if(bullet_pos > -1) {
    if(board[ROWS-2][bullet_pos] == INVADERS) {
      score++;
      board[ROWS-2][bullet_pos] = 0;
      bullet_pos = -1;
      if(score == INVADERS) {
        game_over = 1;
        printf("Congratulations! You win!\n");
      }
    } else if(board[ROWS-2][bullet_pos] > 0) {
      game_over = 1;
      printf("Game over!\n");
    } else {
      bullet_pos--;
      if(bullet_pos > -1) {
        board[ROWS-2][bullet_pos] = BULLET_SIZE;
      }
    }
  }
}

void move_invaders() {
  int i, j, move_down = 0;
  srand(time(NULL));
  for(i = ROWS-1; i >= 0; i--) {
    for(j = 0; j < COLS; j++) {
      if(board[i][j] == INVADERS) {
        board[i][j] = 0;
        if(i == ROWS-1) {
          move_down = 1;
        } else if(j == COLS-1) {
          move_left = 1;
        } else if(j == 0) {
          move_left = 0;
        }
        if(move_down) {
          game_over = 1;
          printf("Game over!\n");
          break;
        } else if(move_left) {
          invaders[i] = j-1;
        } else {
          invaders[i] = j+1;
        }
      }
    }
    if(game_over) {
      break;
    }
  }
  for(i = 0; i < INVADERS; i++) {
    board[ROWS-2][invaders[i]] = INVADERS;
  }
}

void check_input() {
  char input;
  if(scanf(" %c", &input) == 1) {
    switch(input) {
      case 'L':
      case 'R':
        move_player(input);
        break;
      case 'F':
        if(bullet_pos == -1) {
          bullet_pos = player_pos;
          board[ROWS-2][bullet_pos] = BULLET_SIZE;
        }
        break;
      default:
        break;
    }
  }
}

int main() {
  init_board();
  board[ROWS-1][player_pos] = PLAYER_SIZE;
  while(!game_over) {
    display_board();
    check_input();
    move_bullet();
    move_invaders();
  }
  return 0;
}