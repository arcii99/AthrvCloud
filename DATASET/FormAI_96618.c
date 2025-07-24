//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3];  //Array to store the values of the board
int bestrow, bestcol;

void display_board()  //Function to display the current state of the board
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int score(char player)  //Function to calculate the score of the board for the given player
{
    int i, j, count = 0;
    for(i=0;i<3;i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 10;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 10;
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 10;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 10;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j] != ' ')
            {
                count++;
            }
        }
    }
    if(count == 9)
        return 0;
    return -1;
}

int minimax(char player)   //Function to implement the minimax algorithm
{
    int i, j, s, bestscore;
    char opponent;
    if(player == 'X')
        opponent = 'O';
    else
        opponent = 'X';
    s = score(player);
    if(s == 10 || s == 0 || s == -1)
        return s;
    bestscore = -1000;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = player;
                s = -minimax(opponent);
                board[i][j] = ' ';
                if(s > bestscore)
                {
                    bestscore = s;
                    if(player == 'X')
                    {
                        bestrow = i;
                        bestcol = j;
                    }
                }
            }
        }
    }
    return bestscore;
}

void computer_move()  //Function to get the computer move
{
    if(board[1][1] == ' ')
    {
        bestrow = 1;
        bestcol = 1;
    }
    else
        minimax('X');
    board[bestrow][bestcol] = 'X';
}

void player_move()  //Function to get the player move
{
    int row, col;
    printf("Enter Row and Column (1-3): ");
    scanf("%d%d",&row,&col);
    while(row<1 || row>3 || col<1 || col>3 || board[row-1][col-1] != ' ')
    {
        printf("Invalid move! Enter Row and Column (1-3): ");
        scanf("%d%d",&row,&col);
    }
    board[row-1][col-1] = 'O';
}

int main()  //Main function
{
    int i, s;
    for(i=0;i<3;i++)
        board[i][0] = board[i][1] = board[i][2] = ' ';
    while(1)
    {
        display_board();
        player_move();
        s = score('O');
        if(s == 10)
        {
            printf("You Win!\n");
            return 0;
        }
        else if(s == 0)
        {
            printf("Game Drawn!\n");
            return 0;
        }
        computer_move();
        s = score('X');
        if(s == 10)
        {
            printf("You Lose!\n");
            return 0;
        }
        else if(s == 0)
        {
            printf("Game Drawn!\n");
            return 0;
        }
    }
    return 0;
}