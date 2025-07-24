//FormAI DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define BOARD_SQUARES BOARD_SIZE * BOARD_SIZE

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Define the board
  int board[BOARD_SIZE][BOARD_SIZE];

  // Generate random numbers
  int numbers[BOARD_SQUARES/2];
  for (int i=0; i<BOARD_SQUARES/2; i++) {
    numbers[i] = (rand() % (BOARD_SQUARES/2)) + 1;
  }

  // Shuffle the numbers
  for (int i=0; i<BOARD_SQUARES/2; i++) {
    int j = rand() % (BOARD_SQUARES/2);
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }

  // Place the numbers on the board
  for (int i=0; i<BOARD_SQUARES/2; i++) {
    for (int j=0; j<2; j++) {
      int x, y;
      do {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
      } while (board[x][y] != 0);
      board[x][y] = numbers[i];
    }
  }

  // Print the board (with hidden numbers)
  printf("   ");
  for (int i=1; i<=BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i=0; i<BOARD_SIZE; i++) {
    printf("%d  ", i+1);
    for (int j=0; j<BOARD_SIZE; j++) {
      printf("# ");
    }
    printf("\n");
  }

  // Play the game
  int score = 0;
  int guesses = 0;
  int x1, y1, x2, y2;
  do {
    printf("Enter first guess (row column): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter second guess (row column): ");
    scanf("%d %d", &x2, &y2);

    if (board[x1-1][y1-1] == board[x2-1][y2-1]) {
      score += 2;
      board[x1-1][y1-1] = -1;
      board[x2-1][y2-1] = -1;
      printf("Match!\n\n");
    } else {
      printf("No match.\n\n");
    }
    guesses++;
  } while (score < BOARD_SQUARES && guesses < BOARD_SQUARES*2);

  // Print the final board (with revealed numbers)
  printf("   ");
  for (int i=1; i<=BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i=0; i<BOARD_SIZE; i++) {
    printf("%d  ", i+1);
    for (int j=0; j<BOARD_SIZE; j++) {
      if (board[i][j] == -1) {
        printf("%d ", numbers[(i*BOARD_SIZE + j)/2]);
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }

  // Print the final score
  printf("Final score: %d\n", score);

  return 0;
}