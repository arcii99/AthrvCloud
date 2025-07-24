//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void print_board(char board[SIZE][SIZE], int score);
void initialize_board(char board[SIZE][SIZE]);
void generate_random_tile(char board[SIZE][SIZE]);
void move_left(char board[SIZE][SIZE], int *score);
void move_right(char board[SIZE][SIZE], int *score);
void move_up(char board[SIZE][SIZE], int *score);
void move_down(char board[SIZE][SIZE], int *score);
int check_game_over(char board[SIZE][SIZE]);

int main()
{
    char board[SIZE][SIZE];
    int score = 0;
    char direction;
    int game_over = 0;

    srand(time(NULL));

    initialize_board(board);
    generate_random_tile(board);
    generate_random_tile(board);
    print_board(board, score);

    while (!game_over)
    {
        printf("Enter direction (L, R, U, D): ");
        scanf(" %c", &direction);

        switch (direction)
        {
            case 'L':
                move_left(board, &score);
                break;
            case 'R':
                move_right(board, &score);
                break;
            case 'U':
                move_up(board, &score);
                break;
            case 'D':
                move_down(board, &score);
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        game_over = check_game_over(board);
        if (!game_over)
        {
            generate_random_tile(board);
            print_board(board, score);
        }
    }
    
    printf("Game over!\n");

    return 0;
}

void print_board(char board[SIZE][SIZE], int score)
{
    int i, j;

    printf("Score: %d\n\n", score);
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%5d", board[i][j] - '0');
        }
        printf("\n\n");
    }
}

void initialize_board(char board[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            board[i][j] = '0';
        }
    }
}

void generate_random_tile(char board[SIZE][SIZE])
{
    int i, j;
    int count = 0;
    int value;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '0')
            {
                count++;
            }
        }
    }

    if (count == 0)
    {
        return;
    }

    value = ((rand() % 2) + 1) * 2;
    count = rand() % count;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '0')
            {
                if (count == 0)
                {
                    board[i][j] = value + '0';
                    return;
                }
                count--;
            }
        }
    }
}

void move_left(char board[SIZE][SIZE], int *score)
{
    int i, j, k;
    int merged[SIZE] = {0};

    for (i = 0; i < SIZE; i++)
    {
        k = -1;
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] != '0')
            {
                if (k < 0)
                {
                    k = j;
                }
                else if (board[i][k] == board[i][j] && !merged[k])
                {
                    board[i][k] += board[i][j];
                    board[i][j] = '0';
                    *score += (board[i][k] - '0');
                    merged[k] = 1;
                    k = -1;
                }
                else
                {
                    k++;
                    if (k != j)
                    {
                        board[i][k] = board[i][j];
                        board[i][j] = '0';
                    }
                }
            }
        }
    }
}

void move_right(char board[SIZE][SIZE], int *score)
{
    int i, j, k;
    int merged[SIZE] = {0};

    for (i = 0; i < SIZE; i++)
    {
        k = -1;
        for (j = SIZE - 1; j >= 0; j--)
        {
            if (board[i][j] != '0')
            {
                if (k < 0)
                {
                    k = j;
                }
                else if (board[i][k] == board[i][j] && !merged[k])
                {
                    board[i][k] += board[i][j];
                    board[i][j] = '0';
                    *score += (board[i][k] - '0');
                    merged[k] = 1;
                    k = -1;
                }
                else
                {
                    k--;
                    if (k != j)
                    {
                        board[i][k] = board[i][j];
                        board[i][j] = '0';
                    }
                }
            }
        }
    }
}

void move_up(char board[SIZE][SIZE], int *score)
{
    int i, j, k;
    int merged[SIZE] = {0};

    for (j = 0; j < SIZE; j++)
    {
        k = -1;
        for (i = 0; i < SIZE; i++)
        {
            if (board[i][j] != '0')
            {
                if (k < 0)
                {
                    k = i;
                }
                else if (board[k][j] == board[i][j] && !merged[k])
                {
                    board[k][j] += board[i][j];
                    board[i][j] = '0';
                    *score += (board[k][j] - '0');
                    merged[k] = 1;
                    k = -1;
                }
                else
                {
                    k++;
                    if (k != i)
                    {
                        board[k][j] = board[i][j];
                        board[i][j] = '0';
                    }
                }
            }
        }
    }
}

void move_down(char board[SIZE][SIZE], int *score)
{
    int i, j, k;
    int merged[SIZE] = {0};

    for (j = 0; j < SIZE; j++)
    {
        k = -1;
        for (i = SIZE - 1; i >= 0; i--)
        {
            if (board[i][j] != '0')
            {
                if (k < 0)
                {
                    k = i;
                }
                else if (board[k][j] == board[i][j] && !merged[k])
                {
                    board[k][j] += board[i][j];
                    board[i][j] = '0';
                    *score += (board[k][j] - '0');
                    merged[k] = 1;
                    k = -1;
                }
                else
                {
                    k--;
                    if (k != i)
                    {
                        board[k][j] = board[i][j];
                        board[i][j] = '0';
                    }
                }
            }
        }
    }
}

int check_game_over(char board[SIZE][SIZE])
{
    int i, j;
    int count = 0;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '0')
            {
                count++;
            }
        }
    }

    if (count > 0)
    {
        return 0;
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE - 1; j++)
        {
            if (board[i][j] == board[i][j + 1])
            {
                return 0;
            }
        }
    }

    for (j = 0; j < SIZE; j++)
    {
        for (i = 0; i < SIZE - 1; i++)
        {
            if (board[i][j] == board[i + 1][j])
            {
                return 0;
            }
        }
    }

    return 1;
}