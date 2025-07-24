//FormAI DATASET v1.0 Category: Checkers Game ; Style: single-threaded
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; // Initialize empty board

void initialize_board() { // Initialize starting board
    //Initialize black pieces
    board[0][1] = 'b';
    board[0][3] = 'b';
    board[0][5] = 'b';
    board[0][7] = 'b';
    board[1][0] = 'b';
    board[1][2] = 'b';
    board[1][4] = 'b';
    board[1][6] = 'b';
    board[2][1] = 'b';
    board[2][3] = 'b';
    board[2][5] = 'b';
    board[2][7] = 'b';

    // Initialize white pieces
    board[5][0] = 'w';
    board[5][2] = 'w';
    board[5][4] = 'w';    
    board[5][6] = 'w';
    board[6][1] = 'w';
    board[6][3] = 'w';
    board[6][5] = 'w';
    board[6][7] = 'w';
    board[7][0] = 'w';
    board[7][2] = 'w';
    board[7][4] = 'w';
    board[7][6] = 'w';
}

void display_board() { // Display board
    for(int row=0; row<BOARD_SIZE; row++) {
        printf("  %d ", BOARD_SIZE-row);
        for(int col=0; col<BOARD_SIZE; col++) {
            printf(" %c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n     a  b  c  d  e  f  g  h\n\n");
}

int check_move(char player, int start_row, int start_col, int end_row, int end_col) {
    int x_movement = start_row - end_row; // Movement in x-axis
    int y_movement = start_col - end_col; // Movement in y-axis
    
    // Check if move is diagonal
    if(abs(x_movement) == abs(y_movement)) {
        int steps = abs(x_movement); // Number of steps required
        
        // Check for piece in between start and end
        int i,j;
        for(i=1; i<steps; i++) {
            // Diagonal up-right
            if(x_movement < 0 && y_movement > 0) {
                if(board[start_row+i][start_col-i] != '_') return 0;
            }
            // Diagonal up-left
            if(x_movement < 0 && y_movement < 0) {
                if(board[start_row+i][start_col+i] != '_') return 0;
            }
            // Diagonal down-left
            if(x_movement > 0 && y_movement < 0) {
                if(board[start_row-i][start_col+i] != '_') return 0;
            }
            // Diagonal down-right
            if(x_movement > 0 && y_movement > 0) {
                if(board[start_row-i][start_col-i] != '_') return 0;
            }
        }
        
        // Check for opposite player's piece at destination
        if(player == 'w' && board[end_row][end_col] == 'b') return 1;
        else if(player == 'b' && board[end_row][end_col] == 'w') return 1;
        
        return 0; // No opposite player's piece
    }
    
    return 0; // Not a diagonal move
}

void make_move(char player, int start_row, int start_col, int end_row, int end_col) {
    board[start_row][start_col] = '_'; // Remove piece from starting position
    board[end_row][end_col] = player; // Add piece to end position
    
    // Check if move resulted in capture
    int x_movement = start_row - end_row;
    int y_movement = start_col - end_col;
    if(abs(x_movement) == 2 && abs(y_movement) == 2) { // Capture move
        int captured_row = start_row - x_movement / 2;
        int captured_col = start_col - y_movement / 2;
        board[captured_row][captured_col] = '_'; // Remove captured piece
    }
}

int main() {
    initialize_board();
    display_board();
    
    char curr_player = 'b';
    while(1) {
        printf("%c's move:\n", curr_player);
        int start_row, start_col, end_row, end_col;
        
        // Get player's move
        printf("Enter starting row (1-8): ");
        scanf("%d", &start_row);
        printf("Enter starting column (a-h): ");
        char start_col_char;
        scanf(" %c", &start_col_char);
        start_col = start_col_char - 'a';
        printf("Enter ending row (1-8): ");
        scanf("%d", &end_row);
        printf("Enter ending column (a-h): ");
        char end_col_char;
        scanf(" %c", &end_col_char);
        end_col = end_col_char - 'a';
        
        // Check if move is valid and make move
        if(board[start_row-1][start_col] == curr_player) { // Valid starting piece
            if(check_move(curr_player, start_row-1, start_col, end_row-1, end_col)) { // Valid move
                make_move(curr_player, start_row-1, start_col, end_row-1, end_col);
                
                display_board(); // Display updated board
                
                // Check if game has ended
                int b_pieces = 0, w_pieces = 0;
                for(int row=0; row<BOARD_SIZE; row++) {
                    for(int col=0; col<BOARD_SIZE; col++) {
                        if(board[row][col] == 'b' || board[row][col] == 'B') b_pieces++;
                        else if(board[row][col] == 'w' || board[row][col] == 'W') w_pieces++;
                    }
                }
                if(b_pieces == 0 || w_pieces == 0) { // Game has ended
                    printf("\nGame over!\n");
                    if(b_pieces == 0) printf("White wins!\n");
                    else if(w_pieces == 0) printf("Black wins!\n");
                    break;
                }
                
                // Switch player
                if(curr_player == 'b') curr_player = 'w';
                else curr_player = 'b';
            }
            else printf("Invalid move.\n");
        }
        else printf("Invalid starting piece.\n");
    }
    
    return 0;
}