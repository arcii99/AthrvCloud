//FormAI DATASET v1.0 Category: Poker Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define MAX_NAME_LENGTH 20

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int hand[NUM_CARDS];
    int numCards;
    int chips;
} Player;

// Function prototypes
void initDeck(int deck[]);
void shuffleDeck(int deck[]);
char* getCardName(int card);
void dealCards(Player players[], int numPlayers, int deck[]);
int checkHand(int hand[]);
int getWinner(Player players[], int numPlayers);
void playRound(Player players[], int dealer, int numPlayers, int deck[]);
void printPlayer(Player player);

int main() {
    printf("Welcome to the Visionary Poker Game!\n");

    srand(time(NULL)); // Initialize random seed
    
    // Get number of players
    int numPlayers;
    printf("How many players? (1-6): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 1 || numPlayers > 6) {
        printf("Invalid number of players, please choose a value between 1-6: ");
        scanf("%d", &numPlayers);
    }

    // Get player names
    Player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].numCards = 0;
        players[i].chips = 100; // Set starting chips to 100
    }

    // Play game
    int dealer = 0; // Start with first player as dealer
    while (1) { // Infinite loop until players quit or run out of chips
        int deck[NUM_CARDS];
        initDeck(deck);
        shuffleDeck(deck);
        dealCards(players, numPlayers, deck);
        playRound(players, dealer, numPlayers, deck);
        dealer = (dealer + 1) % numPlayers; // Change dealer
        printf("Press any key to continue or q to quit: ");
        char input[2];
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].chips == 0) {
                printf("%s is out of chips and has been eliminated! Better luck next time!\n", players[i].name);
                numPlayers--; // Reduce number of players
                for (int j = i; j < numPlayers; j++) {
                    players[j] = players[j+1]; // Shift players over to fill gap
                }
                i--; // Recheck current index
            }
        }
        if (numPlayers == 0) {
            printf("All players have run out of chips! Game over!\n");
            break;
        }
    }

    return 0;
}

/**
 * Initialize the deck with values 0-51 representing each card.
 * 0-12 represent the Ace-King of Clubs, 13-25 represent the Ace-King of Diamonds, etc.
 **/
void initDeck(int deck[]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
}

/**
 * Shuffle the deck using the Fisher-Yates shuffle algorithm.
 **/
void shuffleDeck(int deck[]) {
    for (int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

/**
 * Get the name of the card based on its value (0-51).
 **/
char* getCardName(int card) {
    char* name = malloc(sizeof(char) * 3);
    int rank = card % NUM_RANKS;
    int suit = card / NUM_RANKS;
    switch (rank) {
        case 0:
            strcpy(name, "A");
            break;
        case 9:
            strcpy(name, "T");
            break;
        case 10:
            strcpy(name, "J");
            break;
        case 11:
            strcpy(name, "Q");
            break;
        case 12:
            strcpy(name, "K");
            break;
        default:
            sprintf(name, "%d", rank+1);
    }
    switch (suit) {
        case 0:
            strcat(name, "C");
            break;
        case 1:
            strcat(name, "D");
            break;
        case 2:
            strcat(name, "H");
            break;
        case 3:
            strcat(name, "S");
            break;
    }
    return name;
}

/**
 * Deal cards to each player.
 **/
void dealCards(Player players[], int numPlayers, int deck[]) {
    // Reset hands
    for (int i = 0; i < numPlayers; i++) {
        players[i].numCards = 0;
    }
    // Deal cards
    for (int i = 0; i < numPlayers*2; i++) {
        int playerIndex = i % numPlayers;
        players[playerIndex].hand[players[playerIndex].numCards++] = deck[i];
    }
}

/**
 * Check the current hand for its rank (e.g. Full House, Flush, etc.).
 **/
int checkHand(int hand[]) {
    // TODO: Implement logic to check hand for its rank
    return 0;
}

/**
 * Determine the winner of the round.
 **/
int getWinner(Player players[], int numPlayers) {
    int winner = 0;
    int rank = checkHand(players[0].hand);
    for (int i = 1; i < numPlayers; i++) {
        int currRank = checkHand(players[i].hand);
        if (currRank > rank) {
            winner = i;
            rank = currRank;
        }
    }
    return winner;
}

/**
 * Play a round of the game.
 **/
void playRound(Player players[], int dealer, int numPlayers, int deck[]) {
    int currPlayer = (dealer + 1) % numPlayers; // Start with player left of dealer
    int pot = 0;
    int highestBet = 0;
    int folded[numPlayers];
    memset(folded, 0, sizeof(folded));
    printf("Dealer: %s\n", players[dealer].name);
    printf("Starting pot: %d chips\n", pot);
    while (1) { // Loop until all but one player folds or bets are equal
        if (folded[currPlayer]) {
            currPlayer = (currPlayer + 1) % numPlayers; // Skip folded player
            continue;
        }
        printf("Current player: %s\n", players[currPlayer].name);
        printf("%s's hand: ", players[currPlayer].name);
        for (int i = 0; i < players[currPlayer].numCards; i++) {
            printf("%s ", getCardName(players[currPlayer].hand[i]));
        }
        printf("\n");
        printf("Pot: %d chips\n", pot);
        printf("Current bet: %d chips\n", highestBet);
        printf("Chips: %d\n", players[currPlayer].chips);
        printf("Enter b to bet, c to check, r to raise, f to fold: ");
        char input[2];
        scanf("%s", input);
        if (strcmp(input, "b") == 0) {
            int bet;
            printf("Enter bet amount: ");
            scanf("%d", &bet);
            if (bet > players[currPlayer].chips) {
                printf("Cannot bet more chips than you have!\n");
                continue;
            }
            players[currPlayer].chips -= bet;
            pot += bet;
            highestBet = bet;
        }
        else if (strcmp(input, "c") == 0) {
            if (players[currPlayer].chips < highestBet) {
                printf("You cannot check, you need to call the highest bet or fold!\n");
                continue;
            }
            if (highestBet == 0) {
                printf("%s checks.\n", players[currPlayer].name);
            }
            else {
                players[currPlayer].chips -= highestBet;
                pot += highestBet;
                printf("%s calls.\n", players[currPlayer].name);
            }
        }
        else if (strcmp(input, "r") == 0) {
            int raise;
            printf("Enter raise amount: ");
            scanf("%d", &raise);
            if (raise > players[currPlayer].chips) {
                printf("Cannot raise more chips than you have!\n");
                continue;
            }
            players[currPlayer].chips -= raise;
            pot += raise;
            highestBet += raise;
        }
        else if (strcmp(input, "f") == 0) {
            folded[currPlayer] = 1;
            printf("%s folds!\n", players[currPlayer].name);
        }
        else {
            printf("Invalid input, please try again!\n");
            continue;
        }
        int activePlayers = 0;
        for (int i = 0; i < numPlayers; i++) {
            if (!folded[i]) {
                activePlayers++;
            }
        }
        if (activePlayers == 1 || (activePlayers == 2 && highestBet == 0)) { // All but one or two players have folded, round over
            for (int i = 0; i < numPlayers; i++) { // Show hands of all players who did not fold
                if (!folded[i]) {
                    printf("%s's hand: ", players[i].name);
                    for (int j = 0; j < players[i].numCards; j++) {
                        printf("%s ", getCardName(players[i].hand[j]));
                    }
                    printf("\n");
                }
            }
            int winner = getWinner(players, numPlayers);
            players[winner].chips += pot;
            printf("%s wins the pot of %d chips!\n", players[winner].name, pot);
            break;
        }
        currPlayer = (currPlayer + 1) % numPlayers;
    }
}

/**
 * Print the name, number of cards, and chips of a player.
 **/
void printPlayer(Player player) {
    printf("%s [%d cards, %d chips]\n", player.name, player.numCards, player.chips);
}