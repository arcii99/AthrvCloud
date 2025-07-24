//FormAI DATASET v1.0 Category: Chess AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate a random integer between min and max, inclusive
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Struct to represent a chess piece
typedef struct {
    char name; // 'k' for king, 'q' for queen, 'r' for rook, 'b' for bishop, 'n' for knight, 'p' for pawn
    bool is_white; // true if piece is white, false if piece is black
} Piece;

// Function to print the chess board
void print_board(Piece board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].name == '\0') { // empty square
                printf(".");
            } else {
                printf("%c", board[i][j].name);
            }
            printf(" ");
        }
        printf("\n");
    }
}

// Function to setup the chess board with pieces in their starting positions
void setup_board(Piece board[8][8]) {
    // Pawns
    for (int j = 0; j < 8; j++) {
        board[1][j] = (Piece) {'p', false};
        board[6][j] = (Piece) {'p', true};
    }

    // Rooks
    board[0][0] = (Piece) {'r', false};
    board[0][7] = (Piece) {'r', false};
    board[7][0] = (Piece) {'r', true};
    board[7][7] = (Piece) {'r', true};

    // Knights
    board[0][1] = (Piece) {'n', false};
    board[0][6] = (Piece) {'n', false};
    board[7][1] = (Piece) {'n', true};
    board[7][6] = (Piece) {'n', true};

    // Bishops
    board[0][2] = (Piece) {'b', false};
    board[0][5] = (Piece) {'b', false};
    board[7][2] = (Piece) {'b', true};
    board[7][5] = (Piece) {'b', true};

    // Queens
    board[0][3] = (Piece) {'q', false};
    board[7][3] = (Piece) {'q', true};

    // Kings
    board[0][4] = (Piece) {'k', false};
    board[7][4] = (Piece) {'k', true};
}

// Function to check if a move is valid
bool is_valid_move(Piece board[8][8], int from_x, int from_y, int to_x, int to_y) {
    // Make sure piece exists at the starting position
    if (board[from_x][from_y].name == '\0') {
        return false;
    }

    // Make sure piece is not moving to the same square
    if (from_x == to_x && from_y == to_y) {
        return false;
    }

    // Make sure piece is not capturing a friendly piece
    if (board[from_x][from_y].is_white == board[to_x][to_y].is_white && board[to_x][to_y].name != '\0') {
        return false;
    }

    // Move is valid for all pieces except knights if the path to the destination square is obstructed
    if (board[from_x][from_y].name != 'n') {
        int delta_x = to_x - from_x;
        int delta_y = to_y - from_y;
        int x_step = delta_x == 0 ? 0 : delta_x / abs(delta_x);
        int y_step = delta_y == 0 ? 0 : delta_y / abs(delta_y);
        int x = from_x + x_step;
        int y = from_y + y_step;
        while (x != to_x || y != to_y) {
            if (board[x][y].name != '\0') {
                return false;
            }
            x += x_step;
            y += y_step;
        }
    }

    // Move is valid
    return true;
}

// Function to make a move
void make_move(Piece board[8][8], int from_x, int from_y, int to_x, int to_y) {
    // Move piece
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = (Piece) {'\0', false};
}

// Function to randomly choose a valid move for the specified player
void make_random_move(Piece board[8][8], bool is_white) {
    // Find all pieces belonging to the player
    int num_pieces = 0;
    int pieces[16][2];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].is_white == is_white) {
                pieces[num_pieces][0] = i;
                pieces[num_pieces][1] = j;
                num_pieces++;
            }
        }
    }

    // Choose a random piece to move
    int index = rand_range(0, num_pieces - 1);
    int from_x = pieces[index][0];
    int from_y = pieces[index][1];

    // Find all valid moves for the chosen piece
    int num_moves = 0;
    int moves[64][2];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (is_valid_move(board, from_x, from_y, i, j)) {
                moves[num_moves][0] = i;
                moves[num_moves][1] = j;
                num_moves++;
            }
        }
    }

    if (num_moves > 0) {
        // Choose a random move for the chosen piece
        index = rand_range(0, num_moves - 1);
        int to_x = moves[index][0];
        int to_y = moves[index][1];

        // Make the move
        make_move(board, from_x, from_y, to_x, to_y);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Piece board[8][8];
    setup_board(board);

    print_board(board); // Print starting board

    // Make 20 random moves
    for (int i = 0; i < 20; i++) {
        make_random_move(board, i % 2 == 0); // White moves on even turns, black moves on odd turns
        printf("\nMove %d:\n", i + 1);
        print_board(board);
    }

    return 0;
}