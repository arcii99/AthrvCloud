//FormAI DATASET v1.0 Category: Poker Game ; Style: distributed
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define NUM_PLAYERS 4
#define NUM_CARDS 52

int cards[NUM_CARDS];

void shuffle() {
    for(int i = 0; i < NUM_CARDS; i++) {
        cards[i] = i;
    }

    srand(time(NULL));

    for(int i = NUM_CARDS-1; i >= 0; i--) {
        int j = rand() % NUM_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void deal_cards(int **player_cards) {
    for(int i = 0; i < NUM_PLAYERS; i++) {
        for(int j = 0; j < 2; j++) {
            player_cards[i][j] = cards[i*2+j];
        }
    }
}

void display_card(int card) {
    int suit = card / 13;
    int rank = card % 13;

    printf("%c", "CDHS"[suit]);

    switch(rank) {
        case 0:
            printf("A");
            break;
        case 9:
            printf("T");
            break;
        case 10:
            printf("J");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d", rank + 1);
            break;
    }
}

void display_hand(int *hand, int n) {
    for(int i = 0; i < n; i++) {
        display_card(hand[i]);
        printf(" ");
    }
}

int main() {
    int *player_cards[NUM_PLAYERS];

    for(int i = 0; i < NUM_PLAYERS; i++) {
        player_cards[i] = malloc(2*sizeof(int));
    }

    shuffle();
    deal_cards(player_cards);

    for(int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i+1);
        display_hand(player_cards[i], 2);
        printf("\n");
    }

    for(int i = 0; i < NUM_PLAYERS; i++) {
        free(player_cards[i]);
    }

    return 0;
}