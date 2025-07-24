//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// function to print the bingo card
void printCard(int card[ROWS][COLS]) {
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      printf("%3d ", card[i][j]);
    }
    printf("\n");
  }
}

// function to check if the player has won
int checkWin(int card[ROWS][COLS], int calledNums[]) {
  int cnt = 0;
  for(int i=0; i<ROWS; i++) {
    int flag = 1;
    for(int j=0; j<COLS; j++) {
      if(card[i][j]!=-1 && !calledNums[card[i][j]]) {
        flag = 0;
        break;
      }
    }
    if(flag) cnt++;
  }
  for(int i=0; i<COLS; i++) {
    int flag = 1;
    for(int j=0; j<ROWS; j++) {
      if(card[j][i]!=-1 && !calledNums[card[j][i]]) {
        flag = 0;
        break;
      }
    }
    if(flag) cnt++;
  }
  int flag1 = 1, flag2 = 1;
  for(int i=0; i<ROWS; i++) {
    if(card[i][i]!=-1 && !calledNums[card[i][i]]) {
      flag1 = 0;
      break;
    }
  }
  for(int i=0; i<ROWS; i++) {
    if(card[i][COLS-1-i]!=-1 && !calledNums[card[i][COLS-1-i]]) {
      flag2 = 0;
      break;
    }
  }
  if(flag1) cnt++;
  if(flag2) cnt++;
  return cnt;
}

int main() {
  srand(time(NULL));
  int card[ROWS][COLS];
  int calledNums[76] = {0};
  printf("Welcome to the Bingo Simulator!\n");
  printf("Here is your bingo card:\n");
  // generate random numbers for the card
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      if(j==2 && i==2) {
        card[i][j] = -1;
      } else {
        int num;
        do {
          num = rand()%15 + 15*j + 1;
        } while(calledNums[num]);
        card[i][j] = num;
        calledNums[num] = 1;
      }
    }
  }
  printCard(card);
  int cnt = 0;
  while(cnt<5) {
    // generate random number
    int num;
    do {
      num = rand()%75 + 1;
    } while(calledNums[num]);
    printf("The next number called is: %d\n", num);
    calledNums[num] = 1;
    int won = checkWin(card, calledNums);
    if(won>cnt) {
      printf("Congratulations! You have %d lines.\n", won);
      cnt = won;
    }
  }
  printf("Bingo! You have won!\n");
  return 0;
}