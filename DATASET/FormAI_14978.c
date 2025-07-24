//FormAI DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define CHESS_BOARD_SIZE 8

char chess_board[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE]; // The matrix representation of the chess board

// Initialize the chess board with starting position of the checkers
void init_chess_board() {
    // Initialize the empty cells with '-'
    for(int i=0; i<CHESS_BOARD_SIZE; i++) {
        for(int j=0; j<CHESS_BOARD_SIZE; j++) {
            chess_board[i][j] = '-';
        }
    }

    // Initialize the black checkers with 'b'
    for(int i=0; i<3; i++) {
        for(int j=0; j<CHESS_BOARD_SIZE; j+=2) {
            if((i%2) == 0) {
                chess_board[i][j+1] = 'b';
            } else {
                chess_board[i][j] = 'b';
            }
        }
    }

    // Initialize the red checkers with 'r'
    for(int i=CHESS_BOARD_SIZE-3; i<CHESS_BOARD_SIZE; i++) {
        for(int j=0; j<CHESS_BOARD_SIZE; j+=2) {
            if((i%2) == 0) {
                chess_board[i][j+1] = 'r';
            } else {
                chess_board[i][j] = 'r';
            }
        }
    }
}

// Print the chess board with current checker positions
void print_chess_board() {
    printf(" ");
    for(int i=0; i<CHESS_BOARD_SIZE; i++) {
        printf(" %c", 'A'+i);
    }
    printf("\n");

    for(int i=0; i<CHESS_BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j=0; j<CHESS_BOARD_SIZE; j++) {
            printf("%c ", chess_board[i][j]);
        }
        printf("%d", i+1);
        printf("\n");
    }

    printf(" ");
    for(int i=0; i<CHESS_BOARD_SIZE; i++) {
        printf(" %c", 'A'+i);
    }
    printf("\n");
}

int main() {
    printf("Welcome to My Checkers Game!\n");
    printf("Let's start by initializing the chess board...\n\n");

    init_chess_board(); // Initialize the chess board with the starting position of the checkers

    printf("The chess board has been initialized with the starting position of the checkers: \n\n");
    print_chess_board(); // Print the chess board with the current checker positions

    // TODO: Implement the game logic and user input/output accordingly

    return 0;
}