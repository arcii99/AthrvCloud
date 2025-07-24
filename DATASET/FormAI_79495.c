//FormAI DATASET v1.0 Category: Poker Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5
#define NUM_RANKS 13
#define NUM_SUITS 4

enum rank {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
enum suit {Hearts, Diamonds, Clubs, Spades};

typedef struct {
    enum rank r;
    enum suit s;
} card;

void shuffle_deck(card *deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(card c) {
    switch(c.r) {
        case Ace:
            printf("A");
            break;
        case Two:
            printf("2");
            break;
        case Three:
            printf("3");
            break;
        case Four:
            printf("4");
            break;
        case Five:
            printf("5");
            break;
        case Six:
            printf("6");
            break;
        case Seven:
            printf("7");
            break;
        case Eight:
            printf("8");
            break;
        case Nine:
            printf("9");
            break;
        case Ten:
            printf("T");
            break;
        case Jack:
            printf("J");
            break;
        case Queen:
            printf("Q");
            break;
        case King:
            printf("K");
            break;
    }
    switch(c.s) {
        case Hearts:
            printf("H\t");
            break;
        case Diamonds:
            printf("D\t");
            break;
        case Clubs:
            printf("C\t");
            break;
        case Spades:
            printf("S\t");
            break;
    }
}

void print_hand(card *h, int size) {
    for (int i = 0; i < size; i++) {
        print_card(h[i]);
        printf("\n");
    }
}

int rank_count(enum rank r, card *h, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (h[i].r == r) {
            count++;
        }
    }
    return count;
}

int suit_count(enum suit s, card *h, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (h[i].s == s) {
            count++;
        }
    }
    return count;
}

int is_straight(card *h, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (h[i+1].r != h[i].r + 1) {
            return 0;
        }
    }
    return 1;
}

int is_flush(card *h, int size) {
    enum suit s = h[0].s;
    for (int i = 1; i < size; i++) {
        if (h[i].s != s) {
            return 0;
        }
    }
    return 1;
}

int is_straight_flush(card *h, int size) {
    return is_straight(h, size) && is_flush(h, size);
}

int is_four_of_a_kind(card *h, int size) {
    for (int i = 0; i < size; i++) {
        if (rank_count(h[i].r, h, size) == 4) {
            return 1;
        }
    }
    return 0;
}

int is_full_house(card *h, int size) {
    return ((rank_count(h[0].r, h, size) == 3 && rank_count(h[4].r, h, size) == 2) ||
            (rank_count(h[0].r, h, size) == 2 && rank_count(h[4].r, h, size) == 3));
}

int is_three_of_a_kind(card *h, int size) {
    for (int i = 0; i < size; i++) {
        if (rank_count(h[i].r, h, size) == 3) {
            return 1;
        }
    }
    return 0;
}

int is_two_pair(card *h, int size) {
    int pairs = 0;
    for (int i = 0; i < size; i++) {
        if (rank_count(h[i].r, h, size) == 2) {
            pairs++;
        }
    }
    return pairs == 2;
}

int is_one_pair(card *h, int size) {
    for (int i = 0; i < size; i++) {
        if (rank_count(h[i].r, h, size) == 2) {
            return 1;
        }
    }
    return 0;
}

int rank_value(enum rank r) {
    switch(r) {
        case Ace:
            return 1;
        case Two:
            return 2;
        case Three:
            return 3;
        case Four:
            return 4;
        case Five:
            return 5;
        case Six:
            return 6;
        case Seven:
            return 7;
        case Eight:
            return 8;
        case Nine:
            return 9;
        case Ten:
        case Jack:
        case Queen:
        case King:
            return 10;
    }
}

int hand_value(card *h, int size) {
    if (is_straight_flush(h, size)) {
        return rank_value(h[4].r) * 10000;
    } else if (is_four_of_a_kind(h, size)) {
        return rank_value(h[2].r) * 100;
    } else if (is_full_house(h, size)) {
        return rank_value(h[2].r) * 10 + rank_value(h[4].r);
    } else if (is_flush(h, size)) {
        return rank_value(h[4].r);
    } else if (is_straight(h, size)) {
        return rank_value(h[4].r);
    } else if (is_three_of_a_kind(h, size)) {
        return rank_value(h[2].r);
    } else if (is_two_pair(h, size)) {
        enum rank high_pair;
        for (int i = 0; i < size - 1; i++) {
            if (h[i].r == h[i+1].r) {
                high_pair = h[i].r;
            }
        }
        return rank_value(high_pair);
    } else if (is_one_pair(h, size)) {
        enum rank pair_rank;
        for (int i = 0; i < size - 1; i++) {
            if (h[i].r == h[i+1].r) {
                pair_rank = h[i].r;
            }
        }
        return rank_value(pair_rank);
    } else {
        return rank_value(h[4].r);
    }
}

void swap(card *a, card *b) {
    card temp = *a;
    *a = *b;
    *b = temp;
}

void sort_hand(card *h, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (rank_value(h[j].r) < rank_value(h[i].r)) {
                swap(&h[i], &h[j]);
            }
        }
    }
}

void deal_hands(card *deck, card *hand1, card *hand2) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand1[i] = deck[i];
        hand2[i] = deck[i+HAND_SIZE];
    }
    sort_hand(hand1, HAND_SIZE);
    sort_hand(hand2, HAND_SIZE);
}

int main() {
    card deck[DECK_SIZE];
    int count = 0;
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck[count].r = i;
            deck[count].s = j;
            count++;
        }
    }
    shuffle_deck(deck);

    card hand1[HAND_SIZE];
    card hand2[HAND_SIZE];

    deal_hands(deck, hand1, hand2);

    printf("Player 1's hand:\n");
    print_hand(hand1, HAND_SIZE);
    printf("\nPlayer 2's hand:\n");
    print_hand(hand2, HAND_SIZE);

    int hand1_value = hand_value(hand1, HAND_SIZE);
    int hand2_value = hand_value(hand2, HAND_SIZE);

    if (hand1_value > hand2_value) {
        printf("\nPlayer 1 wins!\n");
    } else if (hand2_value > hand1_value) {
        printf("\nPlayer 2 wins!\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}