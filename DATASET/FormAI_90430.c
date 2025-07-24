//FormAI DATASET v1.0 Category: Poker Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between 0 and 51 */
int getRandomNumber() {
    return rand() % 52;
}

/* Function to deal cards to all players */
void dealCards(int *deck, int numPlayers, int cardsPerPlayer, int **hands) {
    int cardIndex = 0;
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < cardsPerPlayer; j++) {
            hands[i][j] = deck[cardIndex++];
        }
    }
}

/* Function to print the cards in a hand */
void printHand(int *hand, int numCards) {
    for (int i = 0; i < numCards; i++) {
        char suit;
        int value;
        switch (hand[i] / 13) {
            case 0:
                suit = 'S';
                break;
            case 1:
                suit = 'H';
                break;
            case 2:
                suit = 'D';
                break;
            case 3:
                suit = 'C';
                break;
        }
        value = hand[i] % 13 + 1;
        if (value == 1 || value == 11 || value == 12 || value == 13) {
            printf("%c", value == 1 ? 'A' : value == 11 ? 'J' : value == 12 ? 'Q' : 'K');
        } else {
            printf("%d", value);
        }
        printf("%c ", suit);
    }
    printf("\n");
}

int main() {
    int deck[52];
    int **hands;
    int numPlayers, cardsPerPlayer;
    
    /* Initialize the deck */
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    
    /* Shuffle the deck */
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int index1 = getRandomNumber();
        int index2 = getRandomNumber();
        int temp = deck[index1];
        deck[index1] = deck[index2];
        deck[index2] = temp;
    }
    
    /* Get the number of players and cards per player from user */
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    printf("Enter the number of cards per player: ");
    scanf("%d", &cardsPerPlayer);
    
    /* Allocate memory for hands */
    hands = (int **) malloc(numPlayers * sizeof(int *));
    for (int i = 0; i < numPlayers; i++) {
        hands[i] = (int *) malloc(cardsPerPlayer * sizeof(int));
    }
    
    /* Deal cards */
    dealCards(deck, numPlayers, cardsPerPlayer, hands);
    
    /* Print hands */
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: ", i+1);
        printHand(hands[i], cardsPerPlayer);
    }

    /* Free allocated memory */
    for (int i = 0; i < numPlayers; i++) {
        free(hands[i]);
    }
    free(hands);
    
    return 0;
}