//FormAI DATASET v1.0 Category: Poker Game ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_CARDS 52 // Number of cards in a deck
#define NUM_PLAYERS 4 // Number of players in the game

int main(){
    srand(time(NULL)); // Initialize random seed
    
    int cards[NUM_CARDS] = {0}; // Array to store cards, initially set to 0
    
    // Assign unique values to each card in the deck
    for(int i=0; i<NUM_CARDS; i++){
        cards[i] = i+1;
    }
    
    // Shuffle the deck of cards
    for(int i=0; i<NUM_CARDS; i++){
        int j = rand() % NUM_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    
    // Distribute cards to the players
    int hands[NUM_PLAYERS][5] = {0}; // Array to store each player's hand
    int cardsDealt = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<NUM_PLAYERS; j++){
            hands[j][i] = cards[cardsDealt];
            cardsDealt++;
        }
    }
    
    // Print each player's hand
    printf("Player 1: ");
    for(int i=0; i<5; i++){
        printf("%d ", hands[0][i]);
    }
    printf("\n");
    
    printf("Player 2: ");
    for(int i=0; i<5; i++){
        printf("%d ", hands[1][i]);
    }
    printf("\n");
    
    printf("Player 3: ");
    for(int i=0; i<5; i++){
        printf("%d ", hands[2][i]);
    }
    printf("\n");
    
    printf("Player 4: ");
    for(int i=0; i<5; i++){
        printf("%d ", hands[3][i]);
    }
    printf("\n");
    
    return 0; // End program
}