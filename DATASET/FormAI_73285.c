//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    printf("     1   2   3\n");
    printf("   +---+---+---+\n");
    for (int i = 0; i < 3; i++) {
        printf("%d  | %c | %c | %c |\n", i+1, board[i][0], board[i][1], board[i][2]);
        printf("   +---+---+---+\n");
    }
}

// Function to check if the game has been won or tied
int checkGameState(char board[3][3]) {
    // Check for a win in the rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            if (board[i][0] == 'X') {
                return 1; // X wins
            } else {
                return -1; // O wins
            }
        }
    }

    // Check for a win in the columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            if (board[0][i] == 'X') {
                return 1; // X wins
            } else {
                return -1; // O wins
            }
        }
    }

    // Check for a win in the diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        if (board[0][0] == 'X') {
            return 1; // X wins
        } else {
            return -1; // O wins
        }
    }

    // Check for a win in the anti-diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        if (board[0][2] == 'X') {
            return 1; // X wins
        } else {
            return -1; // O wins
        }
    }

    // Check for a tie
    int emptySpaces = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                emptySpaces++;
            }
        }
    }

    if (emptySpaces == 0) {
        return 0; // Tie game
    }

    return 2; // Game is not over
}

// Function to get a move from the user
void getUserMove(int *row, int *col, char board[3][3]) {
    printf("Enter move (row, column): ");
    scanf("%d %d", row, col);

    // Check for valid move
    while (board[*row-1][*col-1] != ' ') {
        printf("Invalid move, please try again.\n");
        printf("Enter move (row, column): ");
        scanf("%d %d", row, col);
    }
}

// Function to get a random move for the computer
void getRandomMove(int *row, int *col, char board[3][3]) {
    srand(time(NULL));
    *row = rand() % 3;
    *col = rand() % 3;

    // Check for valid move
    while (board[*row][*col] != ' ') {
        *row = rand() % 3;
        *col = rand() % 3;
    }
}

// Function to get the best move for the computer using the minimax algorithm
int getBestMove(char board[3][3], int depth, int maximizingPlayer) {
    int gameState = checkGameState(board);

    // If the game is over, return the score
    if (gameState != 2) {
        if (gameState == 0) {
            return 0; // Tie game
        } else if (gameState == 1) {
            return 10-depth; // X wins
        } else {
            return depth-10; // O wins
        }
    }

    // If it is the maximizing player's turn (X)
    if (maximizingPlayer) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = getBestMove(board, depth+1, 0);
                    board[i][j] = ' ';
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else { // If it is the minimizing player's turn (O)
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = getBestMove(board, depth+1, 1);
                    board[i][j] = ' ';
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

// Function to get the best move for the computer
void getAI_Move(int *row, int *col, char board[3][3]) {
    int bestScore = -1000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int score = getBestMove(board, 0, 0);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;

    // Print initial board
    printBoard(board);

    // Main game loop
    while (1) {
        // Get user move
        getUserMove(&row, &col, board);
        board[row-1][col-1] = 'O';

        // Print board after user move
        printBoard(board);

        // Check game state after user move
        int gameState = checkGameState(board);
        if (gameState != 2) {
            if (gameState == 0) {
                printf("Tie game!\n");
                break;
            } else if (gameState == 1) {
                printf("You win!\n");
                break;
            } else {
                printf("Computer wins!\n");
                break;
            }
        }

        // Get AI move
        getAI_Move(&row, &col, board);
        printf("Computer's move: %d, %d\n", row+1, col+1);
        board[row][col] = 'X';

        // Print board after AI move
        printBoard(board);

        // Check game state after AI move
        gameState = checkGameState(board);
        if (gameState != 2) {
            if (gameState == 0) {
                printf("Tie game!\n");
                break;
            } else if (gameState == 1) {
                printf("You win!\n");
                break;
            } else {
                printf("Computer wins!\n");
                break;
            }
        }
    }

    return 0;
}