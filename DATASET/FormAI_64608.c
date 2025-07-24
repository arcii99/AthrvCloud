//FormAI DATASET v1.0 Category: Poker Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    char suit;
} card;

void shuffle(card *deck) {
    srand(time(NULL));
    for (int i = 51; i >= 1; i--) {
        int j = rand() % (i + 1);
        card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void deal(card *deck, card *hand) {
    int i = 0;
    while (hand[i].value != 0) {
        i++;
    }
    hand[i] = *deck;
    deck += 1;
}

void print_cards(card *hand) {
    printf("Your hand:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d%c ", hand[i].value, hand[i].suit);
    }
    printf("\n");
}

int pair(card *hand) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (hand[i].value == hand[j].value) {
                count++;
            }
        }
    }
    return count;
}

int flush(card *hand) {
    char suit = hand[0].suit;
    for (int i = 1; i < 5; i++) {
        if (hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Welcome to the Happy Poker Game!\n");

    card deck[52] = {
        {2, 'C'}, {3, 'C'}, {4, 'C'}, {5, 'C'}, {6, 'C'}, {7, 'C'}, {8, 'C'}, {9, 'C'}, {10, 'C'}, {11, 'C'}, {12, 'C'}, {13, 'C'}, {14, 'C'},
        {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}, {10, 'D'}, {11, 'D'}, {12, 'D'}, {13, 'D'}, {14, 'D'},
        {2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'}, {10, 'H'}, {11, 'H'}, {12, 'H'}, {13, 'H'}, {14, 'H'},
        {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'}, {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'}, {14, 'S'},
    };

    shuffle(deck);

    card hand[5] = {{0, ' '}, {0, ' '}, {0, ' '}, {0, ' '}, {0, ' '}};
    deal(deck, hand);
    deal(deck, hand);
    deal(deck, hand);
    deal(deck, hand);
    deal(deck, hand);

    print_cards(hand);

    int pair_count = pair(hand);
    int flush_count = flush(hand);

    if (pair_count == 1 && flush_count == 0) {
        printf("You got a pair! Yay!\n");
    } else if (pair_count == 0 && flush_count == 1) {
        printf("You got a flush! Yippee!\n");
    } else if (pair_count == 1 && flush_count == 1) {
        printf("You got both a pair and a flush! Awesome!\n");
    } else {
        printf("Sorry, no luck this time. Better luck next round!\n");
    }

    return 0;
}