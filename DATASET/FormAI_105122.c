//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

//declaring the board
char board[3][3];

//function to print the board
void print_board()
{
    printf("\n     1     2     3\n\n");
    printf("1    %c  | %c  | %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("    ____|____|____\n");
    printf("2    %c  | %c  | %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("    ____|____|____\n");
    printf("3    %c  | %c  | %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("         |    |    \n\n");
}

//function to check the winner
int check_win(char player)
{
    int i, j;
    for(i=0;i<3;i++)
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return 1;
        else if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return 1;
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return 1;
    else if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return 1;
        
    return 0;
}

//function to check if the game is over
int game_over()
{
    int i, j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(board[i][j]==' ')
                return 0;
    
    return 1;
}

//function for the AI move
void ai_move()
{
    int i, j, s, t, count = 0;
    char temp_board[3][3];
    int score[9] = {0};
    
    //copying the board to a temporary board
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            temp_board[i][j] = board[i][j];
    
    //checking for empty spaces and calculating the score for each empty space
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(temp_board[i][j]==' ')
            {
                temp_board[i][j] = 'O';
                
                //checking if the move results in an AI victory
                if(check_win('O'))
                    score[count] = 10;
                else
                {
                    //checking for human victory in the next move
                    for(s=0;s<3;s++)
                    {
                        for(t=0;t<3;t++)
                        {
                            if(temp_board[s][t]==' ')
                            {
                                temp_board[s][t] = 'X';
                                
                                if(check_win('X'))
                                    score[count] = -10;
                                else
                                    score[count] = 0;
                                
                                temp_board[s][t] = ' ';
                            }
                        }
                    }
                }
                
                temp_board[i][j] = ' ';
                count++;
            }
        }
    }
    
    int max_index = 0;
    int max_score = -100;
    
    //finding the move with the maximum score
    for(i=0;i<9;i++)
    {
        if(score[i]>max_score)
        {
            max_score = score[i];
            max_index = i;
        }
    }
    
    //making the move at the index with the maximum score
    count = 0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                if(count==max_index)
                {
                    board[i][j] = 'O';
                    printf("AI moves to (%d,%d)\n", i+1, j+1);
                    return;
                }
                else
                    count++;
            }
        }
}

int main()
{
    int i, j, row, col, result = 0;
    
    //initializing the board
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            board[i][j] = ' ';
            
    printf("\nWelcome to Tic Tac Toe\n");
    printf("Player: X, AI: O\n");
    printf("The board is as follows:\n");
    print_board();
    
    //looping until game is over
    while(!game_over())
    {
        printf("Enter the row and column to place your move (e.g. 2 3):\n");
        scanf("%d%d", &row, &col);
        
        if(board[row-1][col-1]==' ')
        {
            board[row-1][col-1] = 'X';
            print_board();
            
            if(check_win('X'))
            {
                printf("Congratulations! You won!\n");
                result = 1;
                break;
            }
            
            ai_move();
            print_board();
            
            if(check_win('O'))
            {
                printf("Sorry, you lost! Better luck next time.\n");
                result = 1;
                break;
            }
        }
        else
            printf("Invalid move. Please enter an empty cell.\n");
    }
    
    if(!result)
        printf("The game is a draw!\n");
    
    return 0;
}