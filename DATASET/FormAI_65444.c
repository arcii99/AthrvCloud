//FormAI DATASET v1.0 Category: Checkers Game ; Style: Sherlock Holmes
#include <stdio.h>

void printBoard(char board[][8]){
    printf("  _________________\n");
    for (int i=0; i<8; i++){
        printf("%d| ", i+1);
        for (int j=0; j<8; j++){
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  |A B C D E F G H |\n");
    printf("  -----------------\n");
}

int movePiece(char board[][8], int pieceRow, int pieceCol, int destRow, int destCol){
    int diffRow = destRow - pieceRow;
    int diffCol = destCol - pieceCol;

    if (board[destRow][destCol] == ' ' && diffRow == 0 && diffCol == 0){
        printf("Cannot move to the same location!\n");
        return -1;
    }

    if (board[pieceRow][pieceCol] == ' ' || board[pieceRow][pieceCol] == '_'){
        printf("There is no piece at this location!\n");
        return -1;
    }

    if (destRow < 0 || destRow > 7 || destCol < 0 || destCol > 7){
        printf("Invalid move, out of bounds!\n");
        return -1;
    }

    if (board[destRow][destCol] != ' '){
        printf("Invalid move, the destination is not empty!\n");
        return -1;
    }

    if (abs(diffRow) != abs(diffCol)){
        printf("Invalid move, you can only move diagonally!\n");
        return -1;
    }

    if (board[pieceRow][pieceCol] == 'B'){
        if (diffRow > 0){
            printf("Invalid move for the Black piece!\n");
            return -1;
        }
        if (abs(diffRow) == 1 && abs(diffCol) == 1){
            board[pieceRow][pieceCol] = ' ';
            board[destRow][destCol] = 'B';
        }
        else if (abs(diffRow) == 2 && abs(diffCol) == 2 && board[pieceRow+1][pieceCol+1] != ' '){
            board[pieceRow][pieceCol] = ' ';
            board[pieceRow+1][pieceCol+1] = ' ';
            board[destRow][destCol] = 'B';
        }
        else{
            printf("Invalid move for the Black piece!\n");
            return -1;
        }
    }

    if (board[pieceRow][pieceCol] == 'W'){
        if (diffRow < 0){
            printf("Invalid move for the White piece!\n");
            return -1;
        }
        if (abs(diffRow) == 1 && abs(diffCol) == 1){
            board[pieceRow][pieceCol] = ' ';
            board[destRow][destCol] = 'W';
        }
        else if (abs(diffRow) == 2 && abs(diffCol) == 2 && board[pieceRow-1][pieceCol+1] != ' '){
            board[pieceRow][pieceCol] = ' ';
            board[pieceRow-1][pieceCol+1] = ' ';
            board[destRow][destCol] = 'W';
        }
        else{
            printf("Invalid move for the White piece!\n");
            return -1;
        }
    }

    return 0;
}

int main(){
    char board[8][8] = {
        {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
        {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
        {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
        {'_', ' ', '_', ' ', '_', ' ', '_', ' '},
        {' ', '_', ' ', '_', ' ', '_', ' ', '_'},
        {'W', ' ', 'W', ' ', 'W', ' ', 'W', ' '},
        {' ', 'W', ' ', 'W', ' ', 'W', ' ', 'W'},
        {'W', ' ', 'W', ' ', 'W', ' ', 'W', ' '}
    };

    printf("Welcome to the Checkers game, my dear Watson!\n");
    printf("The game board is as follows, with Black (B) and White (W) pieces:\n");
    printBoard(board);

    int currentPlayer = 0;
    char currentPiece;
    int pieceRow, pieceCol, destRow, destCol;

    while(1){
        if (currentPlayer % 2 == 0){
            printf("It is Black's turn!\n");
            currentPiece = 'B';
        }
        else{
            printf("It is White's turn!\n");
            currentPiece = 'W';
        }

        printf("Select the piece you want to move, by typing the row and column (e.g. 2B): ");
        scanf("%d %c", &pieceRow, &pieceCol);
        pieceRow--;
        pieceCol = pieceCol - 65;

        printf("Select the destination you want to move to, by typing the row and column (e.g. 4D): ");
        scanf("%d %c", &destRow, &destCol);
        destRow--;
        destCol = destCol - 65;

        if (movePiece(board, pieceRow, pieceCol, destRow, destCol) == 0){
            currentPlayer++;
            printf("The board after the move is:\n");
            printBoard(board);

            for (int i=0; i<8; i++){
                for (int j=0; j<8; j++){
                    if (board[i][j] == 'B'){
                        if (i == 7){
                            printf("Black wins!\n");
                            return 0;
                        }
                    }
                    else if (board[i][j] == 'W'){
                        if (i == 0){
                            printf("White wins!\n");
                            return 0;
                        }
                    }
                }
            }
        }

    }

    return 0;
}