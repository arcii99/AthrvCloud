//FormAI DATASET v1.0 Category: Poker Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  char rank[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
  char suit[4] = {'C', 'D', 'H', 'S'};
  char card[2], player1[2], player2[2];
  int deck[52], i, j, k, player1_score = 0, player2_score = 0;
  srand(time(NULL)); // seed the random number generator
  
  // create the deck
  for(i = 0; i < 52; i++){
    deck[i] = i;
  }

  // shuffle the deck
  for(i = 0; i < 52; i++){
    j = rand() % 52;
    k = deck[i];
    deck[i] = deck[j];
    deck[j] = k;
  }

  // deal the cards to the players
  for(i = 0; i < 5; i++){
    // player1
    k = deck[i];
    sprintf(card, "%c%c", rank[k % 13], suit[k / 13]);
    printf("Player 1's card %d: %s\n", i+1, card);
    player1_score += k % 13 + 2; // add the rank value to player1's score
    player1[i] = k; // store the card in player1's hand
    
    // player2
    k = deck[i+5];
    sprintf(card, "%c%c", rank[k % 13], suit[k / 13]);
    printf("Player 2's card %d: %s\n", i+1, card);
    player2_score += k % 13 + 2; // add the rank value to player2's score
    player2[i] = k; // store the card in player2's hand
  }

  // determine the winner
  if(player1_score > player2_score){
    printf("Player 1 wins!\n");
  }
  else if(player2_score > player1_score){
    printf("Player 2 wins!\n");
  }
  else{
    printf("It's a tie!\n");
  }

  return 0;
}