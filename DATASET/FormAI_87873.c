//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define RANGE 75

int main()
{
  int numbers[RANGE];
  int bingo[ROWS][COLS];

  // fill array with numbers 1 - 75
  for(int i = 0; i < RANGE; i++) {
    numbers[i] = i+1;
  }

  // shuffle array
  srand(time(NULL));
  for(int i = 0; i < RANGE; i++){
    int randomIndex = rand() % RANGE;
    int temp = numbers[i];
    numbers[i] = numbers[randomIndex];
    numbers[randomIndex] = temp; 
  }

  // initialize bingo card array with 0's
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      bingo[i][j] = 0;
    }
  }

  // place numbers on bingo card
  int numIndex = 0;
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      if(i == 2 && j == 2) {
        continue; // middle spot is free space
      }
      bingo[i][j] = numbers[numIndex];
      numIndex++;
    }
  }

  // print bingo card
  printf("\n------BINGO CARD------\n\n");
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      if(bingo[i][j] == 0){
        printf(" [FREE] ");
      } else {
        printf(" [%2d] ", bingo[i][j]);
      }
    }
    printf("\n");
  }

  // play bingo
  int numCalls = 0;
  int gameOver = 0;
  while(!gameOver) {
    printf("\nPlease enter the number called (1-75): ");
    int calledNum;
    scanf("%d", &calledNum);
    numCalls++;

    // check if number is on bingo card
    for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLS; j++) {
        if(bingo[i][j] == calledNum) {
          printf("\nNumber %d found on card!\n", calledNum);
          bingo[i][j] = 0;
          // check for bingo
          if((bingo[0][0] == 0 && bingo[0][1] == 0 && bingo[0][2] == 0 && bingo[0][3] == 0 && bingo[0][4] == 0) || // horizontal top row bingo
             (bingo[1][0] == 0 && bingo[1][1] == 0 && bingo[1][2] == 0 && bingo[1][3] == 0 && bingo[1][4] == 0) || // horizontal second row bingo
             (bingo[2][0] == 0 && bingo[2][1] == 0 && bingo[2][2] == 0 && bingo[2][3] == 0 && bingo[2][4] == 0) || // horizontal third row bingo
             (bingo[3][0] == 0 && bingo[3][1] == 0 && bingo[3][2] == 0 && bingo[3][3] == 0 && bingo[3][4] == 0) || // horizontal fourth row bingo
             (bingo[4][0] == 0 && bingo[4][1] == 0 && bingo[4][2] == 0 && bingo[4][3] == 0 && bingo[4][4] == 0) || // horizontal bottom row bingo
             (bingo[0][0] == 0 && bingo[1][0] == 0 && bingo[2][0] == 0 && bingo[3][0] == 0 && bingo[4][0] == 0) || // vertical left column bingo
             (bingo[0][1] == 0 && bingo[1][1] == 0 && bingo[2][1] == 0 && bingo[3][1] == 0 && bingo[4][1] == 0) || // vertical second column bingo
             (bingo[0][2] == 0 && bingo[1][2] == 0 && bingo[2][2] == 0 && bingo[3][2] == 0 && bingo[4][2] == 0) || // vertical third column bingo
             (bingo[0][3] == 0 && bingo[1][3] == 0 && bingo[2][3] == 0 && bingo[3][3] == 0 && bingo[4][3] == 0) || // vertical fourth column bingo
             (bingo[0][4] == 0 && bingo[1][4] == 0 && bingo[2][4] == 0 && bingo[3][4] == 0 && bingo[4][4] == 0) || // vertical right column bingo
             (bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) || // diagonal top-left to bottom-right bingo
             (bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0))   // diagonal top-right to bottom-left bingo
          {
            printf("\nBINGO! You win!\n");
            printf("You called %d numbers before getting a bingo.\n", numCalls);
            gameOver = 1;
          }
          break;
        }
      }
      if(gameOver) break;
    }
    if(!gameOver){
      printf("\nNumber %d not found on card.\n", calledNum);
    }
  }

  return 0;
}