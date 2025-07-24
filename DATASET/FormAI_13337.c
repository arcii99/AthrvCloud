//FormAI DATASET v1.0 Category: Poker Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4 // Number of players in the game
#define NUM_CARDS_IN_DECK 52 // Number of cards in a standard deck
#define HAND_SIZE 5 // Number of cards per hand

// Global variables
int deck[NUM_CARDS_IN_DECK]; // Array to store the deck of cards
int players[NUM_PLAYERS][HAND_SIZE]; // 2D array to store each player's hand
char *suit[] = {"Hearts", "Diamonds", "Spades", "Clubs"}; // Array of string suit names
char *face[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"}; // Array of string face values

// Function prototypes
void shuffleDeck(int[]);
void dealCards(int, int[][HAND_SIZE]);
void printHand(int[], int);
void evaluateHands(int[][HAND_SIZE]);

// Main function
int main() {
    int i, j;
    
    // Seed random number generator
    srand((unsigned int)time(NULL));
    
    // Initialize the deck of cards
    for (i = 0; i < NUM_CARDS_IN_DECK; i++) {
        deck[i] = i;
    }
    
    // Shuffle the deck
    shuffleDeck(deck);
    
    // Deal each player their hand
    dealCards(NUM_PLAYERS, players);
    
    // Print each player's hand
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        printHand(players[i], HAND_SIZE);
        printf("\n");
    }
    
    // Evaluate each player's hand
    printf("Evaluation Results:\n");
    evaluateHands(players);
    
    return 0;
}

// Function to shuffle the deck of cards using Fisher-Yates algorithm
void shuffleDeck(int deck[]) {
    int i, j, temp;
    
    for (i = NUM_CARDS_IN_DECK - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal cards to each player
void dealCards(int numPlayers, int players[][HAND_SIZE]) {
    int i, j, cardIndex = 0;
    
    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            players[i][j] = deck[cardIndex++];
        }
    }
}

// Function to print a player's hand
void printHand(int hand[], int size) {
    int i;
    
    for (i = 0; i < size; i++) {
        printf("%s of %s\n", face[hand[i] % 13], suit[hand[i] / 13]);
    }
}

// Function to evaluate each player's hand
void evaluateHands(int players[][HAND_SIZE]) {
    int i, j, k, l, card1, card2, bestHandIndex;
    int handStrengths[NUM_PLAYERS] = {0}; // Array to store strength of each player's hand
    int bestFiveCards[5] = {0}; // Array to store the best five cards of a hand
    
    for (i = 0; i < NUM_PLAYERS; i++) {
        // Check for Royal Flush
        for (j = 0; j < HAND_SIZE; j++) {
            if (players[i][j] % 13 != 12) {
                break;
            }
        }
        if (j == HAND_SIZE) {
            handStrengths[i] = 10;
            goto printResult;
        }
        
        // Check for Straight Flush
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                card2 = players[i][k];
                if ((card1 % 13) + 1 != (card2 % 13)) {
                    break;
                }
                if (card1 / 13 != card2 / 13) {
                    break;
                }
            }
            if (k == HAND_SIZE && (card2 % 13) == 0) {
                handStrengths[i] = 9;
                goto printResult;
            }
            if (k == HAND_SIZE) {
                handStrengths[i] = 8;
                goto printResult;
            }
        }
        
        // Check for Four of a Kind
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                card2 = players[i][k];
                if (card1 % 13 != card2 % 13) {
                    break;
                }
                if (k - j == 2) {
                    for (l = j + 3; l < HAND_SIZE; l++) {
                        if (players[i][l] % 13 == card1 % 13) {
                            bestFiveCards[0] = players[i][j];
                            bestFiveCards[1] = players[i][k];
                            bestFiveCards[2] = players[i][l];
                            bestFiveCards[3] = bestFiveCards[4] = -1;
                            goto foundBestHand;
                        }
                    }
                    handStrengths[i] = 7;
                    goto printResult;
                }
            }
        }
        
        // Check for Full House
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                card2 = players[i][k];
                if (card1 % 13 != card2 % 13) {
                    break;
                }
                if (k - j == 2) {
                    if (card1 % 13 == players[i][k + 1] % 13) {
                        bestFiveCards[0] = players[i][j];
                        bestFiveCards[1] = players[i][k];
                        bestFiveCards[2] = players[i][k + 1];
                        bestFiveCards[3] = bestFiveCards[4] = -1;
                        goto foundBestHand;
                    }
                    else if (card1 % 13 == players[i][j - 1] % 13) {
                        bestFiveCards[0] = players[i][j - 1];
                        bestFiveCards[1] = players[i][j];
                        bestFiveCards[2] = players[i][k];
                        bestFiveCards[3] = bestFiveCards[4] = -1;
                        goto foundBestHand;
                    }
                    handStrengths[i] = 6;
                    goto printResult;
                }
            }
        }
        
        // Check for Flush
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                if (card1 / 13 != players[i][k] / 13) {
                    break;
                }
            }
            if (k == HAND_SIZE) {
                handStrengths[i] = 5;
                goto printResult;
            }
        }
        
        // Check for Straight
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                card2 = players[i][k];
                if ((card1 % 13) + 1 != (card2 % 13)) {
                    break;
                }
            }
            if (k == HAND_SIZE && (card2 % 13) == 0) {
                if (players[i][0] % 13 == 0) {
                    bestFiveCards[0] = players[i][0];
                    bestFiveCards[1] = players[i][HAND_SIZE - 1];
                    bestFiveCards[2] = players[i][HAND_SIZE - 2];
                    bestFiveCards[3] = players[i][HAND_SIZE - 3];
                    bestFiveCards[4] = players[i][HAND_SIZE - 4];
                }
                else {
                    for (l = 0; l < HAND_SIZE; l++) {
                        if (players[i][l] % 13 == (card2 % 13) - 4) {
                            bestFiveCards[0] = players[i][l];
                            bestFiveCards[1] = players[i][l + 1];
                            bestFiveCards[2] = players[i][l + 2];
                            bestFiveCards[3] = players[i][l + 3];
                            bestFiveCards[4] = players[i][l + 4];
                            goto foundBestHand;
                        }
                    }
                }
                goto foundBestHand;
            }
            if (k == HAND_SIZE) {
                bestFiveCards[0] = players[i][k - 1];
                bestFiveCards[1] = players[i][k - 2];
                bestFiveCards[2] = players[i][k - 3];
                bestFiveCards[3] = players[i][k - 4];
                bestFiveCards[4] = players[i][k - 5];
                goto foundBestHand;
            }
        }
        
        // Check for Three of a Kind
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                card2 = players[i][k];
                if (card1 % 13 != card2 % 13) {
                    break;
                }
                if (k - j == 2) {
                    bestFiveCards[0] = players[i][j];
                    bestFiveCards[1] = players[i][k - 1];
                    bestFiveCards[2] = players[i][k];
                    for (l = 0; l < HAND_SIZE; l++) {
                        if (l == j || l == k) {
                            continue;
                        }
                        if (bestFiveCards[3] == -1) {
                            bestFiveCards[3] = players[i][l];
                        }
                        else if (bestFiveCards[4] == -1) {
                            bestFiveCards[4] = players[i][l];
                            goto foundBestHand;
                        }
                    }
                    goto foundBestHand;
                }
            }
        }
        
        // Check for Two Pairs
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                card2 = players[i][k];
                if (card1 % 13 != card2 % 13) {
                    continue;
                }
                for (l = k + 1; l < HAND_SIZE; l++) {
                    if (players[i][l] % 13 == card1 % 13 ||
                        players[i][l] % 13 == card2 % 13) {
                        bestFiveCards[0] = card1;
                        bestFiveCards[1] = card2;
                        if (card1 % 13 == card2 % 13) {
                            bestFiveCards[2] = players[i][j < k ? l : j];
                            bestFiveCards[3] = players[i][j < k ? k : l];
                            for (card1 = 0; card1 < HAND_SIZE; card1++) {
                                if (players[i][card1] == bestFiveCards[0] ||
                                    players[i][card1] == bestFiveCards[1] ||
                                    players[i][card1] == bestFiveCards[2] ||
                                    players[i][card1] == bestFiveCards[3]) {
                                    continue;
                                }
                                bestFiveCards[4] = players[i][card1];
                                goto foundBestHand;
                            }
                        }
                        else {
                            bestFiveCards[2] = players[i][l];
                            for (card1 = 0; card1 < HAND_SIZE; card1++) {
                                if (players[i][card1] == bestFiveCards[0] ||
                                    players[i][card1] == bestFiveCards[1] ||
                                    players[i][card1] == bestFiveCards[2]) {
                                    continue;
                                }
                                if (bestFiveCards[3] == -1) {
                                    bestFiveCards[3] = players[i][card1];
                                }
                                else {
                                    bestFiveCards[4] = players[i][card1];
                                    goto foundBestHand;
                                }
                            }
                        }
                        goto foundBestHand;
                    }
                }
            }
        }
        
        // Check for One Pair
        for (j = 0; j < HAND_SIZE; j++) {
            card1 = players[i][j];
            for (k = j + 1; k < HAND_SIZE; k++) {
                card2 = players[i][k];
                if (card1 % 13 != card2 % 13) {
                    continue;
                }
                bestFiveCards[0] = card1;
                bestFiveCards[1] = card2;
                for (l = 0; l < HAND_SIZE; l++) {
                    if (l == j || l == k) {
                        continue;
                    }
                    if (bestFiveCards[2] == -1) {
                        bestFiveCards[2] = players[i][l];
                    }
                    else if (bestFiveCards[3] == -1) {
                        bestFiveCards[3] = players[i][l];
                    }
                    else {
                        bestFiveCards[4] = players[i][l];
                        goto foundBestHand;
                    }
                }
                goto foundBestHand;
            }
        }
        
        // Check for High Card
        bestFiveCards[0] = players[i][0];
        for (j = 1; j < HAND_SIZE; j++) {
            if (players[i][j] % 13 > bestFiveCards[0] % 13) {
                bestFiveCards[0] = players[i][j];
            }
        }
        for (j = 1; j < 5; j++) {
            bestFiveCards[j] = players[i][j - 1];
        }
        
    foundBestHand:
        // Print the best five cards for the hand
        printf("Player %d's best hand is:\n", i + 1);
        printHand(bestFiveCards, 5);
        printf("\n");
        
    printResult:
        // Print the strength of the hand
        printf("Player %d's hand strength is: ", i + 1);
        switch (handStrengths[i]) {
            case 10:
                printf("Royal Flush\n");
                break;
            case 9:
                printf("Straight Flush\n");
                break;
            case 8:
                printf("Four of a Kind\n");
                break;
            case 7:
                printf("Full House\n");
                break;
            case 6:
                printf("Flush\n");
                break;
            case 5:
                printf("Straight\n");
                break;
            case 4:
                printf("Three of a Kind\n");
                break;
            case 3:
                printf("Two Pairs\n");
                break;
            case 2:
                printf("One Pair\n");
                break;
            default:
                printf("High Card\n");
                break;
        }
        printf("\n");
    }
}