//FormAI DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_UNIQUE_CARDS ((BOARD_SIZE * BOARD_SIZE) / 2)
#define MAX_ATTEMPTS 1000

// Global Variables
int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];
int cardsLeft = NUM_UNIQUE_CARDS;

// Function Declarations
void initializeBoard();
void printBoard();
void shuffleBoard();
void takeTurn();
void resetRevealed();
int isValid(int row1, int col1, int row2, int col2);
int isGameOver();

int main() {
    initializeBoard();
    shuffleBoard();
    while (!isGameOver()) {
        printBoard();
        takeTurn();
    }
    printf("\n\n\nCongratulations! You won the game!\n");
    return 0;
}

void initializeBoard() {
    int cardsInDeck[NUM_UNIQUE_CARDS];
    for (int i = 0; i < NUM_UNIQUE_CARDS; i++) {
        cardsInDeck[i] = i;
    }
    // Shuffle the deck by swapping pairs randomly
    srand(time(NULL));
    for (int i = 0; i < NUM_UNIQUE_CARDS; i++) {
        int j = rand() % NUM_UNIQUE_CARDS;
        int temp = cardsInDeck[i];
        cardsInDeck[i] = cardsInDeck[j];
        cardsInDeck[j] = temp;
    }
    // Copy unique cards to board
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (count < NUM_UNIQUE_CARDS) {
                board[i][j] = cardsInDeck[count];
                count++;
            } else {
                board[i][j] = -1;
            }
        }
    }
}

void printBoard() {
    printf("\n\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }
}

void shuffleBoard() {
    // Shuffle the board by swapping pairs randomly
    srand(time(NULL));
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        int row1 = rand() % BOARD_SIZE;
        int col1 = rand() % BOARD_SIZE;
        int row2 = rand() % BOARD_SIZE;
        int col2 = rand() % BOARD_SIZE;
        int temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
}

void takeTurn() {
    int row1, col1, row2, col2;
    printf("\n\nEnter the row and column of the first card (separated by a space): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the second card (separated by a space): ");
    scanf("%d %d", &row2, &col2);
    if (isValid(row1, col1, row2, col2)) {
        revealed[row1][col1] = 1;
        revealed[row2][col2] = 1;
        printf("\n\nYou found a match!\n\n");
        cardsLeft--;
    } else {
        printf("\n\nSorry, those cards don't match.\n\n");
        resetRevealed();
    }
}

void resetRevealed() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            revealed[i][j] = 0;
        }
    }
}

int isValid(int row1, int col1, int row2, int col2) {
    // Make sure the cards are on the board
    if (row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE ||
        row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
        return 0;
    }
    // Make sure the cards are not already revealed
    if (revealed[row1][col1] || revealed[row2][col2]) {
        return 0;
    }
    // Make sure the cards match
    if (board[row1][col1] != board[row2][col2]) {
        return 0;
    }
    return 1;
}

int isGameOver() {
    return cardsLeft == 0;
}