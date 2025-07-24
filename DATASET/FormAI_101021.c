//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Welcome to the Bingo Simulator! This program will randomly generate a 5x5 Bingo card, 
  and then randomly select numbers until one player gets Bingo. Enjoy!
*/

int main() {
  int bingoCard[5][5];
  int numbersCalled[75];
  int numCount = 0;
  int currentNum;
  int bingo = 0;
  
  srand(time(NULL)); // seeding random number generator
  
  // filling bingo card with random numbers
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      bingoCard[i][j] = rand() % 15 + (j*15+1);
      if(i == 2 && j == 2) { // middle square is always free
        bingoCard[i][j] = 0;
      }
    }
  }
  
  // printing the bingo card
  printf("\n");
  printf("**********************************************\n");
  printf("\tWelcome to BINGO!\n");
  printf("**********************************************\n");
  printf("\n");
  printf("Here is your randomly generated Bingo card:\n\n");
  
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      printf("%d\t", bingoCard[i][j]);
    }
    printf("\n");
  }
  
  printf("\n");
  printf("**********************************************\n");
  printf("\n");
  
  // generating random numbers until someone gets Bingo
  while(!bingo) {
    currentNum = rand() % 75 + 1;
    
    // checking if number has already been called
    for(int i = 0; i < numCount; i++) {
      if(numbersCalled[i] == currentNum) {
        currentNum = rand() % 75 + 1;
        i = -1;
      }
    }
    
    numbersCalled[numCount] = currentNum;
    numCount++;
    
    printf("The number called is: %d\n", currentNum);
    
    // checking each row for Bingo
    for(int i = 0; i < 5; i++) {
      int inRow = 0;
      for(int j = 0; j < 5; j++) {
        if(bingoCard[i][j] == currentNum) {
          bingoCard[i][j] = 0; // marking number as called on the card
          inRow++;
        }
      }
      if(inRow == 5) {
        printf("BINGO! Someone got a Bingo on row %d!\n", i+1);
        bingo = 1;
        break;
      }
    }
    
    // checking each column for Bingo
    if(!bingo) {
      for(int i = 0; i < 5; i++) {
        int inCol = 0;
        for(int j = 0; j < 5; j++) {
          if(bingoCard[j][i] == 0) { // checking if number has been called for column j
            inCol++;
          }
        }
        if(inCol == 5) {
          printf("BINGO! Someone got a Bingo on column %d!\n", i+1);
          bingo = 1;
          break;
        }
      }
    }
    
    // checking diagonals for Bingo
    if(!bingo) {
      int inDiag1 = 0;
      int inDiag2 = 0;
      for(int i = 0; i < 5; i++) {
        if(bingoCard[i][i] == 0) { // checking diagonal from top left to bottom right
          inDiag1++;
        }
        if(bingoCard[4-i][i] == 0) { // checking diagonal from top right to bottom left
          inDiag2++;
        }
      }
      if(inDiag1 == 5) {
        printf("BINGO! Someone got a diagonal Bingo from top left to bottom right!\n");
        bingo = 1;
      }
      if(inDiag2 == 5) {
        printf("BINGO! Someone got a diagonal Bingo from top right to bottom left!\n");
        bingo = 1;
      }
    }
  }
  
  printf("\n");
  printf("**********************************************\n");
  printf("\n");
  printf("Thanks for playing BINGO!\n");
  printf("Here are all the numbers that were called:\n");
  
  for(int i = 0; i < numCount; i++) {
    printf("%d ", numbersCalled[i]);
  }
  
  printf("\n");
  printf("**********************************************\n");
  printf("\n");
  
  return 0;
}