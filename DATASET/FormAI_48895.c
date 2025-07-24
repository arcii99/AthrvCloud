//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>

// Define the size of the board
#define SIZE 8

// Define the pieces
#define EMPTY ' '
#define BLACK 'B'
#define WHITE 'W'

// Define the player turn
#define PLAYER1 BLACK
#define PLAYER2 WHITE

// Define the directions for the pieces to move
const int DIRECTIONS[4][2] = {{-1, 1}, {-1, -1}, {1, 1}, {1, -1}};

// Function to print the current board
void print_board(char board[][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// Function to initialize the board
void init_board(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3) {
                board[i][j] = BLACK;
            }
            else if (i > 4) {
                board[i][j] = WHITE;
            }
            else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Function to check if a move is valid
int is_valid_move(char board[][SIZE], int x1, int y1, int x2, int y2, char player) {
    // Check if the move is within the bounds of the board
    if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) return 0;
    
    // Check if the move is not to an already occupied space
    if (board[x2][y2] != EMPTY) return 0;
    
    // Check if the move is diagonal
    if (x1 == x2 || y1 == y2) return 0;
    
    // Check if the piece being moved belongs to the current player
    if (board[x1][y1] != player) return 0;
    
    // Check if the move is a regular move
    if ((x2 - x1 == 1 || x2 - x1 == -1) && (y2 - y1 == 1 || y2 - y1 == -1)) return 1;
    
    // Check if the move is a capture move
    if ((x2 - x1 == 2 || x2 - x1 == -2) && (y2 - y1 == 2 || y2 - y1 == -2)) {
        // Check if there is a piece of the opposite player in between the move
        int xdiff = (x1 < x2) ? 1 : -1;
        int ydiff = (y1 < y2) ? 1 : -1;
        if (board[x1 + xdiff][y1 + ydiff] == player) return 0;
        if (board[x1 + xdiff][y1 + ydiff] == EMPTY) return 0;
        if (board[x1 + 2*xdiff][y1 + 2*ydiff] != EMPTY) return 0;
        return 1;
    }
    
    // Return 0 if the move is not valid by any condition
    return 0;
}

// Function to make a move
void make_move(char board[][SIZE], int x1, int y1, int x2, int y2, char player) {
    // Set the new position to the player's piece
    board[x2][y2] = board[x1][y1];
    
    // Remove the old position
    board[x1][y1] = EMPTY;
    
    // Check if the move is a capture move
    if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2) {
        // Remove the piece of the opposite player
        board[x1 + (x2 - x1)/2][y1 + (y2 - y1)/2] = EMPTY;
    }
}

// Function to check if the game has ended
int is_game_over(char board[][SIZE]) {
    // Check if one of the players has no pieces left
    int player1_count = 0;
    int player2_count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == PLAYER1) player1_count++;
            if (board[i][j] == PLAYER2) player2_count++;
        }
    }
    if (!player1_count || !player2_count) return 1;
    
    // Check if one of the players has no valid moves left
    int player1_moves_left = 0;
    int player2_moves_left = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == PLAYER1) {
                for (int k = 0; k < 4; k++) {
                    if (is_valid_move(board, i, j, i + DIRECTIONS[k][0], j + DIRECTIONS[k][1], PLAYER1)) {
                        player1_moves_left = 1;
                        break;
                    }
                }
            }
            if (board[i][j] == PLAYER2) {
                for (int k = 0; k < 4; k++) {
                    if (is_valid_move(board, i, j, i + DIRECTIONS[k][0], j + DIRECTIONS[k][1], PLAYER2)) {
                        player2_moves_left = 1;
                        break;
                    }
                }
            }
        }
        if (player1_moves_left && player2_moves_left) return 0;
    }
    return 1;
}

int main() {
    // Initialize the variables
    char board[SIZE][SIZE];
    int x1, y1, x2, y2;
    char player = PLAYER1;
    
    // Initialize the board
    init_board(board);
    
    // Loop until the game is over
    while (!is_game_over(board)) {
        // Print the current board
        print_board(board);
        
        // Get the player's move
        printf("Player %c make your move: (x1, y1, x2, y2)\n", player);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        // Check if the move is valid
        if (is_valid_move(board, x1, y1, x2, y2, player)) {
            // Make the move
            make_move(board, x1, y1, x2, y2, player);
            player = (player == PLAYER1) ? PLAYER2 : PLAYER1;
        }
        else {
            printf("Invalid move, please try again.\n");
        }
    }
    
    // Print the final board
    print_board(board);
    
    // Print the winner
    if (!is_game_over(board)) {
        printf("It's a tie!\n");
    }
    else if (!player) {
        printf("Player %c wins!\n", PLAYER2);
    }
    else {
        printf("Player %c wins!\n", PLAYER1);
    }
    
    return 0;
}