//FormAI DATASET v1.0 Category: Poker Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define global variables for card values and suits
char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

// Define a struct for a card
struct card{
    int value;
    char *suit;
};

// Define a struct for the deck
struct deck{
    struct card cards[52];
    int position;
};

// Define a function to create a new deck
struct deck createDeck(){
    struct deck newDeck;
    int counter = 0;
    // Loop through all card values and suits to create 52 cards in the deck
    for(int i=0; i<13; i++){
        for(int j=0; j<4; j++){
            struct card newCard = {i+1, suits[j]};
            newDeck.cards[counter] = newCard;
            counter++;
        }
    }
    newDeck.position = 0;
    return newDeck;
}

// Define a function to print all cards in the deck
void printDeck(struct deck *deck){
    for(int i=0; i<52; i++){
        printf("%s of %s\n", values[deck->cards[i].value-1], deck->cards[i].suit);
    }
}

// Define a function to shuffle the deck
void shuffleDeck(struct deck *deck){
    srand(time(NULL));
    // Swap each card with a random card in the deck
    for(int i=0; i<52; i++){
        int randomIndex = rand() % 52;
        struct card temp = deck->cards[i];
        deck->cards[i] = deck->cards[randomIndex];
        deck->cards[randomIndex] = temp;
    }
    deck->position = 0;
}

// Define a function to deal a card from the deck
struct card dealCard(struct deck *deck){
    struct card dealtCard = deck->cards[deck->position];
    deck->position++;
    return dealtCard;
}

// Define a main function to play the game
int main(){
    struct deck gameDeck = createDeck();
    shuffleDeck(&gameDeck);
    // Deal two cards to the player and the dealer
    struct card playerCards[2];
    playerCards[0] = dealCard(&gameDeck);
    playerCards[1] = dealCard(&gameDeck);
    struct card dealerCards[2];
    dealerCards[0] = dealCard(&gameDeck);
    dealerCards[1] = dealCard(&gameDeck);
    printf("Player has:\n%s of %s\n%s of %s\n", values[playerCards[0].value-1], playerCards[0].suit, values[playerCards[1].value-1], playerCards[1].suit);
    printf("Dealer has:\n%s of %s\n?\n", values[dealerCards[0].value-1], dealerCards[0].suit);
    // Loop for the player's turn
    int playerPoints = playerCards[0].value + playerCards[1].value;
    int dealerPoints = dealerCards[0].value + dealerCards[1].value;
    int turn = 0;
    char hitOrStand = ' ';
    while(playerPoints < 21 && turn == 0){
        printf("Do you want to hit or stand? (h/s): ");
        scanf(" %c", &hitOrStand);
        if(hitOrStand == 'h'){
            struct card newCard = dealCard(&gameDeck);
            printf("Player draws:\n%s of %s\n", values[newCard.value-1], newCard.suit);
            playerPoints += newCard.value;
        }
        else if(hitOrStand == 's'){
            turn = 1;
        }
    }
    // Loop for the dealer's turn
    if(playerPoints <= 21){
        printf("Dealer's turn:\n");
        printf("Dealer has:\n%s of %s\n%s of %s\n", values[dealerCards[0].value-1], dealerCards[0].suit, values[dealerCards[1].value-1], dealerCards[1].suit);
        while(dealerPoints < 17){
            struct card newCard = dealCard(&gameDeck);
            printf("Dealer draws:\n%s of %s\n", values[newCard.value-1], newCard.suit);
            dealerPoints += newCard.value;
        }
        if(dealerPoints > 21 || dealerPoints < playerPoints){
            printf("Player wins!\n");
        }
        else if(dealerPoints > playerPoints){
            printf("Dealer wins!\n");
        }
        else{
            printf("Tie!\n");
        }
    }
    else{
        printf("Player busts! Dealer wins.\n");
    }
    return 0;
}