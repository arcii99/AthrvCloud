//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the board
void init_board(char board[][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the board
void display_board(char board[][3]) {
    printf("\n-------------\n");
    for(int i=0; i<3; i++) {
        printf("| ");
        for(int j=0; j<3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Function to check if the given move is valid or not
int is_valid_move(char board[][3], int row, int col) {
    if(row < 0 || row >= 3 || col < 0 || col >=3) {
        return 0;
    }
    return board[row][col] == '-';
}

// Function to check if the game has ended
int is_game_over(char board[][3]) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    // Check if the board is full
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 2;
}

// Function to get the best possible move for the computer
int get_best_move(char board[][3], int* row, int* col) {
    int best_score = -1000;
    int score;
    int move_found = 0;

    // Try all possible moves and choose the best one
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'O';
                score = minimax(board, 0, 0, -1000, 1000, 1);
                board[i][j] = '-';
                if(score > best_score) {
                    best_score = score;
                    *row = i;
                    *col = j;
                    move_found = 1;
                }
            }
        }
    }

    return move_found;
}

// Function to get the minimax score for the given board
int minimax(char board[][3], int depth, int is_max, int alpha, int beta, int max_depth) {
    int game_result = is_game_over(board);
    if(game_result == 1 || game_result == 0) {
        return game_result;
    }

    if(depth == max_depth) {
        return 0;
    }

    if(is_max) {
        int best_score = -1000;
        int score;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'O';
                    score = minimax(board, depth+1, 0, alpha, beta, max_depth);
                    board[i][j] = '-';
                    if(score > best_score) {
                        best_score = score;
                    }
                    if(best_score >= beta) {
                        return best_score;
                    }
                    if(best_score > alpha) {
                        alpha = best_score;
                    }
                }
            }
        }

        return best_score;
    } else {
        int best_score = 1000;
        int score;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = 'X';
                    score = minimax(board, depth+1, 1, alpha, beta, max_depth);
                    board[i][j] = '-';
                    if(score < best_score) {
                        best_score = score;
                    }
                    if(best_score <= alpha) {
                        return best_score;
                    }
                    if(best_score < beta) {
                        beta = best_score;
                    }
                }
            }
        }

        return best_score;
    }
}

int main() {
    char board[3][3];
    int row, col;

    // Initialize the board
    init_board(board);

    printf("Welcome to Tic Tac Toe!\n");

    // Decide who goes first
    srand(time(NULL));
    int turn = rand() % 2;
    if(turn == 0) {
        printf("You go first!\n");
    } else {
        printf("I go first!\n");
    }

    // Game loop
    while(1) {
        // Player's turn
        if(turn == 0) {
            int valid_move = 0;
            while(!valid_move) {
                printf("\nYour turn\n");
                printf("Enter row (1-3): ");
                scanf("%d", &row);
                printf("Enter column (1-3): ");
                scanf("%d", &col);
                row--;
                col--;
                valid_move = is_valid_move(board, row, col);
                if(!valid_move) {
                    printf("\nInvalid move! Please try again.");
                }
            }
            board[row][col] = 'X';
        }
        // Computer's turn
        else {
            printf("\nMy turn\n");
            if(!get_best_move(board, &row, &col)) {
                break;
            }
            board[row][col] = 'O';
        }

        // Display the board
        display_board(board);

        // Check if the game has ended
        int game_result = is_game_over(board);
        if(game_result == 1) {
            if(turn == 0) {
                printf("\nCongratulations! You win!\n");
            } else {
                printf("\nSorry, I win!\n");
            }
            break;
        } else if(game_result == 2) {
            printf("\nIt's a tie!\n");
            break;
        }

        // Switch turns
        turn = !turn;
    }

    return 0;
}