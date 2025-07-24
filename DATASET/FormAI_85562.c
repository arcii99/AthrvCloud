//FormAI DATASET v1.0 Category: Poker Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS_HAND 5
#define NUM_PLAYERS 2

int tally_points(int hand[]);
void initialize_deck(int deck[][NUM_RANKS]);
void shuffle_deck(int deck[][NUM_RANKS]);
void deal_cards(int deck[][NUM_RANKS], int hands[][NUM_CARDS_HAND]);
void print_hand(int hand[], const char* player);
void swap(int* a, int* b);
void sort_hand(int hand[]);

int main(void) {
    int deck[NUM_SUITS][NUM_RANKS];
    int hands[NUM_PLAYERS][NUM_CARDS_HAND];
    int points[NUM_PLAYERS] = { 0 };
    int round = 1;

    srand((unsigned int) time(NULL));

    initialize_deck(deck);

    do {
        printf("Round %d\n\n", round);

        shuffle_deck(deck);

        deal_cards(deck, hands);

        print_hand(hands[0], "Player 1");
        points[0] = tally_points(hands[0]);
        printf("Player 1's Points: %d\n", points[0]);
        printf("\n");

        print_hand(hands[1], "Player 2");
        points[1] = tally_points(hands[1]);
        printf("Player 2's Points: %d\n", points[1]);
        printf("\n");

        if (points[0] > points[1]) {
            printf("Player 1 wins the round!\n\n");
        } else if (points[1] > points[0]) {
            printf("Player 2 wins the round!\n\n");
        } else {
            printf("It's a tie!\n\n");
        }

        round++;
    } while (round <= 3);

    printf("GAME OVER!\n");

    if (points[0] > points[1]) {
        printf("Player 1 wins!\n");
    } else if (points[1] > points[0]) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

void initialize_deck(int deck[][NUM_RANKS]) {
    int suit, rank;

    for (suit = 0; suit < NUM_SUITS; suit++) {
        for (rank = 0; rank < NUM_RANKS; rank++) {
            deck[suit][rank] = rank + 1;
        }
    }
}

void shuffle_deck(int deck[][NUM_RANKS]) {
    int suit, rank;

    for (suit = 0; suit < NUM_SUITS; suit++) {
        for (rank = 0; rank < NUM_RANKS; rank++) {
            int i = rand() % NUM_SUITS;
            int j = rand() % NUM_RANKS;
            swap(&deck[suit][rank], &deck[i][j]);
        }
    }
}

void deal_cards(int deck[][NUM_RANKS], int hands[][NUM_CARDS_HAND]) {
    int i, j, k;

    k = 0;
    for (i = 0; i < NUM_CARDS_HAND; i++) {
        for (j = 0; j < NUM_PLAYERS; j++) {
            hands[j][i] = deck[k / NUM_RANKS][k % NUM_RANKS];
            k++;
        }
    }
}

void print_hand(int hand[], const char* player) {
    int i;

    printf("%s's Hand\n", player);

    for (i = 0; i < NUM_CARDS_HAND; i++) {
        switch (hand[i]) {
            case 1:
                printf("Ace ");
                break;

            case 11:
                printf("Jack ");
                break;

            case 12:
                printf("Queen ");
                break;

            case 13:
                printf("King ");
                break;

            default:
                printf("%d ", hand[i]);
                break;
        }
    }

    printf("\n");
}

int tally_points(int hand[]) {
    int i, sum = 0;

    for (i = 0; i < NUM_CARDS_HAND; i++) {
        if (hand[i] >= 10) {
            sum += 10;
        } else {
            sum += hand[i];
        }
    }

    return sum;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_hand(int hand[]) {
    int i, j, min_index;

    for (i = 0; i < NUM_CARDS_HAND - 1; i++) {
        min_index = i;

        for (j = i + 1; j < NUM_CARDS_HAND; j++) {
            if (hand[j] < hand[min_index]) {
                min_index = j;
            }
        }

        swap(&hand[i], &hand[min_index]);
    }
}