//FormAI DATASET v1.0 Category: Chess AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

/* Chess board with 0 as empty and a positive/negative number representing the pieces. */
int board[8][8] = { {-2, -3, -4, -5, -6, -4, -3, -2},
                    {-1, -1, -1, -1, -1, -1, -1, -1},
                    { 0,  0,  0,  0,  0,  0,  0,  0},
                    { 0,  0,  0,  0,  0,  0,  0,  0},
                    { 0,  0,  0,  0,  0,  0,  0,  0},
                    { 0,  0,  0,  0,  0,  0,  0,  0},
                    { 1,  1,  1,  1,  1,  1,  1,  1},
                    { 2,  3,  4,  5,  6,  4,  3,  2} };

/* function to print the chess board */
void printBoard() {

    printf("\n  A B C D E F G H\n");
    for (int row = 0; row < 8; row++) {
        printf("%d ", 8 - row);
        for (int col = 0; col < 8; col++) {
            switch (board[row][col]) {
            case -1:
                printf("♟︎ ");
                break;
            case -2:
                printf("♜︎ ");
                break;
            case -3:
                printf("♞ ");
                break;
            case -4:
                printf("♝︎ ");
                break;
            case -5:
                printf("♛︎ ");
                break;
            case -6:
                printf("♚ ");
                break;
            case 0:
                printf(". ");
                break;
            case 1:
                printf("♙︎ ");
                break;
            case 2:
                printf("♖︎ ");
                break;
            case 3:
                printf("♘︎ ");
                break;
            case 4:
                printf("♗︎ ");
                break;
            case 5:
                printf("♕︎ ");
                break;
            case 6:
                printf("♔︎ ");
                break;
            }
        }
        printf("%d\n", 8 - row);
    }
    printf("  A B C D E F G H\n\n");
}

int main() {

    int gameEnded = 0, turn = 0;
    while (!gameEnded) {
        turn++;

        // print the board after each turn
        printBoard();

        // get user input for move
        char input[6];
        printf("Player %d's turn (Enter move in algebraic notation): ", turn % 2 + 1);
        scanf("%s", &input);

        // move the piece on the board
        // TODO: add logic for checking valid moves and checking if the game has ended
    }

    return 0;
}