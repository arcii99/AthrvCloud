//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function declaration */
void bingo();

/* global variables */
int numCalls = 0;
int card[5][5];
int called[25];
int rowCrossed, colCrossed, diagCrossed;    

/* main function */
int main() {
  int i, j;

  /* seed the random number generator */
  srand(time(NULL)); 

  /* generate the bingo card */
  printf("-------------------\nWelcome to Bingo Game!\n-------------------\n");
  printf("Here is your card:\n");
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (i == 2 && j == 2) {
        card[i][j] = 0;
        printf("|      ");
      } else {
        card[i][j] = rand() % 15 + (15*j)+1;
        printf("|%2d    ", card[i][j]);
      }
    }
    printf("|\n");
  }

  /* play the game */
  bingo();
}

/* function definition */
void bingo() {
  int i, j, num;
  char choice;

  /* ask user if they are ready to begin */
  printf("Are you ready to play? (y/n): ");
  scanf(" %c", &choice);

  /* check if user is ready */
  if (choice == 'y' || choice == 'Y') {
    
    /* game loop */
    while (1) {
      /* generate a random number */
      num = rand() % 75 + 1;
     
      /* check if number has been called already */
      for (i = 0; i < numCalls; i++) {
        if (called[i] == num) {
          break;
        }
      }
      
      /* number has not been called before */
      if (i == numCalls) {
        printf("Number called: %d\n", num);
        called[numCalls++] = num;
        rowCrossed = colCrossed = diagCrossed = 0;

        /* check if number appears on the card */
        for (i = 0; i < 5; i++) {
          for (j = 0; j < 5; j++) {
            if (card[i][j] == num) {
              card[i][j] = 0;
              printf("Number found at row %d, column %d!\n", i+1, j+1);
            }
          }
        }

        /* check if a row is crossed */
        for (i = 0; i < 5; i++) {
          if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0) {
            rowCrossed = 1;
            printf("Row %d crossed!\n", i+1);
          }
        }

        /* check if a column is crossed */
        for (i = 0; i < 5; i++) {
          if (card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 && card[3][i] == 0 && card[4][i] == 0) {
            colCrossed = 1;
            printf("Column %d crossed!\n", i+1);
          }
        }

        /* check if a diagonal is crossed */
        if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
          diagCrossed = 1;
          printf("Diagonal (left to right) crossed!\n");
        }
        if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
          diagCrossed = 1;
          printf("Diagonal (right to left) crossed!\n");
        }

        /* check if a winning pattern has been formed */
        if (rowCrossed || colCrossed || diagCrossed) {
          printf("Bingo! You win!\n");
          break;
        }
      } else {
        /* number has been called before */
        printf("Number %d has already been called.\n", num);
      }

      /* ask user if they want to continue */
      printf("Do you want to continue? (y/n): ");
      scanf(" %c", &choice);

      /* check if user wants to continue */
      if (choice == 'n' || choice == 'N') {
        break;
      }
    }
  } else {
    /* user not ready to play */
    printf("Goodbye!");
  }
}