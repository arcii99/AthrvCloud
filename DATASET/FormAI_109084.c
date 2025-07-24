//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MINE_COUNT 10

char board[BOARD_SIZE][BOARD_SIZE];
int mines[MINE_COUNT][2];

void initializeBoard()
{
    int i, j, k;

    // Initialize board with empty spaces
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '-';

    // Set random mines
    srand(time(NULL));
    for (k = 0; k < MINE_COUNT; k++)
    {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        if (board[i][j] == '-')
        {
            board[i][j] = '*';
            mines[k][0] = i;
            mines[k][1] = j;
        }
        else
        {
            k--;
        }
    }
}

void displayBoard(int revealMines)
{
    int i, j;

    printf("\n   ");
    for (i = 0; i < BOARD_SIZE; i++)
        printf("%d ", i);

    printf("\n  ");
    for (i = 0; i < BOARD_SIZE; i++)
        printf("--");

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d| ", i);
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == '*' && revealMines)
                printf("%c ", board[i][j]);
            else if (board[i][j] != '*' && board[i][j] != '-')
                printf("%c ", board[i][j]);
            else
                printf("- ");
        }
        printf("\n");
    }
}

int countAdjacentMines(int i, int j)
{
    int count = 0;
    int x, y;

    for (x = i - 1; x <= i + 1; x++)
    {
        for (y = j - 1; y <= j + 1; y++)
        {
            if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE)
            {
                if (board[x][y] == '*')
                    count++;
            }
        }
    }

    return count;
}

void revealCell(int i, int j)
{
    int adjacentMines;

    if (board[i][j] != '-')
        return;

    adjacentMines = countAdjacentMines(i, j);

    if (adjacentMines == 0)
    {
        board[i][j] = ' ';
        if (i > 0)
        {
            revealCell(i - 1, j);
            if (j > 0)
                revealCell(i - 1, j - 1);
            if (j < BOARD_SIZE - 1)
                revealCell(i - 1, j + 1);
        }
        if (i < BOARD_SIZE - 1)
        {
            revealCell(i + 1, j);
            if (j > 0)
                revealCell(i + 1, j - 1);
            if (j < BOARD_SIZE - 1)
                revealCell(i + 1, j + 1);
        }
        if (j > 0)
            revealCell(i, j - 1);
        if (j < BOARD_SIZE - 1)
            revealCell(i, j + 1);
    }
    else
    {
        board[i][j] = '0' + adjacentMines;
    }
}

int main()
{
    int x, y;
    char command;

    initializeBoard();
    displayBoard(0);

    do
    {
        printf("Enter coordinates (x y) or 'q' to quit: ");
        scanf("%c", &command);
        if (command != 'q')
        {
            scanf("%d %d", &x, &y);
            if (board[x][y] == '*')
            {
                printf("Oh no! You hit a mine! Game over!\n");
                displayBoard(1);
                break;
            }
            else
            {
                revealCell(x, y);
                displayBoard(0);
            }
        }
    } while (command != 'q');

    printf("Thanks for playing!\n");

    return 0;
}