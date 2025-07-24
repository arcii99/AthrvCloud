//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int board[ROWS][COLS];

// Function to check if someone has won
int check_win() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        // Check Rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            return board[i][0];
        }
        // Check Columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
            return board[0][i];
        }
    }
    // Check Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        return board[0][2];
    }
    return 0;
}

// Function to print the board
void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("   |");
            } else if (board[i][j] == 1) {
                printf(" X |");
            } else {
                printf(" O |");
            }
        }
        printf("\n");
        printf("------------\n");
    }
}

// Function to determine the move of the AI
void ai_move() {
    int i, j;
    int bestScore = -1000;
    int bestMove[2];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 2; // AI's Turn
                int score = minimax(board, 0, 0);
                board[i][j] = 0; // Reset the board
                if (score > bestScore) {
                    bestScore = score;
                    bestMove[0] = i;
                    bestMove[1] = j;
                }
            }
        }
    }
    board[bestMove[0]][bestMove[1]] = 2;
}

// Function to run the mini-max algorithm
int minimax(int board[ROWS][COLS], int depth, int isMax) {
    int winner = check_win();
    if (winner == 2) {
        return 1;
    }
    if (winner == 1) {
        return -1;
    }
    if (depth == 9) {
        return 0;
    }
    if (isMax) {
        int maxScore = -1000;
        int i, j;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 2; // AI's Turn
                    int score = minimax(board, depth + 1, 0);
                    board[i][j] = 0; // Reset the board
                    if (score > maxScore) {
                        maxScore = score;
                    }
                }
            }
        }
        return maxScore;

    } else {
        int minScore = 1000;
        int i, j;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 1; // Player's Turn
                    int score = minimax(board, depth + 1, 1);
                    board[i][j] = 0; // Reset the board
                    if (score < minScore) {
                        minScore = score;
                    }
                }
            }
        }
        return minScore;
    }
}

int main() {
    int i, j;
    int winner = 0;
    int turn = 2;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing against a very intelligent AI!\n");
    printf("You are X's, and the AI is O's\n");
    print_board();
    while (winner == 0) {
        if (turn == 1) {
            printf("Your turn!\n");
            int row, col;
            printf("Enter row and column separated by a space: ");
            scanf("%d%d", &row, &col);
            if (board[row][col] != 0) {
                printf("That spot is already taken, try again!\n");
                continue;
            }
            board[row][col] = 1; // Player's Turn
        } else {
            printf("AI's turn!\n");
            ai_move(); // AI's Turn
        }
        print_board();
        winner = check_win();
        if (winner == 1) {
            printf("Congratulations, you have won!\n");
        } else if (winner == 2) {
            printf("The AI has won!\n");
        } else if (turn == 1) {
            turn = 2;
        } else {
            turn = 1;
        }
    }
    return 0;
}