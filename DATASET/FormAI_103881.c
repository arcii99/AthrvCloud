//FormAI DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for each playing card
typedef struct {
    int rank;
    int suit;
} Card;

// Function to print the rank and suit of a card
void printCard(Card c) {
    char *rankNames[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                            "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    char *suitNames[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    printf("%s of %s\n", rankNames[c.rank], suitNames[c.suit]);
}

// Function to initialize a deck of cards
void initDeck(Card *deck) {
    int i, j;

    for(i = 0; i < 13; i++) {
        for(j = 0; j < 4; j++) {
            deck[4*i+j].rank = i;
            deck[4*i+j].suit = j;
        }
    }
}

// Function to shuffle a deck of cards
void shuffleDeck(Card *deck) {
    int i, j;
    Card temp;

    srand(time(NULL));

    for(i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal a card from the deck
Card dealCard(Card *deck, int *numCards) {
    (*numCards)--;
    return deck[*numCards];
}

// Structure for a player's hand
typedef struct {
    Card cards[2];
    int chips;
    int betAmount;
} Hand;

// Function to print a player's hand
void printHand(Hand hand) {
    printf("Your hand:\n");
    printCard(hand.cards[0]);
    printCard(hand.cards[1]);
}

// Function to get a player's bet for the round
int getBet(int chips) {
    int bet = 0;
    while(bet <= 0 || bet > chips) {
        printf("You have %d chips. How much would you like to bet? ", chips);
        scanf("%d", &bet);
        if(bet <= 0) {
            printf("Your bet must be greater than 0.\n");
        } else if(bet > chips) {
            printf("You do not have enough chips for that bet.\n");
        }
    }
    return bet;
}

// Function to determine the winner of the round
int determineWinner(Hand p1, Hand p2) {
    int p1Score = p1.cards[0].rank + p1.cards[1].rank;
    int p2Score = p2.cards[0].rank + p2.cards[1].rank;

    if(p1Score > p2Score) {
        printf("You win!\n");
        return 1;
    } else if(p1Score < p2Score) {
        printf("The computer wins.\n");
        return -1;
    } else {
        printf("It's a tie.\n");
        return 0;
    }
}

int main() {
    int numPlayers = 2;
    int numCards = 52;
    int pot = 0;
    int winner;
    
    Card deck[52];
    Hand playerHand, computerHand;

    // Initialize and shuffle the deck
    initDeck(deck);
    shuffleDeck(deck);

    // Deal two cards to each player
    playerHand.cards[0] = dealCard(deck, &numCards);
    computerHand.cards[0] = dealCard(deck, &numCards);
    playerHand.cards[1] = dealCard(deck, &numCards);
    computerHand.cards[1] = dealCard(deck, &numCards);

    // Print the player's hand
    printHand(playerHand);
    
    // Get the player's bet for the round
    playerHand.betAmount = getBet(playerHand.chips);
    computerHand.betAmount = playerHand.betAmount;

    // Update the chips and pot
    playerHand.chips -= playerHand.betAmount;
    computerHand.chips -= computerHand.betAmount;
    pot += playerHand.betAmount + computerHand.betAmount;

    // Determine the winner of the round
    winner = determineWinner(playerHand, computerHand);

    // Update the pot and chips based on the winner
    if(winner == 1) {
        playerHand.chips += pot;
    } else if(winner == -1) {
        computerHand.chips += pot;
    }

    return 0;
}