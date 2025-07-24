//FormAI DATASET v1.0 Category: Poker Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This struct represents a card
struct Card {
    int value;
    char suit;
};

// This struct represents a player
struct Player {
    int hand[5];
    int score;
};

void shuffle(struct Card deck[]) {
    // This function shuffles the deck
    int i, j;
    struct Card temp;
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(struct Card deck[], struct Player players[], int numPlayers) {
    // This function deals cards to the players
    int i, j, k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < numPlayers; j++) {
            players[j].hand[i] = deck[k].value;
            k++;
        }
    }
}

void printHand(struct Player player) {
    // This function prints a player's hand
    int i;
    printf("Your hand:");
    for (i = 0; i < 5; i++) {
        if (player.hand[i] == 11) {
            printf(" Jack");
        } else if (player.hand[i] == 12) {
            printf(" Queen");
        } else if (player.hand[i] == 13) {
            printf(" King");
        } else if (player.hand[i] == 14) {
            printf(" Ace");
        } else {
            printf(" %d", player.hand[i]);
        }
    }
}

void calculateScore(struct Player player) {
    // This function calculates a player's score
    int i, j, k;
    int numPairs = 0;
    int numThreeOfAKind = 0;
    int numFourOfAKind = 0;
    int straight = 0;
    int flush = 0;
    int fullHouse = 0;

    // Check for pairs
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (player.hand[i] == player.hand[j]) {
                numPairs++;
            }
        }
    }

    // Check for three of a kind
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            for (k = j + 1; k < 5; k++) {
                if (player.hand[i] == player.hand[j] && player.hand[j] == player.hand[k]) {
                    numThreeOfAKind++;
                }
            }
        }
    }

    // Check for four of a kind
    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 3; j++) {
            for (k = j + 1; k < 4; k++) {
                if (player.hand[i] == player.hand[j] && player.hand[j] == player.hand[k] && player.hand[k] == player.hand[4]) {
                    numFourOfAKind++;
                }
            }
        }
    }

    // Check for straight
    if ((player.hand[0] + 1) == player.hand[1] && (player.hand[1] + 1) == player.hand[2] && (player.hand[2] + 1) == player.hand[3] && (player.hand[3] + 1) == player.hand[4]) {
        straight = 1;
    }

    // Check for flush
    if (player.hand[0] % 4 == player.hand[1] % 4 && player.hand[1] % 4 == player.hand[2] % 4 && player.hand[2] % 4 == player.hand[3] % 4 && player.hand[3] % 4 == player.hand[4] % 4) {
        flush = 1;
    }

    // Check for full house
    if ((player.hand[0] == player.hand[1] && player.hand[1] == player.hand[2] && player.hand[3] == player.hand[4]) || (player.hand[0] == player.hand[1] && player.hand[2] == player.hand[3] && player.hand[3] == player.hand[4])) {
        fullHouse = 1;
    }

    // Calculate score based on hand
    if (numPairs == 1) {
        player.score = 1;
    } else if (numPairs == 2) {
        player.score = 2;
    } else if (numThreeOfAKind == 1) {
        player.score = 3;
    } else if (straight == 1) {
        player.score = 4;
    } else if (flush == 1) {
        player.score = 5;
    } else if (fullHouse == 1) {
        player.score = 6;
    } else if (numFourOfAKind == 1) {
        player.score = 7;
    } else {
        player.score = 0;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the deck of cards
    struct Card deck[52];
    int i, j, k = 0;
    for (i = 2; i <= 14; i++) {
        for (j = 0; j < 4; j++) {
            deck[k].value = i;
            if (j == 0) {
                deck[k].suit = 'C';
            } else if (j == 1) {
                deck[k].suit = 'D';
            } else if (j == 2) {
                deck[k].suit = 'H';
            } else {
                deck[k].suit = 'S';
            }
            k++;
        }
    }

    // Shuffle the deck
    shuffle(deck);

    // Get the number of players
    int numPlayers;
    printf("How many players? (1-4): ");
    scanf("%d", &numPlayers);

    // Create the players
    struct Player players[numPlayers];
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d:\n", i + 1);
        deal(deck, &players[i], 1);
        calculateScore(players[i]);
        printHand(players[i]);
        printf("\n");
    }

    return 0;
}