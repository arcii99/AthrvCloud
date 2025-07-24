//FormAI DATASET v1.0 Category: Checkers Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Global Variables
#define BOARD_SIZE 8
#define PLAYER_ONE_PIECE 'X'
#define PLAYER_TWO_PIECE 'O'

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'X', '_', 'X', '_', 'X', '_', 'X', '_'},
    {'_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'O', '_', 'O', '_', 'O', '_', 'O', '_'},
    {'_', 'O', '_', 'O', '_', 'O', '_', 'O'},
    {'O', '_', 'O', '_', 'O', '_', 'O', '_'},
};

// Function Declaration
void print_board();
bool is_valid_move(int row, int col, int new_row, int new_col, char player_piece);
bool is_king(int row, int col, char player_piece);
bool is_adjacent(int row, int col, int new_row, int new_col);
bool can_jump(char player_piece);
void move_piece(int row, int col, int new_row, int new_col, char player_piece);
bool execute_jump(int row, int col, int new_row, int new_col, char player_piece);
bool execute_moves();
bool check_win(char player_piece);

int main()
{
    int turn_counter = 0;
    char player_one_piece = PLAYER_ONE_PIECE;
    char player_two_piece = PLAYER_TWO_PIECE;
    char current_player_piece = player_one_piece;
    
    printf("Welcome to Checkers: Post-Apocalypse Edition!\n");
    
    while (true) {
        print_board();
        
        if (turn_counter % 2 == 0) {
            current_player_piece = player_one_piece;
        } else {
            current_player_piece = player_two_piece;
        }
        
        printf("Player %d's Turn (%c)\n", (turn_counter % 2) + 1, current_player_piece);
        
        if (!execute_moves()) {
            printf("Player %d cannot make a move. Game Over.\n", (turn_counter % 2) + 1);
            break;
        }
        
        if (check_win(current_player_piece)) {
            printf("Player %d has won the game!\n", (turn_counter % 2) + 1);
            break;
        }
        
        turn_counter++;
    }

    return 0;
}

void print_board()
{   
    printf("\n   0  1  2  3  4  5  6  7\n");
    printf("  ------------------------\n");
    
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("| %c", board[row][col]);
        }
        printf("| %d\n", row);
    }
    
    printf("  ------------------------\n");
    printf("   0  1  2  3  4  5  6  7\n");
}

bool is_valid_move(int row, int col, int new_row, int new_col, char player_piece)
{   
    // Check if new position is within board bounds
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return false;
    }
    
    // Check if new position is a diagonal move
    if (new_row % 2 == new_col % 2) {
        return false;
    }
    
    // Check if new position is empty
    if (board[new_row][new_col] != '_') {
        return false;
    }
    
    // Check if player is moving their own piece
    if (board[row][col] != player_piece) {
        return false;
    }
    
    // Check if piece is making a correct diagonal move
    if (!is_king(row, col, player_piece)) {
        if ((player_piece == PLAYER_ONE_PIECE && new_row > row) || (player_piece == PLAYER_TWO_PIECE && new_row < row)) {
            return false;
        }
    }
    
    // Check if piece is moving more than one diagonal
    if (abs(row - new_row) > 1 || abs(col - new_col) > 1) {
        return execute_jump(row, col, new_row, new_col, player_piece);
    }
    
    return true;
}

bool is_king(int row, int col, char player_piece)
{
    if (player_piece == PLAYER_ONE_PIECE && row == 0) {
        return true;
    }
    
    if (player_piece == PLAYER_TWO_PIECE && row == 7) {
        return true;
    }
    
    return false;
}

bool is_adjacent(int row, int col, int new_row, int new_col)
{
    return (abs(row - new_row) == 1 && abs(col - new_col) == 1);
}

bool can_jump(char player_piece)
{
    int row_dir, col_dir;
    
    if (player_piece == PLAYER_ONE_PIECE) {
        row_dir = -1;
    } else {
        row_dir = 1;
    }
    
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == player_piece) {
                if (is_king(row, col, player_piece)) {
                    // King's jumps
                    for (int i = 1; i < BOARD_SIZE; i++) {
                        if (row + i < BOARD_SIZE && col + i < BOARD_SIZE && board[row+i][col+i] == '_' && board[row+i-1][col+i-1] != '_') {
                            if (board[row+i-1][col+i-1] == PLAYER_ONE_PIECE || board[row+i-1][col+i-1] == 'K') {
                                return true;
                            }
                        }
                        
                        if (row + i < BOARD_SIZE && col - i >= 0 && board[row+i][col-i] == '_' && board[row+i-1][col-i+1] != '_') {
                            if (board[row+i-1][col-i+1] == PLAYER_ONE_PIECE || board[row+i-1][col-i+1] == 'K') {
                                return true;
                            }
                        }
                        
                        if (row - i >= 0 && col + i < BOARD_SIZE && board[row-i][col+i] == '_' && board[row-i+1][col+i-1] != '_') {
                            if (board[row-i+1][col+i-1] == PLAYER_ONE_PIECE || board[row-i+1][col+i-1] == 'K') {
                                return true;
                            }
                        }
                        
                        if (row - i >= 0 && col - i >= 0 && board[row-i][col-i] == '_' && board[row-i+1][col-i+1] != '_') {
                            if (board[row-i+1][col-i+1] == PLAYER_ONE_PIECE || board[row-i+1][col-i+1] == 'K') {
                                return true;
                            }
                        }
                    }
                } else {
                    // Regular piece jumps
                    if (row - 2 >= 0 && col - 2 >= 0 && board[row-1][col-1] == PLAYER_ONE_PIECE && board[row-2][col-2] == '_') {
                        return true;
                    }
                    
                    if (row - 2 >= 0 && col + 2 < BOARD_SIZE && board[row-1][col+1] == PLAYER_ONE_PIECE && board[row-2][col+2] == '_') {
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

void move_piece(int row, int col, int new_row, int new_col, char player_piece)
{
    board[new_row][new_col] = board[row][col];
    board[row][col] = '_';
    
    if (is_king(new_row, new_col, player_piece)) {
        if (player_piece == PLAYER_ONE_PIECE) {
            board[new_row][new_col] = 'K';
        } else {
            board[new_row][new_col] = 'Q';
        }
    }
}

bool execute_jump(int row, int col, int new_row, int new_col, char player_piece)
{
    int mid_row = (row + new_row) / 2;
    int mid_col = (col + new_col) / 2;
    
    if (board[mid_row][mid_col] == PLAYER_ONE_PIECE || board[mid_row][mid_col] == 'K') {
        board[mid_row][mid_col] = '_';
        move_piece(row, col, new_row, new_col, player_piece);
        
        if (!can_jump(player_piece)) {
            return true;
        }
        
        if (execute_jump(new_row, new_col, new_row-2, new_col-2, player_piece) 
            || execute_jump(new_row, new_col, new_row-2, new_col+2, player_piece)
            || execute_jump(new_row, new_col, new_row+2, new_col-2, player_piece)
            || execute_jump(new_row, new_col, new_row+2, new_col+2, player_piece))
        {
            return true;
        }
    }
    
    return false;
}

bool execute_moves()
{
    int row, col, new_row, new_col;
    char player_piece;
    
    printf("Enter piece position and move (-1 to quit): ");
    scanf("%d %d %d %d", &row, &col, &new_row, &new_col);
    
    if (row == -1 || col == -1 || new_row == -1 || new_col == -1) {
        return false;
    }
    
    player_piece = board[row][col];
    
    if (!is_valid_move(row, col, new_row, new_col, player_piece)) {
        printf("Invalid Move.\n");
        return execute_moves();
    }
    
    if (abs(row - new_row) > 1 || abs(col - new_col) > 1) {
        execute_jump(row, col, new_row, new_col, player_piece);
    } else {
        move_piece(row, col, new_row, new_col, player_piece);
    }
    
    return true;
}

bool check_win(char player_piece)
{
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == PLAYER_ONE_PIECE || board[row][col] == 'K') {
                return false;
            }
        }
    }
    
    printf("Player %c has won the game!\n", player_piece);
    return true;
}