//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MINES 10

int board[BOARD_SIZE][BOARD_SIZE];
int mines[MINES][2];

int is_valid(int row, int col)
{
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

void init_board()
{
    int i, j, rand_row, rand_col;
    srand(time(NULL));

    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    for(i = 0; i < MINES; i++)
    {
        rand_row = rand() % BOARD_SIZE;
        rand_col = rand() % BOARD_SIZE;

        if(board[rand_row][rand_col] != -1)
        {
            board[rand_row][rand_col] = -1;
            mines[i][0] = rand_row;
            mines[i][1] = rand_col;
        }
        else
        {
            i--;
        }
    }

    int row, col;
    for(i = 0; i < MINES; i++)
    {
        row = mines[i][0];
        col = mines[i][1];

        if(is_valid(row - 1, col - 1) && board[row - 1][col - 1] != -1)
            board[row - 1][col - 1]++;

        if(is_valid(row - 1, col) && board[row - 1][col] != -1)
            board[row - 1][col]++;

        if(is_valid(row - 1, col + 1) && board[row - 1][col + 1] != -1)
            board[row - 1][col + 1]++;

        if(is_valid(row, col - 1) && board[row][col - 1] != -1)
            board[row][col - 1]++;

        if(is_valid(row, col + 1) && board[row][col + 1] != -1)
            board[row][col + 1]++;

        if(is_valid(row + 1, col - 1) && board[row + 1][col - 1] != -1)
            board[row + 1][col - 1]++;

        if(is_valid(row + 1, col) && board[row + 1][col] != -1)
            board[row + 1][col]++;

        if(is_valid(row + 1, col + 1) && board[row + 1][col + 1] != -1)
            board[row + 1][col + 1]++;
    }
}

void display_board(int show)
{
    printf("\n");

    int i, j;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(show || board[i][j] == -1)
            {
                if(board[i][j] == -1)
                {
                    printf("* ");
                }
                else
                {
                    printf("%d ", board[i][j]);
                }
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int is_game_over()
{
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == -1)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    printf("=================================\n");
    printf("        M I N E S W E E P E R    \n");
    printf("=================================\n");

    printf("Press 's' to start game: ");

    char input;
    scanf("%c", &input);

    if(input == 's')
    {
        int row, col, is_first_move = 1;
        char action;

        init_board();
        display_board(0);

        while(1)
        {
            if(is_first_move)
            {
                printf("Enter row and column (separated by space) to reveal: ");
                scanf("%d %d", &row, &col);
                is_first_move = 0;
            }
            else
            {
                printf("Enter action (r - reveal, f - flag): ");
                scanf(" %c", &action);

                if(action == 'r')
                {
                    printf("Enter row and column (separated by space) to reveal: ");
                    scanf("%d %d", &row, &col);
                }
                else if(action == 'f')
                {
                    printf("Enter row and column (separated by space) to flag: ");
                    scanf("%d %d", &row, &col);

                    if(board[row][col] != -1)
                    {
                        board[row][col] = -2;
                    }
                }
            }

            if(is_valid(row, col))
            {
                if(action == 'r')
                {
                    if(board[row][col] == -1)
                    {
                        printf("Game over!\n");
                        display_board(1);
                        break;
                    }
                    else
                    {
                        board[row][col] *= -1;

                        if(board[row][col] == 0)
                        {
                            int i;
                            int j;
                            for(i = row - 1; i <= row + 1; i++)
                            {
                                for(j = col - 1; j <= col + 1; j++)
                                {
                                    if(is_valid(i, j) && board[i][j] > 0)
                                    {
                                        board[i][j] *= -1;

                                        if(board[i][j] == 0)
                                        {
                                            // uncover neighbours recursively
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if(is_game_over())
                    {
                        printf("Congratulations, you won!\n");
                        display_board(1);
                        break;
                    }
                }

                display_board(0);
            }
        }
    }

    return 0;
}