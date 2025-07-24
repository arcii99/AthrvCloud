//FormAI DATASET v1.0 Category: Poker Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define MAX_PLAYERS 6

enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum HandRanking { HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH };

typedef struct {
    enum Rank rank;
    enum Suit suit;
} Card;

typedef struct {
    Card cards[5];
    enum HandRanking ranking;
} Hand;

void shuffleDeck(Card *deck) {
    int i, j;
    Card tmp;

    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % i;
        tmp = deck[j];
        deck[j] = deck[i];
        deck[i] = tmp;
    }
}

void dealHands(Card *deck, Hand *hands, int numPlayers) {
    int i, j, c = 0;

    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < 5; j++) {
            hands[i].cards[j] = deck[c++];
        }
    }
}

void printCard(Card card) {
    const char *ranks[NUM_RANKS] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suits[NUM_SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void printHand(Hand hand) {
    int i;

    for (i = 0; i < 5; i++) {
        printCard(hand.cards[i]);
    }
}

void evaluateHand(Hand *hand) {
    int i, j;
    int rankCounts[NUM_RANKS] = {0};
    int suitCounts[NUM_SUITS] = {0};
    int maxRankCount = 0, maxSuitCount = 0;
    int hasPair = 0, hasTwoPair = 0, hasThreeOfAKind = 0, hasFourOfAKind = 0, hasFlush = 0, hasStraight = 0;
    int straightStart = -1, straightEnd = -1;

    /* Count ranks and suits */
    for (i = 0; i < 5; i++) {
        rankCounts[hand->cards[i].rank]++;
        suitCounts[hand->cards[i].suit]++;
    }

    /* Check for flush */
    for (i = 0; i < NUM_SUITS; i++) {
        if (suitCounts[i] == 5) {
            hasFlush = 1;
            break;
        }
    }

    /* Check for straight */
    for (i = 0; i < NUM_RANKS - 4; i++) {
        for (j = i; j < i + 5; j++) {
            if (rankCounts[j]) {
                if (straightStart == -1) {
                    straightStart = j;
                }
                else {
                    straightEnd = j;
                }
            }
            else {
                straightStart = -1;
                straightEnd = -1;
                break;
            }
        }

        if (straightStart != -1 && straightEnd != -1) {
            hasStraight = 1;
            break;
        }
    }

    /* Check for four of a kind, three of a kind, and pair */
    for (i = 0; i < NUM_RANKS; i++) {
        if (rankCounts[i] > maxRankCount) {
            maxRankCount = rankCounts[i];
        }

        switch (rankCounts[i]) {
            case 2:
                hasPair = 1;
                break;
            case 3:
                hasThreeOfAKind = 1;
                break;
            case 4:
                hasFourOfAKind = 1;
                break;
        }
    }

    /* Check for two pair */
    for (i = 0; i < NUM_RANKS; i++) {
        if (rankCounts[i] == 2) {
            for (j = i + 1; j < NUM_RANKS; j++) {
                if (rankCounts[j] == 2) {
                    hasTwoPair = 1;
                    break;
                }
            }
        }

        if (hasTwoPair) {
            break;
        }
    }

    /* Evaluate hand */
    if (hasFlush && hasStraight) {
        hand->ranking = STRAIGHT_FLUSH;
    }
    else if (hasFourOfAKind) {
        hand->ranking = FOUR_OF_A_KIND;
    }
    else if (hasThreeOfAKind && hasPair) {
        hand->ranking = FULL_HOUSE;
    }
    else if (hasFlush) {
        hand->ranking = FLUSH;
    }
    else if (hasStraight) {
        hand->ranking = STRAIGHT;
    }
    else if (hasThreeOfAKind) {
        hand->ranking = THREE_OF_A_KIND;
    }
    else if (hasTwoPair) {
        hand->ranking = TWO_PAIR;
    }
    else if (hasPair) {
        hand->ranking = PAIR;
    }
    else {
        hand->ranking = HIGH_CARD;
    }
}

int compareHands(const void *a, const void *b) {
    Hand *handA = (Hand *)a;
    Hand *handB = (Hand *)b;

    if (handA->ranking < handB->ranking) {
        return -1;
    }
    else if (handA->ranking > handB->ranking) {
        return 1;
    }
    else {
        int i, rankCountA[NUM_RANKS] = {0}, rankCountB[NUM_RANKS] = {0};

        /* Count the ranks in both hands */
        for (i = 0; i < 5; i++) {
            rankCountA[handA->cards[i].rank]++;
            rankCountB[handB->cards[i].rank]++;
        }

        /* Compare hand ranks */
        switch (handA->ranking) {
            case HIGH_CARD:
            case PAIR:
            case THREE_OF_A_KIND:
            case FOUR_OF_A_KIND:
                for (i = NUM_RANKS - 1; i >= 0; i--) {
                    if (rankCountA[i] > rankCountB[i]) {
                        return 1;
                    }
                    else if (rankCountA[i] < rankCountB[i]) {
                        return -1;
                    }
                }

                break;

            case TWO_PAIR:
                /* Find the highest pair in each hand */
                int pairRankA = -1, pairRankB = -1;

                for (i = NUM_RANKS - 1; i >= 0; i--) {
                    if (rankCountA[i] == 2 && pairRankA == -1) {
                        pairRankA = i;
                    }

                    if (rankCountB[i] == 2 && pairRankB == -1) {
                        pairRankB = i;
                    }
                }

                /* Compare pair ranks */
                if (pairRankA > pairRankB) {
                    return 1;
                }
                else if (pairRankA < pairRankB) {
                    return -1;
                }

                /* Find the highest non-pair card in each hand */
                for (i = NUM_RANKS - 1; i >= 0; i--) {
                    if (i == pairRankA) {
                        continue;
                    }

                    if (rankCountA[i] > rankCountB[i]) {
                        return 1;
                    }
                    else if (rankCountA[i] < rankCountB[i]) {
                        return -1;
                    }
                }

                break;

            case STRAIGHT:
            case STRAIGHT_FLUSH:
                /* Compare high card rank */
                if (handA->cards[4].rank > handB->cards[4].rank) {
                    return 1;
                }
                else if (handA->cards[4].rank < handB->cards[4].rank) {
                    return -1;
                }

                break;

            case FULL_HOUSE:
                /* Find the rank of the three of a kind in each hand */
                int threeRankA = -1, threeRankB = -1;

                for (i = NUM_RANKS - 1; i >= 0; i--) {
                    if (rankCountA[i] == 3 && threeRankA == -1) {
                        threeRankA = i;
                    }

                    if (rankCountB[i] == 3 && threeRankB == -1) {
                        threeRankB = i;
                    }
                }

                /* Compare rank of three of a kind */
                if (threeRankA > threeRankB) {
                    return 1;
                }
                else if (threeRankA < threeRankB) {
                    return -1;
                }

                /* Find the rank of the pair in each hand */
                int pairRankFullA = -1, pairRankFullB = -1;

                for (i = NUM_RANKS - 1; i >= 0; i--) {
                    if (rankCountA[i] == 2 && pairRankFullA == -1) {
                        pairRankFullA = i;
                    }

                    if (rankCountB[i] == 2 && pairRankFullB == -1) {
                        pairRankFullB = i;
                    }
                }

                /* Compare rank of pair */
                if (pairRankFullA > pairRankFullB) {
                    return 1;
                }
                else if (pairRankFullA < pairRankFullB) {
                    return -1;
                }

                break;

            default:
                break;
        }

        /* Compare remaining cards */
        for (i = 4; i >= 0; i--) {
            if (handA->cards[i].rank > handB->cards[i].rank) {
                return 1;
            }
            else if (handA->cards[i].rank < handB->cards[i].rank) {
                return -1;
            }
        }

        return 0;
    }
}

int main() {
    Card deck[NUM_CARDS];
    Hand hands[MAX_PLAYERS];
    int numPlayers;

    int i, j;

    /* Create deck */
    for (i = 0; i < NUM_RANKS; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck[i * NUM_SUITS + j].rank = i;
            deck[i * NUM_SUITS + j].suit = j;
        }
    }

    /* Seed random number generator */
    srand(time(NULL));

    /* Shuffle deck */
    shuffleDeck(deck);

    /* Get number of players */
    while (1) {
        printf("Enter number of players (2-6): ");
        scanf("%d", &numPlayers);

        if (numPlayers < 2 || numPlayers > 6) {
            printf("Invalid number of players. Please choose a number between 2 and 6.\n");
        }
        else {
            break;
        }
    }

    /* Deal hands */
    dealHands(deck, hands, numPlayers);

    /* Evaluate hands */
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d:\n", i + 1);
        printHand(hands[i]);
        evaluateHand(&hands[i]);
        printf("Ranking: %d\n", hands[i].ranking);
        printf("\n");
    }

    /* Determine winner */
    qsort(hands, numPlayers, sizeof(Hand), compareHands);

    printf("Winner: Player %d\n", 1 + (int)(hands - &hands[0]));

    return 0;
}