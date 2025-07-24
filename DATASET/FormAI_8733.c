//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>

char board[3][3];
char player = 'X';
char cpu = 'O';

void print_board()
{
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

int check_win(char player)
{
    int i, j, count;

    // Check rows
    for(i=0; i<3; i++)
    {
        count = 0;
        for(j=0; j<3; j++)
        {
            if(board[i][j] == player)
            {
                count++;
            }
        }
        if(count == 3)
        {
            return 1;
        }
    }

    // Check columns
    for(i=0; i<3; i++)
    {
        count = 0;
        for(j=0; j<3; j++)
        {
            if(board[j][i] == player)
            {
                count++;
            }
        }
        if(count == 3)
        {
            return 1;
        }
    }

    // Check diagonal 1
    if((board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) ||
       (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player))
    {
        return 1;
    }

    return 0;
}

int minimax(char player)
{
    int i, j, value, best_value;
    char other_player;
    int row = -1, col = -1;

    if(check_win(player))
    {
        if(player == cpu)
        {
            return 100;
        }
        else
        {
            return -100;
        }
    }

    other_player = (player == cpu) ? 'X' : 'O';

    best_value = (player == cpu) ? -1000 : 1000;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = player;
                value = minimax(other_player);
                board[i][j] = ' ';
                if(player == cpu)
                {
                    if(value > best_value)
                    {
                        best_value = value;
                        row = i;
                        col = j;
                    }
                }
                else if(player != cpu)
                {
                    if(value < best_value)
                    {
                        best_value = value;
                        row = i;
                        col = j;
                    }
                }
            }
        }
    }

    if(row != -1 && col != -1)
    {
        board[row][col] = player;
    }

    return best_value;
}

void cpu_move()
{
    int value;

    minimax(cpu);

    if(check_win(cpu))
    {
        printf("\n\nCPU won!\n\n");
        print_board();
        return;
    }
    else if(check_win(player))
    {
        printf("\n\nPlayer won!\n\n");
        print_board();
        return;
    }

    player = (player == 'X') ? 'O' : 'X';
    print_board();
    printf("Player %c's turn.\n\n", player);
}

int main()
{
    int i, j;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }

    print_board();
    printf("Player %c's turn.\n\n", player);

    while(1)
    {
        if(player == 'X')
        {
            int row, col;
            printf("Enter row: ");
            scanf("%d", &row);
            printf("Enter column: ");
            scanf("%d", &col);
            if(row >= 1 && row <= 3 && col >= 1 && col <= 3)
            {
                if(board[row-1][col-1] == ' ')
                {
                    board[row-1][col-1] = player;
                    player = 'O';
                    print_board();

                    if(check_win('X'))
                    {
                        printf("\n\nPlayer 1 won!\n\n");
                        break;
                    }
                    else if(check_win('O'))
                    {
                        printf("\n\nPlayer 2 won!\n\n");
                        break;
                    }
                }
                else
                {
                    printf("That space is already occupied. Please try again.\n");
                }
            }
            else
            {
                printf("Invalid input. Please try again.\n");
            }
        }
        else
        {
            cpu_move();
        }
    }

    return 0;
}