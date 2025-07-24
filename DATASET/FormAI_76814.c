//FormAI DATASET v1.0 Category: Poker Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2
#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define MAX_NUM_CARDS 5

const char *rank_str[] = {"Ace", "Two", "Three", "Four", "Five",
                          "Six", "Seven", "Eight", "Nine", "Ten",
                          "Jack", "Queen", "King"};
const char *suit_str[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[MAX_NUM_CARDS];
    int num_cards;
} Hand;

typedef struct {
    Hand hand;
    int money;
} Player;

void shuffle_cards(Card *cards, int num_cards) {
    srand(time(NULL));
    for (int i = 0; i < num_cards; i++) {
        int j = rand() % num_cards;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void deal_cards(Player *players) {
    Card cards[NUM_CARDS];
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int rank = 0; rank < NUM_RANKS; rank++) {
            cards[NUM_RANKS * suit + rank].rank = rank;
            cards[NUM_RANKS * suit + rank].suit = suit;
        }
    }
    shuffle_cards(cards, NUM_CARDS);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].hand.num_cards = MAX_NUM_CARDS;
        for (int j = 0; j < MAX_NUM_CARDS; j++) {
            players[i].hand.cards[j] = cards[MAX_NUM_CARDS * i + j];
        }
    }
}

void print_card(Card *card) {
    printf("%s of %s\n", rank_str[card->rank], suit_str[card->suit]);
}

void print_hand(Hand *hand) {
    for (int i = 0; i < hand->num_cards; i++) {
        print_card(&hand->cards[i]);
    }
}

void print_hands(Player *players) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d hand:\n", i + 1);
        print_hand(&players[i].hand);
        printf("\n");
    }
}

int main() {
    Player players[NUM_PLAYERS];
    deal_cards(players);
    print_hands(players);
    return 0;
}