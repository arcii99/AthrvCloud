//FormAI DATASET v1.0 Category: Chess engine ; Style: multi-threaded
#include<pthread.h>
#include<stdio.h>
#include<string.h>

char board[8][8] = { 
  {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
  {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
  {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'} 
};

void print_board() {
  int i, j;
  for(i = 0; i < 8; i++) {
    for(j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  print_board();
  return 0;
}