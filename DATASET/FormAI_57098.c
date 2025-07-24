//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void drawCard(int card[]);
void displayCard(int card[]);
int callNumber(int calledNums[]);
int checkWin(int card[]);

int main() {
  // initialize variables and arrays
  int card[25] = {0};
  int calledNums[75] = {0};
  int numCalled = 0;
  int win = 0;
  
  // seed random number generator
  srand(time(0));
  
  // print greeting
  printf("Welcome to Bingo Simulator!\n");
  
  // draw player's card
  drawCard(card);
  printf("Here is your card:\n");
  displayCard(card);
  
  // main game loop
  while (win == 0) {

    // call next number
    numCalled = callNumber(calledNums);

    // check number against player's card
    for (int i = 0; i < 25; i++) {
      if (card[i] == numCalled) {
        card[i] = -1;   // mark number as called on player's card
      }
    }

    // display called number
    printf("\n%d is called!\n", numCalled);

    // display updated player's card
    printf("Here is your card:\n");
    displayCard(card);

    // check for win
    win = checkWin(card);

    // if player wins
    if (win == 1) {
      printf("\nCongratulations! You've won!\n");
      break;
    }

    // delay before next call
    printf("\nNext call will be in 3 seconds.\n");
    printf("Please wait...\n");
    sleep(3);
  }

  // print ending message
  printf("\nThanks for playing Bingo Simulator!\n");
  return 0;
}

// function to draw player's card
void drawCard(int card[]) {
  int drawnNums = 0;
  int randNum;

  while (drawnNums < 25) {
    randNum = (rand() % 75) + 1;  // generate random number between 1 and 75
    int duplicate = 0;
    for (int i = 0; i < 25; i++) {
      if (randNum == card[i]) {   // check if number is already on card
        duplicate = 1;
        break;
      }
    }
    if (duplicate == 0) {         // if number is not already on card, add it
      card[drawnNums] = randNum;
      drawnNums++;
    }
  }
  return;
}

// function to display player's card
void displayCard(int card[]) {
  for (int i = 0; i < 25; i++) {
    if (i == 12) {
      printf("\n");
    }
    if (card[i] == -1) {   // if number is called, print X instead
      printf("X\t");
    } else {
      printf("%d\t", card[i]);
    }
  }
  printf("\n");
  return;
}

// function to call next number
int callNumber(int calledNums[]) {
  int randNum;

  while (1) {
    randNum = (rand() % 75) + 1;  // generate random number between 1 and 75
    
    // check if number has already been called
    int duplicate = 0;
    for (int i = 0; i < 75; i++) {
      if (randNum == calledNums[i]) {
        duplicate = 1;
        break;
      }
    }
    if (duplicate == 0) {         // if number has not been called, add it to calledNums array and return it
      calledNums[randNum - 1] = randNum;
      return randNum;
    }
  }
}

// function to check for win
int checkWin(int card[]) {
  int win = 0;

  // check for horizontal lines
  for (int i = 0; i < 25; i += 5) {
    if (card[i] == -1 && card[i+1] == -1 && card[i+2] == -1 && card[i+3] == -1 && card[i+4] == -1) {
      win = 1;
      break;
    }
  }

  // check for vertical lines
  if (win == 0) {
    for (int i = 0; i < 5; i++) {
      if (card[i] == -1 && card[i+5] == -1 && card[i+10] == -1 && card[i+15] == -1 && card[i+20] == -1) {
        win = 1;
        break;
      }
    }
  }

  // check for diagonal lines
  if (win == 0) {
    if (card[0] == -1 && card[6] == -1 && card[12] == -1 && card[18] == -1 && card[24] == -1) {
      win = 1;
    } else if (card[4] == -1 && card[8] == -1 && card[12] == -1 && card[16] == -1 && card[20] == -1) {
      win = 1;
    }
  }

  return win;
}