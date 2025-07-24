//FormAI DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    int value;
    char suit;
} card;

typedef struct {
    int num_pairs;
    int num_triples;
    int num_fours;
    int num_flush;
    int num_straight;
    int high_card;
} hand_info;

void shuffle_deck(card deck[]) {
    srand(time(NULL));
    int i, j;
    card temp;
    for (i = DECK_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

hand_info get_hand_info(card hand[]) {
    int i, j;
    int value_counts[13] = {0};
    int suit_counts[4] = {0};
    int straight_count = 0;
    int high_card = 0;
    int num_pairs = 0;
    int num_triples = 0;
    int num_fours = 0;
    int num_flush = 0;
    int num_straight = 0;

    for (i = 0; i < HAND_SIZE; i++) {
        value_counts[hand[i].value]++;
        suit_counts[hand[i].suit]++;
        if (hand[i].value > high_card) {
            high_card = hand[i].value;
        }
    }

    for (i = 0; i < 9; i++) {
        straight_count = 0;
        for (j = i; j < i + 5; j++) {
            if (value_counts[j]) {
                straight_count++;
            } else {
                straight_count = 0;
            }
        }
        if (straight_count == 5) {
            num_straight++;
            break;
        }
    }

    for (i = 0; i < 13; i++) {
        if (value_counts[i] == 2) {
            num_pairs++;
        } else if (value_counts[i] == 3) {
            num_triples++;
        } else if (value_counts[i] == 4) {
            num_fours++;
        }
    }

    for (i = 0; i < 4; i++) {
        if (suit_counts[i] == HAND_SIZE) {
            num_flush = 1;
        }
    }

    hand_info info = {num_pairs, num_triples, num_fours, num_flush, num_straight, high_card};
    return info;
}

void print_card(card c) {
    char value;
    switch(c.value) {
        case 0:
            value = '2';
            break;
        case 1:
            value = '3';
            break;
        case 2:
            value = '4';
            break;
        case 3:
            value = '5';
            break;
        case 4:
            value = '6';
            break;
        case 5:
            value = '7';
            break;
        case 6:
            value = '8';
            break;
        case 7:
            value = '9';
            break;
        case 8:
            value = 'T';
            break;
        case 9:
            value = 'J';
            break;
        case 10:
            value = 'Q';
            break;
        case 11:
            value = 'K';
            break;
        case 12:
            value = 'A';
            break;
    }
    printf("%c%c ", value, c.suit);
}

void print_hand(card hand[]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
    }
    printf("\n");
}

void play_game() {
    card deck[DECK_SIZE];
    card hand[HAND_SIZE];
    int i, j, k;
    int num_iterations = 1000;
    int wins[HAND_SIZE] = {0};

    // Initialize deck
    for (i = 0; i < DECK_SIZE; i++) {
        deck[i].value = i % 13;
        if (i < 13) {
            deck[i].suit = 'C';
        } else if (i < 26) {
            deck[i].suit = 'D';
        } else if (i < 39) {
            deck[i].suit = 'H';
        } else {
            deck[i].suit = 'S';
        }
    }

    for (i = 0; i < num_iterations; i++) {
        shuffle_deck(deck);

        // Draw hands
        for (j = 0; j < HAND_SIZE; j++) {
            hand[j] = deck[j];
        }

        // Determine winner
        int winner_index = 0;
        hand_info winner_info = get_hand_info(hand);

        for (j = 1; j < HAND_SIZE; j++) {
            hand_info info = get_hand_info(hand + j);
            if (info.num_flush > winner_info.num_flush) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_flush == winner_info.num_flush && info.high_card > winner_info.high_card) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_straight > winner_info.num_straight) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_straight == winner_info.num_straight && info.high_card > winner_info.high_card) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_fours > winner_info.num_fours) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_fours == winner_info.num_fours && info.high_card > winner_info.high_card) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_triples > winner_info.num_triples) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_triples == winner_info.num_triples && info.high_card > winner_info.high_card) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_pairs > winner_info.num_pairs) {
                winner_info = info;
                winner_index = j;
            } else if (info.num_pairs == winner_info.num_pairs && info.high_card > winner_info.high_card) {
                winner_info = info;
                winner_index = j;
            }
        }

        wins[winner_index]++;
    }

    // Print results
    for (i = 0; i < HAND_SIZE; i++) {
        printf("Hand %d: ", i + 1);
        print_hand(hand);
        printf("Wins: %d\n\n", wins[i]);
    }
}

int main() {
    play_game();
    return 0;
}