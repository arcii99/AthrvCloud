//FormAI DATASET v1.0 Category: Poker Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to initialize deck of cards
void initializeDeck(int deck[][13]){
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            deck[i][j] = 0;    //0 represents the card is not yet dealt
        }
    }
}

//function to deal the cards to players
void dealCards(int deck[][13], int playerCards[][5]){
    int randSuit, randRank;

    //deal 2 cards to each player
    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++){
            do{
                randSuit = rand() % 4;
                randRank = rand() % 13;
            }while(deck[randSuit][randRank] != 0);   //check if the card is already dealt
            playerCards[j][i] = randSuit*100 + randRank;   //store the card as 100 * suit + rank
            deck[randSuit][randRank] = 1;   //mark the card as dealt
        }
    }
}

//function to print the cards of each player
void printCards(int playerCards[][5]){
    char ranks[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    char suits[] = {'C','D','H','S'};

    //print the cards of each player
    for(int i=0;i<5;i++){
        printf("Player %d: ", i+1);
        for(int j=0;j<2;j++){
            int rank = playerCards[i][j] % 100;    //extracting rank
            int suit = playerCards[i][j] / 100;    //extracting suit
            printf("%c%c ", ranks[rank], suits[suit]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));   //seeding the random number generator

    int deck[4][13];
    initializeDeck(deck);   //initialize the deck of cards

    int playerCards[5][2];
    dealCards(deck, playerCards);   //deal the cards to players

    printCards(playerCards);   //print the cards of each player

    return 0;
}