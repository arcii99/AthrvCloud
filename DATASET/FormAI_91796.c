//FormAI DATASET v1.0 Category: Checkers Game ; Style: mathematical
#include <stdio.h>

// Define the dimensions of the checkerboard
#define BOARD_SIZE 8

// Define the players
#define PLAYER_1_TURN 1
#define PLAYER_2_TURN 2

// Define different states for the board
#define EMPTY 0
#define PLAYER_1_PIECE 1
#define PLAYER_2_PIECE 2
#define PLAYER_1_KING 3
#define PLAYER_2_KING 4

// Function signature for a move
typedef struct {
    int initial_row, initial_col;
    int final_row, final_col;
} Move;

// Function signatures
void initialize_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);
int apply_move(int board[][BOARD_SIZE], Move move, int current_turn);
int get_opponent(int player);
int count_pieces(int board[][BOARD_SIZE], int player);
int is_game_over(int board[][BOARD_SIZE]);

// Entry point of the program
int main(void) {
    // Initialize the board
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    
    // Define the initial player
    int current_turn = PLAYER_1_TURN;
    
    // Start the game loop
    while (!is_game_over(board)) {
        // Print the current state of the board
        printf("Current board:\n");
        print_board(board);
        
        // Get the player's move
        Move move;
        printf("Player %d, enter your move (initial row, initial col, final row, final col):\n", current_turn);
        scanf("%d %d %d %d", &move.initial_row, &move.initial_col, &move.final_row, &move.final_col);
        
        // Apply the move and switch turns
        if (apply_move(board, move, current_turn)) {
            current_turn = get_opponent(current_turn);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    
    // Game over
    printf("Game over! Final scores:\n");
    printf("Player 1: %d\n", count_pieces(board, PLAYER_1_PIECE) + count_pieces(board, PLAYER_1_KING));
    printf("Player 2: %d\n", count_pieces(board, PLAYER_2_PIECE) + count_pieces(board, PLAYER_2_KING));
    
    return 0;
}

// Initialize the board
void initialize_board(int board[][BOARD_SIZE]) {
    // Initialize with empty spaces
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            board[row][col] = EMPTY;
        }
    }
    
    // Place player 1's pieces
    for (int row = 0; row < BOARD_SIZE / 2 - 1; ++row) {
        for (int col = (row + 1) % 2; col < BOARD_SIZE; col += 2) {
            board[row][col] = PLAYER_1_PIECE;
        }
    }
    
    // Place player 2's pieces
    for (int row = BOARD_SIZE / 2 + 1; row < BOARD_SIZE; ++row) {
        for (int col = (row + 1) % 2; col < BOARD_SIZE; col += 2) {
            board[row][col] = PLAYER_2_PIECE;
        }
    }
}

// Print the board
void print_board(int board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            switch (board[row][col]) {
                case EMPTY:
                    printf(".");
                    break;
                case PLAYER_1_PIECE:
                    printf("O");
                    break;
                case PLAYER_2_PIECE:
                    printf("X");
                    break;
                case PLAYER_1_KING:
                    printf("K");
                    break;
                case PLAYER_2_KING:
                    printf("Q");
                    break;
            }
        }
        printf("\n");
    }
}

// Apply a move to the board
int apply_move(int board[][BOARD_SIZE], Move move, int current_turn) {
    // Check if the move is valid
    if (board[move.final_row][move.final_col] != EMPTY || 
        (current_turn == PLAYER_1_TURN && (board[move.initial_row][move.initial_col] == PLAYER_2_PIECE ||
                                           board[move.initial_row][move.initial_col] == PLAYER_2_KING)) ||
        (current_turn == PLAYER_2_TURN && (board[move.initial_row][move.initial_col] == PLAYER_1_PIECE ||
                                           board[move.initial_row][move.initial_col] == PLAYER_1_KING))) {
        return 0;
    }
    
    // Move the piece and promote to king if necessary
    int piece = board[move.initial_row][move.initial_col];
    board[move.initial_row][move.initial_col] = EMPTY;
    board[move.final_row][move.final_col] = piece;
    if (piece == PLAYER_1_PIECE && move.final_row == BOARD_SIZE - 1) {
        board[move.final_row][move.final_col] = PLAYER_1_KING;
    }
    if (piece == PLAYER_2_PIECE && move.final_row == 0) {
        board[move.final_row][move.final_col] = PLAYER_2_KING;
    }
    
    // Capture opponent pieces if necessary
    if (move.initial_row - move.final_row == 2 || move.final_row - move.initial_row == 2) {
        int captured_row = (move.initial_row + move.final_row) / 2;
        int captured_col = (move.initial_col + move.final_col) / 2;
        if (board[captured_row][captured_col] == get_opponent(current_turn) ||
            board[captured_row][captured_col] == get_opponent(current_turn) + 2) {
            board[captured_row][captured_col] = EMPTY;
        } else {
            return 0;
        }
    }
    
    return 1;
}

// Get the opponent of a player
int get_opponent(int player) {
    return player == PLAYER_1_TURN ? PLAYER_2_TURN : PLAYER_1_TURN;
}

// Count the number of pieces of a player on the board
int count_pieces(int board[][BOARD_SIZE], int player) {
    int count = 0;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board[row][col] == player) {
                ++count;
            }
        }
    }
    return count;
}

// Check if the game is over
int is_game_over(int board[][BOARD_SIZE]) {
    return count_pieces(board, PLAYER_1_PIECE) + count_pieces(board, PLAYER_1_KING) == 0 ||
           count_pieces(board, PLAYER_2_PIECE) + count_pieces(board, PLAYER_2_KING) == 0;
}