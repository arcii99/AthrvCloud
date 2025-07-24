//FormAI DATASET v1.0 Category: Poker Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int rank, suit;
} card;

void initDeck(card *deck);
void shuffleDeck(card *deck);
void printHand(card *hand, int numCards);
int calculateHandValue(card *hand, int numCards);

int main(){
    srand(time(NULL));

    card deck[52];
    card playerHand[5];
    card dealerHand[5];
    int playerCardsLeft = 5;
    int dealerCardsLeft = 5;

    initDeck(deck);
    shuffleDeck(deck);

    // Deal initial hands
    for(int i=0; i<2; i++){
        playerHand[i] = deck[playerCardsLeft-1];
        dealerHand[i] = deck[dealerCardsLeft-1];
        playerCardsLeft--;
        dealerCardsLeft--;
    }

    printf("Player's hand:\n");
    printHand(playerHand, 2);
    printf("\n");

    // Player's turn
    int playerHandValue = calculateHandValue(playerHand, 2);
    char hitOrStand = 'h';
    while(hitOrStand == 'h'){
        printf("Player, would you like to hit(h) or stand(s)? ");
        scanf(" %c", &hitOrStand);

        if(hitOrStand == 'h'){
            playerHand[playerCardsLeft] = deck[playerCardsLeft-1];
            playerCardsLeft--;
            printf("Player's hand:\n");
            printHand(playerHand, playerCardsLeft+1);
            playerHandValue = calculateHandValue(playerHand, playerCardsLeft+1);
            if(playerHandValue > 21){
                printf("Bust! Player loses.\n");
                exit(0);
            }
        }
    }

    // Dealer's turn
    int dealerHandValue = calculateHandValue(dealerHand, 2);
    while(dealerHandValue < 17){
        dealerHand[dealerCardsLeft] = deck[dealerCardsLeft-1];
        dealerCardsLeft--;
        dealerHandValue = calculateHandValue(dealerHand, dealerCardsLeft+1);
    }

    printf("\nDealer's hand:\n");
    printHand(dealerHand, dealerCardsLeft+1);

    // Determine winner
    if(dealerHandValue > 21){
        printf("Dealer busts! Player wins.\n");
        exit(0);
    }else if(dealerHandValue >= playerHandValue){
        printf("Dealer wins.\n");
        exit(0);
    }else{
        printf("Player wins!\n");
        exit(0);
    }
}

void initDeck(card *deck){
    int i = 0;
    for(int rank=1; rank<=13; rank++){
        for(int suit=0; suit<4; suit++){
            deck[i].rank = rank;
            deck[i].suit = suit;
            i++;
        }
    }
}

void shuffleDeck(card *deck){
    for(int i=0; i<52; i++){
        int swapIndex = rand() % 52;
        card temp = deck[i];
        deck[i] = deck[swapIndex];
        deck[swapIndex] = temp;
    }
}

void printHand(card *hand, int numCards){
    for(int i=0; i<numCards; i++){
        int rank = hand[i].rank;
        int suit = hand[i].suit;
        char suitSymbol;
        if(suit == 0){
            suitSymbol = 'H';
        }else if(suit == 1){
            suitSymbol = 'D';
        }else if(suit == 2){
            suitSymbol = 'C';
        }else{
            suitSymbol = 'S';
        }

        printf("%d%c ", rank, suitSymbol);
    }
    printf("\n");
}

int calculateHandValue(card *hand, int numCards){
    int totalValue = 0;
    int numAces = 0;
    for(int i=0; i<numCards; i++){
        int rank = hand[i].rank;
        if(rank >= 10 && rank <= 13){
            totalValue += 10;
        }else if(rank == 1){
            totalValue += 11;
            numAces++;
        }else{
            totalValue += rank;
        }
    }

    // Handle any aces that may need to be counted as 1 instead of 11
    for(int i=0; i<numAces; i++){
        if(totalValue > 21){
            totalValue -= 10;
        }
    }

    return totalValue;
}