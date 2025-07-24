//FormAI DATASET v1.0 Category: Poker Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO_OF_CARDS 52
#define NO_OF_PLAYERS 4
#define MAX_HAND_SIZE 7

// Enumerated types for cards
enum suit {hearts, diamonds, clubs, spades};
enum card_rank {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

// Structure for each card
struct card {
    enum card_rank rank;
    enum suit s;
};

typedef struct card Card;

// Macro functions to display card rank and suit
#define RANK(x) ((x) % 13)
#define SUIT(x) ((x) / 13)

// Function prototypes
void shuffle(Card *deck);
void deal(const Card *deck, Card *hand, int *current_card);
void print_hand(const Card *hand, int n);
int poker_hand(const Card *hand);
int compare_hands(const void *hand1, const void *hand2);

int main() {
    Card deck[NO_OF_CARDS];
    Card hand[MAX_HAND_SIZE];
    int current_card = 0, i, j, player_wins[NO_OF_PLAYERS] = {0};

    srand((unsigned) time(NULL));

    // Initialize deck
    for(i = 0; i < NO_OF_CARDS; i++) {
        deck[i].rank = i % 13;
        deck[i].s = i / 13;
    }

    // Shuffle deck
    shuffle(deck);

    // Deal and print each player's hand
    for(i = 0; i < NO_OF_PLAYERS; i++) {
        deal(deck, hand, &current_card);
        printf("Player %d\n", i + 1);
        print_hand(hand, MAX_HAND_SIZE);
        player_wins[i] = poker_hand(hand);
    }

    // Determine and print winner(s)
    int max = player_wins[0];
    for(i = 1; i < NO_OF_PLAYERS; i++)
        if(player_wins[i] > max)
            max = player_wins[i];
    printf("\n");
    for(i = 0; i < NO_OF_PLAYERS; i++)
        if(player_wins[i] == max)
            printf("Player %d wins.\n", i + 1);

    return 0;
}

// Shuffle function to shuffle a deck of cards
void shuffle(Card *deck) {
    int i, j;
    Card temp;
    for(i = 0; i < NO_OF_CARDS; i++) {
        j = rand() % NO_OF_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal function to deal a hand of cards from a deck
void deal(const Card *deck, Card *hand, int *current_card) {
    int i;
    for(i = 0; i < MAX_HAND_SIZE; i++)
        hand[i] = deck[(*current_card)++];
}

// Function to print a hand of cards
void print_hand(const Card *hand, int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%2d%c ", RANK(hand[i].rank) + 1, "cdhs"[SUIT(hand[i].s)]);
    printf("\n\n");
}

// Function to determine the type of poker hand
int poker_hand(const Card *hand) {
    qsort(hand, MAX_HAND_SIZE, sizeof(Card), compare_hands);
    int i, rank = RANK(hand[0].rank), flush = 1, straight = 1;
    for(i = 1; i < MAX_HAND_SIZE; i++) {
        if(RANK(hand[i].rank) != rank + 1)
            straight = 0;
        if(SUIT(hand[i].s) != SUIT(hand[i-1].s))
            flush = 0;
        rank = RANK(hand[i].rank);
    }
    if(flush && straight)
        return 8; // Straight flush
    if(hand[0].rank == hand[3].rank || hand[1].rank == hand[4].rank)
        return 7; // Four of a kind
    if(hand[0].rank == hand[2].rank && hand[3].rank == hand[4].rank ||
       hand[0].rank == hand[1].rank && hand[2].rank == hand[4].rank)
        return 6; // Full house
    if(flush)
        return 5; // Flush
    if(straight)
        return 4; // Straight
    if(hand[0].rank == hand[2].rank || hand[1].rank == hand[3].rank
       || hand[2].rank == hand[4].rank)
        return 3; // Three of a kind
    if(hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank ||
       hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank ||
       hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank)
        return 2; // Two pair
    if(hand[0].rank == hand[1].rank || hand[1].rank == hand[2].rank ||
       hand[2].rank == hand[3].rank || hand[3].rank == hand[4].rank)
        return 1; // One pair
    return 0; // High card
}

// Comparator function for qsort to compare card ranks
int compare_hands(const void *hand1, const void *hand2) {
    return RANK(((Card *) hand1)->rank) - RANK(((Card *) hand2)->rank);
}