//FormAI DATASET v1.0 Category: Checkers Game ; Style: accurate
#include <stdio.h>

// Define Constants
#define BOARD_SIZE 8
#define EMPTY 0
#define WHITE 1
#define BLACK 2
#define MAX_MOVES 50

// Define Structs
typedef struct {
    int row, col;
} location;

// Declare Functions
void initialize_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);
void print_moves(location *moves, int num_moves);
int get_valid_moves(int board[][BOARD_SIZE], int player, location *moves);
int make_move(int board[][BOARD_SIZE], location from, location to);
int is_king_row(int player, int row);

// Main Function
int main() {
    // Initialize Variables
    int board[BOARD_SIZE][BOARD_SIZE], num_moves, valid_move;
    location moves[MAX_MOVES], from, to;
    int turn = WHITE;
    
    // Initialize Board and Print
    initialize_board(board);
    print_board(board);
    
    // Game Loop
    while (1) {
        // Get Valid Moves and Print
        num_moves = get_valid_moves(board, turn, moves);
        printf("Player %d's turn. Num Moves: %d\n", turn, num_moves);
        print_moves(moves, num_moves);
        
        // Get Input and Make Move
        printf("Enter move from(row col): ");
        scanf("%d%d", &from.row, &from.col);
        printf("Enter move to(row col): ");
        scanf("%d%d", &to.row, &to.col);
        valid_move = make_move(board, from, to);
        
        // Check for Win/Loss/Draw
        if (valid_move && is_king_row(turn, to.row)) {
            board[to.row][to.col] = turn + 2;
            print_board(board);
            printf("Player %d wins!\n", turn);
            break;
        } else if (valid_move && num_moves == 0) {
            print_board(board);
            printf("Draw!\n");
            break;
        } else if (!valid_move) {
            printf("Invalid move. Please try again.\n");
        } else {
            print_board(board);
            turn = (turn == WHITE) ? BLACK : WHITE;
        }
    }
    
    return 0;   
}

// Define Functions
void initialize_board(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = BLACK;
                } else if (i > 4) {
                    board[i][j] = WHITE;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board(int board[][BOARD_SIZE]) {
    int i, j;
    printf("   0 1 2 3 4 5 6 7\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d: ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case WHITE:
                    printf("w ");
                    break;
                case BLACK:
                    printf("b ");
                    break;
                case 3:
                    printf("W ");
                    break;
                case 4:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int get_valid_moves(int board[][BOARD_SIZE], int player, location *moves) {
    int i, j, k = 0;
    int row, col, next_row, next_col, dir;
    int num_moves = 0;
    int opponent = (player == WHITE) ? BLACK : WHITE;
    
    // Loop through entire board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            // Check if piece belongs to player
            if (board[i][j] == player || board[i][j] == player + 2) {
                
                // Determine directions piece can move
                if (board[i][j] == player || board[i][j] == player + 2) {
                    dir = (board[i][j] == player) ? 1 : -1;
                    if (board[i][j] % 2) {  // If piece is a king
                        dir *= -1;
                    }
                }
                
                // Check moves for pieces
                if (board[i][j] == player || board[i][j] == player + 2) {
                    // Move forward-left
                    row = i + dir;
                    col = j - 1;
                    next_row = row + dir;
                    next_col = col - 1;
                    if (col >= 0 && next_col >= 0 &&
                        row >= 0 && next_row >= 0 &&
                        board[row][col] == opponent &&
                        board[next_row][next_col] == EMPTY) {
                        moves[k].row = i;
                        moves[k].col = j;
                        k++;
                        num_moves++;
                    }
                    
                    // Move forward-right
                    col = j + 1;
                    next_col = col + 1;
                    if (col < BOARD_SIZE && next_col < BOARD_SIZE &&
                        row >= 0 && next_row >= 0 &&
                        board[row][col] == opponent &&
                        board[next_row][next_col] == EMPTY) {
                        moves[k].row = i;
                        moves[k].col = j;
                        k++;
                        num_moves++;
                    }
                }
                
                // Check moves for kings
                if (board[i][j] == player + 2) {
                    // Move backward-left
                    row = i - dir;
                    col = j - 1;
                    next_row = row - dir;
                    next_col = col - 1;
                    if (col >= 0 && next_col >= 0 &&
                        row < BOARD_SIZE && next_row < BOARD_SIZE &&
                        board[row][col] == opponent &&
                        board[next_row][next_col] == EMPTY) {
                        moves[k].row = i;
                        moves[k].col = j;
                        k++;
                        num_moves++;
                    }
                    
                    // Move backward-right
                    col = j + 1;
                    next_col = col + 1;
                    if (col < BOARD_SIZE && next_col < BOARD_SIZE &&
                        row < BOARD_SIZE && next_row < BOARD_SIZE &&
                        board[row][col] == opponent &&
                        board[next_row][next_col] == EMPTY) {
                        moves[k].row = i;
                        moves[k].col = j;
                        k++;
                        num_moves++;
                    }
                }
            }
        }
    }
    
    return num_moves;
}

void print_moves(location *moves, int num_moves) {
    int i;
    for (i = 0; i < num_moves; i++) {
        printf("(%d %d) ", moves[i].row, moves[i].col);
    }
    printf("\n");
}

int make_move(int board[][BOARD_SIZE], location from, location to) {
    int row_diff = to.row - from.row;
    int col_diff = to.col - from.col;
    
    // Check for valid move
    if ((row_diff == 1 || row_diff == -1) && 
        (col_diff == 1 || col_diff == -1) &&
        board[to.row][to.col] == EMPTY) {
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col] = EMPTY;
        return 1;
    } else if ((row_diff == 2 || row_diff == -2) && 
               (col_diff == 2 || col_diff == -2) &&
               board[to.row][to.col] == EMPTY) {
        int opponent_row = (to.row + from.row) / 2;
        int opponent_col = (to.col + from.col) / 2;
        int player = board[from.row][from.col];
        int opponent = board[opponent_row][opponent_col];
        if (opponent != EMPTY && opponent != player && opponent != player + 2) {
            board[to.row][to.col] = player;
            board[from.row][from.col] = EMPTY;
            board[opponent_row][opponent_col] = EMPTY;
            return 1;
        }
    }
    return 0;
}

int is_king_row(int player, int row) {
    if (player == WHITE && row == 0) {
        return 1;
    } else if (player == BLACK && row == BOARD_SIZE - 1) {
        return 1;
    }
    return 0;
}