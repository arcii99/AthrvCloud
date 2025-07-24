//FormAI DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the board
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Define function to display the board
void display_board() {
    printf("\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Define function to get user input
char* get_input() {
    static char input[256];
    printf("Enter move: ");
    fgets(input, 256, stdin);
    return input;
}

// Define function to convert input to coordinates
int* to_coordinates(char* input) {
    static int coordinates[4];
    // Convert letters to numbers
    coordinates[0] = toupper(input[0]) - 65;
    coordinates[1] = atoi(&input[1]) - 1;
    coordinates[2] = toupper(input[3]) - 65;
    coordinates[3] = atoi(&input[4]) - 1;
    return coordinates;
}

// Define function to move a piece
void move_piece(int from_x, int from_y, int to_x, int to_y) {
    board[to_y][to_x] = board[from_y][from_x];
    board[from_y][from_x] = ' ';
}

// Define function to check if a move is valid
int is_valid_move(int from_x, int from_y, int to_x, int to_y) {
    // Check if piece is being moved to the same position
    if (from_x == to_x && from_y == to_y) {
        printf("Invalid move: piece is not moving.\n");
        return 0;
    }

    // Check if the starting position contains a valid piece
    char piece = board[from_y][from_x];
    if (piece == ' ' || piece == '.') {
        printf("Invalid move: no piece to move.\n");
        return 0;
    }

    // Check if the piece is moving to a valid position
    char to_piece = board[to_y][to_x];
    if (isspace(to_piece)) {
        // Empty space, move is valid
        return 1;
    }
    else if (islower(piece) && isupper(to_piece)) {
        // Piece is moving to a square occupied by an opponent's piece
        return 1;
    }
    else if (isupper(piece) && islower(to_piece)) {
        // Piece is moving to a square occupied by an opponent's piece
        return 1;
    }
    else {
        // Piece is moving to a square occupied by a friendly piece or an invalid square
        printf("Invalid move: piece cannot capture its own pieces.\n");
        return 0;
    }
}

int main() {
    display_board();

    while (1) {
        char* input = get_input();
        int* coordinates = to_coordinates(input);

        if (is_valid_move(coordinates[0], coordinates[1], coordinates[2], coordinates[3])) {
            move_piece(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
            display_board();
        }
    }

    return 0;
}