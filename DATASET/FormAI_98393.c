//FormAI DATASET v1.0 Category: Chess engine ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the move is valid or not
int isMoveValid(char board[8][8], int x1, int y1, int x2, int y2) {

    // Check if the piece selected is in the boundary of board
    if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > 7 || y1 > 7 || x2 > 7 || y2 > 7)
        return 0;

    // Check if the destination is same as starting position
    if(x1 == x2 && y1 == y2)
        return 0;

    // Check if the piece at starting position is not empty
    if(board[x1][y1] == '_')
        return 0;

    // Check if the piece at destination is empty or opposing team's piece
    if(board[x2][y2] != '_' && board[x1][y1] % 32 == board[x2][y2] % 32)
        return 0;

    // Check if the move is valid based on the type of piece
    switch(board[x1][y1]) {

        case 'P':
        case 'p': {
            if(board[x1][y1] == 'P' && x2 == x1 + 1 && y2 == y1 && board[x2][y2] == '_')
                return 1;
            else if(board[x1][y1] == 'p' && x2 == x1 - 1 && y2 == y1 && board[x2][y2] == '_')
                return 1;
            else if(board[x1][y1] == 'P' && x2 == x1 + 2 && y2 == y1 && x1 == 1 && board[x2][y2] == '_' && board[x1+1][y1] == '_')
                return 1;
            else if(board[x1][y1] == 'p' && x2 == x1 - 2 && y2 == y1 && x1 == 6 && board[x2][y2] == '_' && board[x1-1][y1] == '_')
                return 1;
            else if(board[x1][y1] == 'P' && x2 == x1 + 1 && (y2 == y1 + 1 || y2 == y1 - 1) && board[x2][y2] != '_')
                return 1;
            else if(board[x1][y1] == 'p' && x2 == x1 - 1 && (y2 == y1 + 1 || y2 == y1 - 1) && board[x2][y2] != '_')
                return 1;
            else
                return 0;
        }

        case 'R':
        case 'r': {
            if(x1 == x2)
            {
                if(y2 > y1) {
                    for(int i = y1+1; i < y2; i++) {
                        if(board[x1][i] != '_')
                            return 0;
                    }
                    return 1;
                }
                else {
                    for(int i = y1-1; i > y2; i--) {
                        if(board[x1][i] != '_')
                            return 0;
                    }
                    return 1;   
                }
            }
            else if(y1 == y2)
            {
                if(x2 > x1) {
                    for(int i = x1+1; i < x2; i++) {
                        if(board[i][y1] != '_')
                            return 0;
                    }
                    return 1;
                }
                else {
                    for(int i = x1-1; i > x2; i--) {
                        if(board[i][y1] != '_')
                            return 0;
                    }
                    return 1;   
                }
            }
            else
                return 0;
        }

        case 'N':
        case 'n': {
            if((x2 == x1+1 && y2 == y1+2) || 
               (x2 == x1+2 && y2 == y1+1) || 
               (x2 == x1+2 && y2 == y1-1) || 
               (x2 == x1+1 && y2 == y1-2) || 
               (x2 == x1-1 && y2 == y1-2) || 
               (x2 == x1-2 && y2 == y1-1) || 
               (x2 == x1-2 && y2 == y1+1) || 
               (x2 == x1-1 && y2 == y1+2))
               return 1;
            else
               return 0;
        }

        case 'B':
        case 'b': {
            if(x2 - x1 == y2 - y1 || x2 - x1 == y1 - y2)
            {
                if(x2 > x1 && y2 > y1) {
                    for(int i = x1+1, j = y1+1; i < x2 && j < y2; i++, j++) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
                else if(x2 > x1 && y2 < y1) {
                    for(int i = x1+1, j = y1-1; i < x2 && j > y2; i++, j--) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
                else if(x2 < x1 && y2 > y1) {
                    for(int i = x1-1, j = y1+1; i > x2 && j < y2; i--, j++) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
                else {
                    for(int i = x1-1, j = y1-1; i > x2 && j > y2; i--, j--) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
            }
            else
                return 0;
        }

        case 'Q':
        case 'q': {
            // Check if the move is valid based on Bishop rules
            if(x2 - x1 == y2 - y1 || x2 - x1 == y1 - y2)
            {
                if(x2 > x1 && y2 > y1) {
                    for(int i = x1+1, j = y1+1; i < x2 && j < y2; i++, j++) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
                else if(x2 > x1 && y2 < y1) {
                    for(int i = x1+1, j = y1-1; i < x2 && j > y2; i++, j--) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
                else if(x2 < x1 && y2 > y1) {
                    for(int i = x1-1, j = y1+1; i > x2 && j < y2; i--, j++) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
                else {
                    for(int i = x1-1, j = y1-1; i > x2 && j > y2; i--, j--) {
                        if(board[i][j] != '_')
                            return 0;
                    }
                    return 1;
                }
            }
            // Check if the move is valid based on Rook rules
            else if(x1 == x2)
            {
                if(y2 > y1) {
                    for(int i = y1+1; i < y2; i++) {
                        if(board[x1][i] != '_')
                            return 0;
                    }
                    return 1;
                }
                else {
                    for(int i = y1-1; i > y2; i--) {
                        if(board[x1][i] != '_')
                            return 0;
                    }
                    return 1;   
                }
            }
            else if(y1 == y2)
            {
                if(x2 > x1) {
                    for(int i = x1+1; i < x2; i++) {
                        if(board[i][y1] != '_')
                            return 0;
                    }
                    return 1;
                }
                else {
                    for(int i = x1-1; i > x2; i--) {
                        if(board[i][y1] != '_')
                            return 0;
                    }
                    return 1;   
                }
            }
            else
                return 0;
        }

        case 'K':
        case 'k': {
            if((x2 == x1+1 && y2 == y1) || 
               (x2 == x1+1 && y2 == y1+1) || 
               (x2 == x1 && y2 == y1+1) || 
               (x2 == x1-1 && y2 == y1+1) || 
               (x2 == x1-1 && y2 == y1) || 
               (x2 == x1-1 && y2 == y1-1) || 
               (x2 == x1 && y2 == y1-1) || 
               (x2 == x1+1 && y2 == y1-1))
               return 1;
            else
               return 0;
        }

        default:
            return 0;
    }
}

// Function to print the board
void printBoard(char board[8][8]) {

    printf("  1  2  3  4  5  6  7  8\n\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < 8; j++) {
            printf("%c  ", board[i][j]);
        }
        printf(" %d\n", i+1);
    }
    printf("\n  1  2  3  4  5  6  7  8\n");
}

int main()
{
    char board[8][8] =
    {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    printBoard(board);
    printf("\n\n");

    while(1) {

        int x1, y1, x2, y2;

        printf("Enter starting position of piece to move: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter ending position of piece to move: ");
        scanf("%d %d", &x2, &y2);

        if(isMoveValid(board, x1-1, y1-1, x2-1, y2-1)) {
            board[x2-1][y2-1] = board[x1-1][y1-1];
            board[x1-1][y1-1] = '_';
            printBoard(board);

            // Check if the move results in a win
            if(board[x2-1][y2-1] == 'k' || board[x2-1][y2-1] == 'K') {
                printf("\nCongratulations! You won!\n");
                break;
            }
        }
        else {
            printf("\nInvalid move. Try again.\n\n");
        }
    }

    return 0;
}