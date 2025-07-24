//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 3x3 Tic Tac Toe board
char board[3][3];

// Function to display the Tic Tac Toe board
void display_board()
{
    printf("\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf(" %c%c", board[i][j], j<2?'|':' ');
        printf("%c", i<2?'\n':'\0');
        if(i<2)
            printf("------\n");
    }
    printf("\n");
}

// Function to check if three characters are same
int check_win(char c1, char c2, char c3)
{
    if(c1=='.' || c2=='.' || c3=='.')
        return 0;
    return c1==c2 && c2==c3;
}

// Function to check if the game has ended
int check_end()
{
    for(int i=0;i<3;i++)
        if(check_win(board[i][0], board[i][1], board[i][2]) || check_win(board[0][i], board[1][i], board[2][i]))
            return 1;
    return check_win(board[0][0], board[1][1], board[2][2]) || check_win(board[0][2], board[1][1], board[2][0]);
}

// Function to get the optimal move for AI
int get_optimal_move(char player, char ai)
{
    int best_score = -1000;
    int row, col;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            // Check if it's available
            if(board[i][j]=='.')
            {
                board[i][j] = ai;
                
                // Minimax algorithm
                int score = 0;
                if(check_win(ai, ai, ai))
                    score = 10;
                else if(check_end())
                    score = 0;
                else
                {
                    int min_score = 1000;
                    for(int m=0;m<3;m++)
                        for(int n=0;n<3;n++)
                            if(board[m][n]=='.')
                            {
                                board[m][n] = player;
                                int temp_score = 0;
                                if(check_win(player, player, player))
                                    temp_score = -10;
                                else if(check_end())
                                    temp_score = 0;
                                else
                                    temp_score = get_optimal_move(player, ai);
                                if(temp_score < min_score)
                                    min_score = temp_score;
                                board[m][n] = '.';
                            }
                    score = min_score;
                }
                
                board[i][j] = '.';
                
                // Update best score
                if(score > best_score)
                {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    return row*3+col;
}

// Main game function
void game(char player, char ai)
{
    int turn = 0;
    while(turn<9 && !check_end())
    {
        if((turn&1)==0)
        {
            printf("Your turn: Enter row (0-2) and column (0-2): ");
            int row, col;
            scanf("%d %d", &row, &col);
            if(row<0 || row>=3 || col<0 || col>=3 || board[row][col]!='.')
            {
                printf("Invalid move!\n");
                continue;
            }
            board[row][col] = player;
        }
        else
        {
            printf("\nAI's turn:\n");
            int move = get_optimal_move(player, ai);
            board[move/3][move%3] = ai;
        }
        display_board();
        turn++;
    }
    if(check_win(player, player, player))
        printf("Congratulations! You win!\n");
    else if(check_win(ai, ai, ai))
        printf("You lost! Better luck next time.\n");
    else
        printf("It's a draw!\n");
}

int main()
{
    printf("Welcome to Tic Tac Toe!\n");
    printf("Do you want to play first? [y/n]: ");
    char player;
    char ai;
    if(getchar()=='y')
    {
        player = 'O';
        ai = 'X';
    }
    else
    {
        player = 'X';
        ai = 'O';
    }
    // Initialize board
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = '.';
    display_board();
    game(player, ai);
    return 0;
}