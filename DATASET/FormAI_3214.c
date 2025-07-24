//FormAI DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *deck, int n) {
    // Fisher-Yates shuffle algorithm
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(int *deck, int n, int **hands, int num_players, int cards_per_hand) {
    // Allocate memory for each player's hand
    for (int i = 0; i < num_players; i++) {
        hands[i] = malloc(cards_per_hand * sizeof(int));
    }

    // Deal cards to each player
    int card_index = 0;
    for (int i = 0; i < cards_per_hand; i++) {
        for (int j = 0; j < num_players; j++) {
            hands[j][i] = deck[card_index++];
        }
    }
}

int compare(const void *a, const void *b) {
    // Compare function for sorting cards in ascending order
    return *(int *)a - *(int *)b;
}

void print_hand(int *hand, int n) {
    // Print a player's hand
    for (int i = 0; i < n; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

void check_pair(int *hand, int n) {
    // Check if a player has a pair of cards
    qsort(hand, n, sizeof(int), compare);

    for (int i = 0; i < n - 1; i++) {
        if (hand[i] == hand[i + 1]) {
            printf("You have a pair of %d's!\n", hand[i]);
            return;
        }
    }
    printf("You do not have a pair.\n");
}

int main() {
    srand(time(NULL));  // Seed for random number generation

    int deck[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};  // Cards in a deck
    int num_players = 3;
    int cards_per_hand = 2;
    int *hands[num_players];

    shuffle(deck, 13);
    deal(deck, 13, hands, num_players, cards_per_hand);

    for (int i = 0; i < num_players; i++) {
        printf("Player %d's hand: ", i + 1);
        print_hand(hands[i], cards_per_hand);
        check_pair(hands[i], cards_per_hand);
        printf("\n");
    }

    // Free memory allocated for each player's hand
    for (int i = 0; i < num_players; i++) {
        free(hands[i]);
    }

    return 0;
}