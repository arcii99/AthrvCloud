//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int board[8][8] = {  // initialize the checkerboard
    {0,-1,0,-1,0,-1,0,-1},
    {-1,0,-1,0,-1,0,-1,0},
    {0,-1,0,-1,0,-1,0,-1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0}
};

void display_board()  // display the checkerboard
{
    printf("\n-----------------");
    for(int i=0; i<8; i++)
    {
        printf("\n");
        for(int j=0; j<8; j++)
        {
            if(board[i][j] == -1) printf("| O ");
            else if(board[i][j] == 1) printf("| X ");
            else printf("|   ");
        }
        printf("|");
        printf("\n-----------------");
    }
}

int main()
{
    int turn = 1;  // 1 for player X, -1 for player O
    int i, j, move_i, move_j;
    int valid_move = 0;
    display_board();  // display initial checkerboard
    while(1)
    {
        printf("\n\n>>> TURN OF PLAYER %c <<<", turn==1 ? 'X' : 'O');
        printf("\n\nEnter the coordinates of the piece you want to move (row, column): ");
        scanf("%d %d", &i, &j);
        if(board[i][j] != turn)  // check if the selected piece belongs to the current player
        {
            printf("\nInvalid piece chosen!\n");
            continue;
        }
        printf("Enter the coordinates of the square you want to move to (row, column): ");
        scanf("%d %d", &move_i, &move_j);
        if(board[move_i][move_j] != 0)  // check if the target square is already occupied
        {
            printf("\nInvalid move - target square is already occupied!\n");
            continue;
        }
        if(board[i][j] == 1 && move_i < i)  // player X can only move upwards
        {
            printf("\nInvalid move - player X can only move upwards!\n");
            continue;
        }
        else if(board[i][j] == -1 && move_i > i)  // player O can only move downwards
        {
            printf("\nInvalid move - player O can only move downwards!\n");
            continue;
        }
        if(abs(move_i-i) == 1 && abs(move_j-j) == 1)  // check for a simple diagonal move
        {
            board[move_i][move_j] = turn;
            board[i][j] = 0;
            valid_move = 1;
        }
        else if(abs(move_i-i) == 2 && abs(move_j-j) == 2)  // check for a jump move
        {
            if(board[(move_i+i)/2][(move_j+j)/2] == -turn)  // check if the jumped piece belongs to the opposing player
            {
                board[move_i][move_j] = turn;
                board[(move_i+i)/2][(move_j+j)/2] = 0;
                board[i][j] = 0;
                valid_move = 1;
            }
            else printf("\nInvalid move - the piece you are trying to jump over does not belong to the opposing player!\n");
        }
        if(!valid_move) printf("\nInvalid move - please try again!\n");
        valid_move = 0;
        display_board();  // display updated checkerboard
        int total_X = 0, total_O = 0;  // count the number of pieces for each player
        for(int m=0; m<8; m++)
        {
            for(int n=0; n<8; n++)
            {
                if(board[m][n] == 1) total_X++;
                else if(board[m][n] == -1) total_O++;
            }
        }
        if(total_X == 0)
        {
            printf("\n\n\t\t*** GAME OVER ***");
            printf("\n\n\t\tPlayer O wins %d to 0!", total_O);
            break;
        }
        if(total_O == 0)
        {
            printf("\n\n\t\t*** GAME OVER ***");
            printf("\n\n\t\tPlayer X wins %d to 0!", total_X);
            break;
        }
        turn = -turn;  // change the turn to the next player
    }
    return 0;
}