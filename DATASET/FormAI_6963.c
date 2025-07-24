//FormAI DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define constants for board size and player colors
#define BOARD_SIZE 8
#define RED 'R'
#define BLACK 'B'
#define EMPTY '-'

// Define the struct for a checker piece
typedef struct {
    char color;
    int is_king;
} Checker;

// Define the global board array
Checker board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the starting board
void init_board() {
    int i, j;
    // Set all cells to empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].color = EMPTY;
            board[i][j].is_king = 0;
        }
    }
    // Set the starting positions of red checkers
    for (i = 0; i < 3; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == j % 2) {
                board[i][j].color = RED;
            }
        }
    }
    // Set the starting positions of black checkers
    for (i = BOARD_SIZE-3; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == j % 2) {
                board[i][j].color = BLACK;
            }
        }
    }
}

// Function to print out the current board state
void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].color);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_move_valid(int start_x, int start_y, int end_x, int end_y, char player_color) {
    // Check if end location is vacant
    if (board[end_x][end_y].color != EMPTY) {
        return 0;
    }
    // Check if player is trying to move empty cell
    if (board[start_x][start_y].color == EMPTY) {
        return 0;
    }
    // Check if player is trying to move opponent's checker
    if (board[start_x][start_y].color != player_color) {
        return 0;
    }
    // Check if player is trying to move diagonally
    if (abs(start_x-end_x) != abs(start_y-end_y)) {
        return 0;
    }
    // Check if player is moving backwards without being a king
    if ((player_color == RED && end_x > start_x) || (player_color == BLACK && end_x < start_x)) {
        if (!board[start_x][start_y].is_king) {
            return 0;
        }
    }
    // Check if player is moving more than one cell without taking opponent's checker
    if (abs(start_x-end_x) > 2) {
        return 0;
    }
    // Check if player is jumping over opponent's checker
    if (abs(start_x-end_x) == 2) {
        int middle_x = (start_x + end_x)/2;
        int middle_y = (start_y + end_y)/2;
        if (board[middle_x][middle_y].color == EMPTY || board[middle_x][middle_y].color == player_color) {
            return 0;
        }
    }
    // All checks passed, move is valid
    return 1;
}

// Function to make a move
void make_move(int start_x, int start_y, int end_x, int end_y) {
    // Move checker
    board[end_x][end_y].color = board[start_x][start_y].color;
    board[start_x][start_y].color = EMPTY;
    // Check if checker has become a king
    if (board[end_x][end_y].color == RED && end_x == 0) {
        board[end_x][end_y].is_king = 1;
    }
    if (board[end_x][end_y].color == BLACK && end_x == BOARD_SIZE-1) {
        board[end_x][end_y].is_king = 1;
    }
    // Check if checker has taken opponent's checker
    if (abs(start_x-end_x) == 2) {
        int middle_x = (start_x + end_x)/2;
        int middle_y = (start_y + end_y)/2;
        board[middle_x][middle_y].color = EMPTY;
    }
}

int main() {
    init_board();
    print_board();
    
    char current_player = RED;
    
    while (1) {
        int start_x, start_y, end_x, end_y;
        printf("Player %c, enter start and end locations separated by a space: ", current_player);
        scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
        if (is_move_valid(start_x, start_y, end_x, end_y, current_player)) {
            make_move(start_x, start_y, end_x, end_y);
            print_board();
            // Check if game is over
            int red_pieces = 0, black_pieces = 0;
            int i, j;
            for (i = 0; i < BOARD_SIZE; i++) {
                for (j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j].color == RED) {
                        red_pieces++;
                    }
                    if (board[i][j].color == BLACK) {
                        black_pieces++;
                    }
                }
            }
            if (red_pieces == 0 || black_pieces == 0) {
                printf("Game over! Player %c wins!\n", current_player);
                break;
            }
            // Switch player
            if (current_player == RED) {
                current_player = BLACK;
            } else {
                current_player = RED;
            }
        } else {
            printf("Invalid move!\n");
        }
    }
    
    return 0;
}