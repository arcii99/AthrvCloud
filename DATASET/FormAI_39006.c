//FormAI DATASET v1.0 Category: Poker Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARDS 52
#define N_RANKS 13
#define N_SUITS 4

typedef struct {
    int rank;
    int suit;
} Card;

void shuffle_deck(Card *deck) {
    srand(time(NULL));
    for (int i = N_CARDS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card c) {
    const char *rank_string[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    const char *suit_string[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    printf("%s of %s\n", rank_string[c.rank], suit_string[c.suit]);
}

void print_hand(Card *hand, int n) {
    for (int i = 0; i < n; i++)
    {
        print_card(hand[i]);
    }
}

int main() {
    Card deck[N_CARDS];
    for (int i = 0; i < N_RANKS; i++)
    {
        for (int j = 0; j < N_SUITS; j++)
        {
            int pos = i * N_SUITS + j;
            deck[pos].rank = i;
            deck[pos].suit = j;
        }
    }

    shuffle_deck(deck);

    Card hand[5];
    for (int i = 0; i < 5; i++)
    {
        hand[i] = deck[i];
    }

    printf("Your hand:\n");
    print_hand(hand, 5);

    return 0;
}