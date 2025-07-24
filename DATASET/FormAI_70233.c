//FormAI DATASET v1.0 Category: Poker Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

void shuffle(int deck[], int n);
void deal(int deck[], char suits[], char *ranks[]);
int evaluate(int hand[], const char *ranks[]);

int main() {
    int deck[DECK_SIZE];
    char suits[] = "CDHS";
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    srand(time(NULL));
    shuffle(deck, DECK_SIZE);
    deal(deck, suits, ranks);

    return 0;
}

void shuffle(int deck[], int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        deck[i] = i;
    }
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(int deck[], char suits[], char *ranks[]) {
    int i, hand[HAND_SIZE], card, rank, suit;
    const char *hand_results[] = {"High card", "Pair", "Two pairs", "Three of a kind", "Straight", "Flush", "Full house", "Four of a kind", "Straight flush", "Royal flush"};

    for (i = 0; i < HAND_SIZE; i++) {
        card = deck[i];
        rank = card % 13;
        suit = card / 13;
        printf("%s%c ", ranks[rank], suits[suit]);
        hand[i] = rank;
    }
    printf("\n\n%s\n", hand_results[evaluate(hand, ranks)]);
}

int evaluate(int hand[], const char *ranks[]) {
    int i, j, count, max_count = 1, rank, suit, flush = 1, straight = 0, potential_straight = 0, has_ace = 0;
    int rank_counts[13] = {0}, suit_counts[4] = {0};

    for (i = 0; i < HAND_SIZE; i++) {
        rank_counts[hand[i]]++;
        suit_counts[hand[i] / 4]++;
        if (hand[i] == 0) {
            has_ace = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (suit_counts[i] != HAND_SIZE / 5) {
            flush = 0;
        }
    }
    for (i = 0; i < 9; i++) {
        count = 0;
        for (j = i; j < i + 5; j++) {
            if (rank_counts[j % 13] > 0) {
                count++;
            } else if (j % 13 == 0 && has_ace) {
                count++;
            } else {
                potential_straight = 1;
                count = 0;
            }
        }
        max_count = count > max_count ? count : max_count;
    }
    straight = max_count == 5 || (max_count == 4 && rank_counts[0] > 0);

    if (straight && flush && rank_counts[12] > 0) {
        return 9;  // Royal flush
    }
    if (straight && flush) {
        return 8;  // Straight flush
    }
    if (rank_counts[12] >= 4 || rank_counts[11] >= 4 || rank_counts[10] >= 4 || rank_counts[9] >= 4) {
        return 7;  // Four of a kind
    }
    if (rank_counts[12] == 3 || rank_counts[11] == 3 || rank_counts[10] == 3 || rank_counts[9] == 3) {
        if (rank_counts[9] == 2 || rank_counts[10] == 2 || rank_counts[11] == 2 || rank_counts[12] == 2) {
            return 6;  // Full house
        }
        return 3;  // Three of a kind
    }
    if (rank_counts[12] == 2 || rank_counts[11] == 2 || rank_counts[10] == 2 || rank_counts[9] == 2) {
        if (rank_counts[9] == 2 || rank_counts[10] == 2 || rank_counts[11] == 2 || rank_counts[12] == 2) {
            return 2;  // Two pairs
        }
        return 1;  // Pair
    }
    if (flush) {
        return 5;  // Flush
    }
    if (potential_straight || straight) {
        return 4;  // Straight
    }
    return 0;  // High card
}