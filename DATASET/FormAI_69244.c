//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 24
#define COLS 26

void initializeGameBoard(char gameBoard[][COLS]);
void printGameBoard(char gameBoard[][COLS]);
void movePacman(int *pacmanRow, int *pacmanCol, char direction, char gameBoard[][COLS]);
void moveGhosts(char gameBoard[][COLS], int ghostRow[], int ghostCol[]);
bool checkCollision(int pacmanRow, int pacmanCol, int ghostRow[], int ghostCol[]);
void endGame(char gameBoard[][COLS]);

int main()
{
    char gameBoard[ROWS][COLS];
    int pacmanRow = ROWS/2;
    int pacmanCol = COLS/2;
    int ghostRow[4] = {ROWS/4, ROWS/2, ROWS/2, ROWS/2 + ROWS/4};
    int ghostCol[4] = {COLS/4, COLS/4, COLS/2, COLS/2 + COLS/4};
    char direction;
    srand(time(NULL));

    initializeGameBoard(gameBoard);

    while(true)
    {
        printGameBoard(gameBoard);

        printf("Enter direction (w/a/s/d): ");
        scanf(" %c", &direction);

        movePacman(&pacmanRow, &pacmanCol, direction, gameBoard);
        moveGhosts(gameBoard, ghostRow, ghostCol);

        if(checkCollision(pacmanRow, pacmanCol, ghostRow, ghostCol))
        {
            endGame(gameBoard);
            break;
        }
    }

    return 0;
}

void initializeGameBoard(char gameBoard[][COLS])
{
    //set top and bottom borders
    for(int j=0; j<COLS; j++)
    {
        gameBoard[0][j] = '_';
        gameBoard[ROWS-1][j] = '_';
    }

    //set left and right borders
    for(int i=1; i<ROWS-1; i++)
    {
        gameBoard[i][0] = '|';
        gameBoard[i][COLS-1] = '|';
    }

    //set pellets
    for(int i=1; i<ROWS-1; i++)
    {
        for(int j=1; j<COLS-1; j++)
        {
            gameBoard[i][j] = '.';
        }
    }

    //set pacman
    gameBoard[ROWS/2][COLS/2] = 'C';

    //set ghosts
    gameBoard[ROWS/4][COLS/4] = 'G';
    gameBoard[ROWS/2][COLS/4] = 'G';
    gameBoard[ROWS/2][COLS/2] = 'G';
    gameBoard[ROWS/2 + ROWS/4][COLS/2 + COLS/4] = 'G';
}

void printGameBoard(char gameBoard[][COLS])
{
    system("clear"); //clear console

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

void movePacman(int *pacmanRow, int *pacmanCol, char direction, char gameBoard[][COLS])
{
    int newRow = *pacmanRow;
    int newCol = *pacmanCol;

    switch(direction)
    {
        case 'w':
            newRow--;
            break;
        case 'a':
            newCol--;
            break;
        case 's':
            newRow++;
            break;
        case 'd':
            newCol++;
            break;
        default:
            printf("Invalid direction.\n");
            return;
    }

    if(gameBoard[newRow][newCol] == '|'|| gameBoard[newRow][newCol] == '_' || gameBoard[newRow][newCol] == 'G')
    {
        return;
    }

    gameBoard[newRow][newCol] = 'C';
    gameBoard[*pacmanRow][*pacmanCol] = '.';
    *pacmanRow = newRow;
    *pacmanCol = newCol;
}

void moveGhosts(char gameBoard[][COLS], int ghostRow[], int ghostCol[])
{
    for(int i=0; i<4; i++)
    {
        //random direction
        int randDir = rand()%4;
        int newRow = ghostRow[i];
        int newCol = ghostCol[i];

        switch(randDir)
        {
            case 0:
                newRow--;
                break;
            case 1:
                newCol--;
                break;
            case 2:
                newRow++;
                break;
            case 3:
                newCol++;
                break;
        }

        if(gameBoard[newRow][newCol] == '|' || gameBoard[newRow][newCol] == '_' || gameBoard[newRow][newCol] == 'G')
        {
            continue;
        }

        gameBoard[newRow][newCol] = 'G';
        gameBoard[ghostRow[i]][ghostCol[i]] = '.';
        ghostRow[i] = newRow;
        ghostCol[i] = newCol;
    }
}

bool checkCollision(int pacmanRow, int pacmanCol, int ghostRow[], int ghostCol[])
{
    for(int i=0; i<4; i++)
    {
        if(pacmanRow == ghostRow[i] && pacmanCol == ghostCol[i])
        {
            return true;
        }
    }

    return false;
}

void endGame(char gameBoard[][COLS])
{
    printGameBoard(gameBoard);
    printf("Game over! Pac-man caught by the ghosts!\n");
}