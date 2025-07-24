//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// A struct representing a checker piece
typedef struct {
    int is_king; // Flag indicating if the piece is a king
    int is_red; // Flag indicating if the piece is red (versus black)
} Checker;

// Function to initialize the game board (represented as a 2D array of Checker structs)
void init_board(Checker board[BOARD_SIZE][BOARD_SIZE]) {
    // Set up the red pieces on the board
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                board[i][j].is_king = 0;
                board[i][j].is_red = 1;
            }
        }
    }
    
    // Set up the black pieces on the board
    for(int i = BOARD_SIZE - 1; i >= BOARD_SIZE - 3; i--) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                board[i][j].is_king = 0;
                board[i][j].is_red = 0;
            }
        }
    }
}

// Function to print out the current state of the game board
void print_board(Checker board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for(int i = 0; i < BOARD_SIZE; i++)
        printf("%d ", i);
    printf("\n");
    
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j].is_red)
                printf("R");
            else
                printf("B");
                
            if(board[i][j].is_king)
                printf("K");
            else
                printf(" ");
            
            printf("|");
        }
        printf("\n");
    }
}

// Function to check if a move is legal
int is_legal_move(Checker board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    // Check that the start and end positions are within bounds of the board
    if(start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE || end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE)
        return 0;
    
    // Check that the end position is empty
    if(board[end_row][end_col].is_red || !board[start_row][start_col].is_red)
        return 0;
    
    // Check that the move is diagonal and the correct distance
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    if(abs(row_diff) != abs(col_diff))
        return 0;
    if(abs(row_diff) == 1 && board[start_row][start_col].is_king) // Kings can move one space diagonally in any direction
        return 1;
    if(abs(row_diff) != 2 || abs(col_diff) != 2) // Moves must be exactly two spaces diagonally
        return 0;
    
    // Check that there is an opponent's piece in between the start and end positions
    int enemy_row = start_row + row_diff / 2;
    int enemy_col = start_col + col_diff / 2;
    if(!board[enemy_row][enemy_col].is_red || board[start_row][start_col].is_red == board[enemy_row][enemy_col].is_red)
        return 0;
        
    return 1;
}

// Function to make a move on the game board
void make_move(Checker board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    // Set the end position to be the same as the start position
    board[end_row][end_col].is_red = board[start_row][start_col].is_red;
    board[end_row][end_col].is_king = board[start_row][start_col].is_king;
    
    // Empty the start position
    board[start_row][start_col].is_red = 0;
    board[start_row][start_col].is_king = 0;
    
    // If the move was a jump, remove the jumped piece from the board
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    if(abs(row_diff) == 2 && abs(col_diff) == 2) {
        int enemy_row = start_row + row_diff / 2;
        int enemy_col = start_col + col_diff / 2;
        board[enemy_row][enemy_col].is_red = 0;
        board[enemy_row][enemy_col].is_king = 0;
    }
    
    // If the piece reached the opposite end of the board, make it a king
    if(end_row == 0 || end_row == BOARD_SIZE - 1)
        board[end_row][end_col].is_king = 1;
}

int main() {
    Checker board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);
    
    int turn_counter = 0;
    int game_ended = 0;
    while(!game_ended) {
        turn_counter++;
        printf("Turn %d\n", turn_counter);
        
        // Determine whose turn it is based on the turn counter
        int is_red_turn = turn_counter % 2;
        if(is_red_turn)
            printf("Red's turn\n");
        else
            printf("Black's turn\n");
            
        // Ask the player for their move
        int start_row, start_col, end_row, end_col;
        printf("Enter start row: ");
        scanf("%d", &start_row);
        printf("Enter start column: ");
        scanf("%d", &start_col);
        printf("Enter end row: ");
        scanf("%d", &end_row);
        printf("Enter end column: ");
        scanf("%d", &end_col);
        
        // Check if the move is legal
        if(!is_legal_move(board, start_row, start_col, end_row, end_col)) {
            printf("Illegal move. Try again.\n");
            continue;
        }
        
        // Make the move
        make_move(board, start_row, start_col, end_row, end_col);
        print_board(board);
        
        // Check if the game has ended
        game_ended = 1;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j].is_red) {
                    int can_move_left = is_legal_move(board, i, j, i + 1, j - 1);
                    int can_move_right = is_legal_move(board, i, j, i + 1, j + 1);
                    int can_jump_left = is_legal_move(board, i, j, i + 2, j - 2);
                    int can_jump_right = is_legal_move(board, i, j, i + 2, j + 2);
                    if(can_move_left || can_move_right || can_jump_left || can_jump_right) {
                        game_ended = 0;
                        break;
                    }
                }
            }
        }
    }
    
    // Determine the winner of the game
    int red_count = 0;
    int black_count = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j].is_red)
                red_count++;
            else
                black_count++;
        }
    }
    if(red_count > black_count)
        printf("Red wins!\n");
    else
        printf("Black wins!\n");
        
    return 0;
}