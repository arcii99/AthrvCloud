//FormAI DATASET v1.0 Category: Poker Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Define constants for card suits */
#define HEARTS "\u2665"
#define DIAMONDS "\u2666"
#define CLUBS "\u2663"
#define SPADES "\u2660"

/* Define constants for card ranks */
#define ACE "A"
#define KING "K"
#define QUEEN "Q"
#define JACK "J"

/* Define constants for the card deck */
#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define SHUFFLE_COUNT 250

/* Define card structure containing rank, suit, and value */
typedef struct {
    char rank[3];
    char suit[4];
    int value;
} Card;

/* Define function to initialize card deck */
void initDeck(Card *deck) {
    int i, j, k = 0;
    for(i = 0; i < NUM_RANKS; i++) {
        for(j = 0; j < NUM_SUITS; j++) {
            strcpy(deck[k].rank, i == 0 ? ACE : i == 12 ? KING : i == 11 ? QUEEN : i == 10 ? JACK : (i+1) + '0');
            strcpy(deck[k].suit, j == 0 ? HEARTS : j == 1 ? DIAMONDS : j == 2 ? CLUBS : SPADES);
            deck[k].value = i < 9 ? i+1 : 10;
            k++;
        }
    }
}

/* Define function to shuffle the card deck */
void shuffle(Card *deck) {
    int i, j, k;
    Card temp;
    srand(time(0));
    for(k = 0; k < SHUFFLE_COUNT; k++) {
        for(i = NUM_CARDS-1; i > 0; i--) {
            j = rand() % (i+1);
            temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
        }
    }
}

/* Define function to print a card */
void printCard(Card card) {
    printf("%s%s ", card.rank, card.suit);
}

/* Define function to print the player's hand */
void printPlayerHand(Card *hand, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

/* Define function to calculate the hand value */
int calculateHandValue(Card *hand, int size) {
    int i, value = 0, aces = 0;
    for(i = 0; i < size; i++) {
        value += hand[i].value;
        if(strcmp(hand[i].rank, ACE) == 0) {
            aces++;
        }
    }
    while(value > 21 && aces > 0) {
        value -= 10;
        aces--;
    }
    return value;
}

/* Define function for player's turn */
void playerTurn(Card *deck, Card *hand, int *size) {
    char choice[10];
    while(1) {
        printf("Your hand: ");
        printPlayerHand(hand, *size);
        printf("Do you want to hit or stand? ");
        scanf("%s", choice);
        if(strcmp(choice, "hit") == 0) {
            hand[*size] = deck[*size];
            printf("You drew a ");
            printCard(hand[*size]);
            printf("\n");
            (*size)++;
            if(calculateHandValue(hand, *size) > 21) {
                printf("Bust! Your hand is worth %d.\n", calculateHandValue(hand, *size));
                break;
            }
        }
        else if(strcmp(choice, "stand") == 0) {
            printf("Your hand is worth %d.\n", calculateHandValue(hand, *size));
            break;
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }
}

/* Define function for dealer's turn */
void dealerTurn(Card *deck, Card *hand, int *size) {
    printf("Dealer's hand: ");
    printPlayerHand(hand, *size);
    while(calculateHandValue(hand, *size) < 17) {
        hand[*size] = deck[*size];
        printf("Dealer drew a ");
        printCard(hand[*size]);
        printf("\n");
        (*size)++;
    }
    if(calculateHandValue(hand, *size) > 21) {
        printf("Dealer busts! Dealer's hand is worth %d.\n", calculateHandValue(hand, *size));
    }
    else {
        printf("Dealer's hand is worth %d.\n", calculateHandValue(hand, *size));
    }
}

/* Define main function */
int main() {
    int i, playerSize = 2, dealerSize = 2;
    Card deck[NUM_CARDS];
    initDeck(deck);
    shuffle(deck);
    Card playerHand[10], dealerHand[10];
    playerHand[0] = deck[0];
    dealerHand[0] = deck[1];
    playerHand[1] = deck[2];
    dealerHand[1] = deck[3];
    printf("Welcome to the C Poker Game!\n\n");
    playerTurn(deck, playerHand, &playerSize);
    if(calculateHandValue(playerHand, playerSize) <= 21) {
        dealerTurn(deck, dealerHand, &dealerSize);
    }
    printf("Player's hand: ");
    printPlayerHand(playerHand, playerSize);
    printf("Dealer's hand: ");
    printPlayerHand(dealerHand, dealerSize);
    if(calculateHandValue(dealerHand, dealerSize) > 21) {
        printf("Player wins!\n");
    }
    else if(calculateHandValue(playerHand, playerSize) > calculateHandValue(dealerHand, dealerSize)) {
        printf("Player wins!\n");
    }
    else if(calculateHandValue(playerHand, playerSize) == calculateHandValue(dealerHand, dealerSize)) {
        printf("Push!\n");
    }
    else {
        printf("Dealer wins!\n");
    }
    return 0;
}