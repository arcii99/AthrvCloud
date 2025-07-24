//FormAI DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define CARD_COUNT (BOARD_SIZE * BOARD_SIZE / 2)

typedef struct {
  int row;
  int col;
} Tile;

typedef struct {
  char face;
  int revealed;
  int matched;
} Card;

void seed_rng(void) {
  srand(time(NULL));
}

int rand_int(int a, int b) {
  int range = b - a + 1;
  return rand() % range + a;
}

void shuffle(char* arr, int count) {
  for (int i = 0; i < count; i++) {
    int j = rand_int(i, count - 1);
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

void draw_board(Card** board) {
  printf("  ");
  for (int j = 0; j < BOARD_SIZE; j++)
    printf("%2d", j);
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j].revealed)
        printf("%2c", board[i][j].face);
      else
        printf("  ");
    }
    printf("\n");
  }
}

void reveal_card(Card** board, Tile t) {
  board[t.row][t.col].revealed = 1;
}

void hide_card(Card** board, Tile t) {
  board[t.row][t.col].revealed = 0;
}

int cards_match(Card** board, Tile t1, Tile t2) {
  return board[t1.row][t1.col].face == board[t2.row][t2.col].face;
}

void mark_card_matched(Card** board, Tile t) {
  board[t.row][t.col].matched = 1;
}

void initialize_board(Card** board, char* card_faces) {
  shuffle(card_faces, CARD_COUNT);
  int count[CARD_COUNT] = {0};

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      int card_idx;
      do {
        card_idx = rand_int(0, CARD_COUNT - 1);
      } while (count[card_idx] == 2);
      count[card_idx]++;
      board[i][j].face = card_faces[card_idx];
      board[i][j].revealed = 0;
      board[i][j].matched = 0;
    }
  }
}

int all_cards_matched(Card** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (!board[i][j].matched)
        return 0;
    }
  }
  return 1;
}

int main() {
  Card** board = calloc(BOARD_SIZE, sizeof(Card*));
  for (int i = 0; i < BOARD_SIZE; i++)
    board[i] = calloc(BOARD_SIZE, sizeof(Card));

  char card_faces[CARD_COUNT * 2] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D'};
  seed_rng();
  initialize_board(board, card_faces);

  int moves = 0;

  while (!all_cards_matched(board)) {
    printf("Moves: %d\n", moves);
    draw_board(board);

    Tile t1, t2;
    do {
      printf("Enter the row and column of the first card to reveal: ");
      scanf("%d %d", &t1.row, &t1.col);
    } while (board[t1.row][t1.col].revealed || board[t1.row][t1.col].matched);
    reveal_card(board, t1);

    do {
      printf("Enter the row and column of the second card to reveal: ");
      scanf("%d %d", &t2.row, &t2.col);
    } while ((t2.row == t1.row && t2.col == t1.col) || board[t2.row][t2.col].revealed || board[t2.row][t2.col].matched);
    reveal_card(board, t2);

    if (cards_match(board, t1, t2)) {
      mark_card_matched(board, t1);
      mark_card_matched(board, t2);
      printf("Match!\n");
    } else {
      printf("No match.\n");
      hide_card(board, t1);
      hide_card(board, t2);
    }

    moves++;
  }

  printf("Congratulations! You won in %d moves.\n", moves);

  for (int i = 0; i < BOARD_SIZE; i++)
    free(board[i]);
  free(board);

  return 0;
}