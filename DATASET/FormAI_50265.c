//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count = 0;
    int row, col, pos, i, j, k;
    char board[3][3], res;
    srand(time(0));
    
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            count++;
            board[i][j] = count + '0';
        }
    }
    
    printf("\n---------------------------------------\n");
    printf("\t   Welcome to C Table Game!\n");
    printf("---------------------------------------\n");
    printf("Instructions:\n");
    printf("1. The game can be played by two players.\n");
    printf("2. The game is played on a 3x3 board.\n");
    printf("3. Player X starts the game.\n");
    printf("4. Players take turns to place their symbol (X or O).\n");
    printf("5. The first player to get three of their symbols in a row (vertically, horizontally, or diagonally) wins the game.\n");
    printf("6. If all the cells of the board are filled and no player has won, then the game ends in a tie.\n\n");
    
    printf("Game board:\n");
    printf("-----------\n");
    
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf(" %c \t", board[i][j]);
        }
        printf("\n");
    }
    
    printf("\nPlayer X starts the game.\n\n");
    
    while(1) {
        printf("Player X turn.\n");
        printf("Enter the row and column: ");
        scanf("%d%d", &row, &col);
        pos = (row - 1) * 3 + (col - 1);
        if(board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O' || row > 3 || col > 3 || row < 1 || col < 1) {
            printf("Invalid move. Try again.\n\n");
            continue;
        }
        board[row-1][col-1] = 'X';
        printf("\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                printf(" %c \t", board[i][j]);
            }
            printf("\n");
        }
        
        if((board[0][0]=='X'&&board[0][1]=='X'&&board[0][2]=='X') || (board[1][0]=='X'&&board[1][1]=='X'&&board[1][2]=='X') || (board[2][0]=='X'&&board[2][1]=='X'&&board[2][2]=='X') || (board[0][0]=='X'&&board[1][0]=='X'&&board[2][0]=='X') || (board[0][1]=='X'&&board[1][1]=='X'&&board[2][1]=='X') || (board[0][2]=='X'&&board[1][2]=='X'&&board[2][2]=='X') || (board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X') || (board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X')) {
            printf("\nCongratulations! Player X wins the game.\n");
            break;
        }
        
        if(count == 9) {
            printf("\nThe game has ended in a tie.\n");
            break;
        }
        
        printf("\nPlayer O turn.\n");
        while(1) {
            row = rand() % 3;
            col = rand() % 3;
            if(board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'O';
                break;
            }
        }
        printf("\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                printf(" %c \t", board[i][j]);
            }
            printf("\n");
        }
        
        if((board[0][0]=='O'&&board[0][1]=='O'&&board[0][2]=='O') || (board[1][0]=='O'&&board[1][1]=='O'&&board[1][2]=='O') || (board[2][0]=='O'&&board[2][1]=='O'&&board[2][2]=='O') || (board[0][0]=='O'&&board[1][0]=='O'&&board[2][0]=='O') || (board[0][1]=='O'&&board[1][1]=='O'&&board[2][1]=='O') || (board[0][2]=='O'&&board[1][2]=='O'&&board[2][2]=='O') || (board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O') || (board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O')) {
            printf("\nCongratulations! Player O wins the game.\n");
            break;
        }
        
        count++;
    }
    
    return 0;
}