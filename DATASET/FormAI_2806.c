//FormAI DATASET v1.0 Category: Poker Game ; Style: lively
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the number of cards and card values
#define NUM_CARDS 52
#define NUM_VALS 13

// Card structure
typedef struct {
    int number;
    char suit;
} Card;

// Function to print the current hand
void printHand(Card *hand, int numCards) {
    printf("Current Hand:\n");
    for (int i = 0; i < numCards; i++) {
        printf("%d%c ", hand[i].number, hand[i].suit);
    }
    printf("\n\n");
}

// Function to shuffle the deck
void shuffleDeck(Card *deck) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal a card from the deck
Card dealCard(Card *deck, int *numCards) {
    Card dealt = deck[(*numCards) - 1];
    (*numCards)--;
    return dealt;
}

int main() {
    Card deck[NUM_CARDS];
    int numCards = NUM_CARDS;
    char suits[4] = {'S', 'H', 'D', 'C'};
    
    // Initialize the deck
    for (int i = 0; i < NUM_VALS; i++) {
        for (int j = 0; j < 4; j++) {
            deck[4*i+j].number = i+1;
            deck[4*i+j].suit = suits[j];
        }
    }
    
    // Shuffle the deck
    shuffleDeck(deck);
    
    // Deal initial hand for player and dealer
    Card playerHand[2];
    playerHand[0] = dealCard(deck, &numCards);
    playerHand[1] = dealCard(deck, &numCards);
    
    Card dealerHand[2];
    dealerHand[0] = dealCard(deck, &numCards);
    dealerHand[1] = dealCard(deck, &numCards);
    
    // Print initial hands
    printf("Welcome to the Poker game!\n");
    printf("You have been dealt:\n");
    printHand(playerHand, 2);
    printf("The dealer is showing:\n");
    printf("%d%c\n\n", dealerHand[1].number, dealerHand[1].suit);
    
    // Ask player to hit or stand
    char choice;
    int total = playerHand[0].number + playerHand[1].number;
    printf("Your current total is %d.\n", total);
    printf("Do you want to hit or stand (h/s)? ");
    scanf(" %c", &choice);
    
    // Player hits until stand or bust
    while (choice == 'h') {
        playerHand[total%2] = dealCard(deck, &numCards);
        total += playerHand[total%2].number;
        printf("You drew a %d%c.\n", playerHand[total%2].number, playerHand[total%2].suit);
        if (total > 21) {
            printf("Bust! Your total is %d.\n", total);
            return 0;
        }
        printf("Your current total is %d.\n", total);
        printf("Do you want to hit or stand (h/s)? ");
        scanf(" %c", &choice);
    }
    
    // Dealer hits until 17 or higher
    int dealerTotal = dealerHand[0].number + dealerHand[1].number;
    while (dealerTotal < 17) {
        dealerHand[dealerTotal%2] = dealCard(deck, &numCards);
        dealerTotal += dealerHand[dealerTotal%2].number;
        printf("\nThe dealer drew a %d%c.\n", dealerHand[dealerTotal%2].number, dealerHand[dealerTotal%2].suit);
    }
    printf("\nThe dealer's total is %d.\n", dealerTotal);
    
    // Determine winner
    if (total > dealerTotal || dealerTotal > 21) {
        printf("Congratulations, you win with a total of %d!\n", total);
    } else if (total < dealerTotal) {
        printf("Sorry, the dealer wins with a total of %d.\n", dealerTotal);
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}