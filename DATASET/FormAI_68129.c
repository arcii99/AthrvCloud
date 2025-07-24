//FormAI DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(char board[ROWS][COLS]);
void updateBoard(char board[ROWS][COLS], int row1, int col1, int row2, int col2);
int checkWin(char board[ROWS][COLS]);

int main(void) {
    srand(time(NULL));
    int numPairs = (ROWS * COLS) / 2;
    char values[numPairs];
    char board[ROWS][COLS];

    // Populate values array
    for (int i = 0; i < numPairs; i++) {
        values[i] = i + 'A';
    }

    // Shuffle values array
    for (int i = 0; i < numPairs - 1; i++) {
        int j = i + rand() % (numPairs - i);
        char temp = values[j];
        values[j] = values[i];
        values[i] = temp;
    }

    // Initialize board with shuffled values
    int counter = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = values[counter];
            counter++;
        }
    }

    // Game loop
    int playerScore = 0;
    while (1) {
        printBoard(board);

        int row1, col1, row2, col2;
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);

        row1--; col1--; row2--; col2--;

        // Check if selected cards are valid
        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS ||
            row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS) {
            printf("Invalid card selection.\n");
            continue;
        }

        // Update board and check for win condition
        updateBoard(board, row1, col1, row2, col2);
        int pairs = checkWin(board);
        if (pairs == numPairs) {
            printf("Congratulations! You won in %d moves.\n", playerScore / 2);
            break;
        }

        playerScore++;
    }

    return 0;
}

void printBoard(char board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void updateBoard(char board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        board[row1][col1] = ' ';
        board[row2][col2] = ' ';
    }
}

int checkWin(char board[ROWS][COLS]) {
    int numPairs = (ROWS * COLS) / 2;
    int counter = 0;
    char pairs[numPairs];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char currentCard = board[i][j];
            if (currentCard != ' ') {
                int pairFound = 0;
                for (int k = 0; k < counter; k++) {
                    if (pairs[k] == currentCard) {
                        pairFound = 1;
                        break;
                    }
                }
                if (!pairFound) {
                    pairs[counter] = currentCard;
                    counter++;
                }
            }
        }
    }

    return counter;
}