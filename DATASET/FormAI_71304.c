//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateBoard(int board[ROWS][COLS]);
void displayBoard(int board[ROWS][COLS]);
int checkBoard(int board[ROWS][COLS], int num);
int checkHorizontal(int board[ROWS][COLS], int num);
int checkVertical(int board[ROWS][COLS], int num);
int checkDiagonal(int board[ROWS][COLS], int num);
void generateCall(int *num);
int checkLine(int board[ROWS][COLS], int line);
int checkBingo(int board[ROWS][COLS]);
void printWin();

int main()
{
    int board[ROWS][COLS];
    int num, line, win = 0;

    srand(time(NULL));
    generateBoard(board);
    printf("Welcome to Bingo Simulator!\n\n");

    while (!win)
    {
        displayBoard(board);
        generateCall(&num);
        printf("The next number is: %d\n", num);
        if (checkBoard(board, num))
        {
            printf("BINGO!\n");
            printWin();
            win = 1;
        }
    }
    return 0;
}

void generateBoard(int board[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = rand() % 75 + 1;
        }
    }
}

void displayBoard(int board[ROWS][COLS])
{
    int i, j;
    printf("\nB   I   N   G   O\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i == 2 && j == 2)
            {
                printf(" F  ");
            }
            else
            {
                printf("%2d  ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int checkBoard(int board[ROWS][COLS], int num)
{
    int line, win = 0;
    for (line = 0; line < ROWS; line++)
    {
        if (checkLine(board, line))
        {
            win = 1;
            break;
        }
    }
    return win;
}

int checkLine(int board[ROWS][COLS], int line)
{
    return (checkHorizontal(board, line) || checkVertical(board, line) || checkDiagonal(board, line));
}

int checkHorizontal(int board[ROWS][COLS], int line)
{
    int j, count = 0;
    for (j = 0; j < COLS; j++)
    {
        if (board[line][j] == 0)
        {
            count++;
        }
    }
    return (count == 5);
}

int checkVertical(int board[ROWS][COLS], int line)
{
    int i, count = 0;
    for (i = 0; i < ROWS; i++)
    {
        if (board[i][line] == 0)
        {
            count++;
        }
    }
    return (count == 5);
}

int checkDiagonal(int board[ROWS][COLS], int line)
{
    if (line == 0 || line == 4)
    {
        return (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) ||
               (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0);
    }
    else
    {
        return (board[0][4] == 0 && board[1][3] == 0 && board[3][1] == 0 && board[4][0] == 0) ||
               (board[0][0] == 0 && board[1][1] == 0 && board[3][3] == 0 && board[4][4] == 0);
    }
}

void generateCall(int *num)
{
    *num = rand() % 75 + 1;
}

void printWin()
{
    printf("\n  _______ _                 _            _   _            \n"
           " |__   __| |               (_)          | | (_)           \n"
           "    | |  | | __ _  __ _ ___ _ _ __ __ _| |_ _  ___  _ __ \n"
           "    | |  | |/ _` |/ _` / __| | '__/ _` | __| |/ _ \\| '__|\n"
           "    | |  | | (_| | (_| \\__ \\ | | | (_| | |_| | (_) | |   \n"
           "    |_|  |_|\\__,_|\\__, |___/_|_|  \\__,_|\\__|_|\\___/|_|   \n"
           "                    __/ |                                 \n"
           "                   |___/                                  \n");
}