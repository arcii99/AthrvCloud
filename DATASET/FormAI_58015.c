//FormAI DATASET v1.0 Category: Poker Game ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card {
    char suit[20];
    char face[20];
    int value;
};

typedef struct card Card;

void shuffle(Card deck[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(Card deck[], Card hand[], int* count) {
    hand[*count] = deck[*count];
    (*count)++;
}

void printHand(Card hand[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s of %s\n", hand[i].face, hand[i].suit);
    }
}

void valueSort(Card hand[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (hand[i].value > hand[j].value) {
                Card temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

void suitSort(Card hand[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(hand[i].suit, hand[j].suit) > 0) {
                Card temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

int isStraight(Card hand[], int count) {
    valueSort(hand, count);
    for (int i = 0; i < count - 1; i++) {
        if (hand[i+1].value != hand[i].value + 1) {
            return 0;
        }
    }
    return 1;
}

int isFlush(Card hand[], int count) {
    for (int i = 0; i < count - 1; i++) {
        if (strcmp(hand[i].suit, hand[i+1].suit) != 0) {
            return 0;
        }
    }
    return 1;
}

int isStraightFlush(Card hand[], int count) {
    if (isFlush(hand, count) && isStraight(hand, count)) {
        return 1;
    }
    return 0;
}

int isRoyalFlush(Card hand[], int count) {
    valueSort(hand, count);
    if (hand[0].value == 10 && isStraightFlush(hand, count)) {
        return 1;
    }
    return 0;
}

int main() {
    Card deck[52] = {
        {"Hearts", "Ace", 1}, {"Hearts", "Two", 2}, {"Hearts", "Three", 3}, {"Hearts", "Four", 4}, 
        {"Hearts", "Five", 5}, {"Hearts", "Six", 6}, {"Hearts", "Seven", 7}, {"Hearts", "Eight", 8}, 
        {"Hearts", "Nine", 9}, {"Hearts", "Ten", 10}, {"Hearts", "Jack", 11}, {"Hearts", "Queen", 12}, 
        {"Hearts", "King", 13}, {"Diamonds", "Ace", 1}, {"Diamonds", "Two", 2}, {"Diamonds", "Three", 3}, 
        {"Diamonds", "Four", 4}, {"Diamonds", "Five", 5}, {"Diamonds", "Six", 6}, {"Diamonds", "Seven", 7}, 
        {"Diamonds", "Eight", 8}, {"Diamonds", "Nine", 9}, {"Diamonds", "Ten", 10}, {"Diamonds", "Jack", 11}, 
        {"Diamonds", "Queen", 12}, {"Diamonds", "King", 13}, {"Clubs", "Ace", 1}, {"Clubs", "Two", 2}, 
        {"Clubs", "Three", 3}, {"Clubs", "Four", 4}, {"Clubs", "Five", 5}, {"Clubs", "Six", 6}, 
        {"Clubs", "Seven", 7}, {"Clubs", "Eight", 8}, {"Clubs", "Nine", 9}, {"Clubs", "Ten", 10}, 
        {"Clubs", "Jack", 11}, {"Clubs", "Queen", 12}, {"Clubs", "King", 13}, {"Spades", "Ace", 1}, 
        {"Spades", "Two", 2}, {"Spades", "Three", 3}, {"Spades", "Four", 4}, {"Spades", "Five", 5}, 
        {"Spades", "Six", 6}, {"Spades", "Seven", 7}, {"Spades", "Eight", 8}, {"Spades", "Nine", 9}, 
        {"Spades", "Ten", 10}, {"Spades", "Jack", 11}, {"Spades", "Queen", 12}, {"Spades", "King", 13}
    };
    shuffle(deck, 52);
    Card hand[5];
    int count = 0;
    deal(deck, hand, &count);
    deal(deck, hand, &count);
    deal(deck, hand, &count);
    deal(deck, hand, &count);
    deal(deck, hand, &count);
    printf("Your hand:\n");
    printHand(hand, 5);
    if (isRoyalFlush(hand, 5)) {
        printf("Royal flush!\n");
    } else if (isStraightFlush(hand, 5)) {
        printf("Straight flush!\n");
    } else if (isFlush(hand, 5)) {
        printf("Flush!\n");
    } else if (isStraight(hand, 5)) {
        printf("Straight!\n");
    } else {
        printf("Nothing!\n");
    }
    return 0;
}