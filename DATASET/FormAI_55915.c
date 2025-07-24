//FormAI DATASET v1.0 Category: Poker Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rank;
    char suit[10];
    int value;
} Card;

typedef struct {
    Card cards[5];
} Hand;

Card deck[52];

void initialize_deck() {
    int i,j;
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for(i=0; i<4; i++) {
        for(j=0; j<13; j++) {
            deck[i*13+j].rank = j+1;
            deck[i*13+j].value = (j+1 > 10) ? 10 : j+1; 
            strcpy(deck[i*13+j].suit, suits[i]);
        }
    }
}

void shuffle_deck() {
    srand(time(NULL));
    int i=0;
    for(i=0; i<52; i++) {
        int r = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void print_hand(Hand *hand) {
    int i;
    for(i=0; i<5; i++) {
        printf("%d of %s\n", hand->cards[i].rank, hand->cards[i].suit);
    }
}

void deal_hand(Hand *hand) {
    int i;
    for(i=0; i<5; i++) {
        hand->cards[i] = deck[i];
    }
}

int main() {
    Hand player_hand;
    initialize_deck();
    shuffle_deck();
    deal_hand(&player_hand);
    print_hand(&player_hand);
    return 0;
}