//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_MARKER '-'

// Function declarations
void print_board(char board[3][3]);
int check_winner(char board[3][3]);
int minimax(char board[3][3], int depth, int isMaximizing);
int get_best_move(char board[3][3]);
int get_player_move(char board[3][3]);

// Main function
int main() {
    char board[3][3] = {
        {EMPTY_MARKER, EMPTY_MARKER, EMPTY_MARKER},
        {EMPTY_MARKER, EMPTY_MARKER, EMPTY_MARKER},
        {EMPTY_MARKER, EMPTY_MARKER, EMPTY_MARKER}
    };
    int game_over = 0;
    int num_moves = 0;
    int current_player = 1; // 1 for player, -1 for AI
    
    while (!game_over) {
        // Print board
        printf("Current board:\n");
        print_board(board);
        
        // Get move from player or AI
        int move;
        if (current_player == 1) {
            move = get_player_move(board);
        } else {
            move = get_best_move(board);
            printf("AI chooses location %d, %d\n", move / 3, move % 3);
        }
        
        // Make move and check for winner
        board[move / 3][move % 3] = (current_player == 1) ? 'X' : 'O';
        num_moves++;
        int winner = check_winner(board);
        
        if (winner != 0) {
            // Game over
            game_over = 1;
            printf("Current board:\n");
            print_board(board);
            
            if (winner == 1) {
                printf("Player wins!\n");
            } else if (winner == -1) {
                printf("AI wins!\n");
            } else {
                printf("It's a tie!\n");
            }
        } else if (num_moves == 9) {
            // Game over
            game_over = 1;
            printf("Current board:\n");
            print_board(board);
            printf("It's a tie!\n");
        } else {
            // Switch player
            current_player = -current_player;
        }
    }
    
    return 0;
}

// Function definitions

void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1;
            } else if (board[i][0] == 'O') {
                return -1;
            }
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                return 1;
            } else if (board[0][j] == 'O') {
                return -1;
            }
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1;
        } else if (board[0][0] == 'O') {
            return -1;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 1;
        } else if (board[0][2] == 'O') {
            return -1;
        }
    }
    
    return 0;
}

int minimax(char board[3][3], int depth, int isMaximizing) {
    int winner = check_winner(board);
    if (winner != 0) {
        return winner * (10 - depth);
    }
    if (depth == 0) {
        return 0;
    }
    
    int best_score;
    if (isMaximizing) {
        best_score = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i / 3][i % 3] == EMPTY_MARKER) {
                board[i / 3][i % 3] = 'O';
                int score = minimax(board, depth - 1, !isMaximizing);
                board[i / 3][i % 3] = EMPTY_MARKER;
                if (score > best_score) {
                    best_score = score;
                }
            }
        }
    } else {
        best_score = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i / 3][i % 3] == EMPTY_MARKER) {
                board[i / 3][i % 3] = 'X';
                int score = minimax(board, depth - 1, !isMaximizing);
                board[i / 3][i % 3] = EMPTY_MARKER;
                if (score < best_score) {
                    best_score = score;
                }
            }
        }
    }
    
    return best_score;
}

int get_best_move(char board[3][3]) {
    int best_move;
    int best_score = -1000;
    for (int i = 0; i < 9; i++) {
        if (board[i / 3][i % 3] == EMPTY_MARKER) {
            board[i / 3][i % 3] = 'O';
            int score = minimax(board, 4, 0);
            board[i / 3][i % 3] = EMPTY_MARKER;
            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }
    return best_move;
}

int get_player_move(char board[3][3]) {
    int move = -1;
    while (move < 0 || move > 8 || board[move / 3][move % 3] != EMPTY_MARKER) {
        printf("Enter a number between 0 and 8 for your move: ");
        scanf("%d", &move);
    }
    return move;
}