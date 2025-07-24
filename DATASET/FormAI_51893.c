//FormAI DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

struct card {
    int value;
    char suit;
};

void shuffle(struct card* deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int randIndex = rand() % DECK_SIZE;
        struct card temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

void printCard(struct card c) {
    if (c.value >= 2 && c.value <= 10) {
        printf("%d", c.value);
    } else if (c.value == 11) {
        printf("J");
    } else if (c.value == 12) {
        printf("Q");
    } else if (c.value == 13) {
        printf("K");
    } else if (c.value == 14) {
        printf("A");
    }
    printf("%c ", c.suit);
}

void printHand(struct card* hand, int size) {
    for (int i = 0; i < size; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

int isFlush(struct card* hand, int size) {
    char suit = hand[0].suit;
    for (int i = 1; i < size; i++) {
        if (hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int isStraight(struct card* hand, int size) {
    int values[HAND_SIZE];
    for (int i = 0; i < size; i++) {
        values[i] = hand[i].value;
    }
    int min = values[0];
    int max = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] < min) {
            min = values[i];
        } else if (values[i] > max) {
            max = values[i];
        }
    }
    return (max - min) == 4;
}

int isStraightFlush(struct card* hand, int size) {
    return isFlush(hand, size) && isStraight(hand, size);
}

int isRoyalFlush(struct card* hand, int size) {
    int values[HAND_SIZE];
    for (int i = 0; i < size; i++) {
        values[i] = hand[i].value;
    }
    int min = values[0];
    int max = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] < min) {
            min = values[i];
        } else if (values[i] > max) {
            max = values[i];
        }
    }
    char suit = hand[0].suit;
    return (min == 10) && (max == 14) && isFlush(hand, size);
}

int main() {
    struct card deck[DECK_SIZE];
    int index = 0;
    for (int i = 2; i <= 14; i++) {
        deck[index].value = i;
        deck[index].suit = 'H';
        index++;
        deck[index].value = i;
        deck[index].suit = 'D';
        index++;
        deck[index].value = i;
        deck[index].suit = 'C';
        index++;
        deck[index].value = i;
        deck[index].suit = 'S';
        index++;
    }

    shuffle(deck);

    struct card hand[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    printf("Your hand: ");
    printHand(hand, HAND_SIZE);

    if (isRoyalFlush(hand, HAND_SIZE)) {
        printf("Royal flush!\n");
    } else if (isStraightFlush(hand, HAND_SIZE)) {
        printf("Straight flush!\n");
    } else if (isFlush(hand, HAND_SIZE)) {
        printf("Flush!\n");
    } else if (isStraight(hand, HAND_SIZE)) {
        printf("Straight!\n");
    } else {
        printf("Nothing special...\n");
    }

    return 0;
}