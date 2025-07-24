//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printInstructions();
void generateBoard(int board[][8]);
void printBoard(int board[][8], int revealed[][8]);
int validMove(int board[][8], int revealed[][8], int row, int col);
int gameOver(int revealed[][8]);
void revealSpaces(int board[][8], int revealed[][8], int row, int col);

int main() {
    int board[8][8]; // 8x8 game board
    int revealed[8][8] = {0}; // 8x8 array to keep track of which spaces have been revealed
    int row, col; // coordinates for player moves
    int numMoves = 0; // number of successful moves made by player

    // initialize random seed
    srand(time(NULL));

    // generate game board and display instructions
    generateBoard(board);
    printInstructions();
    printBoard(board, revealed);

    // loop until game is over
    while (!gameOver(revealed)) {
        // get player move
        printf("\nEnter row and column for your move (separated by a space): ");
        scanf("%d%d", &row, &col);

        // check if move is valid
        if (validMove(board, revealed, row, col)) {
            // increment number of successful moves made by player
            numMoves++;
            printf("\nGood move! You have made %d successful moves.\n", numMoves);

            // reveal spaces and print updated board
            revealSpaces(board, revealed, row, col);
            printBoard(board, revealed);
        } else {
            printf("\nInvalid move. Please try again.\n");
        }
    }

    // print final score
    printf("\nGame over! You made %d successful moves.\n", numMoves);

    return 0;
}

/*
 * Function: printInstructions
 * ---------------------------
 * Displays instructions for the game.
 */
void printInstructions() {
    printf("\nWELCOME TO THE MEMORY GAME!\n\n");
    printf("HOW TO PLAY: You will select a space on the board by entering its row and column.\n");
    printf("The space you select and the space next to it will be revealed.\n");
    printf("If the two spaces match, they will remain revealed and you will score a point.\n");
    printf("If they do not match, they will be covered again and you will have to try again.\n");
    printf("The game is over when all pairs have been matched.\n\n");
}

/*
 * Function: generateBoard
 * -----------------------
 * Generates the game board by randomly assigning pairs of numbers to spaces.
 */
void generateBoard(int board[][8]) {
    int i, j, k, l;
    int numPairs = 16;
    int pairs[numPairs][2]; // array to hold indices of pairs

    // initialize pairs
    for (i = 0; i < numPairs; i++) {
        pairs[i][0] = -1;
        pairs[i][1] = -1;
    }

    // generate random pairs
    for (i = 0; i < numPairs; i++) {
        // check that pair is not already assigned
        do {
            k = rand() % 8;
            l = rand() % 8;
        } while (board[k][l] != 0);

        // assign pair to board
        board[k][l] = i + 1;

        // check that second half of pair is not already assigned
        do {
            j = rand() % 8;
            i = board[k][l] - 1;
        } while (board[j][i] != 0);

        // assign second half of pair to board
        board[j][i] = board[k][l];
        pairs[i][0] = k;
        pairs[i][1] = l;
    }

    // debug print statement (uncomment to see pairs)
    /*
    for (i = 0; i < numPairs; i++) {
        printf("(%d, %d), (%d, %d)\n", pairs[i][0], pairs[i][1], j, i);
    }
    */
}

/*
 * Function: printBoard
 * --------------------
 * Displays the current state of the game board.
 */
void printBoard(int board[][8], int revealed[][8]) {
    int i, j;

    // display column indices
    printf("\n ");
    for (i = 0; i < 8; i++) {
        printf(" %d", i);
    }

    // display each row of the board
    for (i = 0; i < 8; i++) {
        printf("\n%d", i); // display row index
        for (j = 0; j < 8; j++) {
            if (revealed[i][j] == 1) { // space has been revealed
                printf(" %d", board[i][j]);
            } else { // space has not been revealed
                printf(" -");
            }
        }
    }
    printf("\n");
}

/*
 * Function: validMove
 * -------------------
 * Determines if a move is valid (i.e. if the selected space is adjacent to a previously revealed space).
 */
int validMove(int board[][8], int revealed[][8], int row, int col) {
    int i, j;

    // check if space has already been revealed
    if (revealed[row][col] == 1) {
        return 0;
    }

    // check if space is adjacent to a previously revealed space
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((row + i >= 0 && row + i < 8) && (col + j >= 0 && col + j < 8) && revealed[row + i][col + j] == 1) {
                return 1;
            }
        }
    }

    // space is not adjacent to a previously revealed space
    return 0;
}

/*
 * Function: gameOver
 * ------------------
 * Determines if the game is over (i.e. if all pairs have been revealed).
 */
int gameOver(int revealed[][8]) {
    int i, j;

    // check if any spaces are still unrevealed
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (revealed[i][j] == 0) {
                return 0;
            }
        }
    }

    // all spaces have been revealed
    return 1;
}

/*
 * Function: revealSpaces
 * ----------------------
 * Reveals spaces on the game board based on the selected move and corresponding matches.
 */
void revealSpaces(int board[][8], int revealed[][8], int row, int col) {
    int i, j;

    // reveal selected space
    revealed[row][col] = 1;

    // reveal adjacent spaces that match selected space (if any)
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((row + i >= 0 && row + i < 8) && (col + j >= 0 && col + j < 8) && revealed[row + i][col + j] == 0 && board[row + i][col + j] == board[row][col]) {
                revealed[row + i][col + j] = 1;
            }
        }
    }
}