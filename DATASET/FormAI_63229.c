//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of Bingo Board
#define MAX_NUM 90 // Maximum Bingo number

// Function to initialize the Bingo Board
void initialize_board(int board[N][N]) {
  srand(time(NULL)); // Seed for random number generation
  int rand_num, count;
  for(int i = 0; i < N; i++) {
    count = 0;
    while(count < 5) {
      rand_num = rand() % MAX_NUM + 1;
      // Check if the number is already present in the row
      int flag = 0;
      for(int j = 0; j < i; j++) {
        if(board[j][count] == rand_num) {
          flag = 1;
          break;
        }
      }
      if(flag == 0) {
        board[i][count] = rand_num;
        count++;
      }
    }
  }
}

// Function to print the Bingo Board
void print_board(int board[N][N], int marks[N][N]) {
  printf("\n");
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(marks[i][j]) {
        printf("%d [X]\t", board[i][j]);

      }
      else {
        printf("%d [ ]\t", board[i][j]);
      }
    }
    printf("\n");
  }
}

// Function to check if Bingo has been achieved
int check_bingo(int marks[N][N]) {
  int count;
  // Check rows
  for(int i = 0; i < N; i++) {
    count = 0;
    for(int j = 0; j < N; j++) {
      if(marks[i][j] == 1) {
        count++;
      }
    }
    if(count == N) {
      return 1;
    }
  }
  // Check columns
  for(int j = 0; j < N; j++) {
    count = 0;
    for(int i = 0; i < N; i++) {
      if(marks[i][j] == 1) {
        count++;
      }
    }
    if(count == N) {
      return 1;
    }
  }
  // Check diagonals
  count = 0;
  for(int i = 0, j = 0; i < N && j < N; i++, j++) {
    if(marks[i][j] == 1) {
      count++;
    }
  }
  if(count == N) {
    return 1;
  }
  count = 0;
  for(int i = 0, j = N-1; i < N && j >= 0; i++, j--) {
    if(marks[i][j] == 1) {
      count++;
    }
  }
  if(count == N) {
    return 1;
  }
  return 0;
}

int main() {
  int board[N][N], marks[N][N] = {0};
  initialize_board(board);
  printf("Welcome to the Bingo Simulator!\n\n");
  while(1) {
    printf("Press any key to generate a new number or 'Q' to quit.\n");
    char ch;
    scanf(" %c", &ch);
    if(ch == 'Q' || ch == 'q') {
      break;
    }
    int rand_num;
    while(1) {
      rand_num = rand() % MAX_NUM + 1;
      int flag = 0;
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          if(board[i][j] == rand_num && marks[i][j] == 0) {
            printf("The generated number is: %d\n", rand_num);
            marks[i][j] = 1; // Mark the number on the board
            print_board(board, marks);
            if(check_bingo(marks)) {
              printf("\nBINGO!! You have won the game!\n");
              return 0;
            }
            flag = 1;
          }
          if(flag == 1) {
            break;
          }
        }
        if(flag == 1) {
          break;
        }
      }
      if(flag == 1) {
        break;
      }
    }
  }
  printf("\nThanks for playing the Bingo Simulator!\n");
  return 0;
}