//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define BOMB_COUNT 10

void init_board(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_bomb_board(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE]);
int reveal_square(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE], int x, int y);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char secret_board[BOARD_SIZE][BOARD_SIZE];
    int x, y;

    srand(time(NULL));

    init_board(board, secret_board);
    print_board(board);

    // GAME LOOP
    while (1)
    {
        printf("Enter row and column to reveal: ");
        scanf("%d %d", &x, &y);

        // check for invalid input
        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
        {
            printf("Invalid input! Please try again.\n");
            continue;
        }

        // reveal square
        if (reveal_square(board, secret_board, x, y) == -1)
        {
            print_bomb_board(board, secret_board);
            printf("\n\nGAME OVER!\n\n");
            break;
        }

        print_board(board);

        if (check_win(board, secret_board))
        {
            print_bomb_board(board, secret_board);
            printf("\n\nYOU WIN!\n\n");
            break;
        }
    }

    return 0;
}

void init_board(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    int bomb_count = 0;

    // initialize board to empty squares
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '.';
            secret_board[i][j] = '.';
        }
    }

    // randomly place bombs on secret board
    while (bomb_count < BOMB_COUNT)
    {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;

        if (secret_board[i][j] != '*')
        {
            secret_board[i][j] = '*';
            bomb_count++;
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    printf("   ");

    // print column numbers
    for (j = 0; j < BOARD_SIZE; j++)
    {
        printf("%d ", j);
    }

    printf("\n");

    // print board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d ", i);

        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

void print_bomb_board(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    printf("   ");

    // print column numbers
    for (j = 0; j < BOARD_SIZE; j++)
    {
        printf("%d ", j);
    }

    printf("\n");

    // print board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%2d ", i);

        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (secret_board[i][j] == '*')
            {
                printf("* ");
            }
            else
            {
                printf("%c ", board[i][j]);
            }
        }

        printf("\n");
    }
}

int reveal_square(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE], int x, int y)
{
    if (secret_board[x][y] == '*')
    {
        board[x][y] = '*';
        return -1;
    }

    if (board[x][y] != '.')
    {
        printf("Square already revealed!\n");
        return 0;
    }

    int i, j;
    int count = 0;

    // check surrounding squares for bombs
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && secret_board[i][j] == '*')
            {
                count++;
            }
        }
    }

    if (count == 0)
    {
        board[x][y] = ' ';
    }
    else
    {
        board[x][y] = count + '0';
    }

    return 0;
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char secret_board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (secret_board[i][j] != '*' && board[i][j] == '.')
            {
                return 0;
            }
        }
    }

    return 1;
}