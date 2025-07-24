//FormAI DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4 // Configurable maximum number of players
#define MAX_CARDS_PER_SUIT 13 // Number of cards in a suit
#define MAX_HAND_CARDS 5 // Number of cards in a hand

typedef enum { SPADES, HEARTS, CLUBS, DIAMONDS } Suit;
typedef enum { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

typedef struct {
    Card cards[MAX_HAND_CARDS];
} Hand;

typedef struct {
    Hand hand;
    int rank;
} Player;

Card deck[MAX_PLAYERS * MAX_HAND_CARDS];
Player players[MAX_PLAYERS];

// Shuffle the deck of cards
void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < MAX_PLAYERS * MAX_HAND_CARDS; i++) {
        int j = rand() % (i+1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Print the given card
void printCard(Card card) {
    switch(card.rank) {
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
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        case ACE:
            printf("A");
            break;
    }
    switch(card.suit) {
        case SPADES:
            printf("S");
            break;
        case HEARTS:
            printf("H");
            break;
        case CLUBS:
            printf("C");
            break;
        case DIAMONDS:
            printf("D");
            break;
    }
}

// Initialize the deck of cards
void initDeck() {
    for (int i = 0; i < MAX_PLAYERS * MAX_HAND_CARDS; i++) {
        deck[i].rank = ((i % MAX_CARDS_PER_SUIT) + 2);
        deck[i].suit = (Suit)(i / MAX_CARDS_PER_SUIT);
    }
}

// Deal cards to the players
void dealCards(int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < MAX_HAND_CARDS; j++) {
            players[i].hand.cards[j] = deck[(i*MAX_HAND_CARDS)+j];
        }
    }
}

void printPlayer(Player player) {
    for (int i = 0; i < MAX_HAND_CARDS; i++) {
        printCard(player.hand.cards[i]);
        printf(" ");
    }
    printf("\tRank: %d\n", player.rank);
}

// Evaluate and assign rank of each player
void evaluateRank(int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        Card* cards = players[i].hand.cards;

        int ranks[MAX_CARDS_PER_SUIT] = {0};
        int suits[MAX_PLAYERS] = {0};

        // Count the number of cards of each rank
        for (int j = 0; j < MAX_HAND_CARDS; j++) {
            ranks[cards[j].rank - 2]++;
            suits[cards[j].suit]++;
        }

        // Check for flush
        int flush = 0;
        for (int j = 0; j < MAX_PLAYERS; j++) {
            if (suits[j] == MAX_HAND_CARDS) {
                flush = 1;
            }
        }

        // Check for straight
        int straight = 0;
        int highAceStraight = 0;
        for (int j = 0; j < MAX_CARDS_PER_SUIT - MAX_HAND_CARDS + 1; j++) {
            int straightCount = 0;
            for (int k = 0; k < MAX_HAND_CARDS; k++) {
                if (ranks[j+k] == 1) {
                    straightCount++;
                } else {
                    break;
                }
            }
            if (straightCount == MAX_HAND_CARDS) {
                straight = 1;
                if (j == MAX_CARDS_PER_SUIT - MAX_HAND_CARDS && ranks[j] == 1) {
                    highAceStraight = 1;
                }
            }
        }

        // Assign rank of the player
        if (flush && straight && highAceStraight) {
            players[i].rank = 10; // Royal Flush
        } else if (flush && straight) {
            players[i].rank = 9; // Straight Flush
        } else if (ranks[10] == 1 && ranks[11] == 1 && ranks[12] == 1 && ranks[0] == 1 && ranks[1] == 1) {
            players[i].rank = 8; // Straight with Ace High
        } else if (straight) {
            players[i].rank = 7; // Straight
        } else if (flush) {
            players[i].rank = 6; // Flush
        } else {
            // Count the number of cards of each rank
            int pairs = 0;
            int threeOfAKind = 0;
            int fourOfAKind = 0;
            for (int j = 0; j < MAX_CARDS_PER_SUIT; j++) {
                if (ranks[j] == 2) {
                    pairs++;
                } else if (ranks[j] == 3) {
                    threeOfAKind = 1;
                } else if (ranks[j] == 4) {
                    fourOfAKind = 1;
                }
            }
            if (fourOfAKind) {
                players[i].rank = 5; // Four of a kind
            } else if (threeOfAKind && pairs) {
                players[i].rank = 4; // Full house
            } else if (flush) {
                players[i].rank = 3; // Flush
            } else if (straight) {
                players[i].rank = 2; // Straight
            } else if (threeOfAKind) {
                players[i].rank = 1; // Three of a kind
            } else if (pairs == 2) {
                players[i].rank = 0; // Two pairs
            } else if (pairs == 1) {
                players[i].rank = -1; // One pair
            } else {
                players[i].rank = -2; // High card
            }
        }
    }
}

int main() {
    int numPlayers = 3; // Configurable number of players

    initDeck();
    shuffleDeck();
    dealCards(numPlayers);
    evaluateRank(numPlayers);

    // Print the hand of each player along with their rank
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: ", i+1);
        printPlayer(players[i]);
    }

    return 0;
}