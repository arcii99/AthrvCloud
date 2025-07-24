//FormAI DATASET v1.0 Category: Chess AI ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8 // Standard chessboard size (8x8)
#define TOTAL_MOVES 20 // Maximum number of moves to be played

// Define the piece types
enum piece_type {
    NONE,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
};

// Define the piece structure
typedef struct {
    enum piece_type type; // Stores the piece's type
    char symbol; // Stores the piece's symbol
    int value; // Stores the piece's point value
} piece;

// Define the board structure
typedef struct {
    piece squares[BOARD_SIZE][BOARD_SIZE]; // Stores the pieces and their locations on the board
} board;

// Define the move structure
typedef struct {
    int start_row, start_col; // Starting location of the piece
    int end_row, end_col; // Ending location of the piece
} move;

board g_board; // The global chess board
int g_move_counter = 0; // Keeps track of the number of moves played

// Function to initialize the chess board
void init_board() {
    // Initialize the squares with their correct pieces
    g_board.squares[0][0] = (piece) {ROOK, 'R', 5};
    g_board.squares[0][1] = (piece) {KNIGHT, 'N', 3};
    g_board.squares[0][2] = (piece) {BISHOP, 'B', 3};
    g_board.squares[0][3] = (piece) {QUEEN, 'Q', 9};
    g_board.squares[0][4] = (piece) {KING, 'K', 100};
    g_board.squares[0][5] = (piece) {BISHOP, 'B', 3};
    g_board.squares[0][6] = (piece) {KNIGHT, 'N', 3};
    g_board.squares[0][7] = (piece) {ROOK, 'R', 5};

    // Initialize the pawn squares
    for(int i=0; i<BOARD_SIZE; i++) {
        g_board.squares[1][i] = (piece) {PAWN, 'P', 1};
    }

    // Initialize the empty spaces in the middle of the board
    for(int i=2; i<BOARD_SIZE-2; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            g_board.squares[i][j] = (piece) {NONE, ' ', 0};
        }
    }

    // Initialize the pawn squares
    for(int i=0; i<BOARD_SIZE; i++) {
        g_board.squares[6][i] = (piece) {PAWN, 'P', 1};
    }

    // Initialize the pieces on the black side
    g_board.squares[7][0] = (piece) {ROOK, 'R', 5};
    g_board.squares[7][1] = (piece) {KNIGHT, 'N', 3};
    g_board.squares[7][2] = (piece) {BISHOP, 'B', 3};
    g_board.squares[7][3] = (piece) {QUEEN, 'Q', 9};
    g_board.squares[7][4] = (piece) {KING, 'K', 100};
    g_board.squares[7][5] = (piece) {BISHOP, 'B', 3};
    g_board.squares[7][6] = (piece) {KNIGHT, 'N', 3};
    g_board.squares[7][7] = (piece) {ROOK, 'R', 5};
}

// Function to print the chess board
void print_board() {
    printf("\n");
    printf("   A  B  C  D  E  F  G  H\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("[%c]", g_board.squares[i][j].symbol);
        }
        printf(" %d", i+1);
        printf("\n");
    }
    printf("   A  B  C  D  E  F  G  H\n");
    printf("\n");
}

// Function to get the user's move input
void get_move(move *m) {
    char start[3], end[3];

    printf("Enter your move (e.g. A1 to B2): ");
    scanf("%s to %s", start, end);

    // Convert the user input to row and column numbers
    m->start_row = atoi(&start[1]) - 1;
    m->start_col = start[0] - 'A';
    m->end_row = atoi(&end[1]) - 1;
    m->end_col = end[0] - 'A';
}

// Function to check if a move is valid
int is_valid_move(move m) {
    // Check if the starting location has a piece
    if(g_board.squares[m.start_row][m.start_col].type == NONE) {
        return 0;
    }

    // Check if the ending location has a piece of the same color
    if((g_board.squares[m.end_row][m.end_col].type != NONE) && 
       (g_board.squares[m.start_row][m.start_col].symbol == g_board.squares[m.end_row][m.end_col].symbol)) {
        return 0;
    }

    // Check if the move is valid for the piece type
    switch(g_board.squares[m.start_row][m.start_col].type) {
        case PAWN:
            // Check if the pawn is moving forward
            if(m.start_col == m.end_col) {
                // Check single step forward
                if((m.start_row + 1 == m.end_row) && (g_board.squares[m.end_row][m.end_col].type == NONE)) {
                    return 1;
                }
                // Check double step forward
                if((m.start_row + 2 == m.end_row) && (m.start_row == 1) && (g_board.squares[m.end_row][m.end_col].type == NONE) &&
                   (g_board.squares[m.start_row+1][m.start_col].type == NONE)) {
                    return 1;
                }
            }
            else {
                // Check if the pawn is capturing diagonally
                if((m.start_row + 1 == m.end_row) && ((m.start_col + 1 == m.end_col) || (m.start_col - 1 == m.end_col)) &&
                   (g_board.squares[m.end_row][m.end_col].type != NONE)) {
                    return 1;
                }
            }
            break;

        case BISHOP:
            // Check if the bishop is moving diagonally
            if(abs(m.start_row - m.end_row) == abs(m.start_col - m.end_col)) {
                // Check all squares on the bishop's path to the destination are empty
                int row_dir = m.end_row - m.start_row > 0 ? 1 : -1;
                int col_dir = m.end_col - m.start_col > 0 ? 1 : -1;
                int curr_row = m.start_row + row_dir;
                int curr_col = m.start_col + col_dir;
                while((curr_row != m.end_row) && (curr_col != m.end_col)) {
                    if(g_board.squares[curr_row][curr_col].type != NONE) {
                        return 0;
                    }
                    curr_row += row_dir;
                    curr_col += col_dir;
                }
                return 1;
            }
            break;

        case KNIGHT:
            // Check if the knight is moving in L-shape
            if(((abs(m.start_row - m.end_row) == 2) && (abs(m.start_col - m.end_col) == 1)) ||
               ((abs(m.start_row - m.end_row) == 1) && (abs(m.start_col - m.end_col) == 2))) {
                return 1;
            }
            break;

        case ROOK:
            // Check if the rook is moving horizontally or vertically
            if((m.start_row == m.end_row) || (m.start_col == m.end_col)) {
                // Check all squares on the rook's path to the destination are empty
                if(m.start_row == m.end_row) {
                    int col_dir = m.end_col - m.start_col > 0 ? 1 : -1;
                    int curr_col = m.start_col + col_dir;
                    while(curr_col != m.end_col) {
                        if(g_board.squares[m.start_row][curr_col].type != NONE) {
                            return 0;
                        }
                        curr_col += col_dir;
                    }
                    return 1;
                }
                else {
                    int row_dir = m.end_row - m.start_row > 0 ? 1 : -1;
                    int curr_row = m.start_row + row_dir;
                    while(curr_row != m.end_row) {
                        if(g_board.squares[curr_row][m.start_col].type != NONE) {
                            return 0;
                        }
                        curr_row += row_dir;
                    }
                    return 1;
                }
            }
            break;

        case QUEEN:
            // Check if the queen is moving along diagonals or in a straight line
            if(abs(m.start_row - m.end_row) == abs(m.start_col - m.end_col)) {
                // Check all squares on the queen's path to the destination are empty
                int row_dir = m.end_row - m.start_row > 0 ? 1 : -1;
                int col_dir = m.end_col - m.start_col > 0 ? 1 : -1;
                int curr_row = m.start_row + row_dir;
                int curr_col = m.start_col + col_dir;
                while((curr_row != m.end_row) && (curr_col != m.end_col)) {
                    if(g_board.squares[curr_row][curr_col].type != NONE) {
                        return 0;
                    }
                    curr_row += row_dir;
                    curr_col += col_dir;
                }
                return 1;
            }
            else if((m.start_row == m.end_row) || (m.start_col == m.end_col)) {
                // Check all squares on the queen's path to the destination are empty
                if(m.start_row == m.end_row) {
                    int col_dir = m.end_col - m.start_col > 0 ? 1 : -1;
                    int curr_col = m.start_col + col_dir;
                    while(curr_col != m.end_col) {
                        if(g_board.squares[m.start_row][curr_col].type != NONE) {
                            return 0;
                        }
                        curr_col += col_dir;
                    }
                    return 1;
                }
                else {
                    int row_dir = m.end_row - m.start_row > 0 ? 1 : -1;
                    int curr_row = m.start_row + row_dir;
                    while(curr_row != m.end_row) {
                        if(g_board.squares[curr_row][m.start_col].type != NONE) {
                            return 0;
                        }
                        curr_row += row_dir;
                    }
                    return 1;
                }
            }
            break;

        case KING:
            // Check if the king is moving one square in any direction
            if(abs(m.start_row - m.end_row) <= 1 && abs(m.start_col - m.end_col) <= 1) {
                return 1;
            }
            break;

        default:
            break;
    }

    return 0;
}

// Function to make a move on the chess board
int move_piece(move m) {
    // Check if the move is valid
    if(!is_valid_move(m)) {
        return 0;
    }

    // Move the piece to the new location
    g_board.squares[m.end_row][m.end_col] = g_board.squares[m.start_row][m.start_col];
    g_board.squares[m.start_row][m.start_col] = (piece) {NONE, ' ', 0};

    return 1;
}

// Function to play the game
void play_game() {
    move m;

    // Initialize the board
    init_board();

    // Print the board
    print_board();

    // Make the moves
    do {
        // Get the user's move
        get_move(&m);

        // Make the move
        if(move_piece(m)) {
            // Increment the move counter
            g_move_counter++;

            // Print the board
            print_board();
        }
        else {
            printf("Invalid move. Try again.\n");
        }

    } while((g_move_counter < TOTAL_MOVES) && (g_board.squares[g_board.squares[0][4].type == KING ? 0 : BOARD_SIZE-1][g_board.squares[0][4].type == KING ? 4 : 0].type != KING));
}

// Main function
int main(int argc, char *argv[]) {
    // Play the game
    play_game();

    return 0;
}