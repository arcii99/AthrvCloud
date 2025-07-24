//FormAI DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void shuffleDeck(int deck[], int size);
void printDeck(int deck[], int size);
int getScore(int hand[], int size);
int hitOrStay();
void clearScreen();
void printScore(int playerScore, int dealerScore);

int main() {
    // initialize variables
    int deck[52];
    int playerHand[11]; // player can have up to 11 cards before busting
    int dealerHand[11]; // dealer can have up to 11 cards before busting
    int playerScore = 0;
    int dealerScore = 0;
    int playerCards = 0;
    int dealerCards = 0;
    int i, j;
    char playAgain = 'y';
    srand(time(NULL));

    // game loop
    while (playAgain == 'y') {
        shuffleDeck(deck, 52);
        playerHand[0] = deck[0];
        dealerHand[0] = deck[1];
        playerHand[1] = deck[2];
        dealerHand[1] = deck[3];

        playerCards = 2;
        dealerCards = 2;

        clearScreen(); // clear console before starting game
        printf("Welcome to C Table Game!\n\n");

        // print player hand
        printf("Your hand:\n");
        printDeck(playerHand, playerCards);
        playerScore = getScore(playerHand, playerCards);
        printf("Your score: %d\n", playerScore);

        // print dealer hand with one card hidden
        printf("\nDealer's hand:\n");
        printf("Card 1: X\n");
        printf("Card 2: %d\n", dealerHand[1]);
        dealerScore = getScore(dealerHand, dealerCards);

        // player's turn
        while (playerScore < 21) {
            if (hitOrStay()) {
                playerCards++;
                playerHand[playerCards - 1] = deck[playerCards + dealerCards - 1];
                clearScreen();
                printf("Your hand:\n");
                printDeck(playerHand, playerCards);
                playerScore = getScore(playerHand, playerCards);
                printf("Your score: %d\n", playerScore);
                printf("\nDealer's hand:\n");
                printf("Card 1: X\n");
                printf("Card 2: %d\n", dealerHand[1]);
            }
            else {
                break;
            }
        }

        // dealer's turn
        while (dealerScore < 17) {
            dealerCards++;
            dealerHand[dealerCards - 1] = deck[playerCards + dealerCards - 1];
            clearScreen();
            printf("Your hand:\n");
            printDeck(playerHand, playerCards);
            printf("Your score: %d\n", playerScore);
            printf("\nDealer's hand:\n");
            printDeck(dealerHand, dealerCards);
            dealerScore = getScore(dealerHand, dealerCards);
        }

        // print final hands and scores
        clearScreen();
        printf("Your hand:\n");
        printDeck(playerHand, playerCards);
        printf("Your score: %d\n\n", playerScore);
        printf("Dealer's hand:\n");
        printDeck(dealerHand, dealerCards);
        printf("Dealer's score: %d\n", dealerScore);

        // check who won
        if (dealerScore > 21 || playerScore > dealerScore) {
            printf("\nCongratulations! You win!\n");
        }
        else if (playerScore == dealerScore) {
            printf("\nIt's a tie!\n");
        }
        else {
            printf("\nYou lose. Better luck next time!\n");
        }

        // prompt to play again
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
    }

    return 0;
}

void shuffleDeck(int deck[], int size) {
    // initialize deck
    for (int i = 0; i < size; i++) {
        deck[i] = i % 13 + 1; // 13 ranks, each representing a card value
    }

    // shuffle deck using Fisher-Yates algorithm
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(int deck[], int size) {
    for (int i = 0; i < size; i++) {
        if (deck[i] == 1) {
            printf("A ");
        }
        else if (deck[i] >= 10) {
            printf("%c ", '0' + 10);
        }
        else {
            printf("%d ", deck[i]);
        }
    }
    printf("\n");
}

int getScore(int hand[], int size) {
    int score = 0;
    int aceCount = 0;
    for (int i = 0; i < size; i++) {
        if (hand[i] > 10) {
            score += 10;
        }
        else if (hand[i] == 1) {
            aceCount++;
            score += 11;
        }
        else {
            score += hand[i];
        }
    }
    while (score > 21 && aceCount > 0) {
        score -= 10;
        aceCount--;
    }
    return score;
}

int hitOrStay() {
    char choice;
    do {
        printf("\nDo you want to hit or stay? (H/S): ");
        scanf(" %c", &choice);
    } while (choice != 'h' && choice != 's');
    return (choice == 'h');
}

void clearScreen() {
    #ifdef __linux__
    system("clear");
    #elif _WIN32
    system("cls");
    #endif
}

void printScore(int playerScore, int dealerScore) {
    printf("Your score: %d\nDealer's score: %d\n", playerScore, dealerScore);
}