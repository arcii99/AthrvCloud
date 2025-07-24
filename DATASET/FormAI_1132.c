//FormAI DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function to randomly shuffle an array
void shuffle(int deck[], int n) {
    srand(time(NULL)); // seed for random
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // swap elements of deck
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to display player's hand
void displayCards(int hand[], int n) {
    printf("Your cards: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

// function to determine hand ranking
int checkHand(int hand[], int n) {
    // check for pairs, triples, and quads
    int count[13] = {0};
    for (int i = 0; i < n; i++) {
        count[hand[i] - 1]++;
    }
    int pairs = 0;
    int triples = 0;
    int quads = 0;
    for (int i = 0; i < 13; i++) {
        if (count[i] == 2) {
            pairs++;
        }
        else if (count[i] == 3) {
            triples++;
        }
        else if (count[i] == 4) {
            quads++;
        }
    }
    // check for flush and straight
    int flush = 1;
    int straight = 0;
    for (int i = 0; i < n - 1; i++) {
        if (hand[i] % 4 != hand[i+1] % 4) {
            flush = 0;
            break;
        }
        if (hand[i] + 1 == hand[i+1]) {
            straight++;
        }
        else {
            straight = 0;
        }
    }
    if (hand[n-1] - hand[0] == 4) {
        straight++;
    }
    // analyze hand ranking
    if (quads == 1) {
        return 7;
    }
    else if (triples == 1 && pairs == 1) {
        return 6;
    }
    else if (flush == 1) {
        return 5;
    }
    else if (straight > 0) {
        return 4;
    }
    else if (triples == 1) {
        return 3;
    }
    else if (pairs == 2) {
        return 2;
    }
    else if (pairs == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to play poker game
void playPoker() {
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i + 1;
    }
    shuffle(deck, 52);
    int hand[5];
    for (int i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }
    displayCards(hand, 5);
    int ranking = checkHand(hand, 5);
    switch (ranking) {
        case 0:
            printf("High card\n");
            break;
        case 1:
            printf("Pair\n");
            break;
        case 2:
            printf("Two pairs\n");
            break;
        case 3:
            printf("Three of a kind\n");
            break;
        case 4:
            printf("Straight\n");
            break;
        case 5:
            printf("Flush\n");
            break;
        case 6:
            printf("Full house\n");
            break;
        case 7:
            printf("Four of a kind\n");
            break;
    }
}

int main() {
    playPoker();
    return 0;
}