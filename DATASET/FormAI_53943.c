//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>

char board[3][3];

void initialize_board()
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void print_board()
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_move_valid(int row, int col)
{
    if(row>=0 && row<3 && col>=0 && col<3 && board[row][col]=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_game_status()
{
    int i, j;
    for(i=0; i<3; i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!='-')
        {
            if(board[i][0]=='X')
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!='-')
        {
            if(board[0][i]=='X')
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!='-')
    {
        if(board[0][0]=='X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!='-')
    {
        if(board[0][2]=='X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(board[i][j]=='-')
            {
                return 0;
            }
        }
    }

    return 3;
}

int minimax(int depth, int is_maximizing)
{
    int i, j, score, best_score;
    int result = check_game_status();

    if(result==1)
    {
        return -10+depth;
    }
    else if(result==2)
    {
        return 10-depth;
    }
    else if(result==3)
    {
        return 0;
    }

    if(is_maximizing)
    {
        best_score = -10000;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(is_move_valid(i, j))
                {
                    board[i][j] = 'O';
                    score = minimax(depth+1, !is_maximizing);
                    board[i][j] = '-';
                    if(score>best_score)
                    {
                        best_score = score;
                    }
                }
            }
        }
    }
    else
    {
        best_score = 10000;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(is_move_valid(i, j))
                {
                    board[i][j] = 'X';
                    score = minimax(depth+1, !is_maximizing);
                    board[i][j] = '-';
                    if(score<best_score)
                    {
                        best_score = score;
                    }
                }
            }
        }
    }

    return best_score;
}

void make_best_move()
{
    int i, j, best_score, score;
    int best_row = -1, best_col = -1;

    best_score = -10000;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(is_move_valid(i, j))
            {
                board[i][j] = 'O';
                score = minimax(0, 0);
                board[i][j] = '-';
                if(score>best_score)
                {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }

    board[best_row][best_col] = 'O';
}

int main()
{
    initialize_board();

    printf("Welcome to Tic Tac Toe AI\n");
    printf("You are X and AI is O.\n");
    printf("Enter row and column numbers (0-2) to make a move.\n");

    int row, col, status, player = 1;
    while(1)
    {
        printf("\n");
        print_board();

        if(player==1)
        {
            printf("X's turn: ");

            while(1)
            {
                scanf("%d %d", &row, &col);
                if(is_move_valid(row, col))
                {
                    break;
                }
                else
                {
                    printf("Invalid move. Try again.\n");
                }
            }

            board[row][col] = 'X';
            player = 2;
        }
        else
        {
            printf("O's turn: \n");
            make_best_move();
            player = 1;
        }

        status = check_game_status();
        if(status==1)
        {
            printf("\n");
            print_board();
            printf("\nX wins!\n");
            break;
        }
        else if(status==2)
        {
            printf("\n");
            print_board();
            printf("\nO wins!\n");
            break;
        }
        else if(status==3)
        {
            printf("\n");
            print_board();
            printf("\nIt's a tie!\n");
            break;
        }
    }

    return 0;
}