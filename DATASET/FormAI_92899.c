//FormAI DATASET v1.0 Category: Poker Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void shuffle(int deck[52]);
int deal(int deck[52], int* position);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the deck of cards
    int deck[52];
    for(int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    
    // Shuffle the deck of cards
    shuffle(deck);
    
    // Deal two cards to each player
    int player1[2];
    int player2[2];
    int position = 0;
    player1[0] = deal(deck, &position);
    player2[0] = deal(deck, &position);
    player1[1] = deal(deck, &position);
    player2[1] = deal(deck, &position);
    
    // Print the cards dealt to each player
    printf("Player 1's cards: ");
    for(int i = 0; i < 2; i++) {
        printf("%d ", player1[i]);
    }
    printf("\n");
    printf("Player 2's cards: ");
    for(int i = 0; i < 2; i++) {
        printf("%d ", player2[i]);
    }
    printf("\n");
    
    // Determine the winner
    int total1 = player1[0] + player1[1];
    int total2 = player2[0] + player2[1];
    if(total1 > total2) {
        printf("Player 1 wins!\n");
    } else if(total1 < total2) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}

// Shuffle the deck of cards
void shuffle(int deck[52]) {
    int randomIndex;
    int temp;
    for(int i = 0; i < 52; i++) {
        randomIndex = rand() % 52;
        temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

// Deal a card from the deck
int deal(int deck[52], int* position) {
    (*position)++;
    return deck[*position - 1];
}