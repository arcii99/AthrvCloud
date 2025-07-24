//FormAI DATASET v1.0 Category: Poker Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define card suits and values
#define SPADES "SPADES"
#define HEARTS "HEARTS"
#define CLUBS "CLUBS"
#define DIAMONDS "DIAMONDS"

#define ACE "ACE"
#define KING "KING"
#define QUEEN "QUEEN"
#define JACK "JACK"
#define TEN "TEN"
#define NINE "NINE"
#define EIGHT "EIGHT"
#define SEVEN "SEVEN"
#define SIX "SIX"
#define FIVE "FIVE"
#define FOUR "FOUR"
#define THREE "THREE"
#define TWO "TWO"

// define data structures
typedef struct {
    char suit[8];
    char value[6];
} Card;

typedef struct {
    Card cards[5];
} Hand;

// function to draw a card
void draw_card(Card *card) {
    // randomize suit
    int suit_rand = rand() % 4;
    switch (suit_rand) {
        case 0:
            strcpy(card->suit, SPADES);
            break;
        case 1:
            strcpy(card->suit, HEARTS);
            break;
        case 2:
            strcpy(card->suit, CLUBS);
            break;
        case 3:
            strcpy(card->suit, DIAMONDS);
            break;
        default:
            break;
    }

    // randomize value
    int value_rand = rand() % 13;
    switch (value_rand) {
        case 0:
            strcpy(card->value, ACE);
            break;
        case 1:
            strcpy(card->value, KING);
            break;
        case 2:
            strcpy(card->value, QUEEN);
            break;
        case 3:
            strcpy(card->value, JACK);
            break;
        case 4:
            strcpy(card->value, TEN);
            break;
        case 5:
            strcpy(card->value, NINE);
            break;
        case 6:
            strcpy(card->value, EIGHT);
            break;
        case 7:
            strcpy(card->value, SEVEN);
            break;
        case 8:
            strcpy(card->value, SIX);
            break;
        case 9:
            strcpy(card->value, FIVE);
            break;
        case 10:
            strcpy(card->value, FOUR);
            break;
        case 11:
            strcpy(card->value, THREE);
            break;
        case 12:
            strcpy(card->value, TWO);
            break;
        default:
            break;
    }
}

// function to print a card
void print_card(Card card) {
    printf("%s OF %s\n", card.value, card.suit);
}

// function to print a hand
void print_hand(Hand hand) {
    for (int i = 0; i < 5; i++) {
        print_card(hand.cards[i]);
    }
}

// function to find the largest group of cards with the same value
int find_largest_group(Hand hand) {
    int groups[13] = {0};
    for (int i = 0; i < 5; i++) {
        if (strcmp(hand.cards[i].value, ACE) == 0) {
            groups[0]++;
        } else if (strcmp(hand.cards[i].value, KING) == 0) {
            groups[1]++;
        } else if (strcmp(hand.cards[i].value, QUEEN) == 0) {
            groups[2]++;
        } else if (strcmp(hand.cards[i].value, JACK) == 0) {
            groups[3]++;
        } else if (strcmp(hand.cards[i].value, TEN) == 0) {
            groups[4]++;
        } else if (strcmp(hand.cards[i].value, NINE) == 0) {
            groups[5]++;
        } else if (strcmp(hand.cards[i].value, EIGHT) == 0) {
            groups[6]++;
        } else if (strcmp(hand.cards[i].value, SEVEN) == 0) {
            groups[7]++;
        } else if (strcmp(hand.cards[i].value, SIX) == 0) {
            groups[8]++;
        } else if (strcmp(hand.cards[i].value, FIVE) == 0) {
            groups[9]++;
        } else if (strcmp(hand.cards[i].value, FOUR) == 0) {
            groups[10]++;
        } else if (strcmp(hand.cards[i].value, THREE) == 0) {
            groups[11]++;
        } else if (strcmp(hand.cards[i].value, TWO) == 0) {
            groups[12]++;
        }
    }

    int largest_group = 0;
    for (int i = 0; i < 13; i++) {
        if (groups[i] > largest_group) {
            largest_group = groups[i];
        }
    }
    return largest_group;
}

// main function
int main() {
    srand(time(NULL));
    printf("Welcome to the C Poker Game!\n");

    printf("Let's deal you a hand...\n");

    Hand hand;
    for (int i = 0; i < 5; i++) {
        draw_card(&hand.cards[i]);
    }

    printf("Your hand is:\n");
    print_hand(hand);

    int largest_group = find_largest_group(hand);
    printf("The largest group of cards with the same value is %d.\n", largest_group);

    printf("Thanks for playing!\n");
    return 0;
}