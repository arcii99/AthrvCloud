//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: creative
#include <stdio.h>

// This function prints the current state of the Tic Tac Toe board
void printBoard(char board[][3]) {
    printf("\n");
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            printf(" %c ", board[row][col]);
            if(col != 2) printf("|");
        }
        printf("\n");
        if(row != 2) printf("-----------\n");
    }
    printf("\n");
}

// This function checks if a given player has won the game
int checkWin(char board[][3], char player) {
    // Check for horizontal wins
    for(int row=0; row<3; row++) {
        if(board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return 1;
        }
    }

    // Check for vertical wins
    for(int col=0; col<3; col++) {
        if(board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return 1;
        }
    }

    // Check for diagonal wins
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// This function evaluates the minimax value of a given Tic Tac Toe board state
int evaluate(char board[][3], char player, char opponent) {
    if(checkWin(board, opponent)) {
        return -10;
    } else if(checkWin(board, player)) {
        return 10;
    } else {
        return 0;
    }
}

// This function uses the minimax algorithm to determine the optimal move for the AI player
int minimax(char board[][3], int depth, int isMax, char player, char opponent) {
    // Evaluate the current state of the board
    int score = evaluate(board, player, opponent);

    // If the AI player has won, return the score plus the current depth of the tree
    if(score == 10) {
        return score - depth;
    }

    // If the opponent player has won, return the score minus the current depth of the tree
    if(score == -10) {
        return score + depth;
    }

    // If the game is a tie, return 0
    if(depth == 9) {
        return 0;
    }

    // If it is the AI player's turn, maximize the score
    if(isMax) {
        int bestScore = -1000;

        for(int row=0; row<3; row++) {
            for(int col=0; col<3; col++) {
                if(board[row][col] == '_') {
                    board[row][col] = player;
                    int currentScore = minimax(board, depth+1, 0, player, opponent);
                    board[row][col] = '_';

                    if(currentScore > bestScore) {
                        bestScore = currentScore;
                    }
                }
            }
        }

        return bestScore;
    } else {
        // If it is the opponent player's turn, minimize the score
        int bestScore = 1000;

        for(int row=0; row<3; row++) {
            for(int col=0; col<3; col++) {
                if(board[row][col] == '_') {
                    board[row][col] = opponent;
                    int currentScore = minimax(board, depth+1, 1, player, opponent);
                    board[row][col] = '_';

                    if(currentScore < bestScore) {
                        bestScore = currentScore;
                    }
                }
            }
        }

        return bestScore;
    }
}

// This function returns the optimal move for the AI player
void getOptimalMove(char board[][3], char player, char opponent, int *row, int *col) {
    int bestScore = -1000;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '_') {
                board[i][j] = player;
                int currentScore = minimax(board, 0, 0, player, opponent);
                board[i][j] = '_';

                if(currentScore > bestScore) {
                    bestScore = currentScore;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

int main() {
    char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};

    printf("Welcome to Tic Tac Toe!\n");

    int row, col, turn=0;

    while(1) {
        printBoard(board);

        // Player 1 (X)
        if(turn%2 == 0) {
            printf("Player 1 (X), please enter your move (row col): ");
            scanf("%d %d", &row, &col);

            if(board[row-1][col-1] == '_') {
                board[row-1][col-1] = 'X';
                if(checkWin(board, 'X')) {
                    printBoard(board);
                    printf("Congratulations! Player 1 (X) is the winner!\n");
                    break;
                }
            } else {
                printf("Invalid move. Please try again.\n");
                continue;
            }
        }
        // Player 2 (O)
        else {
            printf("Player 2 (O) is thinking...\n");
            getOptimalMove(board, 'O', 'X', &row, &col);
            board[row][col] = 'O';
            if(checkWin(board, 'O')) {
                printBoard(board);
                printf("Congratulations! Player 2 (O) is the winner!\n");
                break;
            }
        }

        turn++;

        if(turn == 9) {
            printBoard(board);
            printf("Game ended in a tie.\n");
            break;
        }
    }

    return 0;
}