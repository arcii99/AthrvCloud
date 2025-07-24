//FormAI DATASET v1.0 Category: Poker Game ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define MAX_PLAYERS 6
#define MAX_NAME_LENGTH 20

/* Card Struct */
typedef struct {
    int rank; // 2-10, 11 = Jack, 12 = Queen, 13 = King, 14 = Ace
    char suit; // 'C' = clubs, 'D' = diamonds, 'H' = hearts, 'S' = spades
} Card;

/* Player Struct */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int chips;
    int folded;
    Card hand[2];
} Player;

/* Declarations */
void shuffle(Card deck[DECK_SIZE]);
void deal(Card deck[DECK_SIZE], Player players[MAX_PLAYERS], int numPlayers);
void printCards(Player players[MAX_PLAYERS], int numPlayers, int showHands);
int getWinner(Player players[MAX_PLAYERS], int numPlayers);
void clearHands(Player players[MAX_PLAYERS], int numPlayers);
int getPlayerBet(Player* player, int currentBet, char* playerName);
void printPlayer(Player player);

/* Main Function */
int main() {

    /* Initialize Deck */
    Card deck[DECK_SIZE];
    int rank, i;
    char suit;
    for (i = 0; i < DECK_SIZE; i++) {
        rank = i % 13 + 2;
        if (i < 13) suit = 'C';
        else if (i < 26) suit = 'D';
        else if (i < 39) suit = 'H';
        else suit = 'S';
        deck[i].rank = rank;
        deck[i].suit = suit;
    }

    /* Initialize Players */
    Player players[MAX_PLAYERS];
    int numPlayers = 0;
    char choice;
    printf("How many players? (2-6): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 2 || numPlayers > 6) {
        printf("Invalid number of players. Choose between 2-6: ");
        scanf("%d", &numPlayers);
    }

    /* Get Names */
    for (i = 0; i < numPlayers; i++) {
        printf("Enter Player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].chips = 100;
        players[i].folded = 0;
    }

    /* Begin Game */
    int round = 1;
    int pot = 0;
    int currentBet = 0;
    int dealer = 0;
    while (1) {

        printf("\nROUND %d\n", round);

        /* Shuffle Deck */
        shuffle(deck);

        /* Deal Cards */
        deal(deck, players, numPlayers);

        /* Round of Betting */
        int bets[MAX_PLAYERS];
        int bet;
        int numActivePlayers = numPlayers;
        for (i = 0; i < numPlayers; i++) {
            if (!players[i].folded) {
                printf("\nIt's %s's turn. Here are your cards:\n", players[i].name);
                printPlayer(players[i]);
                bet = getPlayerBet(&players[i], currentBet, players[i].name);
                players[i].chips -= bet;
                pot += bet;
                bets[i] = bet;
                if (bet > currentBet) currentBet = bet;
                if (players[i].chips == 0) numActivePlayers--;
            }
        }

        /* Showdown */
        printf("\nSHOWDOWN\n");
        printCards(players, numPlayers, 1);
        int winner = getWinner(players, numPlayers);
        printf("\n%s wins! They win %d chips from the pot.\n", players[winner].name, pot);
        players[winner].chips += pot;
        pot = 0;
        clearHands(players, numPlayers);
        currentBet = 0;
        dealer = (dealer + 1) % numPlayers;
        round++;
    }

    return 0;
}

/* Function Definitions */

/* Shuffle the Deck of Cards */
void shuffle(Card deck[DECK_SIZE]) {
    srand(time(NULL));
    int i;
    for (i = 0; i < DECK_SIZE; i++) {
        int randIndex = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

/* Deal Cards to Players */
void deal(Card deck[DECK_SIZE], Player players[MAX_PLAYERS], int numPlayers) {
    int i, j;
    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < 2; j++) {
            players[i].hand[j] = deck[i * 2 + j];
        }
    }
}

/* Print Cards for All Players */
void printCards(Player players[MAX_PLAYERS], int numPlayers, int showHands) {
    int i, j;
    for (i = 0; i < numPlayers; i++) {
        printf("%s", players[i].name);
        if (showHands) {
            printf(" (");
            for (j = 0; j < 2; j++) {
                printf("%d%c ", players[i].hand[j].rank, players[i].hand[j].suit);
            }
            printf(")");
        }
        printf("\n");
    }
}

/* Get the Winner of the Round */
int getWinner(Player players[MAX_PLAYERS], int numPlayers) {
    int i, j;
    int bestHand = -1;
    int winner = -1;
    for (i = 0; i < numPlayers; i++) {
        if (!players[i].folded) {
            int handValue = 0;
            for (j = 0; j < 2; j++) {
                if (players[i].hand[j].rank == 14) handValue += 10; // Add 10 for Ace
                else handValue += players[i].hand[j].rank;
            }
            if (handValue > bestHand) {
                bestHand = handValue;
                winner = i;
            }
        }
    }
    return winner;
}

/* Clear Hands for the Next Round */
void clearHands(Player players[MAX_PLAYERS], int numPlayers) {
    int i, j;
    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < 2; j++) {
            players[i].hand[j].rank = 0;
            players[i].hand[j].suit = '\0';
        }
        players[i].folded = 0;
    }
}

/* Get the Bet of a Player */
int getPlayerBet(Player* player, int currentBet, char* playerName) {
    int bet = 0;
    printf("The current bet is %d.\n", currentBet);
    printf("You have %d chips. How much do you want to bet?: ", player->chips);
    scanf("%d", &bet);
    while (bet < currentBet) {
        printf("You must bet at least the current bet of %d. How much do you want to bet?: ", currentBet);
        scanf("%d", &bet);
    }
    while (bet > player->chips) {
        printf("You don't have enough chips. You have %d chips. How much do you want to bet?: ", player->chips);
        scanf("%d", &bet);
    }
    printf("%s bets %d chips.\n", playerName, bet);
    return bet;
}

/* Print Player's Cards */
void printPlayer(Player player) {
    int i;
    printf("(");
    for (i = 0; i < 2; i++) {
        printf("%d%c ", player.hand[i].rank, player.hand[i].suit);
    }
    printf(")\n");
}