//FormAI DATASET v1.0 Category: Checkers Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h> 

#define BOARDSIZE 8

int main(void) {

    // Initialize the Checker Board
    char board[BOARDSIZE][BOARDSIZE] = {
        {'_', 'r', '_', 'r', '_', 'r', '_', 'r'},
        {'r', '_', 'r', '_', 'r', '_', 'r', '_'},
        {'_', 'r', '_', 'r', '_', 'r', '_', 'r'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
        {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
        {'b', '_', 'b', '_', 'b', '_', 'b', '_'}
    };

    // Display the Initial Checker Board
    printf("Starting Board:\n");
    for(int i = 0; i < BOARDSIZE; i++) {
        for(int j = 0; j < BOARDSIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Game Loop
    while(1) {
        int row, col, dest_row, dest_col;
        char piece;

        // Prompt for User Input
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row, &col);
        getchar();
        piece = board[row][col];

        // Validate Input
        if(piece == '_') {
            printf("Invalid move. Please select a valid piece.\n");
            continue;
        }

        // Prompt for Destination
        printf("Enter the destination row and column: ");
        scanf("%d %d", &dest_row, &dest_col);
        getchar();

        // Check if Destination is Valid
        if(board[dest_row][dest_col] != '_' || (dest_row + dest_col) % 2 == 0) {
            printf("Invalid move. Please select a valid destination.\n");
            continue;
        }

        // Check if Move is a Jump
        if(abs(dest_row-row) == 2) {
            int jump_row = (row+dest_row)/2;
            int jump_col = (col+dest_col)/2;
            if(piece == 'r' && board[jump_row][jump_col] == 'b') {
                board[jump_row][jump_col] = '_';
            } else if(piece == 'b' && board[jump_row][jump_col] == 'r') {
                board[jump_row][jump_col] = '_';
            } else {
                printf("Invalid move. Please select a valid destination.\n");
                continue;
            }
        }

        // Move the Piece
        board[dest_row][dest_col] = piece;
        board[row][col] = '_';

        // Check for Game Over
        int red_count = 0, black_count = 0;
        for(int i = 0; i < BOARDSIZE; i++) {
            for(int j = 0; j < BOARDSIZE; j++) {
                if(board[i][j] == 'r' || board[i][j] == 'R') {
                    red_count++;
                } else if(board[i][j] == 'b' || board[i][j] == 'B') {
                    black_count++;
                }
            }
        }

        if(red_count == 0) {
            printf("Black wins!\n");
            break;
        } else if(black_count == 0) {
            printf("Red wins!\n");
            break;
        }

        // Display the Checker Board
        printf("\nChecker Board:\n");
        for(int i = 0; i < BOARDSIZE; i++) {
            for(int j = 0; j < BOARDSIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}