//FormAI DATASET v1.0 Category: Poker Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *deck, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; ++i) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCards(int *cards, int size) {
    char suits[4][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char ranks[13][10] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    for(int i = 0; i < size; ++i) {
        int suit = cards[i] % 4;
        int rank = cards[i] / 4;
        printf("%s of %s\n", ranks[rank], suits[suit]);
    }
}

int main() {
    int deck[52];
    for(int i = 0; i < 52; ++i) {
        deck[i] = i;
    }

    shuffle(deck, 52);
    int player1[5], player2[5];
    for(int i = 0; i < 5; ++i) {     
        player1[i] = deck[i];
        player2[i] = deck[i + 5];
    }

    printf("Player 1's cards:\n");
    printCards(player1, 5); 
    printf("\nPlayer 2's cards:\n");
    printCards(player2, 5);

    return 0;
}