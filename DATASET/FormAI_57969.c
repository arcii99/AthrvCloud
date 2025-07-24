//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>

// Defining constants
#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'

// Function to print the board
void print_board(char board[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initializing the board
    char board[SIZE][SIZE] = {{'_', BLACK, '_', BLACK, '_', BLACK, '_', BLACK},
                              {BLACK, '_', BLACK, '_', BLACK, '_', BLACK, '_'},
                              {'_', BLACK, '_', BLACK, '_', BLACK, '_', BLACK},
                              {'_', '_', '_', '_', '_', '_', '_', '_'},
                              {'_', '_', '_', '_', '_', '_', '_', '_'},
                              {WHITE, '_', WHITE, '_', WHITE, '_', WHITE, '_'},
                              {'_', WHITE, '_', WHITE, '_', WHITE, '_', WHITE},
                              {WHITE, '_', WHITE, '_', WHITE, '_', WHITE, '_'}};
    int turn = 0;
    int x1, y1, x2, y2;

    // Printing the initial board
    printf("Initial board:\n");
    print_board(board);

    // Game loop
    while(1) {
        // Getting input from the user
        if(turn % 2 == 0) {
            printf("\nBlack's turn.\n");
        }
        else {
            printf("\nWhite's turn.\n");
        }
        printf("Enter the coordinates of the piece you want to move (row, column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the destination (row, column): ");
        scanf("%d %d", &x2, &y2);

        // Checking if the move is valid
        if(board[x1][y1] == '_' || board[x2][y2] != '_') {
            printf("\nInvalid move. Please try again.\n");
            continue;
        }
        if(turn % 2 == 0) {
            if(board[x1][y1] != BLACK && board[x1][y1] != 'K') {
                printf("\nInvalid move. Please try again.\n");
                continue;
            }
            if(x2 >= x1 || abs(x2-x1) != abs(y2-y1)) {
                printf("\nInvalid move. Please try again.\n");
                continue;
            }
            if(abs(x2-x1) == 1 && abs(y2-y1) == 1) {
                board[x2][y2] = board[x1][y1];
                board[x1][y1] = '_';
            }
            else if(abs(x2-x1) == 2 && abs(y2-y1) == 2) {
                int dx = (x2-x1) / 2;
                int dy = (y2-y1) / 2;
                if(board[x1+dx][y1+dy] == '_' || board[x1+dx][y1+dy] == BLACK) {
                    printf("\nInvalid move. Please try again.\n");
                    continue;
                }
                else {
                    board[x2][y2] = board[x1][y1];
                    board[x1][y1] = '_';
                    board[x1+dx][y1+dy] = '_';
                }
            }
            if(x2 == 0) {
                board[x2][y2] = 'K';
            }
        }
        else {
            if(board[x1][y1] != WHITE && board[x1][y1] != 'K') {
                printf("\nInvalid move. Please try again.\n");
                continue;
            }
            if(x2 <= x1 || abs(x2-x1) != abs(y2-y1)) {
                printf("\nInvalid move. Please try again.\n");
                continue;
            }
            if(abs(x2-x1) == 1 && abs(y2-y1) == 1) {
                board[x2][y2] = board[x1][y1];
                board[x1][y1] = '_';
            }
            else if(abs(x2-x1) == 2 && abs(y2-y1) == 2) {
                int dx = (x2-x1) / 2;
                int dy = (y2-y1) / 2;
                if(board[x1+dx][y1+dy] == '_' || board[x1+dx][y1+dy] == WHITE) {
                    printf("\nInvalid move. Please try again.\n");
                    continue;
                }
                else {
                    board[x2][y2] = board[x1][y1];
                    board[x1][y1] = '_';
                    board[x1+dx][y1+dy] = '_';
                }
            }
            if(x2 == 7) {
                board[x2][y2] = 'K';
            }
        }

        // Printing the updated board
        printf("\nUpdated board:\n");
        print_board(board);

        // Checking if the game is over
        int i, j, black_pieces = 0, white_pieces = 0;
        for(i = 0; i < SIZE; i++) {
            for(j = 0; j < SIZE; j++) {
                if(board[i][j] == BLACK || board[i][j] == 'K') {
                    black_pieces++;
                }
                else if(board[i][j] == WHITE || board[i][j] == 'K') {
                    white_pieces++;
                }
            }
        }
        if(black_pieces == 0) {
            printf("\nWhite wins!\n");
            break;
        }
        else if(white_pieces == 0) {
            printf("\nBlack wins!\n");
            break;
        }

        turn++;
    }

    return 0;
}