//FormAI DATASET v1.0 Category: Poker Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the card struct
typedef struct {
    char suit;
    int rank;
} Card;

// Function to print the cards in hand
void printHand(Card* hand, int handSize) {
    printf("\nYour hand:\n");
    for(int i=0; i<handSize; i++) {
        printf("[%c %d] ", hand[i].suit, hand[i].rank);
    }
}

// Function to calculate the value of the hand
int handValue(Card* hand, int handSize) {
    int total = 0;
    int aceCount = 0;
    for(int i=0; i<handSize; i++) {
        if(hand[i].rank == 1) {
            aceCount++;
            total += 11;
        } else if(hand[i].rank > 10) {
            total += 10;
        } else {
            total += hand[i].rank;
        }
    }
    while(total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to C Poker Game!\n\n");
    
    // Create the deck of cards
    Card deck[52];
    int deckSize = 0;
    for(int i=1; i<=13; i++) {
        deck[deckSize++] = (Card) {'C', i}; // Clubs
        deck[deckSize++] = (Card) {'D', i}; // Diamonds
        deck[deckSize++] = (Card) {'H', i}; // Hearts
        deck[deckSize++] = (Card) {'S', i}; // Spades
    }
    
    // Shuffle the deck
    for(int i=0; i<deckSize; i++) {
        int randomIndex = rand() % deckSize;
        Card temp = deck[randomIndex];
        deck[randomIndex] = deck[i];
        deck[i] = temp;
    }
    
    // Set up the game
    int bet = 0;
    int pot = 0;
    int cash = 1000;
    int dealerHandSize = 0;
    Card dealerHand[10];
    int playerHandSize = 0;
    Card playerHand[10];
    
    // Game loop
    while(cash > 0) {
        printf("\nYou have $%d. How much do you want to bet? ", cash);
        scanf("%d", &bet);
        if(bet > cash) {
            printf("You don't have that much money!\n");
            continue;
        }
        cash -= bet;
        pot += bet;
        printf("Dealing cards...\n");
        // Deal the cards
        dealerHand[dealerHandSize++] = deck[deckSize--];
        playerHand[playerHandSize++] = deck[deckSize--];
        dealerHand[dealerHandSize++] = deck[deckSize--];
        playerHand[playerHandSize++] = deck[deckSize--];
        // Print the hands
        printf("\nDealer's hand: [%c %d] [X X]\n", dealerHand[0].suit, dealerHand[0].rank);
        printHand(playerHand, playerHandSize);
        // Player's turn
        int playerValue = handValue(playerHand, playerHandSize);
        while(playerValue < 21) {
            char input;
            printf("\nDo you want to hit (h) or stand (s)? ");
            scanf(" %c", &input);
            if(input == 'h') {
                playerHand[playerHandSize++] = deck[deckSize--];
                printf("\nYou drew a [%c %d].", playerHand[playerHandSize-1].suit, playerHand[playerHandSize-1].rank);
                printHand(playerHand, playerHandSize);
                playerValue = handValue(playerHand, playerHandSize);
            } else if(input == 's') {
                break;
            } else {
                printf("Invalid input!\n");
            }
        }
        if(playerValue == 21) {
            printf("\nBlackjack! You win $%d.", pot*2);
            cash += pot*2;
            pot = 0;
            continue;
        } else if(playerValue > 21) {
            printf("\nBust! You lose $%d.", pot);
            pot = 0;
            continue;
        }
        // Dealer's turn
        printf("\nDealer's turn");
        printf("\nDealer's hand: ");
        for(int i=0; i<dealerHandSize; i++) {
            printf("[%c %d] ", dealerHand[i].suit, dealerHand[i].rank);
        }
        while(handValue(dealerHand, dealerHandSize) < 17) {
            dealerHand[dealerHandSize++] = deck[deckSize--];
            printf("\nDealer drew a [%c %d].", dealerHand[dealerHandSize-1].suit, dealerHand[dealerHandSize-1].rank);
        }
        int dealerValue = handValue(dealerHand, dealerHandSize);
        if(dealerValue > 21) {
            printf("\nDealer busts! You win $%d.", pot*2);
            cash += pot*2;
            pot = 0;
            continue;
        } else if(dealerValue > playerValue) {
            printf("\nDealer wins! You lose $%d.", pot);
            pot = 0;
            continue;
        } else if(dealerValue < playerValue) {
            printf("\nYou win $%d.", pot*2);
            cash += pot*2;
            pot = 0;
            continue;
        } else {
            printf("\nIt's a tie! You get your $%d back.", bet);
            cash += bet;
            pot = 0;
            continue;
        }
    }
    printf("\nYou're out of money! Thanks for playing.\n");
    return 0;
}