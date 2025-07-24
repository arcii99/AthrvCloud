//FormAI DATASET v1.0 Category: Checkers Game ; Style: futuristic
#include <stdio.h>

// Function to display the checkers board
void displayBoard(char board[][8]) {
    printf("\n  1 2 3 4 5 6 7 8\n");
    printf(" +---------------+\n");
    for(int i = 0; i < 8; i++) {
        printf("%c| ", i+'A');
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +---------------+\n");
}

// Function to initialize the checkers board with pieces
void initializeBoard(char board[][8]) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i < 3 && (i+j)%2 == 0) {
                board[i][j] = 'B'; // Black piece
            }
            else if(i > 4 && (i+j)%2 == 0) {
                board[i][j] = 'W'; // White piece
            }
            else {
                board[i][j] = ' '; // Empty square
            }
        }
    }
}

int main() {
    char board[8][8];
    initializeBoard(board);
    displayBoard(board);
    return 0;
}