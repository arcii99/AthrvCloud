//FormAI DATASET v1.0 Category: Chess AI ; Style: all-encompassing
#include <stdio.h>

#define BOARD_SIZE 8

// Initialize Board
void Init_Board(int board[][BOARD_SIZE])
{
    // Initialize pieces to their starting position on the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = 0; // Empty Cell
        }
    }
    // Add black pieces
    board[0][0] = 2; // Rook (left)
    board[0][7] = 2; // Rook (right)
    board[0][1] = 3; // Knight (left)
    board[0][6] = 3; // Knight (right)
    board[0][2] = 4; // Bishop (left)
    board[0][5] = 4; // Bishop (right)
    board[0][3] = 5; // Queen
    board[0][4] = 6; // King
    
    for (int col = 0; col < BOARD_SIZE; col++) {
        board[1][col] = 1; // Pawn (black)
    }
      
    // Add white pieces
    board[7][0] = -2; // Rook (left)
    board[7][7] = -2; // Rook (right)
    board[7][1] = -3; // Knight (left)
    board[7][6] = -3; // Knight (right)
    board[7][2] = -4; // Bishop (left)
    board[7][5] = -4; // Bishop (right)
    board[7][3] = -5; // Queen
    board[7][4] = -6; // King
    
    for (int col = 0; col < BOARD_SIZE; col++) {
        board[6][col] = -1; // Pawn (white)
    }
}

// Print Board
void Print_Board(int board[][BOARD_SIZE])
{
    printf("\n      A  B  C  D  E  F  G  H\n\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf(" %d  ", BOARD_SIZE - row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%2d ", board[row][col]);
        }
        printf(" %d\n", BOARD_SIZE - row);
    }
    printf("\n      A  B  C  D  E  F  G  H\n");
}

// Check if move is legal
int Move_Is_Legal(int board[][BOARD_SIZE], int turn, int piece, int from_row, int from_col, int to_row, int to_col)
{
    // check if the selected piece is able to move
    if (turn * board[from_row][from_col] <= 0) {
        return 0; // selected piece is not valid
    }
    // check if the move is valid based on the piece type
    if (piece == 1) { // pawn
        if (board[to_row][to_col] != 0) { // Cannot move if there is a piece on the path
            return 0;
        }
        if (turn > 0 && to_row < from_row) { // Black pawn can only move forward
            return 0;
        }
        if (turn < 0 && to_row > from_row) { // White pawn can only move forward
            return 0;
        }
        if (to_col != from_col) { // Pawn can only move sideways if there is an enemy piece to capture
            if (board[to_row][to_col] == 0) { // No piece to capture
                return 0;
            }
        }
        if (turn > 0 && from_row == 1 && to_row > 3) { // Black pawn can move two squares forward only on its first move
            return 0;
        }
        if (turn < 0 && from_row == 6 && to_row < 4) { // White pawn can move two squares forward only on its first move
            return 0;
        }
    }
    if (piece == 2 || piece == -2) { // rook
        if (from_row != to_row && from_col != to_col) { // Rook can move only in a straight line
            return 0;
        }
        if (from_row == to_row) { // Move horizontally
            for (int col = (from_col > to_col) ? to_col + 1 : from_col + 1; col < ((from_col > to_col) ? from_col : to_col); col++) { // Check if there are any pieces in the way of the rook
                if (board[to_row][col] != 0) {
                    return 0;
                }
            }
        }
        if (from_col == to_col) { // Move vertically
            for (int row = (from_row > to_row) ? to_row + 1 : from_row + 1; row < ((from_row > to_row) ? from_row : to_row); row++) { // Check if there are any pieces in the way of the rook
                if (board[row][to_col] != 0) {
                    return 0;
                }
            }
        }
    }
    if (piece == 3 || piece == -3) { // knight
        if ((abs(from_row - to_row) == 2 && abs(from_col - to_col) == 1) || (abs(from_row - to_row) == 1 && abs(from_col - to_col) == 2)) {
            // Valid move for the knight
        } else {
            return 0; // Invalid move
        }
    }
    if (piece == 4 || piece == -4) { // bishop
        if (abs(from_row - to_row) != abs(from_col - to_col)) { // Bishop can move only diagonally
            return 0;
        }
        int row_direction = (from_row > to_row) ? -1 : 1; // Find the direction of movement
        int col_direction = (from_col > to_col) ? -1 : 1;
        int row = from_row + row_direction;
        int col = from_col + col_direction;
        while (row != to_row && col != to_col) { // Check if there are any pieces in the way of the bishop
            if (board[row][col] != 0) {
                return 0;
            }
            row += row_direction;
            col += col_direction;
        }
    }
    if (piece == 5 || piece == -5) { // queen
        if (from_row != to_row && from_col != to_col && abs(from_row - to_row) != abs(from_col - to_col)) { // Queen can move in a straight line or diagonal
            return 0;
        }
        if (from_row == to_row) { // Move horizontally
            for (int col = (from_col > to_col) ? to_col + 1 : from_col + 1; col < ((from_col > to_col) ? from_col : to_col); col++) { // Check if there are any pieces in the way of the queen
                if (board[to_row][col] != 0) {
                    return 0;
                }
            }
        }
        if (from_col == to_col) { // Move vertically
            for (int row = (from_row > to_row) ? to_row + 1 : from_row + 1; row < ((from_row > to_row) ? from_row : to_row); row++) { // Check if there are any pieces in the way of the queen
                if (board[row][to_col] != 0) {
                    return 0;
                }
            }
        }
        if (abs(from_row - to_row) == abs(from_col - to_col)) { // Move diagonally
            int row_direction = (from_row > to_row) ? -1 : 1; // Find the direction of movement
            int col_direction = (from_col > to_col) ? -1 : 1;
            int row = from_row + row_direction;
            int col = from_col + col_direction;
            while (row != to_row && col != to_col) { // Check if there are any pieces in the way of the queen
                if (board[row][col] != 0) {
                    return 0;
                }
                row += row_direction;
                col += col_direction;
            }
        }
    }
    if (piece == 6 || piece == -6) { // king
        if (abs(from_row - to_row) > 1 || abs(from_col - to_col) > 1) { // King can move only to adjacent cell
            return 0;
        }
    }
    return 1; // Move is Valid
}

// Check if the move puts the player in check
int Move_Puts_In_Check(int board[][BOARD_SIZE], int turn)
{
    int i, j;
    int king_row = 0, king_col = 0;
    // Find the position of the current player's king
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (turn * board[i][j] == 6) {
                king_row = i;
                king_col = j;
                break;
            }
        }
    }
    // Check if the king is under attack
    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (turn * board[i][j] < 0) { // check enemy pieces
                if (Move_Is_Legal(board, -turn, abs(board[i][j]), i, j, king_row, king_col)) {
                    return 1; // Move puts in check
                }
            }
        }
    }
    return 0; // Move doesn't put in check
}

// Make a move
void Make_Move(int board[][BOARD_SIZE], int turn, int piece, int from_row, int from_col, int to_row, int to_col)
{
    // Move the piece
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = 0;
    // Promoting pawn to queen
    if (piece == 1 && ((turn > 0 && to_row == 7) || (turn < 0 && to_row == 0))) {
        board[to_row][to_col] = turn * 5;
    }
}

// Get input from the user
void Get_Input(int board[][BOARD_SIZE], int *turn, int *from_row, int *from_col, int *to_row, int *to_col)
{
    char from_square[3], to_square[3];
    do {
        if (*turn > 0) {
            printf("\nBlack's Move: ");
        } else {
            printf("\nWhite's Move: ");
        }
        printf("Enter the move in algebraic notation (eg. e2 e4): ");
        scanf("%s %s", from_square, to_square);
        *from_col = from_square[0] - 'a';
        *from_row = BOARD_SIZE - (from_square[1] - '0');
        *to_col = to_square[0] - 'a';
        *to_row = BOARD_SIZE - (to_square[1] - '0');
    } while (!Move_Is_Legal(board, *turn, abs(board[*from_row][*from_col]), *from_row, *from_col, *to_row, *to_col));
}

// Play the game
void Play_Game()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    Init_Board(board);
    Print_Board(board);
    
    int turn = 1;
    while (1) {
        int from_row, from_col, to_row, to_col;
        Get_Input(board, &turn, &from_row, &from_col, &to_row, &to_col);
        int piece = board[from_row][from_col];
        Make_Move(board, turn, abs(piece), from_row, from_col, to_row, to_col);
        Print_Board(board);
        if (Move_Puts_In_Check(board, turn)) {
            printf("CHECK!\n");
        }
        turn = -turn;
    }
}

// Main function
int main()
{
    Play_Game();
    return 0;
}