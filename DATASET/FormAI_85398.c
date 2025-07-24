//FormAI DATASET v1.0 Category: Poker Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NumberOfCards 52
#define NumberOfPlayers 4

typedef enum{
  Hearts,
  Diamonds,
  Clubs,
  Spades
} Suit;

typedef struct{
  Suit suit;
  int value;
} Card;

int main(){
  Card deck[NumberOfCards]; //creating a card deck array
  int i, j, k;

  srand(time(NULL)); //initialize random number generator

  for(i = 0; i < NumberOfCards; i++){ //loop to generate deck of cards
    deck[i].value = (i % 13) + 1; //assigns value to cards
    if(i < 13) deck[i].suit = Hearts; //assigns suit to cards
    else if(i < 26) deck[i].suit = Diamonds;
    else if(i < 39) deck[i].suit = Clubs;
    else deck[i].suit = Spades;
  }

  //shuffle deck
  for(i = 0; i < NumberOfCards; i++){
    int j = rand() % NumberOfCards;
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  //deal cards to players
  Card playerHands[NumberOfPlayers][5];
  for(i = 0; i < NumberOfPlayers; i++){
    for(j = 0; j < 5; j++){
      playerHands[i][j] = deck[(i*5) + j];
    }
  }

  //print each player's hand
  for(i = 0; i < NumberOfPlayers; i++){
    printf("Player %d:\n", i+1);
    for(j = 0; j < 5; j++){
      printf("%d of ", playerHands[i][j].value);
      switch(playerHands[i][j].suit){
        case Hearts:
          printf("Hearts");
          break;
        case Diamonds:
          printf("Diamonds");
          break;
        case Clubs:
          printf("Clubs");
          break;
        case Spades:
          printf("Spades");
          break;
      }
      printf("\n");
    }
  }

  return 0;
}