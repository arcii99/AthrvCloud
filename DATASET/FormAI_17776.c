//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>

// constants for the size of the board and the number of pieces per player
#define SIZE 8
#define NUM_PIECES 12

// constants for different types of pieces and the empty square
#define EMPTY 0
#define RED 1
#define BLACK 2
#define KING 3

// struct for a square on the board
typedef struct {
    int row;
    int col;
} Square;

// struct for a checkers piece
typedef struct {
    int type;
    Square position;
} Piece;

// global variables for the board and the pieces
int board[SIZE][SIZE];
Piece red_pieces[NUM_PIECES];
Piece black_pieces[NUM_PIECES];

// set up the starting board and pieces
void init_game() {
    // empty the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    // place the red pieces
    int red_index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = (i + 1) % 2; j < SIZE; j += 2) {
            red_pieces[red_index].type = RED;
            red_pieces[red_index].position.row = i;
            red_pieces[red_index].position.col = j;
            board[i][j] = RED;
            red_index++;
        }
    }
    // place the black pieces
    int black_index = 0;
    for (int i = SIZE - 3; i < SIZE; i++) {
        for (int j = (i + 1) % 2; j < SIZE; j += 2) {
            black_pieces[black_index].type = BLACK;
            black_pieces[black_index].position.row = i;
            black_pieces[black_index].position.col = j;
            board[i][j] = BLACK;
            black_index++;
        }
    }
}

// print the current state of the board
void print_board() {
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(". ");
            } else if (board[i][j] == RED) {
                printf("r ");
            } else if (board[i][j] == BLACK) {
                printf("b ");
            } else if (board[i][j] == KING) {
                printf("K ");
            }
        }
        printf("%d\n", i + 1);
    }
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
}

// check if a move is valid
int is_valid_move(Piece piece, int new_row, int new_col) {
    // check if the new position is out of bounds or already has a piece
    if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE
            || board[new_row][new_col] != EMPTY) {
        return 0;
    }
    // check if the piece is allowed to move diagonally in that direction
    int row_diff = new_row - piece.position.row;
    int col_diff = new_col - piece.position.col;
    if (piece.type == RED && row_diff != 1) {
        return 0;
    }
    if (piece.type == BLACK && row_diff != -1) {
        return 0;
    }
    if (abs(col_diff) != 1) {
        return 0;
    }
    // check if the piece is allowed to move that far (one or two spaces)
    if (abs(row_diff) == 1) {
        return 1;
    }
    // check if the piece is allowed to jump over another piece
    int jumped_row = piece.position.row + row_diff / 2;
    int jumped_col = piece.position.col + col_diff / 2;
    if (board[jumped_row][jumped_col] != (piece.type == RED ? BLACK : RED)) {
        return 0;
    }
    return 1;
}

// move a piece to a new position
void move_piece(Piece* piece, int new_row, int new_col) {
    // remove the piece from its current position
    board[piece->position.row][piece->position.col] = EMPTY;
    // update the piece's position
    piece->position.row = new_row;
    piece->position.col = new_col;
    // check if the piece has become a king
    if (piece->type == RED && new_row == SIZE - 1) {
        piece->type = KING;
    } else if (piece->type == BLACK && new_row == 0) {
        piece->type = KING;
    }
    // place the piece in its new position
    board[new_row][new_col] = piece->type;
}

// remove a captured piece from the board and the corresponding player's pieces
void capture_piece(int row, int col) {
    int piece_index;
    if (board[row][col] == RED || board[row][col] == KING) {
        for (int i = 0; i < NUM_PIECES; i++) {
            if (red_pieces[i].position.row == row && red_pieces[i].position.col == col) {
                piece_index = i;
                break;
            }
        }
        for (int i = piece_index; i < NUM_PIECES - 1; i++) {
            red_pieces[i] = red_pieces[i + 1];
        }
        red_pieces[NUM_PIECES - 1].type = EMPTY;
    } else {
        for (int i = 0; i < NUM_PIECES; i++) {
            if (black_pieces[i].position.row == row && black_pieces[i].position.col == col) {
                piece_index = i;
                break;
            }
        }
        for (int i = piece_index; i < NUM_PIECES - 1; i++) {
            black_pieces[i] = black_pieces[i + 1];
        }
        black_pieces[NUM_PIECES - 1].type = EMPTY;
    }
    board[row][col] = EMPTY;
}

// check if a piece has any valid moves or jumps
int has_valid_moves(Piece piece) {
    // check for diagonal moves
    if (is_valid_move(piece, piece.position.row + 1, piece.position.col - 1)) {
        return 1;
    }
    if (is_valid_move(piece, piece.position.row + 1, piece.position.col + 1)) {
        return 1;
    }
    if (is_valid_move(piece, piece.position.row - 1, piece.position.col - 1)) {
        return 1;
    }
    if (is_valid_move(piece, piece.position.row - 1, piece.position.col + 1)) {
        return 1;
    }
    // check for jumps
    if (piece.type == RED || piece.type == KING) {
        if (piece.position.row + 2 < SIZE && piece.position.col - 2 >= 0 
                && board[piece.position.row + 1][piece.position.col - 1] == BLACK
                && board[piece.position.row + 2][piece.position.col - 2] == EMPTY) {
            return 1;
        }
        if (piece.position.row + 2 < SIZE && piece.position.col + 2 < SIZE 
                && board[piece.position.row + 1][piece.position.col + 1] == BLACK
                && board[piece.position.row + 2][piece.position.col + 2] == EMPTY) {
            return 1;
        }
    }
    if (piece.type == BLACK || piece.type == KING) {
        if (piece.position.row - 2 >= 0 && piece.position.col - 2 >= 0 
                && board[piece.position.row - 1][piece.position.col - 1] == RED
                && board[piece.position.row - 2][piece.position.col - 2] == EMPTY) {
            return 1;
        }
        if (piece.position.row - 2 >= 0 && piece.position.col + 2 < SIZE 
                && board[piece.position.row - 1][piece.position.col + 1] == RED
                && board[piece.position.row - 2][piece.position.col + 2] == EMPTY) {
            return 1;
        }
    }
    return 0;
}

// check if the game is over
int is_game_over() {
    for (int i = 0; i < NUM_PIECES; i++) {
        if (red_pieces[i].type != EMPTY && has_valid_moves(red_pieces[i])) {
            return 0;
        }
        if (black_pieces[i].type != EMPTY && has_valid_moves(black_pieces[i])) {
            return 0;
        }
    }
    return 1;
}

// play a single turn of the game
void play_turn() {
    // print the board
    print_board();
    // ask for the player's move
    printf("Enter a move (e.g. A3 B4): ");
    char from_col, to_col;
    int from_row, to_row;
    scanf(" %c%d %c%d", &from_col, &from_row, &to_col, &to_row);
    // convert the move to row-column indices
    from_row--;
    to_row--;
    from_col -= 'A';
    to_col -= 'A';
    // make sure the indices are within bounds
    if (from_row < 0 || from_row >= SIZE || from_col < 0 || from_col >= SIZE
            || to_row < 0 || to_row >= SIZE || to_col < 0 || to_col >= SIZE) {
        printf("Invalid move: out of bounds\n");
        return;
    }
    // check if the player actually moved a piece
    if (board[from_row][from_col] == EMPTY) {
        printf("Invalid move: no piece at starting position\n");
        return;
    }
    // check if the player moved their own piece (unless it's a king)
    if ((board[from_row][from_col] == RED && from_row > to_row && red_pieces[board[from_row][from_col] - 1].type != KING)
            || (board[from_row][from_col] == BLACK && from_row < to_row && black_pieces[board[from_row][from_col] - 1].type != KING)) {
        printf("Invalid move: can only move own pieces (unless it's a king)\n");
        return;
    }
    // check if the player moved to a valid position
    if (!is_valid_move((board[from_row][from_col] == RED ? red_pieces : black_pieces)[board[from_row][from_col] - 1], to_row, to_col)) {
        printf("Invalid move: cannot move to that position\n");
        return;
    }
    // move the piece and check if it captured another piece
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;
    if (abs(row_diff) == 2) {
        capture_piece(from_row + row_diff / 2, from_col + col_diff / 2);
    }
    move_piece(&(board[from_row][from_col] == RED ? red_pieces : black_pieces)[board[from_row][from_col] - 1], to_row, to_col);
    // check if the game is over
    if (is_game_over()) {
        printf("Game over!");
    }
}

// main function
int main() {
    init_game();
    while (!is_game_over()) {
        play_turn();
    }
    return 0;
}