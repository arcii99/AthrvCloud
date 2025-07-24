//FormAI DATASET v1.0 Category: Chess AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

/* Global variable declarations */
char board[BOARD_SIZE][BOARD_SIZE];

/* Function to print the chess board */
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* Function to initialize the chess board */
void init_board() {
    // Initializing pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P'; // White pawns
        board[6][i] = 'p'; // Black pawns
    }
    
    // Initializing rooks
    board[0][0] = 'R';
    board[0][7] = 'R';
    board[7][0] = 'r';
    board[7][7] = 'r';

    // Initializing knights
    board[0][1] = 'N';
    board[0][6] = 'N';
    board[7][1] = 'n';
    board[7][6] = 'n';

    // Initializing bishops
    board[0][2] = 'B';
    board[0][5] = 'B';
    board[7][2] = 'b';
    board[7][5] = 'b';

    // Initializing queens
    board[0][3] = 'Q';
    board[7][3] = 'q';

    // Initializing kings
    board[0][4] = 'K';
    board[7][4] = 'k';

    // Initializing empty squares
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

/* Function to move the piece on the board */
void move_piece(int from_x, int from_y, int to_x, int to_y) {
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = ' ';
}

/* Function to check if the move is valid */
int is_valid_move(int from_x, int from_y, int to_x, int to_y) {
    if (board[from_x][from_y] == 'P') { // White pawn
        if (to_x == from_x-1 && to_y == from_y) return 1; // One square forward
        else if (from_x == 6 && to_x == from_x-2 && to_y == from_y) return 1; // Two squares forward on first move
        else return 0; // Invalid move
    }
    else if (board[from_x][from_y] == 'p') { // Black pawn
        if (to_x == from_x+1 && to_y == from_y) return 1; // One square forward
        else if (from_x == 1 && to_x == from_x+2 && to_y == from_y) return 1; // Two squares forward on first move
        else return 0; // Invalid move
    }
    else if (board[from_x][from_y] == 'R' || board[from_x][from_y] == 'r') { // Rook
        if (from_x == to_x || from_y == to_y) return 1; // Moving straight along row or column
        else return 0; // Invalid move
    }
    else if (board[from_x][from_y] == 'N' || board[from_x][from_y] == 'n') { // Knight
        int dx = abs(to_x-from_x);
        int dy = abs(to_y-from_y);
        if (dx == 2 && dy == 1 || dx == 1 && dy == 2) return 1; // Valid knight move
        else return 0; // Invalid move
    }
    else if (board[from_x][from_y] == 'B' || board[from_x][from_y] == 'b') { // Bishop
        if (abs(to_x-from_x) == abs(to_y-from_y)) return 1; // Valid bishop move
        else return 0; // Invalid move
    }
    else if (board[from_x][from_y] == 'Q' || board[from_x][from_y] == 'q') { // Queen
        if (from_x == to_x || from_y == to_y || abs(to_x-from_x) == abs(to_y-from_y)) return 1; // Valid queen move
        else return 0; // Invalid move
    }
    else if (board[from_x][from_y] == 'K' || board[from_x][from_y] == 'k') { // King
        int dx = abs(to_x-from_x);
        int dy = abs(to_y-from_y);
        if (dx <= 1 && dy <=1) return 1; // Valid king move (one square in any direction)
        else return 0; // Invalid move
    }
    else {
        return 0; // Invalid move for any other pieces
    }
}

/* Function to make a move randomly */
void make_random_move(char player) {
    int from_x, from_y, to_x, to_y;
    
    do {
        // Generate random source and destination squares
        from_x = rand() % BOARD_SIZE;
        from_y = rand() % BOARD_SIZE;
        to_x = rand() % BOARD_SIZE;
        to_y = rand() % BOARD_SIZE;
    } while (board[from_x][from_y] == ' ' || board[from_x][from_y] == 'K' || board[from_x][from_y] == 'k'
            || (player == 'w' && board[from_x][from_y] >= 'a' && board[from_x][from_y] <= 'z')
            || (player == 'b' && board[from_x][from_y] >= 'A' && board[from_x][from_y] <= 'Z')
            || !is_valid_move(from_x, from_y, to_x, to_y));

    printf("%c %d %d %d %d\n", player, from_x, from_y, to_x, to_y);
    move_piece(from_x, from_y, to_x, to_y);
}

int main() {
    // Seeding the random number generator
    srand(time(NULL));

    // Initializing the chess board
    init_board();

    // Printing the initial board state
    print_board();

    // Starting the game loop
    char player = 'w';

    while (1) {
        printf("Player %c's turn\n", player);
        make_random_move(player);

        // Printing the current board state after the move
        print_board();

        // Switching to the other player's turn
        if (player == 'w') player = 'b';
        else player = 'w';
    }

    return 0;
}