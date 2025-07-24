//FormAI DATASET v1.0 Category: Chess engine ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define BLACK 1

// Global variables
int side = WHITE; // side to move
int board[8][8] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1}
};

// Function prototypes
void printBoard();
void move(char*);
void switchSide();

int main() {
    // Print initial board
    printBoard();

    // Loop to input moves
    char input[6];
    while (1) {
        printf("Enter move: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) { // quit game
            printf("Quitting game...\n");
            return 0;
        }

        move(input);
        switchSide();
        printBoard();
    }

    return 0;
}

// Print the current state of the board
void printBoard() {
    printf("\n   A B C D E F G H\n");
    printf("  -----------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d|", 8-i);
        for (int j = 0; j < 8; j++) {
            switch (board[i][j]) {
                case -6: printf("P|"); break;
                case -5: printf("N|"); break;
                case -4: printf("B|"); break;
                case -3: printf("R|"); break;
                case -2: printf("Q|"); break;
                case -1: printf("K|"); break;
                case 0: printf(" |"); break;
                case 1: printf("k|"); break;
                case 2: printf("q|"); break;
                case 3: printf("r|"); break;
                case 4: printf("b|"); break;
                case 5: printf("n|"); break;
                case 6: printf("p|"); break;
            }
        }
        printf(" %d\n", 8-i);
    }
    printf("  -----------------\n");
    printf("   A B C D E F G H\n");
}

// Update board state based on move input
void move(char* input) {
    // Convert input to coordinates
    int fromRow = 8 - (input[1] - '0');
    int fromCol = input[0] - 'a';
    int toRow = 8 - (input[3] - '0');
    int toCol = input[2] - 'a';

    // Move piece to new position
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = 0;
}

// Switch side to move
void switchSide() {
    if (side == WHITE) side = BLACK;
    else side = WHITE;
}