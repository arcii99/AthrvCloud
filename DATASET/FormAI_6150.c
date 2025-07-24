//FormAI DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARDS 52
#define N_SUITS 4
#define N_RANKS 13

typedef struct {
    int suit;
    int rank;
} Card;

void print_card(Card c) {
    const char *suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char *ranks[] = { "Ace", "2", "3", "4", "5", "6", "7",
                            "8", "9", "10", "Jack", "Queen", "King" };
    printf("%s of %s\n", ranks[c.rank], suits[c.suit]);
}

int main(void) {
    srand((unsigned) time(NULL));

    Card deck[N_CARDS];
    for (int i = 0; i < N_CARDS; i++) {
        deck[i].suit = i / N_RANKS;
        deck[i].rank = i % N_RANKS;
    }

    // shuffle the deck
    for (int i = N_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // deal the cards
    int player_hand[5], dealer_hand[5];
    for (int i = 0; i < 5; i++) {
        player_hand[i] = i * 2;
        dealer_hand[i] = i * 2 + 1;
        printf("Player: ");
        print_card(deck[player_hand[i]]);
        printf("Dealer: ");
        print_card(deck[dealer_hand[i]]);
    }

    // find the winner
    int player_score = 0, dealer_score = 0;
    for (int i = 0; i < 5; i++) {
        if (deck[player_hand[i]].rank == 0 || deck[player_hand[i]].rank > 9) {
            player_score++;
        }
        if (deck[dealer_hand[i]].rank == 0 || deck[dealer_hand[i]].rank > 9) {
            dealer_score++;
        }
    }
    printf("Player score: %d\n", player_score);
    printf("Dealer score: %d\n", dealer_score);
    if (player_score > dealer_score) {
        printf("Player wins!\n");
    } else if (dealer_score > player_score) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}