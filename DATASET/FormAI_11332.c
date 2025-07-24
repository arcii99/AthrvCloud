//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to create a memory game board
void createBoard(int board[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        board[i] = i / 2 + 1;
    }
    for (i = 0; i < n; i++) {
        int j = rand() % n;
        swap(&board[i], &board[j]);
    }
}

int main() {
    printf("Welcome to the Memory Game!\n\n");

    int n;
    printf("Enter the size of the board (must be even): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error: board size must be even.\n");
        return 1;
    }

    srand(time(NULL));
    int board[n];
    createBoard(board, n);

    int turnedOver[n]; // Represents whether each card is currently turned over
    int correct[n]; // Represents whether each card is correct ("matched")
    int i, j;

    // Initialize turnedOver and correct arrays
    for (i = 0; i < n; i++) {
        turnedOver[i] = 0;
        correct[i] = 0;
    }

    // Print board as asterisks
    printf("Board:\n");
    for (i = 0; i < n; i++) {
        printf("* ");
    }
    printf("\n");

    // Main game loop
    int numTurns = 0;
    while (1) {
        // Print board with turned-over cards revealed
        printf("Board:\n");
        for (i = 0; i < n; i++) {
            if (turnedOver[i]) {
                printf("%d ", board[i]);
            } else {
                printf("* ");
            }
        }
        printf("\n");

        // Check if all cards have been correctly matched
        int allCorrect = 1;
        for (i = 0; i < n; i++) {
            if (!correct[i]) {
                allCorrect = 0;
                break;
            }
        }
        if (allCorrect) {
            printf("Congratulations! You won in %d turns.\n", numTurns);
            break;
        }

        // Prompt user for two cards to turn over
        int card1, card2;
        printf("Enter two card indices to turn over (0-%d): ", n - 1);
        scanf("%d %d", &card1, &card2);

        // Check for valid input
        if (card1 < 0 || card1 >= n || card2 < 0 || card2 >= n) {
            printf("Invalid input. Please enter two numbers between 0 and %d.\n", n - 1);
            continue;
        } else if (turnedOver[card1] || turnedOver[card2]) {
            printf("Invalid input. Please enter two cards that haven't already been turned over.\n");
            continue;
        }

        // Update game state
        turnedOver[card1] = 1;
        turnedOver[card2] = 1;
        numTurns++;
        if (board[card1] == board[card2]) {
            correct[card1] = 1;
            correct[card2] = 1;
            printf("Match found!\n");
        } else {
            turnedOver[card1] = 0;
            turnedOver[card2] = 0;
            printf("No match. Try again.\n");
        }
    }

    return 0;
}