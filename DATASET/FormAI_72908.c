//FormAI DATASET v1.0 Category: Poker Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {SPADES, HEARTS, DIAMONDS, CLUBS} Suit;

typedef struct {
    Suit suit;
    int value;
} Card;

void shuffle_deck(Card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card c) {
    if (c.value == 1) {
        printf("A");
    } else if (c.value == 11) {
        printf("J");
    } else if (c.value == 12) {
        printf("Q");
    } else if (c.value == 13) {
        printf("K");
    } else {
        printf("%d", c.value);
    }

    switch (c.suit) {
        case SPADES:
            printf("\u2660");
            break;
        case HEARTS:
            printf("\u2665");
            break;
        case DIAMONDS:
            printf("\u2666");
            break;
        case CLUBS:
            printf("\u2663");
            break;
    }
}

void print_hand(Card hand[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
        printf(" ");
    }
    printf("\n");
}

int evaluate_hand(Card hand[]) {
    int ranks[14] = {0};
    int flush = 1;
    int straight = 0;
    int straight_count = 0;

    for (int i = 0; i < HAND_SIZE; i++) {
        ranks[hand[i].value]++;
        if (i != 0 && hand[i].suit != hand[i-1].suit) {
            flush = 0;
        }
    }

    for (int i = 1; i <= 13; i++) {
        if (ranks[i] >= 1) {
            straight_count++;
        } else {
            straight_count = 0;
        }

        if (straight_count == 5) {
            straight = 1;
            break;
        }
    }

    if (flush && straight) {
        return 800 + hand[4].value;
    }

    for (int i = 1; i <= 9; i++) {
        if (ranks[i] == 1 && 
            ranks[i+1] == 1 && 
            ranks[i+2] == 1 && 
            ranks[i+3] == 1 && 
            ranks[i+4] == 1) {
            return 700 + i + 4;
        }
    }

    for (int i = 1; i <= 13; i++) {
        if (ranks[i] == 4) {
            return 600 + i;
        }
    }

    int three_of_a_kind = 0;
    int pairs = 0;

    for (int i = 1; i <= 13; i++) {
        if (ranks[i] == 3) {
            three_of_a_kind = i;
        } else if (ranks[i] == 2) {
            pairs++;
        }
    }

    if (three_of_a_kind && pairs) {
        return 500 + three_of_a_kind;
    }

    if (flush) {
        return 400 + hand[4].value;
    }

    if (straight) {
        return 300 + hand[4].value;
    }

    for (int i = 1; i <= 13; i++) {
        if (ranks[i] == 3) {
            return 200 + i;
        }
    }

    int pairs_count = 0;
    int high_pair = 0;

    for (int i = 1; i <= 13; i++) {
        if (ranks[i] == 2) {
            pairs_count++;
            if (i > high_pair) {
                high_pair = i;
            }
        }
    }

    if (pairs_count == 2) {
        return 100 + high_pair;
    }

    for (int i = HAND_SIZE-1; i >= 0; i--) {
        ranks[hand[i].value]--;
        if (ranks[hand[i].value] == 0) {
            return hand[i].value;
        }
    }

    return 0;
}

void swap(Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(Card hand[]) {
    for (int i = HAND_SIZE-1; i > 0; i--) {
        int max = 0;
        for (int j = 1; j <= i; j++) {
            if (hand[j].value > hand[max].value) {
                max = j;
            }
        }
        swap(&hand[i], &hand[max]);
    }
}

int main() {
    Card deck[DECK_SIZE];
    int i = 0;
    for (Suit s = SPADES; s <= CLUBS; s++) {
        for (int v = 1; v <= 13; v++) {
            deck[i].suit = s;
            deck[i].value = v;
            i++;
        }
    }
    shuffle_deck(deck);

    Card hand[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
    selection_sort(hand);

    printf("Your hand: ");
    print_hand(hand);
    printf("Your hand value: %d\n", evaluate_hand(hand));

    return 0;
}