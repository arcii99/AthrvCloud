//FormAI DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to shuffle the cards
void shuffle(int deck[][13]) {
    int i, j, tmp;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
          int r = rand() % 4;
          int c = rand() % 13;
          tmp = deck[i][j];
          deck[i][j] = deck[r][c];
          deck[r][c] = tmp;
        }
    }
}

//function to deal the cards
void deal(int deck[][13], char *suits[], char *faces[]) {
    int cards, r, c;
    printf("\nDealer starts dealing the cards...\n\n");

    for (cards = 1; cards <= 5; cards++) {
        printf("Card %d is: ", cards);
        r = rand() % 4;
        c = rand() % 13;
        printf("%s of %s\n", faces[deck[r][c]], suits[r]);
    }
}

int main() {
    int deck[4][13] = {    // 1 means a card is in the deck, 0 means it's not
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    srand(time(NULL));  //seed the random number generator with the current time
    shuffle(deck);  //shuffle the deck
    deal(deck, suits, faces);  //deal the cards

    return 0;
}