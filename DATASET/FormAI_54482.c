//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // Tic Tac Toe board
char player = 'X'; // Current player (X goes first)

// This function initializes the board with dashes (-)
void init_board() {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
}

// This function prints the current state of the board
void print_board() {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// This function checks if the given move is valid or not
int is_valid_move(int row, int col) {
    if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
        return 1; // Valid move
    }
    return 0; // Invalid move
}

// This function checks if the game is over or not
int is_game_over() {
    int i, j;
    // Check rows
    for(i=0; i<3; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1; // Game over
        }
    }
    // Check columns
    for(j=0; j<3; j++) {
        if(board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1; // Game over
        }
    }
    // Check diagonals
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1; // Game over
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1; // Game over
    }
    // Check if the board is full
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return 0; // Game not over yet
            }
        }
    }
    return 2; // Game over (tie)
}

// This function makes the move for the player
void make_move(int row, int col) {
    board[row][col] = player;
    player = (player == 'X') ? 'O' : 'X'; // Switch players
}

// This function uses the minimax algorithm to find the optimal move for the AI
int minimax(int depth, int is_max) {
    int i, j;
    int score;
    int best_score = -100;
    int worst_score = 100;
    int result = is_game_over();
    if(result == 1) {
        return 10 - depth; // Player wins (+10 for winning, -depth for taking longer)
    } else if(result == 2) {
        return 0; // Tie
    } else if(result == 0) {
        if(is_max) {
            for(i=0; i<3; i++) {
                for(j=0; j<3; j++) {
                    if(is_valid_move(i, j)) {
                        make_move(i, j);
                        score = minimax(depth+1, 0); // Recursive call (minimization)
                        if(score > best_score) {
                            best_score = score;
                        }
                        board[i][j] = '-'; // Undo move
                    }
                }
            }
            return best_score;
        } else {
            for(i=0; i<3; i++) {
                for(j=0; j<3; j++) {
                    if(is_valid_move(i, j)) {
                        make_move(i, j);
                        score = minimax(depth+1, 1); // Recursive call (maximization)
                        if(score < worst_score) {
                            worst_score = score;
                        }
                        board[i][j] = '-'; // Undo move
                    }
                }
            }
            return worst_score;
        }
    }
}

// This function makes the move for the AI
void ai_move() {
    int i, j;
    int best_score = -100;
    int score;
    int best_row, best_col;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(is_valid_move(i, j)) {
                make_move(i, j);
                score = minimax(0, 0); // Recursive call (minimization)
                if(score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
                board[i][j] = '-'; // Undo move
            }
        }
    }
    make_move(best_row, best_col);
}

// Main function
int main() {
    int row, col;
    init_board();
    while(is_game_over() == 0) {
        if(player == 'X') {
            printf("Your turn: ");
            scanf("%d %d", &row, &col);
            if(is_valid_move(row, col)) {
                make_move(row, col);
            } else {
                printf("Invalid move\n");
            }
        } else {
            ai_move(); // AI's turn
        }
        print_board();
    }
    if(is_game_over() == 1) {
        printf("Player %c wins!\n", (player == 'X') ? 'O' : 'X');
    } else if(is_game_over() == 2) {
        printf("Tie game!\n");
    }
    return 0;
}