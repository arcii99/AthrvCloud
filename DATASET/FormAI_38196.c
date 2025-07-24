//FormAI DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Card structure
struct card {
    char suit;
    int value;
};

//Deck structure
struct deck {
    struct card cards[52];
    int length;
};

//Function to initialize and shuffle deck
void shuffle_deck(struct deck *d) {
    char suits[] = {'H', 'D', 'C', 'S'};
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int i, j, k = 0;

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 13; j++) {
            d->cards[k].suit = suits[i];
            d->cards[k].value = values[j];
            k++;
        }
    }

    d->length = 52;

    srand(time(NULL));
    for(i = 0; i < 52; i++) {
        j = rand() % 52;
        struct card temp = d->cards[i];
        d->cards[i] = d->cards[j];
        d->cards[j] = temp;
    }
}

//Function to deal cards to players
void deal_cards(struct deck *d, struct card *player1, struct card *player2) {
    int i, j = 0;

    //Player 1 gets cards at index 0 and 1
    player1[0] = d->cards[0];
    player1[1] = d->cards[1];
    j += 2;

    //Player 2 gets cards at index 2 and 3
    player2[0] = d->cards[2];
    player2[1] = d->cards[3];
    j += 2;

    d->length -= 4;

    //Remaining cards are left in deck
    for(i = j; i < 52; i++) {
        d->cards[i-j] = d->cards[i];
    }
}

//Function to print cards in player's hand
void print_hand(struct card *hand) {
    int i;

    for(i = 0; i < 2; i++) {
        if(hand[i].value == 11) printf("J");
        else if(hand[i].value == 12) printf("Q");
        else if(hand[i].value == 13) printf("K");
        else if(hand[i].value == 14) printf("A");
        else printf("%d", hand[i].value);

        printf("%c ", hand[i].suit);
    }
    printf("\n");
}

int main() {
    struct deck d;
    struct card player1[2];
    struct card player2[2];

    shuffle_deck(&d);
    deal_cards(&d, player1, player2);

    printf("Player 1 has: ");
    print_hand(player1);
    printf("Player 2 has: ");
    print_hand(player2);

    return 0;
}