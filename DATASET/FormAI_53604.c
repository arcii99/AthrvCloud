//FormAI DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_HAND_CARDS 5

typedef enum {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
} Suit;

typedef enum {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

void shuffleDeck(Card *deck);
void printHand(Card *hand);
int evaluateHand(Card *hand);

int main() {
    Card deck[NUM_CARDS];
    Card hand[NUM_HAND_CARDS];

    srand(time(NULL));

    // Initialize deck
    for (int rank = ACE; rank <= KING; rank++) {
        for (int suit = SPADES; suit <= CLUBS; suit++) {
            deck[rank * NUM_SUITS + suit].suit = suit;
            deck[rank * NUM_SUITS + suit].rank = rank;
        }
    }

    // Shuffle deck
    shuffleDeck(deck);

    // Deal hand
    for (int i = 0; i < NUM_HAND_CARDS; i++) {
        hand[i] = deck[i];
    }

    // Print hand
    printHand(hand);

    // Evaluate hand
    int score = evaluateHand(hand);
    printf("Score: %d\n", score);

    return 0;
}

void shuffleDeck(Card *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printHand(Card *hand) {
    for (int i = 0; i < NUM_HAND_CARDS; i++) {
        switch(hand[i].rank) {
            case ACE: printf("Ace of "); break;
            case TWO: printf("2 of "); break;
            case THREE: printf("3 of "); break;
            case FOUR: printf("4 of "); break;
            case FIVE: printf("5 of "); break;
            case SIX: printf("6 of "); break;
            case SEVEN: printf("7 of "); break;
            case EIGHT: printf("8 of "); break;
            case NINE: printf("9 of "); break;
            case TEN: printf("10 of "); break;
            case JACK: printf("Jack of "); break;
            case QUEEN: printf("Queen of "); break;
            case KING: printf("King of "); break;
        }
        switch(hand[i].suit) {
            case SPADES: printf("Spades\n"); break;
            case HEARTS: printf("Hearts\n"); break;
            case DIAMONDS: printf("Diamonds\n"); break;
            case CLUBS: printf("Clubs\n"); break;
        }
    }
}

int evaluateHand(Card *hand) {
    int rankFreq[NUM_RANKS] = {0};
    int suitFreq[NUM_SUITS] = {0};
    int pair = 0;
    int threeKind = 0;
    int fourKind = 0;
    int flush = 0;
    int straight = 0;
    int straightFlush = 0;

    // Gather frequency of each rank and suit
    for (int i = 0; i < NUM_HAND_CARDS; i++) {
        rankFreq[hand[i].rank]++;
        suitFreq[hand[i].suit]++;
    }

    // Check if hand has a pair, three of a kind, or four of a kind
    for (int i = 0; i < NUM_RANKS; i++) {
        if (rankFreq[i] == 2) {
            pair++;
        } else if (rankFreq[i] == 3) {
            threeKind++;
        } else if (rankFreq[i] == 4) {
            fourKind++;
        }
    }

    // Check if hand has a flush
    for (int i = 0; i < NUM_SUITS; i++) {
        if (suitFreq[i] == NUM_HAND_CARDS) {
            flush = 1;
            break;
        }
    }

    // Check if hand has a straight
    int straightStart = -1;
    for (int i = 0; i < NUM_RANKS-4; i++) {
        if (rankFreq[i] && rankFreq[i+1] && rankFreq[i+2] && rankFreq[i+3] && rankFreq[i+4]) {
            straightStart = i;
            straight = 1;
            break;
        }
    }

    // Check if hand has a straight flush
    if (straight && flush) {
        for (int i = straightStart; i < straightStart + NUM_HAND_CARDS; i++) {
            if (hand[i].suit != hand[straightStart].suit) {
                straightFlush = 0;
                break;
            } else {
                straightFlush = 1;
            }
        }
    }

    // Determine score
    if (straightFlush) {
        return 1000 + straightStart; // 1000 = straight flush, add rank of highest card for tiebreaker
    } else if (fourKind) {
        for (int i = 0; i < NUM_RANKS; i++) {
            if (rankFreq[i] == 4) {
                return 800 + i; // 800 = four of a kind, add rank of 4 cards for tiebreaker
            }
        }
    } else if (pair && threeKind) {
        for (int i = 0; i < NUM_RANKS; i++) {
            if (rankFreq[i] == 3) {
                return 700 + i; // 700 = full house, add rank of 3 cards for tiebreaker
            }
        }
    } else if (flush) {
        int highCard = -1;
        for (int i = 0; i < NUM_HAND_CARDS; i++) {
            if (hand[i].rank > highCard) {
                highCard = hand[i].rank;
            }
        }
        return 600 + highCard; // 600 = flush, add rank of highest card for tiebreaker
    } else if (straight) {
        return 500 + straightStart; // 500 = straight, add rank of highest card for tiebreaker
    } else if (threeKind) {
        for (int i = 0; i < NUM_RANKS; i++) {
            if (rankFreq[i] == 3) {
                return 400 + i; // 400 = three of a kind, add rank of 3 cards for tiebreaker
            }
        }
    } else if (pair == 2) {
        int highPair = -1;
        for (int i = 0; i < NUM_RANKS; i++) {
            if (rankFreq[i] == 2 && i > highPair) {
                highPair = i;
            }
        }
        return 300 + highPair; // 300 = two pair, add rank of highest pair for tiebreaker
    } else if (pair) {
        int highPairRank = -1;
        for (int i = 0; i < NUM_RANKS; i++) {
            if (rankFreq[i] == 2) {
                highPairRank = i;
                break;
            }
        }
        int highStraight = -1;
        for (int i = NUM_RANKS-1; i >= 0; i--) {
            if (rankFreq[i] && i != highPairRank && i > highStraight) {
                highStraight = i;
            }
        }
        return 200 + highPairRank*100 + highStraight; // 200 = one pair, add rank of pair, then highest card for tiebreaker
    } else {
        int highCard = -1;
        for (int i = 0; i < NUM_HAND_CARDS; i++) {
            if (hand[i].rank > highCard) {
                highCard = hand[i].rank;
            }
        }
        return highCard; // score is just the rank of the highest card
    }
}