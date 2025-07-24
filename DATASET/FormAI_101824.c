//FormAI DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define CARD_SIZE 3

// Function to shuffle cards randomly
void shuffle(int deck[]) {
    srand(time(NULL));

    for (int i = DECK_SIZE-1; i>=0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to convert card code to string representation
void decode(int cardcode, char cardstr[]) {
    char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    int suit = cardcode / 13;
    int rank = cardcode % 13;

    sprintf(cardstr, "%s of %s", ranks[rank], suits[suit]);
}

// Function to deal cards to the players
void deal(int deck[], int *index, int num_players, int hand_size, int hands[][hand_size]) {
    for (int i=0; i<hand_size; i++) {
        for (int j=0; j<num_players; j++) {
            hands[j][i] = deck[*index];
            (*index)++;
        }
    }
}

int main() {
    int deck[DECK_SIZE];
    int hands[5][5];
    int index = 0;
    int num_players = 5;
    int hand_size = 5;

    // Initialize the deck
    for (int i=0; i<DECK_SIZE; i++) {
        deck[i] = i;
    }

    // Shuffle the deck
    shuffle(deck);

    // Deal the cards
    deal(deck, &index, num_players, hand_size, hands);

    // Print the cards
    for (int i=0; i<num_players; i++) {
        printf("Player %d:\n", i+1);
        for (int j=0; j<hand_size; j++) {
            char cardstr[CARD_SIZE];
            decode(hands[i][j], cardstr);
            printf("\t%s\n", cardstr);
        }
    }

    return 0;
}