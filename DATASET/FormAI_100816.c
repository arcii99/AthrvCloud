//FormAI DATASET v1.0 Category: Checkers Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROW 8
#define COL 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'

char board[ROW][COL];
pthread_mutex_t mutex;

void initialize_board() {
  int i, j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      if ((i + j) % 2 == 0) {
        board[i][j] = EMPTY;
      } else if (i < 3) {
        board[i][j] = WHITE;
      } else if (i > 4) {
        board[i][j] = BLACK;
      } else {
        board[i][j] = EMPTY;
      }
    }
  }
}

void print_board() {
  int i, j;
  printf("\n  ");
  for (i = 0; i < ROW; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (i = 0; i < ROW; i++) {
    printf("%d ", i);
    for (j = 0; j < COL; j++) {
      printf("%c ", board[i][j]);
    }
    printf("%d", i);
    printf("\n");
  }
  printf("  ");
  for (i = 0; i < ROW; i++) {
    printf("%d ", i);
  }
  printf("\n\n");
}

void* black_piece() {
  pthread_mutex_lock(&mutex);
  int x, y;
  do {
    printf("Enter the x-coordinate of the piece you want to move: ");
    scanf("%d", &x);
    printf("Enter the y-coordinate of the piece you want to move: ");
    scanf("%d", &y);
  } while (board[x][y] != BLACK);
  printf("Enter the new x-coordinate of the piece: ");
  scanf("%d", &x);
  printf("Enter the new y-coordinate of the piece: ");
  scanf("%d", &y);
  board[x][y] = BLACK;
  board[x+1][y+1] = EMPTY;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void* white_piece() {
  pthread_mutex_lock(&mutex);
  int x, y;
  do {
    printf("Enter the x-coordinate of the piece you want to move: ");
    scanf("%d", &x);
    printf("Enter the y-coordinate of the piece you want to move: ");
    scanf("%d", &y);
  } while (board[x][y] != WHITE);
  printf("Enter the new x-coordinate of the piece: ");
  scanf("%d", &x);
  printf("Enter the new y-coordinate of the piece: ");
  scanf("%d", &y);
  board[x][y] = WHITE;
  board[x-1][y-1] = EMPTY;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main() {
  initialize_board();
  print_board();
  pthread_t black, white;
  while (1) {
    pthread_create(&black, NULL, &black_piece, NULL);
    pthread_create(&white, NULL, &white_piece, NULL);
    pthread_join(black, NULL);
    pthread_join(white, NULL);
    print_board();
  }
  return 0;
}