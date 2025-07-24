//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct card {
    char suit;
    int rank;
} Card;

void print_card(Card c) {
    char rank[6];
    switch (c.rank) {
        case 1:
            sprintf(rank, "Ace");
            break;
        case 11:
            sprintf(rank, "Jack");
            break;
        case 12:
            sprintf(rank, "Queen");
            break;
        case 13:
            sprintf(rank, "King");
            break;
        default:
            sprintf(rank, "%d", c.rank);
            break;
    }
    printf("%s of %c's\n", rank, c.suit);
}

void print_hand(Card* hand, int size) {
    for (int i = 0; i < size; i++) {
        print_card(hand[i]);
    }
}

void shuffle_deck(Card* deck, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card* deck, int deck_size, Card* hand, int hand_size) {
    for (int i = 0; i < hand_size; i++) {
        hand[i] = deck[deck_size - 1 - i];
    }
}

int get_hand_rank(Card* hand, int size) {
    int ranks[14] = {0};
    int suits[4] = {0};
    int straight = 0, flush = 0, pair = 0, three = 0, four = 0;

    for (int i = 0; i < size; i++) {
        ranks[hand[i].rank]++;
        suits[hand[i].suit - 'A']++;
    }

    for (int i = 1; i <= 10; i++) {
        if (ranks[i] && ranks[i+1] && ranks[i+2] && ranks[i+3] && ranks[i+4]) {
            straight = 1;
            break;
        }
    }
    if (ranks[1] && ranks[10] && ranks[11] && ranks[12] && ranks[13]) {
        straight = 1;
    }

    for (int i = 0; i < 4; i++) {
        if (suits[i] == HAND_SIZE) {
            flush = 1;
            break;
        }
    }

    for (int i = 1; i <= 13; i++) {
        if (ranks[i] == 4) {
            four = i;
            break;
        } else if (ranks[i] == 3) {
            three = i;
            pair++;
        } else if (ranks[i] == 2) {
            if (pair) {
                three = i;
            } else {
                pair = i;
            }
        }
    }

    if (flush && straight) {
        return 9;
    } else if (four) {
        return 8;
    } else if (three && pair) {
        return 7;
    } else if (flush) {
        return 6;
    } else if (straight) {
        return 5;
    } else if (three) {
        return 4;
    } else if (pair && pair != three) {
        return 3;
    } else {
        return 2;
    }
}

void swap_cards(Card* hand, int size, int i, int j) {
    Card temp = hand[i];
    hand[i] = hand[j];
    hand[j] = temp;
}

void discard_cards(Card* deck, int deck_size, Card* hand, int hand_size, int* discards, int num_discards) {
    for (int i = 0; i < num_discards; i++) {
        int discard_index;
        do {
            printf("Enter index of card to discard: ");
            scanf("%d", &discard_index);
        } while (discard_index < 0 || discard_index >= hand_size);
        discards[i] = discard_index;
    }

    for (int i = 0; i < num_discards; i++) {
        for (int j = num_discards - 1; j > i; j--) {
            if (discards[j] < discards[j-1]) {
                int temp = discards[j];
                discards[j] = discards[j-1];
                discards[j-1] = temp;
            }
        }
    }

    for (int i = 0; i < num_discards; i++) {
        for (int j = discards[i] + 1; j < hand_size; j++) {
            swap_cards(hand, hand_size, j-1, j);
        }
    }

    deal_cards(deck, deck_size, hand + (hand_size - num_discards), num_discards);
}

int main() {
    Card deck[DECK_SIZE];
    Card hand[HAND_SIZE];
    int discards[HAND_SIZE];
    int deck_index = 0;
    char suits[4] = {'C', 'D', 'H', 'S'};

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            deck[deck_index].suit = suits[i];
            deck[deck_index].rank = j;
            deck_index++;
        }
    }

    shuffle_deck(deck, DECK_SIZE);
    deal_cards(deck, DECK_SIZE, hand, HAND_SIZE);
    print_hand(hand, HAND_SIZE);

    int num_discards;
    do {
        printf("Enter number of cards to discard (0-5): ");
        scanf("%d", &num_discards);
    } while (num_discards < 0 || num_discards > 5);

    discard_cards(deck, DECK_SIZE, hand, HAND_SIZE, discards, num_discards);
    print_hand(hand, HAND_SIZE);

    int rank = get_hand_rank(hand, HAND_SIZE);
    printf("Hand rank: %d\n", rank);

    return 0;
}