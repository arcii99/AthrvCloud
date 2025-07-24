//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include <stdio.h>

// function to print the current state of the board
void printBoard(int board[][8]){
    printf("\t  1  2  3  4  5  6  7  8 \n");
    printf("\t _________________________\n");
    for(int i=0; i<8; i++){
        printf("\t%d|", i+1);
        for(int j=0; j<8; j++){
            if(board[i][j] == 0) printf("  |");
            else if(board[i][j] == 1) printf(" O|");
            else if(board[i][j] == 2) printf(" X|");
        }
        printf("\n\t_|_|_|_|_|_|_|_|_\n");
    }
}

// function to make a move
void makeMove(int board[][8], int *turn){
    int from_x, from_y, to_x, to_y;
    printf("Enter the poition of checker to move (row, column): ");
    scanf("%d%d", &from_x, &from_y);
    printf("Enter the destination position (row, column): ");
    scanf("%d%d", &to_x, &to_y);

    // check if it is a valid move
    if(board[from_x-1][from_y-1] == 0 || board[to_x-1][to_y-1] != 0){
        printf("Invalid move. Try again!\n");
        return;
    }
    if(*turn == 1 && from_x - to_x != 1){
        printf("Invalid move. Try again!\n");
        return;
    }
    if(*turn == 2 && to_x - from_x != 1){
        printf("Invalid move. Try again!\n");
        return;
    }

    // make the move
    board[to_x-1][to_y-1] = board[from_x-1][from_y-1];
    board[from_x-1][from_y-1] = 0;
    if(*turn == 1) *turn = 2;
    else *turn = 1;
}

int main(){
    int board[8][8] = {{0, 1, 0, 1, 0, 1, 0, 1},
                       {1, 0, 1, 0, 1, 0, 1, 0},
                       {0, 1, 0, 1, 0, 1, 0, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {2, 0, 2, 0, 2, 0, 2, 0},
                       {0, 2, 0, 2, 0, 2, 0, 2},
                       {2, 0, 2, 0, 2, 0, 2, 0}};
    int turn = 1;
    printf("--- Welcome to Checkers Game! ---\n");
    printBoard(board);
    
    while(1){
        printf("Turn of Player %d:\n", turn);
        makeMove(board, &turn);
        printBoard(board);

        // check for win
        int count1 = 0, count2 = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] == 1) count1++;
                else if(board[i][j] == 2) count2++;
            }
        }
        if(count1 == 0){
            printf("Player 2 wins!\n");
            break;
        }
        else if(count2 == 0){
            printf("Player 1 wins!\n");
            break;
        }
    }

    printf("--- Thanks for playing! ---\n");
    return 0;
}