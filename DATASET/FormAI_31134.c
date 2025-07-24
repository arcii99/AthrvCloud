//FormAI DATASET v1.0 Category: Chess AI ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8

// Initialize the board to the starting position
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    char pieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};

    // Set up the black pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[0][i] = pieces[i];
        board[1][i] = 'p';
    }

    // Set up the white pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = 'P';
        board[7][i] = pieces[i] - 32;
    }

    // Fill the rest of the board with empty spaces
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Check if a move is valid or not
bool is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int xi, int yi, int xf, int yf) {
    // Check if the initial position is within the bounds of the board
    if (xi < 0 || xi >= BOARD_SIZE || yi < 0 || yi >= BOARD_SIZE) {
        return false;
    }

    // Check if the final position is within the bounds of the board
    if (xf < 0 || xf >= BOARD_SIZE || yf < 0 || yf >= BOARD_SIZE) {
        return false;
    }

    // Check if the initial and final positions are the same
    if (xi == xf && yi == yf) {
        return false;
    }

    // Check if the piece at the initial position is the same color as the one making the move
    char piece = board[xi][yi];
    if (piece >= 'a' && piece <= 'z' && xf > xi) { // black
        return false;
    } else if (piece >= 'A' && piece <= 'Z' && xf < xi) { // white
        return false;
    }

    // Check if the final position is occupied by a piece of the same color
    char dest_piece = board[xf][yf];
    if (piece >= 'a' && piece <= 'z' && dest_piece >= 'a' && dest_piece <= 'z') { // same color black
        return false;
    } else if (piece >= 'A' && piece <= 'Z' && dest_piece >= 'A' && dest_piece <= 'Z') { // same color white
        return false;
    }

    // Check if the move is legal for the given piece type
    switch (piece) {
        case 'p':
        case 'P':
            if (xi == xf) { // pawn cannot move horizontally
                return false;
            } else if (piece == 'p') { // black pawn
                if (xi != 1 && xi - xf != 1) { // can only move one space forward unless on starting rank
                    return false;
                }
                if ((yf - yi != 1 && yf - yi != -1) || (yf == yi)) { // can only move diagonally to capture
                    return false;
                }
                if (dest_piece == ' ') { // pawn cannot move diagonally if no piece to capture
                    return false;
                }
            } else { // white pawn
                if (xi != 6 && xf - xi != 1) {
                    return false;
                }
                if ((yf - yi != 1 && yf - yi != -1) || (yf == yi)) {
                    return false;
                }
                if (dest_piece == ' ') {
                    return false;
                }
            }
            break;
        case 'r':
        case 'R':
            if (xi != xf && yi != yf) { // rook cannot move diagonally
                return false;
            }
            if (xi == xf) { // moving vertically
                int min_y = yi < yf ? yi : yf;
                int max_y = yi > yf ? yi : yf;
                for (int i = min_y + 1; i < max_y; i++) { // check for pieces in the way
                    if (board[xi][i] != ' ') {
                        return false;
                    }
                }
            } else { // moving horizontally
                int min_x = xi < xf ? xi : xf;
                int max_x = xi > xf ? xi : xf;
                for (int i = min_x + 1; i < max_x; i++) { // check for pieces in the way
                    if (board[i][yi] != ' ') {
                        return false;
                    }
                }
            }
            break;
        // TODO: implement logic for other piece types
        default:
            return false;
    }

    return true;
}

// Print the current state of the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("  a b c d e f g h\n");
}

// Get the move from the user
void get_move(int *xi, int *yi, int *xf, int *yf) {
    printf("Enter your move (e.g. 'd2 d4'): ");
    char input[6];
    scanf("%s", input);
    *yi = input[0] - 'a';
    *xi = BOARD_SIZE - (input[1] - '0');
    *yf = input[3] - 'a';
    *xf = BOARD_SIZE - (input[4] - '0');
}

// Generate a random move for the AI to make
void ai_move(char board[BOARD_SIZE][BOARD_SIZE], int *xi, int *yi, int *xf, int *yf) {
    // Generate a random position to move from
    *xi = rand() % BOARD_SIZE;
    *yi = rand() % BOARD_SIZE;

    // Find a legal position to move to from the randomly selected initial position
    while (true) {
        *xf = rand() % BOARD_SIZE;
        *yf = rand() % BOARD_SIZE;

        if (is_valid_move(board, *xi, *yi, *xf, *yf)) {
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);

    // Game loop
    while (true) {
        print_board(board);
        printf("AI's turn:\n");
        int ai_xi, ai_yi, ai_xf, ai_yf;
        ai_move(board, &ai_xi, &ai_yi, &ai_xf, &ai_yf);
        printf("AI moves %c%dc%d to %c%dc%d\n", 'a' + ai_yi, BOARD_SIZE - ai_xi, 'a' + ai_yf, BOARD_SIZE - ai_xf);
        board[ai_xf][ai_yf] = board[ai_xi][ai_yi]; // move the piece
        board[ai_xi][ai_yi] = ' '; // clear the initial position
        print_board(board);
        int player_xi, player_yi, player_xf, player_yf;
        get_move(&player_xi, &player_yi, &player_xf, &player_yf);
        printf("You move %c%dc%d to %c%dc%d\n", 'a' + player_yi, BOARD_SIZE - player_xi, 'a' + player_yf, BOARD_SIZE - player_xf);
        board[player_xf][player_yf] = board[player_xi][player_yi];
        board[player_xi][player_yi] = ' ';
    }

    return 0;
}