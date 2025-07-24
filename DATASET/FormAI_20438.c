//FormAI DATASET v1.0 Category: Poker Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int)time(NULL));

    int deck[52];
    int i, j, k;

    for(i = 0; i < 52; i++) {
        deck[i] = i + 1;
    }

    for(i = 0; i < 52; i++) {
        j = rand() % 52;
        k = deck[i];
        deck[i] = deck[j];
        deck[j] = k;
    }

    int cards[5];

    printf("Your hand:\n");
    for(i = 0; i < 5; i++) {
        cards[i] = deck[i];
        printf("%d ", cards[i]);
    }

    int pairs = 0;
    int suits[4] = {0};
    int ranks[13] = {0};

    for(i = 0; i < 5; i++) {
        int suit = (cards[i] - 1) / 13;
        suits[suit]++;
        int rank = (cards[i] - 1) % 13;
        ranks[rank]++;
    }

    for(i = 0; i < 4; i++) {
        if(suits[i] == 5) {
            printf("\nYou have a flush!\n");
            return 0;
        }
    }

    for(i = 0; i < 13; i++) {
        if(ranks[i] == 4) {
            printf("\nYou have four of a kind!\n");
            return 0;
        } else if(ranks[i] == 3) {
            pairs++;
        }
    }

    if(pairs == 1) {
        printf("\nYou have a three of a kind!\n");
        return 0;
    } else if(pairs == 2) {
        printf("\nYou have two pairs!\n");
        return 0;
    } else {
        printf("\nSorry, you have no winning combinations.\n");
        return 0;
    }
}