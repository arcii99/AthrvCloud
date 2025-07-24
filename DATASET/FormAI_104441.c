//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Bingo Simulator!\n");
  printf("Get ready to shout BINGO!\n\n");

  // Initialize the bingo card
  int card[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      card[i][j] = (j == 2 && i == 2) ? 0 : (i * 15) + (j * 3) + rand() % 3;
    }
  }

  // Shuffle the numbers for the caller
  int numbers[75];
  for (int i = 0; i < 75; i++) {
    numbers[i] = i + 1;
  }
  srand(time(NULL));
  for (int i = 0; i < 75; i++) {
    int temp = numbers[i];
    int randomIndex = rand() % 75;
    numbers[i] = numbers[randomIndex];
    numbers[randomIndex] = temp;
  }

  // Start calling numbers
  int bingoCount = 0;
  for (int i = 0; i < 75; i++) {
    int number = numbers[i];

    printf("The caller says...\nB%d!\n", number);

    // Check the card for the number
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (card[i][j] == number) {
          card[i][j] = 0;
        }
      }
    }

    // Check for a bingo
    int anyBingo = 0;
    for (int i = 0; i < 5; i++) {
      int rowSum = 0, colSum = 0, diagSum = 0, rDiagSum = 0;
      for (int j = 0; j < 5; j++) {
        rowSum += card[i][j];
        colSum += card[j][i];
        if (i == j) diagSum += card[i][j];
        if (i + j == 4) rDiagSum += card[i][j];
      }
      if (rowSum == 0 || colSum == 0 || diagSum == 0 || rDiagSum == 0) {
        printf("BINGO!\n");
        anyBingo = 1;
        bingoCount++;
      }
    }

    if (bingoCount == 1) {
      printf("You got your first BINGO! Keep going!\n\n");
    } else if (bingoCount > 1) {
      printf("You got another BINGO! Keep going!\n\n");
    }

    if (anyBingo && bingoCount < 5) {
      printf("You need %d more BINGOs to win!\n\n", 5 - bingoCount);
    } else if (bingoCount == 5) {
      printf("Congratulations! You've won BINGO!\n");
      break;
    }
  }

  return 0;
}