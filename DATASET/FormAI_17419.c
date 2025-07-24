//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define WIN_SCORE 2048

int board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
  srand(time(NULL));

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      board[row][col] = 0;
    }
  }

  int random_row = rand() % BOARD_SIZE;
  int random_col = rand() % BOARD_SIZE;

  board[random_row][random_col] = 2;
}

void print_board() {
  printf("Score: %d\n", get_score());

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      printf("%d ", board[row][col]);
    }
    printf("\n");
  }

  printf("\n");
}

int get_score() {
  int score = 0;

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      score += board[row][col];
    }
  }

  return score;
}

int has_won() {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == WIN_SCORE) {
        return 1;
      }
    }
  }

  return 0;
}

int can_combine(int current, int neighbor) {
  if (current == neighbor || current == 0 || neighbor == 0) {
    return 1;
  }

  return 0;
}

void combine_tiles(int *current, int *neighbor) {
  *current += *neighbor;
  *neighbor = 0;
}

int slide_left() {
  int made_move = 0;

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE - 1; col++) {
      if (board[row][col] != 0) {
        int neighbor_col = col + 1;

        while (neighbor_col < BOARD_SIZE && board[row][neighbor_col] == 0) {
          neighbor_col++;
        }

        if (neighbor_col < BOARD_SIZE &&
            can_combine(board[row][col], board[row][neighbor_col])) {
          combine_tiles(&board[row][col], &board[row][neighbor_col]);
          made_move = 1;
        }
      }
    }

    int empty_spots[BOARD_SIZE] = {0};
    int num_empty_spots = 0;

    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == 0) {
        empty_spots[num_empty_spots] = col;
        num_empty_spots++;
      }
    }

    for (int i = 0; i < num_empty_spots; i++) {
      int col = empty_spots[i];

      if (col < BOARD_SIZE - 1 && board[row][col + 1] != 0) {
        board[row][col] = board[row][col + 1];
        board[row][col + 1] = 0;
        made_move = 1;
      }
    }
  }

  return made_move;
}

void get_random_blank_tile(int *row, int *col) {
  int blank_found = 0;

  while (!blank_found) {
    *row = rand() % BOARD_SIZE;
    *col = rand() % BOARD_SIZE;

    if (board[*row][*col] == 0) {
      blank_found = 1;
    }
  }
}

void place_new_tile() {
  int new_tile_value = (rand() % 2 + 1) * 2;
  int row, col;

  get_random_blank_tile(&row, &col);

  board[row][col] = new_tile_value;
}

int game_over() {
  int full_board = 1;

  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == 0) {
        full_board = 0;
        break;
      }
    }
  }

  if (full_board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE - 1; col++) {
        if (can_combine(board[row][col], board[row][col + 1]) ||
            can_combine(board[col][row], board[col + 1][row])) {
          return 0;
        }
      }
    }

    return 1;
  }

  return 0;
}

int main() {
  initialize_board();

  while (!game_over()) {
    print_board();

    int move_made = 0;

    while (!move_made) {
      printf("Enter a move (l for left, r for right, u for up, d for down): ");

      char move;

      scanf(" %c", &move);

      int slide_result;

      switch (move) {
        case 'l':
          slide_result = slide_left();
          break;
        case 'r':
          break;
        case 'u':
          break;
        case 'd':
          break;
        default:
          printf("Invalid move.\n");
          continue;
      }

      if (slide_result) {
        place_new_tile();
        move_made = 1;
      }
    }
  }

  if (has_won()) {
    printf("You win!\n");
  } else {
    printf("Game over!\n");
  }

  return 0;
}