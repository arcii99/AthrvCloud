//FormAI DATASET v1.0 Category: Poker Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function Declarations */
void dealCards(int *, int *);
void printHand(int *);
int getCardValue(int);
void evaluateHands(int *, int *);

/* Main Function */
int main() {
  int myHand[5], dealerHand[5], i;
  char playAgain;

  //Initialize random seed
  srand(time(NULL));

  //Begin game loop
  do {
    printf("Dealing cards...\n");

    //Deal cards for player and dealer
    dealCards(myHand, dealerHand);

    printf("Your hand:\n");
    printHand(myHand);

    //Ask player if they want to draw an additional card
    printf("Would you like to draw an additional card? (y/n) ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y') {
      //Draw additional card for player
      myHand[4] = rand() % 52;
    }

    printf("\nDealer hand:\n");
    printHand(dealerHand);

    //Evaluate hands and output winner
    evaluateHands(myHand, dealerHand);

    printf("Would you like to play again? (y/n) ");
    scanf(" %c", &playAgain);

  } while (playAgain == 'y');

  return 0;
}

/* Function Definitions */

/* dealCards: function that deals two cards to both the player and dealer */
void dealCards(int *myHand, int *dealerHand) {
  int i, j, card;

  for (i = 0; i < 4; i++) {
    card = rand() % 52;
    //Check to see if card is already in a hand
    for (j = 0; j < i; j++) {
      if (card == myHand[j] || card == dealerHand[j]) {
        card = rand() % 52;
        j = -1;
      }
    }
    //Add card to hand
    if (i % 2 == 0) {
      myHand[i / 2] = card;
    } else {
      dealerHand[i / 2] = card;
    }
  }
}

/* printHand: function that prints out the contents of a hand */
void printHand(int *hand) {
  int i;

  for (i = 0; i < 5; i++) {
    if (hand[i] == -1) {
      continue;
    }
    printf("%d ", getCardValue(hand[i]));
  }
  printf("\n");
}

/* getCardValue: function that returns the point value of a card */
int getCardValue(int card) {
  int value = card % 13;

  if (value == 0) {
    return 11;
  } else if (value > 8) {
    return 10;
  } else {
    return value + 1;
  }
}

/* evaluateHands: function that evaluates the player and dealer hands and determines the winner */
void evaluateHands(int *myHand, int *dealerHand) {
  int myTotal = 0, dealerTotal = 0, i;

  //Calculate player's total
  for (i = 0; i < 5; i++) {
    myTotal += getCardValue(myHand[i]);
  }

  //Calculate dealer's total
  for (i = 0; i < 5; i++) {
    dealerTotal += getCardValue(dealerHand[i]);
  }

  //Determine winner
  if (myTotal > dealerTotal && myTotal <= 21) {
    printf("Congratulations! You win!\n");
  } else if (dealerTotal > myTotal && dealerTotal <= 21) {
    printf("Dealer wins. Better luck next time!\n");
  } else if (myTotal > 21) {
    printf("Busted! Dealer wins.\n");
  } else if (dealerTotal > 21) {
    printf("Dealer busted! Congratulations, you win!\n");
  } else {
    printf("It's a tie! Nobody wins.\n");
  }
}