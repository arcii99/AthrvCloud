//FormAI DATASET v1.0 Category: Poker Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 5
#define DECK_SIZE 52

char *face_values[] = {"Two", "Three", "Four", "Five", "Six",
                       "Seven", "Eight", "Nine", "Ten", "Jack",
                       "Queen", "King", "Ace"};

char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

typedef struct card {
    int face_value;
    int suit;
} card;

void shuffle(card deck[]);
void swap(card *a, card *b);
void deal(card deck[], card hand[], int hand_size);
void print_hand(card hand[], int hand_size);
int get_face_value(char *face);
void sort_hand(card hand[], int hand_size);
int is_flush(card hand[], int hand_size);
int is_straight(card hand[], int hand_size);
int is_straight_flush(card hand[], int hand_size);
int is_royal_flush(card hand[], int hand_size);
int is_four_of_a_kind(card hand[], int hand_size);
int is_full_house(card hand[], int hand_size);
int is_three_of_a_kind(card hand[], int hand_size);
int is_two_pair(card hand[], int hand_size);
int is_one_pair(card hand[], int hand_size);
int get_high_card(card hand[], int hand_size);
void print_result(int result);

int main() {
    card deck[DECK_SIZE];
    card hand[HAND_SIZE];
    int result = 0;

    srand(time(NULL));

    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].face_value = i % 13;
        deck[i].suit = i / 13;
    }

    shuffle(deck);

    deal(deck, hand, HAND_SIZE);

    sort_hand(hand, HAND_SIZE);

    printf("Your hand:\n");
    print_hand(hand, HAND_SIZE);

    if (is_royal_flush(hand, HAND_SIZE))
        result = 10;
    else if (is_straight_flush(hand, HAND_SIZE))
        result = 9;
    else if (is_four_of_a_kind(hand, HAND_SIZE))
        result = 8;
    else if (is_full_house(hand, HAND_SIZE))
        result = 7;
    else if (is_flush(hand, HAND_SIZE))
        result = 6;
    else if (is_straight(hand, HAND_SIZE))
        result = 5;
    else if (is_three_of_a_kind(hand, HAND_SIZE))
        result = 4;
    else if (is_two_pair(hand, HAND_SIZE))
        result = 3;
    else if (is_one_pair(hand, HAND_SIZE))
        result = 2;
    else
        result = 1;

    printf("\nResult: ");
    print_result(result);

    return 0;
}

void shuffle(card deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        swap(&deck[i], &deck[j]);
    }
}

void swap(card *a, card *b) {
    card temp = *a;
    *a = *b;
    *b = temp;
}

void deal(card deck[], card hand[], int hand_size) {
    for (int i = 0; i < hand_size; i++) {
        hand[i] = deck[i];
    }
}

void print_hand(card hand[], int hand_size) {
    for (int i = 0; i < hand_size; i++) {
        printf("%s of %s\n", face_values[hand[i].face_value], suits[hand[i].suit]);
    }
}

int get_face_value(char *face) {
    for (int i = 0; i < 13; i++) {
        if (face_values[i][0] == face[0])
            return i;
    }
    return -1;
}

void sort_hand(card hand[], int hand_size) {
    int swaps;
    do {
        swaps = 0;
        for (int i = 0; i < hand_size - 1; i++) {
            if (hand[i].face_value > hand[i + 1].face_value) {
                swap(&hand[i], &hand[i + 1]);
                swaps = 1;
            }
        }
    } while (swaps == 1);
}

int is_flush(card hand[], int hand_size) {
    int flush = 1;
    int suit = hand[0].suit;
    for (int i = 1; i < hand_size; i++) {
        if (hand[i].suit != suit) {
            flush = 0;
            break;
        }
    }
    return flush;
}

int is_straight(card hand[], int hand_size) {
    int straight = 1;
    int value = hand[0].face_value;
    for (int i = 1; i < hand_size; i++) {
        if (hand[i].face_value != value + 1) {
            straight = 0;
            break;
        }
        value++;
    }
    return straight;
}

int is_straight_flush(card hand[], int hand_size) {
    if (is_flush(hand, hand_size) && is_straight(hand, hand_size))
        return 1;
    return 0;
}

int is_royal_flush(card hand[], int hand_size) {
    if (is_flush(hand, hand_size) && hand[0].face_value == 9 &&
        hand[1].face_value == 10 && hand[2].face_value == 11 &&
        hand[3].face_value == 12 && hand[4].face_value == 0)
        return 1;
    return 0;
}

int is_four_of_a_kind(card hand[], int hand_size) {
    if (hand[0].face_value == hand[3].face_value ||
        hand[1].face_value == hand[4].face_value)
        return 1;
    return 0;
}

int is_full_house(card hand[], int hand_size) {
    if (hand[0].face_value == hand[1].face_value &&
        hand[2].face_value == hand[4].face_value)
        return 1;
    if (hand[0].face_value == hand[2].face_value &&
        hand[3].face_value == hand[4].face_value)
        return 1;
    return 0;
}

int is_three_of_a_kind(card hand[], int hand_size) {
    if (hand[0].face_value == hand[2].face_value ||
        hand[1].face_value == hand[3].face_value ||
        hand[2].face_value == hand[4].face_value)
        return 1;
    return 0;
}

int is_two_pair(card hand[], int hand_size) {
    if (hand[0].face_value == hand[1].face_value &&
        hand[2].face_value == hand[3].face_value)
        return 1;
    if (hand[0].face_value == hand[1].face_value &&
        hand[3].face_value == hand[4].face_value)
        return 1;
    if (hand[1].face_value == hand[2].face_value &&
        hand[3].face_value == hand[4].face_value)
        return 1;
    return 0;
}

int is_one_pair(card hand[], int hand_size) {
    if (hand[0].face_value == hand[1].face_value ||
        hand[1].face_value == hand[2].face_value ||
        hand[2].face_value == hand[3].face_value ||
        hand[3].face_value == hand[4].face_value)
        return 1;
    return 0;
}

int get_high_card(card hand[], int hand_size) {
    return hand[hand_size - 1].face_value;
}

void print_result(int result) {
    switch (result) {
        case 1:
            printf("High card");
            break;
        case 2:
            printf("One pair");
            break;
        case 3:
            printf("Two pair");
            break;
        case 4:
            printf("Three of a kind");
            break;
        case 5:
            printf("Straight");
            break;
        case 6:
            printf("Flush");
            break;
        case 7:
            printf("Full house");
            break;
        case 8:
            printf("Four of a kind");
            break;
        case 9:
            printf("Straight flush");
            break;
        case 10:
            printf("Royal flush");
            break;
    }
}