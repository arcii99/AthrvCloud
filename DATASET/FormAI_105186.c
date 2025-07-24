//FormAI DATASET v1.0 Category: Poker Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define HAND_SIZE 5

enum suit {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
};

enum rank {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

struct card {
    enum suit suit;
    enum rank rank;
};

void swap(struct card *a, struct card *b) {
    struct card temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(struct card *deck, int size) {
    srand(time(NULL));
    for (int i = size-1; i >= 1; i--) {
        int j = rand() % (i+1);
        swap(&deck[i], &deck[j]);
    }
}

void print_card(struct card c) {
    switch (c.rank) {
        case ACE:
            printf("Ace");
            break;
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        case TEN:
            printf("10");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
        default:
            printf("ERROR");
            break;
    }
    printf(" of ");
    switch (c.suit) {
        case SPADES:
            printf("Spades");
            break;
        case HEARTS:
            printf("Hearts");
            break;
        case DIAMONDS:
            printf("Diamonds");
            break;
        case CLUBS:
            printf("Clubs");
            break;
        default:
            printf("ERROR");
            break;
    }
}

void print_hand(struct card *hand, int size) {
    for (int i = 0; i < size; i++) {
        print_card(hand[i]);
        printf("\n");
    }
}

int get_pair(struct card *hand, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (hand[i].rank == hand[j].rank) {
                return 1;
            }
        }
    }
    return 0;
}

int get_two_pair(struct card *hand, int size) {
    int count = 0;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (hand[i].rank == hand[j].rank) {
                count++;
            }
        }
    }
    if (count == 2) {
        return 1;
    }
    return 0;
}

int get_three_of_a_kind(struct card *hand, int size) {
    for (int i = 0; i < size-2; i++) {
        if (hand[i].rank == hand[i+1].rank &&
            hand[i+1].rank == hand[i+2].rank) {
            return 1;
        }
    }
    return 0;
}

int get_straight(struct card *hand, int size) {
    int count = 0;
    for (int i = 0; i < size-1; i++) {
        if (hand[i].rank == hand[i+1].rank-1) {
            count++;
        }
    }
    if (count == 4) {
        return 1;
    }
    return 0;
}

int get_flush(struct card *hand, int size) {
    int spades = 0;
    int hearts = 0;
    int diamonds = 0;
    int clubs = 0;
    for (int i = 0; i < size; i++) {
        switch (hand[i].suit) {
            case SPADES:
                spades++;
                break;
            case HEARTS:
                hearts++;
                break;
            case DIAMONDS:
                diamonds++;
                break;
            case CLUBS:
                clubs++;
                break;
        }
    }
    if (spades == 5 || hearts == 5 || diamonds == 5 || clubs == 5) {
        return 1;
    }
    return 0;
}

int get_full_house(struct card *hand, int size) {
    int count_pairs = 0;
    int count_triples = 0;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (hand[i].rank == hand[j].rank) {
                if (i+2 < size && hand[i].rank == hand[i+2].rank) {
                    count_triples++;
                } else {
                    count_pairs++;
                }
            }
        }
    }
    if (count_pairs == 1 && count_triples == 1) {
        return 1;
    }
    return 0;
}

int get_four_of_a_kind(struct card *hand, int size) {
    for (int i = 0; i < size-3; i++) {
        if (hand[i].rank == hand[i+1].rank &&
            hand[i+1].rank == hand[i+2].rank &&
            hand[i+2].rank == hand[i+3].rank) {
            return 1;
        }
    }
    return 0;
}

int get_straight_flush(struct card *hand, int size) {
    if (get_flush(hand, size) && get_straight(hand, size)) {
        return 1;
    }
    return 0;
}

int get_royal_flush(struct card *hand, int size) {
    if (get_flush(hand, size) &&
        hand[0].rank == TEN &&
        hand[1].rank == JACK &&
        hand[2].rank == QUEEN &&
        hand[3].rank == KING &&
        hand[4].rank == ACE) {
        return 1;
    }
    return 0;
}

int main() {
    struct card deck[NUM_CARDS];
    int deck_index = 0;

    // build deck
    for (int suit = SPADES; suit <= CLUBS; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            deck[deck_index].suit = suit;
            deck[deck_index].rank = rank;
            deck_index++;
        }
    }

    // shuffle deck
    shuffle(deck, NUM_CARDS);

    // set up hands
    struct card hand[HAND_SIZE];

    // deal cards
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    // print hand
    printf("Your hand:\n");
    print_hand(hand, HAND_SIZE);

    // determine hand strength
    if (get_royal_flush(hand, HAND_SIZE)) {
        printf("Royal flush\n");
    } else if (get_straight_flush(hand, HAND_SIZE)) {
        printf("Straight flush\n");
    } else if (get_four_of_a_kind(hand, HAND_SIZE)) {
        printf("Four of a kind\n");
    } else if (get_full_house(hand, HAND_SIZE)) {
        printf("Full house\n");
    } else if (get_flush(hand, HAND_SIZE)) {
        printf("Flush\n");
    } else if (get_straight(hand, HAND_SIZE)) {
        printf("Straight\n");
    } else if (get_three_of_a_kind(hand, HAND_SIZE)) {
        printf("Three of a kind\n");
    } else if (get_two_pair(hand, HAND_SIZE)) {
        printf("Two pair\n");
    } else if (get_pair(hand, HAND_SIZE)) {
        printf("Pair\n");
    } else {
        printf("High card\n");
    }

    return 0;
}