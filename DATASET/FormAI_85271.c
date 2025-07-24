//FormAI DATASET v1.0 Category: Chess engine ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Board representation of chess game
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

//Function to display the chess board
void display()
{
    printf("\n\n");
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

//Function to initialize the board
void initialize_board()
{
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            board[i][j] = ' ';
        }
    }
    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';

    board[1][0] = 'P';
    board[1][1] = 'P';
    board[1][2] = 'P';
    board[1][3] = 'P';
    board[1][4] = 'P';
    board[1][5] = 'P';
    board[1][6] = 'P';
    board[1][7] = 'P';

    board[7][0] = 'r';
    board[7][1] = 'n';
    board[7][2] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'b';
    board[7][6] = 'n';
    board[7][7] = 'r';

    board[6][0] = 'p';
    board[6][1] = 'p';
    board[6][2] = 'p';
    board[6][3] = 'p';
    board[6][4] = 'p';
    board[6][5] = 'p';
    board[6][6] = 'p';
    board[6][7] = 'p';
}

//Function to play chess
void play_chess()
{
    while(1)
    {
        display();
        //code for playing chess
        //random move
        int move = rand()%4;
        switch(move)
        {
            case 0:
                board[0][0] = ' ';
                board[2][2] = 'R';
                break;
            case 1:
                board[0][7] = ' ';
                board[2][5] = 'R';
                break;
            case 2:
                board[7][0] = ' ';
                board[5][2] = 'r';
                break;
            case 3:
                board[7][7] = ' ';
                board[5][5] = 'r';
                break;
        }
    }
}

int main()
{
    srand(time(NULL));
    initialize_board();
    play_chess();
    return 0;
}