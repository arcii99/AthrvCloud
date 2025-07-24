//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define EMPTY 0
#define RANGE 15

void print_card(int card[ROWS][COLS]) {
  printf("B\tI\tN\tG\tO\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == 2 && j == 2) printf("F");
      else if (card[i][j] == EMPTY) printf("\t");
      else printf("%d\t", card[i][j]);
    }
    printf("\n");
  }
}

void fill_card(int card[ROWS][COLS]) {
  int nums[RANGE];
  for (int i = 0; i < RANGE; i++) nums[i] = i+1;
  srand(time(NULL));
  for (int i = 0; i < ROWS; i++) {
    int start = i * RANGE / ROWS;
    for (int j = 0; j < COLS; j++) {
      if (i == 2 && j == 2) continue;
      int index = rand() % (RANGE / COLS) + j * RANGE / COLS + start;
      card[i][j] = nums[index];
      nums[index] = nums[j * RANGE / COLS + start];
    }
  }
}

int check_card(int card[ROWS][COLS], int num) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (card[i][j] == num) {
        card[i][j] = EMPTY;
        return 1;
      }
    }
  }
  return 0;
}

int check_bingo(int card[ROWS][COLS]) {
  int sum;
  for (int i = 0; i < ROWS; i++) {
    sum = 0;
    for (int j = 0; j < COLS; j++) {
      sum += card[i][j];
    }
    if (sum == EMPTY * COLS) return 1;
  }
  for (int j = 0; j < COLS; j++) {
    sum = 0;
    for (int i = 0; i < ROWS; i++) {
      sum += card[i][j];
    }
    if (sum == EMPTY * ROWS) return 1;
  }
  sum = 0;
  for (int i = 0; i < ROWS; i++) {
    sum += card[i][i];
  }
  if (sum == EMPTY * ROWS) return 1;
  sum = 0;
  for (int i = 0; i < ROWS; i++) {
    sum += card[i][COLS - i - 1];
  }
  if (sum == EMPTY * ROWS) return 1;
  return 0;
}

int main() {
  int card[ROWS][COLS];
  int num;
  fill_card(card);
  print_card(card);
  do {
    printf("Enter a number (1- %d): ", RANGE);
    scanf("%d", &num);
    if (num >= 1 && num <= RANGE) {
      if (check_card(card, num)) {
        if (check_bingo(card)) {
          printf("BINGO!\n");
          break;
        } else {
          printf("Good!\n");
        }
      } else {
        printf("Number already appeared or doesn't exist.\n");
      }
    } else {
      printf("Invalid number.\n");
    }
    print_card(card);
  } while(1);

  return 0;
}