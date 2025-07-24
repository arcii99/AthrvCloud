//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS (ROWS * COLS)

int cards[TOTAL_CARDS];
int flipped[TOTAL_CARDS];

void initialize_cards() {
    for (int i=0; i<TOTAL_CARDS; i+=2) {
        cards[i] = i/2;
        cards[i+1] = i/2;
    }
}

void shuffle_cards() {
    srand(time(NULL));
    for (int i=0; i<TOTAL_CARDS; i++) {
        int j = rand() % TOTAL_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void print_cards() {
    for (int i=0; i<TOTAL_CARDS; i++) {
        if (flipped[i]) {
            printf("%2d ", cards[i]);
        } else {
            printf("[] ");
        }
        if ((i+1) % ROWS == 0) printf("\n");
    }
}

int match_cards(int a, int b) {
    return (cards[a] == cards[b]);
}

int all_flipped() {
    for (int i=0; i<TOTAL_CARDS; i++) {
        if (!flipped[i]) return 0;
    }
    return 1;
}

int main() {
    initialize_cards();
    shuffle_cards();
    int score = 0;
    while (!all_flipped()) {
        printf("\nScore: %d\n", score);
        print_cards();
        int a, b;
        do {
            printf("Choose two cards (row col): ");
            scanf("%d %d", &a, &b);
        } while (flipped[a] || flipped[b]);
        if (match_cards(a, b)) {
            flipped[a] = flipped[b] = 1;
            score++;
            printf("Match found!\n");
        } else {
            printf("No match.\n");
        }
    }
    printf("\nCongratulations! You found all the matches with a score of %d!\n", score);
    return 0;
}