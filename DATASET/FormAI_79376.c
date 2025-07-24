//FormAI DATASET v1.0 Category: Poker Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52

typedef struct {
    char* rank;
    char* suit;
} card;

const char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char* suits[] = {"Spades", "Clubs", "Diamonds", "Hearts"};

card deck[DECK_SIZE];
card player1Hand[5];
card player2Hand[5];

void createDeck();
void shuffle();
void dealCards(card *hand);
void printHand(card *hand);
int getHandValue(card *hand);
int getCardValue(card c);

int main () {
    srand(time(0)); // seed the random number generator with the current time
    createDeck();
    shuffle();
    
    printf("Player 1's hand:\n");
    dealCards(player1Hand);
    printHand(player1Hand);
    int player1Value = getHandValue(player1Hand);
    printf("Hand value: %d\n\n", player1Value);
    
    printf("Player 2's hand:\n");
    dealCards(player2Hand);
    printHand(player2Hand);
    int player2Value = getHandValue(player2Hand);
    printf("Hand value: %d\n\n", player2Value);
    
    if (player1Value > player2Value) {
        printf("Player 1 wins!\n");
    } else if (player1Value < player2Value) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}

void createDeck() {
    int i, j, index;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 4; j++) {
            index = i * 4 + j;
            deck[index].rank = (char*) ranks[i];
            deck[index].suit = (char*) suits[j];
        }
    }
}

void shuffle() {
    int i;
    for (i = 0; i < DECK_SIZE; i++) {
        int randomIndex = rand() % DECK_SIZE;
        card temp = deck[randomIndex];
        deck[randomIndex] = deck[i];
        deck[i] = temp;
    }
}

void dealCards(card *hand) {
    int i;
    for (i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }
}

void printHand(card *hand) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%s of %s\n", hand[i].rank, hand[i].suit);
    }
}

int getHandValue(card *hand) {
    int i, value = 0, aceCount = 0;
    for (i = 0; i < 5; i++) {
        value += getCardValue(hand[i]);
        if (strcmp(hand[i].rank, "Ace") == 0) {
            aceCount++;
        }
    }
    while (aceCount > 0 && value > 21) {
        value -= 10;
        aceCount--;
    }
    return value;
}

int getCardValue(card c) {
    if (strcmp(c.rank, "Ace") == 0) {
        return 11;
    } else if (strcmp(c.rank, "2") == 0) {
        return 2;
    } else if (strcmp(c.rank, "3") == 0) {
        return 3;
    } else if (strcmp(c.rank, "4") == 0) {
        return 4;
    } else if (strcmp(c.rank, "5") == 0) {
        return 5;
    } else if (strcmp(c.rank, "6") == 0) {
        return 6;
    } else if (strcmp(c.rank, "7") == 0) {
        return 7;
    } else if (strcmp(c.rank, "8") == 0) {
        return 8;
    } else if (strcmp(c.rank, "9") == 0) {
        return 9;
    } else {
        return 10;
    }
}