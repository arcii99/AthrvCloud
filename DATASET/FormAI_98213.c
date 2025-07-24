//FormAI DATASET v1.0 Category: Poker Game ; Style: immersive
// Welcome to the immersive C Poker game!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define playing card structure
typedef struct {
    char suit[10];
    char face[5];
    int value;
} Card;

// define deck structure
typedef struct {
    Card cards[52];
    int size;
} Deck;

// initialize deck with 52 cards
void initDeck(Deck *deck) {
    char suits[4][10] = {"Hearts","Diamonds","Spades","Clubs"};
    char faces[13][5] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int values[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
    int i, j, k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck->cards[k].value = values[j];
            strcpy(deck->cards[k].suit, suits[i]);
            strcpy(deck->cards[k].face, faces[j]);
            k++;
        }
    }
    deck->size = 52;
}

// shuffle deck
void shuffleDeck(Deck *deck) {
    srand(time(NULL));
    int i, j;
    Card temp;
    for (i = 0; i < deck->size; i++) {
        j = rand() % deck->size;
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// deal card and remove from deck
Card dealCard(Deck *deck) {
    if (deck->size == 0) {
        printf("The deck is empty!\n");
        exit(1);
    }
    Card card = deck->cards[deck->size - 1];
    deck->size--;
    return card;
}

int main() {
    // create and shuffle deck
    Deck deck;
    initDeck(&deck);
    shuffleDeck(&deck);
    
    // deal two cards to player and two cards to dealer
    Card playerCards[2], dealerCards[2];
    playerCards[0] = dealCard(&deck);
    dealerCards[0] = dealCard(&deck);
    playerCards[1] = dealCard(&deck);
    dealerCards[1] = dealCard(&deck);
    
    // display player's cards and ask for input
    printf("Your cards:\n");
    printf("%s of %s\n", playerCards[0].face, playerCards[0].suit);
    printf("%s of %s\n", playerCards[1].face, playerCards[1].suit);
    printf("Enter 1 to hit or 2 to stay: ");
    int input;
    scanf("%d", &input);
    
    // handle player's input
    while (input == 1) {
        // deal another card to player
        Card newCard = dealCard(&deck);
        printf("You drew the %s of %s\n", newCard.face, newCard.suit);
        
        // calculate new total value of player's cards
        int total = playerCards[0].value + playerCards[1].value + newCard.value;
        
        // check if player busts
        if (total > 21) {
            printf("Bust! Your total is %d\n", total);
            exit(0);
        }
        
        // ask for input again
        printf("Enter 1 to hit or 2 to stay: ");
        scanf("%d", &input);
    }
    
    // dealer's turn
    printf("Dealer's turn:\n");
    printf("%s of %s\n", dealerCards[0].face, dealerCards[0].suit);
    printf("%s of %s\n", dealerCards[1].face, dealerCards[1].suit);
    int dealerTotal = dealerCards[0].value + dealerCards[1].value;
    while (dealerTotal < 17) {
        // dealer draws another card
        Card newCard = dealCard(&deck);
        printf("Dealer drew the %s of %s\n", newCard.face, newCard.suit);
        
        // calculate new total value of dealer's cards
        dealerTotal += newCard.value;
    }
    
    // determine winner
    int playerTotal = playerCards[0].value + playerCards[1].value;
    printf("Your total: %d\n", playerTotal);
    printf("Dealer's total: %d\n", dealerTotal);
    if (playerTotal > dealerTotal || dealerTotal > 21) {
        printf("You win!\n");
    } else if (dealerTotal > playerTotal) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}