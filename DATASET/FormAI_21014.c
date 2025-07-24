//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 3
#define AI_PLAYER 1
#define HUMAN_PLAYER 2

// Function Prototypes
void clear_board(int board[BOARD_SIZE][BOARD_SIZE]);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int is_gameover(int board[BOARD_SIZE][BOARD_SIZE], int player);
int ai_move(int board[BOARD_SIZE][BOARD_SIZE]);
int human_move(int board[BOARD_SIZE][BOARD_SIZE]);

// Main function
int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = HUMAN_PLAYER;
    int gameover = 0;
    int winner = 0;

    clear_board(board);
    printf("Welcome to Tic Tac Toe!\n");
    print_board(board);

    while (!gameover) {
        if (player == AI_PLAYER) {
            ai_move(board);
            player = HUMAN_PLAYER;
        }
        else {
            human_move(board);
            player = AI_PLAYER;
        }

        print_board(board);
        winner = is_gameover(board, HUMAN_PLAYER);
        if (winner) {
            gameover = 1;
            printf("Congratulations, you won!\n");
        } 
        else {
            winner = is_gameover(board, AI_PLAYER);
            if (winner) {
                gameover = 1;
                printf("The AI has won!\n");
            }
            else if (board_full(board)) {
                gameover = 1;
                printf("The game is a draw.\n");
            }
        }
    }

    return 0;
}

// Function to clear board
void clear_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to print board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case HUMAN_PLAYER:
                    printf("X");
                    break;
                case AI_PLAYER:
                    printf("O");
                    break;
                default:
                    printf("_");
                    break;
            }

            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }

        printf("\n");

        if (i < BOARD_SIZE - 1) {
            printf("-----\n");
        }
    }

    printf("\n");
}

// Function to check if game is over
int is_gameover(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    int i, j;
    int diagonal1 = 1, diagonal2 = 1;

    // Check rows and columns
    for (i = 0; i < BOARD_SIZE; i++) {
        diagonal1 *= board[i][i];
        diagonal2 *= board[i][BOARD_SIZE - i - 1];
        int row = 1, col = 1;
        for (j = 0; j < BOARD_SIZE; j++) {
            row *= board[i][j];
            col *= board[j][i];
        }

        if (row == player || col == player) {
            return 1;
        }    
    }

    if (diagonal1 == player || diagonal2 == player) {
        return 1;
    }

    // Game not over
    return 0;
}

// Function for AI move
int ai_move(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    int move = -1;
    int score = -2;

    // Search for optimal move
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = AI_PLAYER;
                int temp_score = -minimax(board, HUMAN_PLAYER);
                board[i][j] = 0;

                if (temp_score > score) {
                    score = temp_score;
                    move = i * BOARD_SIZE + j;
                }
            }
        }
    }

    // Make move
    board[move / BOARD_SIZE][move % BOARD_SIZE] = AI_PLAYER;
    return move;
}

// Function for human move
int human_move(int board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    printf("Enter column (1-3): ");
    scanf("%d", &col);
    row--;
    col--;

    // Make move
    if (board[row][col] == 0) {
        board[row][col] = HUMAN_PLAYER;
        return row * BOARD_SIZE + col;
    }
    else {
        printf("That move is not valid.\n");
        return human_move(board);
    }
}

// Function for minimax algorithm
int minimax(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    int i, j;
    int winner = is_gameover(board, HUMAN_PLAYER);
    if (winner) {
        return winner == HUMAN_PLAYER ? 1 : -1;
    }

    if (board_full(board)) {
        return 0;
    }

    int score = player == AI_PLAYER ? -2 : 2;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = player;
                int temp_score = -minimax(board, 3 - player);
                board[i][j] = 0;

                if (temp_score > score && player == AI_PLAYER) {
                    score = temp_score;
                }
                else if (temp_score < score && player == HUMAN_PLAYER) {
                    score = temp_score;
                }
            }
        }
    }

    return score;
}

// Function to check if board is full
int board_full(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}