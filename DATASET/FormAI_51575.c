//FormAI DATASET v1.0 Category: Poker Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define SUIT_SIZE 13
#define HAND_SIZE 5

char suit[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char rank[13][5] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

struct card {
    int rank;
    int suit;
};

void shuffle_deck(struct card deck[]) {
    srand(time(NULL)); //Seed random number generator
    int i, j;
    struct card temp;
    for(i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_hand(struct card deck[], struct card player_hand[], int num_cards) {
    int i;
    for(i = 0; i < num_cards; i++) {
        player_hand[i] = deck[i];
    }
}

void show_hand(struct card player_hand[], int num_cards) {
    int i;
    for(i = 0; i < num_cards; i++) {
        printf("%s of %s\n", rank[player_hand[i].rank], suit[player_hand[i].suit]);
    }
}

int main() {
    struct card deck[DECK_SIZE];
    struct card player_hand[HAND_SIZE];

    int i, j, k = 0;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 13; j++) {
            deck[k].suit = i;
            deck[k].rank = j;
            k++;
        }
    }

    shuffle_deck(deck);
    deal_hand(deck, player_hand, HAND_SIZE);
    show_hand(player_hand, HAND_SIZE);

    return 0;
}