//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between lower and upper
int generateRandomNumber(int lower, int upper) {
  return rand() % (upper - lower + 1) + lower;
}

// function to check if a number exists in an array
int contains(int number, int* array, int size) {
  for (int i = 0; i < size; i++) {
    if (array[i] == number) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // initialize random seed
  srand(time(NULL));

  // create bingo card
  int bingoCard[5][5] = {{0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0}};

  // fill bingo card with random unique numbers
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 5; col++) {
      int lower = 1, upper = 25;
      int number = generateRandomNumber(lower, upper);
      while (contains(number, bingoCard[row], col + 1)) {
        number = generateRandomNumber(lower, upper);
      }
      bingoCard[row][col] = number;
    }
  }

  // print bingo card
  printf("B\tI\tN\tG\tO\n");
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 5; col++) {
      printf("%d\t", bingoCard[row][col]);
    }
    printf("\n");
  }

  // play bingo game
  printf("\nLet's play bingo!\n");
  int numbersCalled[25] = {0};
  int bingo = 0;
  while (!bingo) {
    // generate random number
    int number = generateRandomNumber(1, 25);
    while (contains(number, numbersCalled, 25)) {
      number = generateRandomNumber(1, 25);
    }
    numbersCalled[number - 1] = 1;

    // print number and check for bingo
    printf("Number called: %d\n", number);
    for (int row = 0; row < 5; row++) {
      int count = 0;
      for (int col = 0; col < 5; col++) {
        if (bingoCard[row][col] == number) {
          bingoCard[row][col] = 0;
        }
        if (bingoCard[row][col] == 0) {
          count++;
        }
      }
      if (count == 5) {
        printf("Bingo! Row %d\n", row + 1);
        bingo = 1;
      }
    }
    for (int col = 0; col < 5; col++) {
      int count = 0;
      for (int row = 0; row < 5; row++) {
        if (bingoCard[row][col] == 0) {
          count++;
        }
      }
      if (count == 5) {
        printf("Bingo! Column %d\n", col + 1);
        bingo = 1;
      }
    }
    int count = 0;
    for (int i = 0; i < 5; i++) {
      if (bingoCard[i][i] == 0) {
        count++;
      }
    }
    if (count == 5) {
      printf("Bingo! Diagonal 1\n");
      bingo = 1;
    }
    count = 0;
    for (int i = 0; i < 5; i++) {
      if (bingoCard[i][4 - i] == 0) {
        count++;
      }
    }
    if (count == 5) {
      printf("Bingo! Diagonal 2\n");
      bingo = 1;
    }
    printf("\n");
  }

  return 0;
}