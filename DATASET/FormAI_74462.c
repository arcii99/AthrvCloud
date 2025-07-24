//FormAI DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define suits of cards
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3

// Define values of cards and hands
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

#define HAND_SIZE 5
#define NUM_PLAYERS 2

// Define struct for card
typedef struct {
    int suit;  // Club, Diamond, Heart, or Spade
    int value; // Ace, 2-10, Jack, Queen, or King
} card;

// Define struct for player
typedef struct {
    char *name;     // Player name
    card hand[HAND_SIZE]; // Player hand
} player;

// Function prototypes
void shuffle_deck(card *deck, int size);
void deal_cards(card *deck, player *players, int num_players);
void print_card(card c);
void print_hand(player p);
void evaluate_hand(player *p);

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Create deck of cards
    card deck[52] = {
        {CLUBS, ACE}, {CLUBS, 2}, {CLUBS, 3}, {CLUBS, 4}, {CLUBS, 5}, {CLUBS, 6}, {CLUBS, 7}, {CLUBS, 8}, {CLUBS, 9}, {CLUBS, 10}, {CLUBS, JACK}, {CLUBS, QUEEN}, {CLUBS, KING},
        {DIAMONDS, ACE}, {DIAMONDS, 2}, {DIAMONDS, 3}, {DIAMONDS, 4}, {DIAMONDS, 5}, {DIAMONDS, 6}, {DIAMONDS, 7}, {DIAMONDS, 8}, {DIAMONDS, 9}, {DIAMONDS, 10}, {DIAMONDS, JACK}, {DIAMONDS, QUEEN}, {DIAMONDS, KING},
        {HEARTS, ACE}, {HEARTS, 2}, {HEARTS, 3}, {HEARTS, 4}, {HEARTS, 5}, {HEARTS, 6}, {HEARTS, 7}, {HEARTS, 8}, {HEARTS, 9}, {HEARTS, 10}, {HEARTS, JACK}, {HEARTS, QUEEN}, {HEARTS, KING},
        {SPADES, ACE}, {SPADES, 2}, {SPADES, 3}, {SPADES, 4}, {SPADES, 5}, {SPADES, 6}, {SPADES, 7}, {SPADES, 8}, {SPADES, 9}, {SPADES, 10}, {SPADES, JACK}, {SPADES, QUEEN}, {SPADES, KING}
    };
    
    // Shuffle deck of cards
    shuffle_deck(deck, 52);
    
    // Create players and deal starting hand
    player players[NUM_PLAYERS] = {
        {"Player 1", {deck[0], deck[2], deck[4], deck[6], deck[8]}},
        {"Player 2", {deck[1], deck[3], deck[5], deck[7], deck[9]}}
    };
    
    // Print player hands and evaluate
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s's Hand:\n", players[i].name);
        print_hand(players[i]);
        evaluate_hand(&players[i]);
        printf("\n");
    }
    
    return 0;
}

// Shuffle deck of cards
void shuffle_deck(card *deck, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal cards to players
void deal_cards(card *deck, player *players, int num_players) {
    int index = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = 0; j < num_players; j++) {
            players[j].hand[i] = deck[index++];
        }
    }
}

// Print card
void print_card(card c) {
    switch (c.value) {
        case ACE:
            printf("A");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        default:
            printf("%d", c.value);
    }
    switch (c.suit) {
        case CLUBS:
            printf("C");
            break;
        case DIAMONDS:
            printf("D");
            break;
        case HEARTS:
            printf("H");
            break;
        case SPADES:
            printf("S");
            break;
    }
}

// Print player hand
void print_hand(player p) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(p.hand[i]);
        printf(" ");
    }
    printf("\n");
}

// Evaluate player hand
void evaluate_hand(player *p) {
    // Sort by value
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = i+1; j < HAND_SIZE; j++) {
            if (p->hand[i].value > p->hand[j].value) {
                card temp = p->hand[i];
                p->hand[i] = p->hand[j];
                p->hand[j] = temp;
            }
        }
    }
    
    // Check for pairs, three of a kind, and four of a kind
    int pairs = 0;
    int trips = 0;
    int quads = 0;
    for (int i = 0; i < HAND_SIZE-1; i++) {
        if (p->hand[i].value == p->hand[i+1].value) {
            pairs++;
            if (i < HAND_SIZE-2 && p->hand[i].value == p->hand[i+2].value) {
                trips++;
                if (i < HAND_SIZE-3 && p->hand[i].value == p->hand[i+3].value) {
                    quads++;
                }
            }
        }
    }
    if (quads > 0) {
        printf("Four of a kind!\n");
        return;
    } else if (trips > 0 && pairs > 0) {
        printf("Full house!\n");
        return;
    } else if (trips > 0) {
        printf("Three of a kind!\n");
        return;
    } else if (pairs > 1) {
        printf("Two pair!\n");
        return;
    } else if (pairs > 0) {
        printf("Pair!\n");
        return;
    }
    
    // Check for straight
    int straight = 1;
    for (int i = 0; i < HAND_SIZE-1; i++) {
        if (p->hand[i].value + 1 != p->hand[i+1].value) {
            straight = 0;
            break;
        }
    }
    if (straight) {
        printf("Straight!\n");
        return;
    }
    
    // Check for flush
    int flush = 1;
    for (int i = 0; i < HAND_SIZE-1; i++) {
        if (p->hand[i].suit != p->hand[i+1].suit) {
            flush = 0;
            break;
        }
    }
    if (flush) {
        printf("Flush!\n");
        return;
    }
    
    printf("High card!\n");  // Default result
}