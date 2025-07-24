//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 4
#define COLS 4
#define TOTAL_CARDS ROWS * COLS / 2
#define MAX_GUESS_ATTEMPTS ROWS * COLS

// Function prototypes
void printStartingInstructions();
void printGameboard(char gameboard[][COLS], int rows, int cols);
void initializeGameboard(char gameboard[][COLS], int rows, int cols);
int getUserGuess();
int isValidChoice(int choice, char gameboard[][COLS], int rows, int cols);
int isMatch(int choice1, int choice2, char gameboard[][COLS], int rows, int cols);
void updateGameboard(int choice1, int choice2, char gameboard[][COLS], int rows, int cols);
void printEndingMessage(int numAttempts);

int main() {
    char gameboard[ROWS][COLS];
    int numGuessAttempts = 0;

    srand(time(NULL));   // Seed random number generator

    printStartingInstructions();
    initializeGameboard(gameboard, ROWS, COLS);

    while (numGuessAttempts < MAX_GUESS_ATTEMPTS) {
        int choice1, choice2;

        printGameboard(gameboard, ROWS, COLS);
        choice1 = getUserGuess();
        while (!isValidChoice(choice1, gameboard, ROWS, COLS)) {
            printf("\nInvalid choice. Please try again.\n");
            printGameboard(gameboard, ROWS, COLS);
            choice1 = getUserGuess();
        }
        gameboard[(choice1 - 1) / COLS][(choice1 - 1) % COLS] = gameboard[(choice1 - 1) / COLS][(choice1 - 1) % COLS] & 0x7F;

        printGameboard(gameboard, ROWS, COLS);
        choice2 = getUserGuess();
        while (!isValidChoice(choice2, gameboard, ROWS, COLS)) {
            printf("\nInvalid choice. Please try again.\n");
            printGameboard(gameboard, ROWS, COLS);
            choice2 = getUserGuess();
        }
        gameboard[(choice2 - 1) / COLS][(choice2 - 1) % COLS] = gameboard[(choice2 - 1) / COLS][(choice2 - 1) % COLS] & 0x7F;

        if (isMatch(choice1, choice2, gameboard, ROWS, COLS)) {
            updateGameboard(choice1, choice2, gameboard, ROWS, COLS);
        } else {
            gameboard[(choice1 - 1) / COLS][(choice1 - 1) % COLS] = gameboard[(choice1 - 1) / COLS][(choice1 - 1) % COLS] | 0x80;
            gameboard[(choice2 - 1) / COLS][(choice2 - 1) % COLS] = gameboard[(choice2 - 1) / COLS][(choice2 - 1) % COLS] | 0x80;
        }

        numGuessAttempts++;
        if (numGuessAttempts >= 2 * TOTAL_CARDS && (numGuessAttempts % 2 == 0)) {
            printEndingMessage(numGuessAttempts);
            return 0;
        }
    }

    return 0;
}

// Prints the instructions for starting the game
void printStartingInstructions() {
    printf("Welcome to the Memory Game!\n");
    printf("Rules:\n");
    printf("Flip over two cards at a time to find matching pairs.\n");
    printf("Cards are matched based on their order in the gameboard (e.g. 1 and 5 are a match).\n");
    printf("Once all matching pairs are found, the game will end.\n");
    printf("Press Enter to begin...\n");
    getchar();
}

// Prints the gameboard to the console
void printGameboard(char gameboard[][COLS], int rows, int cols) {
    printf("\n\n");

    // Prints column numbers
    printf("   ");
    for (int j = 1; j <= cols; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Prints row separators and contents
    for (int i = 0; i < rows; i++) {
        printf("  +");
        for (int j = 0; j < cols; j++) {
            printf("---+");
        }
        printf("\n%2d|", i + 1);
        for (int j = 0; j < cols; j++) {
            if ((gameboard[i][j] & 0x80) != 0) {   // If card is face down
                printf(" - |");
            } else {    // If card is face up
                printf(" %c |", gameboard[i][j] & 0x7F);
            }
        }
        printf("\n");
    }
    printf("  +");
    for (int j = 0; j < cols; j++) {
        printf("---+");
    }
    printf("\n");
}

// Initializes the gameboard with randomly shuffled cards
void initializeGameboard(char gameboard[][COLS], int rows, int cols) {
    int numCardsPlaced[TOTAL_CARDS] = {0};
    int card, i = 0, j = 0, n;

    // Initialize gameboard with face down cards
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            gameboard[i][j] = '-';
        }
    }

    // Place each card in a random location
    for (card = 1; card <= TOTAL_CARDS; card++) {
        for (n = 0; n < 2; n++) {
            // Randomly select a location that hasn't already been used
            do {
                i = rand() % ROWS;
                j = rand() % COLS;
            } while (gameboard[i][j] != '-');

            // Place card at selected location
            gameboard[i][j] = card + 64;    // Converts card number to uppercase letter (e.g. 1 -> A)
        }
    }
}

// Prompts user for their guess and returns it
int getUserGuess() {
    int guess;

    printf("\nEnter your guess (row column): ");
    scanf("%d", &guess);

    return guess;
}

// Validates that the user's choice is within bounds of the gameboard and hasn't already been matched
int isValidChoice(int choice, char gameboard[][COLS], int rows, int cols) {
    int row = (choice - 1) / cols;
    int col = (choice - 1) % cols;
    return (row >= 0 && row < rows && col >= 0 && col < cols && (gameboard[row][col] & 0x80) == 0);
}

// Checks if the user's two choices match
int isMatch(int choice1, int choice2, char gameboard[][COLS], int rows, int cols) {
    int row1 = (choice1 - 1) / cols;
    int col1 = (choice1 - 1) % cols;
    int row2 = (choice2 - 1) / cols;
    int col2 = (choice2 - 1) % cols;

    return (gameboard[row1][col1] == gameboard[row2][col2]);
}

// Updates the gameboard with the user's correct guess
void updateGameboard(int choice1, int choice2, char gameboard[][COLS], int rows, int cols) {
    int row1 = (choice1 - 1) / cols;
    int col1 = (choice1 - 1) % cols;
    int row2 = (choice2 - 1) / cols;
    int col2 = (choice2 - 1) % cols;

    gameboard[row1][col1] = gameboard[row1][col1] | 0x80;
    gameboard[row2][col2] = gameboard[row2][col2] | 0x80;
}

// Prints ending message with the user's number of attempts
void printEndingMessage(int numAttempts) {
    printf("\nCongratulations! You found all the pairs!\n");
    printf("Number of attempts: %d\n", numAttempts);
}