//FormAI DATASET v1.0 Category: Poker Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to shuffle the deck of cards
void shuffle(int *deck) {
    int temp, randIndex;
    for (int i = 0; i < 52; i++) {
        randIndex = rand() % 52;
        temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

int main() {
    //Initialize deck of cards
    int deck[52] = {0};
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    
    //Shuffle deck of cards
    srand(time(NULL));
    shuffle(deck);
    
    //Print shuffled deck of cards
    printf("Shuffled deck of cards:\n");
    for (int i = 0; i < 52; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
    
    //Deal cards to players
    int player1[5] = {0}, player2[5] = {0};
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            player1[j] = deck[i];
        } else {
            player2[j] = deck[i];
            j++;
        }
    }

    //Print cards dealt to players
    printf("Cards dealt to player 1:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", player1[i]);
    }
    printf("\n");
    printf("Cards dealt to player 2:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", player2[i]);
    }
    printf("\n");

    //TODO: Implement poker hand ranking algorithm

    return 0;
}