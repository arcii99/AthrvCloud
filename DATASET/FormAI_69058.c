//FormAI DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6 // Set the board size to be 6x6

// Structures
typedef struct Card {
    int value;
    int isMatched;
} Card;

// Function prototypes
void playMemoryGame(Card board[][BOARD_SIZE]);
void initializeBoard(Card board[][BOARD_SIZE]);
void shuffleBoard(Card board[][BOARD_SIZE]);
void printBoard(Card board[][BOARD_SIZE]);
int getCardChoice();
int isValidCardChoice(int choice, Card board[][BOARD_SIZE]);
void revealCard(int choice, Card board[][BOARD_SIZE]);
int checkForMatches(Card board[][BOARD_SIZE]);
void printMatches(Card board[][BOARD_SIZE]);

// Main function
int main() {
    printf("Welcome to the Memory Game!\n");
    printf("You will have to match all the card pairs to win.\n\n");

    // Initialize random seed
    srand(time(NULL));

    // Play the game
    Card board[BOARD_SIZE][BOARD_SIZE];
    playMemoryGame(board);

    printf("\nCongratulations! You matched all the cards.\n");

    return 0;
}

void playMemoryGame(Card board[][BOARD_SIZE]) {
    // Initialize the board
    initializeBoard(board);

    // Shuffle the board
    shuffleBoard(board);

    // Keep playing until there are no more matches
    while (checkForMatches(board)) {
        // Print the current board
        printBoard(board);

        // Get the first card choice
        int choice1 = getCardChoice();

        // Reveal the first card
        revealCard(choice1, board);

        // Print the current board
        printBoard(board);

        // Get the second card choice
        int choice2 = getCardChoice();

        // Reveal the second card
        revealCard(choice2, board);

        // Check if the cards match
        if (board[choice1 / BOARD_SIZE][choice1 % BOARD_SIZE].value == board[choice2 / BOARD_SIZE][choice2 % BOARD_SIZE].value) {
            board[choice1 / BOARD_SIZE][choice1 % BOARD_SIZE].isMatched = 1;
            board[choice2 / BOARD_SIZE][choice2 % BOARD_SIZE].isMatched = 1;
            printf("Match found!\n");
        } else {
            printf("Sorry, not a match.\n");
        }
    }

    // Print the final board with all the matches revealed
    printMatches(board);
}

void initializeBoard(Card board[][BOARD_SIZE]) {
    // Initialize all the cards with random values
    int i, j, k = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = k % (BOARD_SIZE * BOARD_SIZE / 2) + 1;
            board[i][j].isMatched = 0;
            k++;
        }
    }
}

void shuffleBoard(Card board[][BOARD_SIZE]) {
    // Shuffle the cards by swapping them randomly
    int i, j;
    for (i = BOARD_SIZE - 1; i > 0; i--) {
        for (j = BOARD_SIZE - 1; j > 0; j--) {
            int r = rand() % (i + 1);
            int c = rand() % (j + 1);

            // Swap the cards
            Card temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void printBoard(Card board[][BOARD_SIZE]) {
    // Print the board with hidden values for unmatched cards and revealed values for matched cards
    printf("\n");
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].isMatched) {
                printf("%2d ", board[i][j].value);
            } else {
                printf("** ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int getCardChoice() {
    // Get the card choice from the user
    int choice;
    printf("Enter the number of the card you want to reveal (0-35): ");
    scanf("%d", &choice);
    return choice;
}

int isValidCardChoice(int choice, Card board[][BOARD_SIZE]) {
    // Check if the card choice is valid
    if (choice < 0 || choice >= BOARD_SIZE * BOARD_SIZE) {
        return 0;
    }
    if (board[choice / BOARD_SIZE][choice % BOARD_SIZE].isMatched) {
        return 0;
    }
    return 1;
}

void revealCard(int choice, Card board[][BOARD_SIZE]) {
    // Reveal the card at the chosen index
    if (isValidCardChoice(choice, board)) {
        board[choice / BOARD_SIZE][choice % BOARD_SIZE].isMatched = 1;
    } else {
        printf("Invalid choice, try again.\n");
        int newChoice = getCardChoice();
        revealCard(newChoice, board);
    }
}

int checkForMatches(Card board[][BOARD_SIZE]) {
    // Check if there are any unmatched cards left
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].isMatched) {
                return 1;
            }
        }
    }
    return 0;
}

void printMatches(Card board[][BOARD_SIZE]) {
    // Print the board with all the matches revealed
    printf("\n");
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%2d ", board[i][j].value);
        }
        printf("\n");
    }
    printf("\n");
}