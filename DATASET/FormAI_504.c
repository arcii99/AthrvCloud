//FormAI DATASET v1.0 Category: Checkers Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Functions for checking valid moves
int is_valid_move(int board[][BOARD_SIZE], int current_player, int start_x, int start_y, int end_x, int end_y);
int is_valid_normal_move(int board[][BOARD_SIZE], int current_player, int start_x, int start_y, int end_x, int end_y);
int is_valid_capture_move(int board[][BOARD_SIZE], int current_player, int start_x, int start_y, int end_x, int end_y);

// Function for making moves
void make_move(int board[][BOARD_SIZE], int start_x, int start_y, int end_x, int end_y);

int main() {
    // Initialize the board
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {-1, 0,-1, 0,-1, 0,-1, 0},
        { 0,-1, 0,-1, 0,-1, 0,-1},
        {-1, 0,-1, 0,-1, 0,-1, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 0, 1, 0, 1, 0, 1},
        { 1, 0, 1, 0, 1, 0, 1, 0},
        { 0, 1, 0, 1, 0, 1, 0, 1}
    };
    
    // Define the players
    int player_1 = 1;
    int player_2 = 2;
    int current_player = player_1;
    
    // Start the game loop
    while (1) {
        // Print the board
        printf("Current board:\n\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == -1) {
                    printf("X ");
                } else if (board[i][j] == 0) {
                    printf("- ");
                } else if (board[i][j] == 1) {
                    printf("O ");
                } else if (board[i][j] == 2) {
                    printf("K ");
                }
            }
            printf("\n");
        }
        printf("\n");
        
        // Check if the game is over
        int player_1_pieces = 0;
        int player_2_pieces = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == player_1 || board[i][j] == 2) {
                    player_1_pieces++;
                } else if (board[i][j] == player_2) {
                    player_2_pieces++;
                }
            }
        }
        if (player_1_pieces == 0) {
            printf("Player 2 wins!\n");
            break;
        } else if (player_2_pieces == 0) {
            printf("Player 1 wins!\n");
            break;
        }
        
        // Get the move from the current player
        printf("Player %d's turn:\n", current_player);
        int start_x, start_y, end_x, end_y;
        printf("Enter starting position (x y): ");
        scanf("%d %d", &start_x, &start_y);
        printf("Enter ending position (x y): ");
        scanf("%d %d", &end_x, &end_y);
        
        // Check if the move is valid
        if (is_valid_move(board, current_player, start_x, start_y, end_x, end_y)) {
            // Make the move
            make_move(board, start_x, start_y, end_x, end_y);
            
            // Toggle the current player
            if (current_player == player_1) {
                current_player = player_2;
            } else {
                current_player = player_1;
            }
        } else {
            printf("Invalid move!\n");
        }
    }
    
    return 0;
}

int is_valid_move(int board[][BOARD_SIZE], int current_player, int start_x, int start_y, int end_x, int end_y) {
    if (is_valid_normal_move(board, current_player, start_x, start_y, end_x, end_y)) {
        return 1;
    } else if (is_valid_capture_move(board, current_player, start_x, start_y, end_x, end_y)) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_normal_move(int board[][BOARD_SIZE], int current_player, int start_x, int start_y, int end_x, int end_y) {
    // Check if the end position is empty
    if (board[end_x][end_y] != 0) {
        return 0;
    }
    
    // Check if the end position is adjacent
    if ((current_player == 1 && end_x != start_x + 1) || (current_player == 2 && end_x != start_x - 1)) {
        return 0;
    }
    if (end_y != start_y - 1 && end_y != start_y + 1) {
        return 0;
    }
    
    // Check if the move is forward or backward depending on the player
    if (current_player == 1 && end_x < start_x) {
        return 0;
    }
    if (current_player == 2 && end_x > start_x) {
        return 0;
    }
    
    return 1;
}

int is_valid_capture_move(int board[][BOARD_SIZE], int current_player, int start_x, int start_y, int end_x, int end_y) {
    // Check if the end position is empty
    if (board[end_x][end_y] != 0) {
        return 0;
    }
    
    // Check if the end position is adjacent
    if ((current_player == 1 && end_x != start_x + 2) || (current_player == 2 && end_x != start_x - 2)) {
        return 0;
    }
    if (end_y != start_y - 2 && end_y != start_y + 2) {
        return 0;
    }
    
    // Check if the move is forward or backward depending on the player
    if (current_player == 1 && end_x < start_x) {
        return 0;
    }
    if (current_player == 2 && end_x > start_x) {
        return 0;
    }
    
    // Check if there is an opponent's piece to capture
    int opponent_player;
    if (current_player == 1) {
        opponent_player = 2;
    } else {
        opponent_player = 1;
    }
    int capture_x = (start_x + end_x) / 2;
    int capture_y = (start_y + end_y) / 2;
    if (board[capture_x][capture_y] != opponent_player && board[capture_x][capture_y] != opponent_player + 1) {
        return 0;
    }
    
    return 1;
}

void make_move(int board[][BOARD_SIZE], int start_x, int start_y, int end_x, int end_y) {
    // Move the piece
    board[end_x][end_y] = board[start_x][start_y];
    board[start_x][start_y] = 0;
    
    // Check if the piece is promoted to a king
    if (board[end_x][end_y] == 1 && end_x == 0) {
        board[end_x][end_y] = 2;
    } else if (board[end_x][end_y] == 2 && end_x == 7) {
        board[end_x][end_y] = 3;
    }
    
    // Capture the opponent's piece if necessary
    int capture_x = (start_x + end_x) / 2;
    int capture_y = (start_y + end_y) / 2;
    if (abs(start_x - end_x) == 2 && abs(start_y - end_y) == 2) {
        board[capture_x][capture_y] = 0;
    }
}