//FormAI DATASET v1.0 Category: Poker Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52
#define MAX_PLAYERS 5

enum rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum suit {HEARTS, DIAMONDS, CLUBS, SPADES};

struct card {
    enum rank rank;
    enum suit suit;
};

struct player {
    int id;
    struct card hand[2];
};

void print_card(struct card c) {
    switch(c.rank) {
        case ACE:
            printf("Ace");
            break;
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        case TEN:
            printf("10");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
        default:
            printf("Invalid Rank");
    }
    printf(" of ");
    switch(c.suit) {
        case HEARTS:
            printf("Hearts");
            break;
        case DIAMONDS:
            printf("Diamonds");
            break;
        case CLUBS:
            printf("Clubs");
            break;
        case SPADES:
            printf("Spades");
            break;
        default:
            printf("Invalid Suit");
    }
    printf("\n");
}

void print_hand(struct player p) {
    printf("Player %d's Hand:\n", p.id);
    print_card(p.hand[0]);
    print_card(p.hand[1]);
}

void generate_deck(struct card deck[]) {
    int i = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
}

void shuffle_deck(struct card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int index1 = rand() % MAX_CARDS;
        int index2 = rand() % MAX_CARDS;
        struct card temp = deck[index1];
        deck[index1] = deck[index2];
        deck[index2] = temp;
    }
}

int main() {
    struct card deck[MAX_CARDS];
    struct player players[MAX_PLAYERS];
    generate_deck(deck);
    shuffle_deck(deck);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i + 1;
        players[i].hand[0] = deck[i*2];
        players[i].hand[1] = deck[i*2+1];
        print_hand(players[i]);
    }
    return 0;
}