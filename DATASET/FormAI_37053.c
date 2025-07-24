//FormAI DATASET v1.0 Category: Poker Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5

char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

typedef struct card {
    int rank;
    int suit;
} Card;

typedef struct deck {
    Card cards[NUM_CARDS];
    int size;
} Deck;

typedef struct hand {
    Card cards[HAND_SIZE];
} Hand;

int compare(const void *a, const void *b) {
    int rank_a = ((Card *) a)->rank;
    int rank_b = ((Card *) b)->rank;

    if (rank_a == 0) {
        rank_a = NUM_RANKS;
    }
    if (rank_b == 0) {
        rank_b = NUM_RANKS;
    }

    if (rank_a < rank_b) {
        return -1;
    } else if (rank_a > rank_b) {
        return 1;
    } else {
        return 0;
    }
}

void init_deck(Deck *deck) {
    int i, j, index;
    index = 0;

    for (i = 0; i < NUM_RANKS; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck->cards[index].rank = i;
            deck->cards[index].suit = j;
            index++;
        }
    }

    deck->size = NUM_CARDS;
}

void shuffle_deck(Deck *deck) {
    int i, j;
    Card temp;

    srand(time(NULL));

    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;

        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deal_hand(Deck *deck, Hand *hand) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck->cards[deck->size - 1];
        deck->size--;
    }

    qsort(hand->cards, HAND_SIZE, sizeof(Card), compare);
}

void print_card(Card card) {
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void print_hand(Hand hand) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        print_card(hand.cards[i]);
    }
}

int main() {
    Deck deck;
    Hand hand;

    init_deck(&deck);
    shuffle_deck(&deck);
    deal_hand(&deck, &hand);
    print_hand(hand);

    return 0;
}