//FormAI DATASET v1.0 Category: Poker Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int deck[]);
void dealCards(int deck[], int playerCards[][2]);
void printCards(int playerCards[][2], int playerNum);
int checkScore(int playerCards[][2], int playerNum);

int main() {
  int deck[52];
  int playerOneCards[2][2], playerTwoCards[2][2];
  int playerOneScore, playerTwoScore;
  
  printf("Welcome to the immersive C Poker Game!\n\n");
  
  srand(time(NULL));
  
  shuffle(deck);
  
  dealCards(deck, playerOneCards);
  dealCards(deck, playerTwoCards);
  
  printf("Player 1, your cards are:\n");
  printCards(playerOneCards, 1);
  
  printf("\nPlayer 2, your cards are:\n");
  printCards(playerTwoCards, 2);
  
  playerOneScore = checkScore(playerOneCards, 1);
  playerTwoScore = checkScore(playerTwoCards, 2);
  
  printf("\nPlayer 1 score: %d\n", playerOneScore);
  printf("Player 2 score: %d\n", playerTwoScore);
  
  if(playerOneScore > playerTwoScore) {
    printf("\nPlayer 1 wins!\n");
  }
  else if(playerTwoScore > playerOneScore) {
    printf("\nPlayer 2 wins!\n");
  }
  else {
    printf("\nIt's a tie!\n");
  }
  
  return 0;
}

void shuffle(int deck[]) {
  int i;
  
  for(i = 0; i < 52; i++) {
    deck[i] = i;
  }
  
  for(i = 0; i < 52; i++) {
    int randomIndex = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[randomIndex];
    deck[randomIndex] = temp;
  }
}

void dealCards(int deck[], int playerCards[][2]) {
  static int currentCardIndex = 0;
  
  playerCards[0][0] = deck[currentCardIndex++];
  playerCards[0][1] = deck[currentCardIndex++];
  playerCards[1][0] = deck[currentCardIndex++];
  playerCards[1][1] = deck[currentCardIndex++];
}

void printCards(int playerCards[][2], int playerNum) {
  int i;
  char suits[4] = {'H', 'D', 'C', 'S'};
  char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  
  for(i = 0; i < 2; i++) {
    printf("%c%c ", ranks[playerCards[i][0] % 13], suits[playerCards[i][0] / 13]);
    printf("%c%c\n", ranks[playerCards[i][1] % 13], suits[playerCards[i][1] / 13]);
  }
}

int checkScore(int playerCards[][2], int playerNum) {
  int i, score = 0;
  int ranks[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
  
  for(i = 0; i < 2; i++) {
    score += ranks[playerCards[i][0] % 13] + ranks[playerCards[i][1] % 13];
  }
  
  printf("\nPlayer %d score is %d\n", playerNum, score);
  
  return score;
}