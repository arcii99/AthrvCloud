//FormAI DATASET v1.0 Category: Checkers Game ; Style: enthusiastic
#include <stdio.h>

//Function that prints the board of checkers
void printBoard(char board[8][8]) {
    printf("\n    1   2   3   4   5   6   7   8\n");
    printf("   -----------------------------\n");
    for(int i=0; i<8; i++) {
        printf("%d |", i+1);
        for(int j=0; j<8; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  |---|---|---|---|---|---|---|---|\n");
    }
}

//Function that moves a checker piece
void moveChecker(char board[8][8], int currentPlayer) {
    int fromRow, fromCol, toRow, toCol;
    printf("Enter the coordinates of the piece you want to move: ");
    scanf("%d%d", &fromRow, &fromCol);
    printf("Enter the coordinates of the position you want to move the piece to: ");
    scanf("%d%d", &toRow, &toCol);
    //Check if the move is valid
    if(currentPlayer == 1) {
        if(board[fromRow-1][fromCol-1] == 'x' || board[fromRow-1][fromCol-1] == 'X') {
            //If it's the player's turn and they are moving their piece
            if(board[toRow-1][toCol-1] == ' ') {
                //If the move is to an empty space on the board
                board[toRow-1][toCol-1] = board[fromRow-1][fromCol-1];
                board[fromRow-1][fromCol-1] = ' ';
            } else {
                printf("That is not a valid move.\n");
                moveChecker(board, currentPlayer);
            }
        } else {
            printf("That is not your piece to move.\n");
            moveChecker(board, currentPlayer);
        }
    } else {
        if(board[fromRow-1][fromCol-1] == 'o' || board[fromRow-1][fromCol-1] == 'O') {
            //If it's the player's turn and they are moving their piece
            if(board[toRow-1][toCol-1] == ' ') {
                //If the move is to an empty space on the board
                board[toRow-1][toCol-1] = board[fromRow-1][fromCol-1];
                board[fromRow-1][fromCol-1] = ' ';
            } else {
                printf("That is not a valid move.\n");
                moveChecker(board, currentPlayer);
            }
        } else {
            printf("That is not your piece to move.\n");
            moveChecker(board, currentPlayer);
        }
    }
}

int main() {
    char board[8][8] = {
        {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
        {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
        {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '},
        {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
        {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '}
    };
    printf("Welcome to Checkers!\n");
    int currentPlayer = 1;
    while(1) {
        printf("Current Board:\n");
        printBoard(board);
        printf("It's Player %d's turn\n", currentPlayer);
        moveChecker(board, currentPlayer);
        //Check if a player has won
        int playerOnePiecesLeft = 0;
        int playerTwoPiecesLeft = 0;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(board[i][j] == 'x' || board[i][j] == 'X') {
                    playerOnePiecesLeft += 1;
                }
                if(board[i][j] == 'o' || board[i][j] == 'O') {
                    playerTwoPiecesLeft += 1;
                }
            }
        }
        if(playerOnePiecesLeft == 0) {
            printf("Player 2 has won!\n");
            break;
        }
        if(playerTwoPiecesLeft == 0) {
            printf("Player 1 has won!\n");
            break;
        }
        //Switch current player
        if(currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }
    return 0;
}