//FormAI DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_COUNT 52
#define SUIT_COUNT 4
#define RANK_COUNT 13

const char* suits[SUIT_COUNT] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char* ranks[RANK_COUNT] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",  "Jack", "Queen", "King"};

int getRandomCard() {
    return rand() % CARD_COUNT;
}

void printCard(int card) {
    int suit = card / RANK_COUNT;
    int rank = card % RANK_COUNT;
    printf("%s of %s\n", ranks[rank], suits[suit]);
}

void shuffleCards(int* deck) {
    for (int i = CARD_COUNT - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    int deck[CARD_COUNT];
    for (int i = 0; i < CARD_COUNT; i++) {
        deck[i] = i;
    }
    shuffleCards(deck);
    printf("Dealing the Cards:\n");
    printCard(deck[0]);
    printCard(deck[1]);
    printCard(deck[2]);
    return 0;
}