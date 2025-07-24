//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 3 // Size of the Tic Tac Toe board
#define HUMAN_PLAYER 'X' // Human player symbol
#define AI_PLAYER 'O' // AI player symbol

// Initialize the Tic Tac Toe board with empty cells
void init_board(char board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Display the Tic Tac Toe board
void display_board(char board[SIZE][SIZE]) {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the game has ended (win, lose, tie)
bool game_over(char board[SIZE][SIZE], char player) {
    // Check for horizontal win
    for(int i = 0; i < SIZE; i++) {
        bool win = true;
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] != player) {
                win = false;
                break;
            }
        }
        if(win) return true;
    }
    
    // Check for vertical win
    for(int i = 0; i < SIZE; i++) {
        bool win = true;
        for(int j = 0; j < SIZE; j++) {
            if(board[j][i] != player) {
                win = false;
                break;
            }
        }
        if(win) return true;
    }
    
    // Check for diagonal win (top-left to bottom-right)
    bool win = true;
    for(int i = 0; i < SIZE; i++) {
        if(board[i][i] != player) {
            win = false;
            break;
        }
    }
    if(win) return true;
    
    // Check for diagonal win (top-right to bottom-left)
    win = true;
    for(int i = 0; i < SIZE; i++) {
        if(board[i][SIZE-i-1] != player) {
            win = false;
            break;
        }
    }
    if(win) return true;
    
    // Check for tie
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == '-') {
                return false;
            }
        }
    }
    
    // Game has ended and it's a tie
    return true;
}

// Evaluate the score of the board (for AI player)
int evaluate(char board[SIZE][SIZE]) {
    // Check for horizontal win
    for(int i = 0; i < SIZE; i++) {
        bool win = true;
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] != AI_PLAYER) {
                win = false;
                break;
            }
        }
        if(win) return +10;
    }
    
    // Check for vertical win
    for(int i = 0; i < SIZE; i++) {
        bool win = true;
        for(int j = 0; j < SIZE; j++) {
            if(board[j][i] != AI_PLAYER) {
                win = false;
                break;
            }
        }
        if(win) return +10;
    }
    
    // Check for diagonal win (top-left to bottom-right)
    bool win = true;
    for(int i = 0; i < SIZE; i++) {
        if(board[i][i] != AI_PLAYER) {
            win = false;
            break;
        }
    }
    if(win) return +10;
    
    // Check for diagonal win (top-right to bottom-left)
    win = true;
    for(int i = 0; i < SIZE; i++) {
        if(board[i][SIZE-i-1] != AI_PLAYER) {
            win = false;
            break;
        }
    }
    if(win) return +10;
    
    // Check for horizontal loss
    for(int i = 0; i < SIZE; i++) {
        bool loss = true;
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] != HUMAN_PLAYER) {
                loss = false;
                break;
            }
        }
        if(loss) return -10;
    }
    
    // Check for vertical loss
    for(int i = 0; i < SIZE; i++) {
        bool loss = true;
        for(int j = 0; j < SIZE; j++) {
            if(board[j][i] != HUMAN_PLAYER) {
                loss = false;
                break;
            }
        }
        if(loss) return -10;
    }
    
    // Check for diagonal loss (top-left to bottom-right)
    win = true;
    for(int i = 0; i < SIZE; i++) {
        if(board[i][i] != HUMAN_PLAYER) {
            win = false;
            break;
        }
    }
    if(win) return -10;
    
    // Check for diagonal loss (top-right to bottom-left)
    win = true;
    for(int i = 0; i < SIZE; i++) {
        if(board[i][SIZE-i-1] != HUMAN_PLAYER) {
            win = false;
            break;
        }
    }
    if(win) return -10;
    
    // Otherwise, return 0 (neutral score)
    return 0;
}

// Minimax algorithm with alpha-beta pruning
int minimax(char board[SIZE][SIZE], int depth, bool maximizing_player, int alpha, int beta) {
    // Check if game has ended or max depth has been reached
    if(depth == 0 || game_over(board, AI_PLAYER) || game_over(board, HUMAN_PLAYER)) {
        return evaluate(board);
    }
    
    // Maximizing player (AI)
    if(maximizing_player) {
        int best_score = INT_MIN;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = AI_PLAYER;
                    int score = minimax(board, depth-1, false, alpha, beta);
                    board[i][j] = '-';
                    best_score = (score > best_score) ? score : best_score;
                    alpha = (best_score > alpha) ? best_score : alpha;
                    if(alpha >= beta) break;
                }
            }
        }
        return best_score;
    }
    
    // Minimizing player (human)
    else {
        int best_score = INT_MAX;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = HUMAN_PLAYER;
                    int score = minimax(board, depth-1, true, alpha, beta);
                    board[i][j] = '-';
                    best_score = (score < best_score) ? score : best_score;
                    beta = (best_score < beta) ? best_score : beta;
                    if(alpha >= beta) break;
                }
            }
        }
        return best_score;
    }
}

// AI makes a move (using minimax algorithm)
void ai_move(char board[SIZE][SIZE]) {
    int best_score = INT_MIN;
    int row = -1;
    int col = -1;
    
    // Find best move for AI
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == '-') {
                board[i][j] = AI_PLAYER;
                int score = minimax(board, 5, false, INT_MIN, INT_MAX);
                board[i][j] = '-';
                if(score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    
    // AI makes the best move
    board[row][col] = AI_PLAYER;
}

int main() {
    char board[SIZE][SIZE];
    init_board(board);
    
    while(!game_over(board, AI_PLAYER) && !game_over(board, HUMAN_PLAYER)) {
        // Human player's move
        int row, col;
        display_board(board);
        printf("Enter your move (row column): ");
        scanf("%d %d", &row, &col);
        while(board[row][col] != '-') {
            printf("Invalid move. Try again.\n");
            printf("Enter your move (row column): ");
            scanf("%d %d", &row, &col);
        }
        board[row][col] = HUMAN_PLAYER;
        
        // AI player's move
        display_board(board);
        printf("AI is making a move...\n");
        ai_move(board);
    }
    
    // Display final board
    display_board(board);
    
    // Declare winner or tie
    if(game_over(board, AI_PLAYER)) {
        printf("AI wins!\n");
    }
    else if(game_over(board, HUMAN_PLAYER)) {
        printf("You win!\n");
    }
    else {
        printf("Tie game.\n");
    }
    
    return 0;
}