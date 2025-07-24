//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int main() {

    char board[SIZE][SIZE] = {0};  // Initialize all values to 0
    char guess[2];
    int turn = 1, score = 0;
    int r1, c1, r2, c2;

    srand(time(NULL));  // Initialize the random number generator

    // Initialize the board with random letters
    for (int i = 0; i < SIZE*SIZE/2; i++) {
        char letter = 'A' + i;
        for (int j = 0; j < 2; j++) {
            int row, col;
            do {
                row = rand() % SIZE;
                col = rand() % SIZE;
            } while (board[row][col] != 0);
            board[row][col] = letter;
        }
    }

    // Main game loop
    while (1) {
        // Display the current board
        printf("\nTurn %d\nScore: %d\n", turn, score);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 0)
                    printf("  ");
                else if (board[i][j] == '*')
                    printf("* ");
                else
                    printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Get user input
        printf("Enter coordinates of first letter: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter coordinates of second letter: ");
        scanf("%d%d", &r2, &c2);

        // Check the letters at the selected coordinates
        if (board[r1][c1] == 0 || board[r2][c2] == 0) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        else if (r1 == r2 && c1 == c2) {
            printf("You chose the same cell. Try again.\n");
            continue;
        }
        else if (board[r1][c1] != board[r2][c2]) {
            printf("No match. Try again.\n");
            board[r1][c1] = board[r2][c2] = '*';
        }
        else {
            score++;
            board[r1][c1] = board[r2][c2] = 0;
        }

        // Check if the game is over
        int game_over = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != 0) {
                    game_over = 0;
                    break;
                }
            }
            if (!game_over)
                break;
        }
        if (game_over) {
            printf("Congratulations, you win!\n");
            break;
        }

        turn++;
    }

    return 0;
}