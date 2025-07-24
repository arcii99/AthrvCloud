//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printBoard(int board[][4], int score);
int generateRandomTile();
int gameWon(int board[][4]);
int gameLost(int board[][4]);
void moveLeft(int board[][4], int* score);
void moveRight(int board[][4], int* score);
void moveUp(int board[][4], int* score);
void moveDown(int board[][4], int* score);

int main()
{
    int board[4][4] = {0};  // initialize board to all zeroes
    int score = 0;  // initialize score to zero
    srand(time(NULL));  // seed random number generator with current time

    // randomly generate two starting tiles
    board[rand() % 4][rand() % 4] = generateRandomTile();
    board[rand() % 4][rand() % 4] = generateRandomTile();

    // print initial board state
    printf("Welcome to 2048 Terminal Edition!\n");
    printBoard(board, score);

    // game loop
    while (!gameWon(board) && !gameLost(board))
    {
        char move;
        printf("Enter your move (w: up, s: down, a: left, d: right): ");
        scanf(" %c", &move);

        switch (move)
        {
            case 'w':
                moveUp(board, &score);
                break;
            case 's':
                moveDown(board, &score);
                break;
            case 'a':
                moveLeft(board, &score);
                break;
            case 'd':
                moveRight(board, &score);
                break;
            default:
                printf("Invalid move, try again.\n");
                continue;  // go back to beginning of loop
        }

        // generate new random tile after valid move
        int x = rand() % 4;
        int y = rand() % 4;
        while (board[x][y] != 0)  // keep searching for empty slot
        {
            x = rand() % 4;
            y = rand() % 4;
        }
        board[x][y] = generateRandomTile();

        printBoard(board, score);
    }

    // print game over message
    if (gameWon(board))
    {
        printf("Congratulations, you won with a score of %d!\n", score);
    }
    else
    {
        printf("Game over, your final score was %d.\n", score);
    }

    return 0;
}

void printBoard(int board[][4], int score)
{
    printf("Score: %d\n", score);
    printf("+------+------+------+------+\n");
    for (int i = 0; i < 4; i++)
    {
        printf("|");
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                printf("      |");
            }
            else
            {
                printf("%6d|", board[i][j]);
            }
        }
        printf("\n+------+------+------+------+\n");
    }
}

int generateRandomTile()
{
    return (rand() % 2 == 0) ? 2 : 4;  // 50/50 chance of returning 2 or 4
}

int gameWon(int board[][4])
{
    // check for a tile with the value 2048
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
            {
                return 1;  // game won!
            }
        }
    }
    return 0;  // game not won yet
}

int gameLost(int board[][4])
{
    // check for any empty slots
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;  // game not lost yet
            }
        }
    }

    // check for any adjacent tiles with the same value
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i < 3 && board[i][j] == board[i+1][j])
            {
                return 0;  // game not lost yet
            }
            if (j < 3 && board[i][j] == board[i][j+1])
            {
                return 0;  // game not lost yet
            }
        }
    }

    return 1;  // game lost
}

void moveLeft(int board[][4], int* score)
{
    for (int i = 0; i < 4; i++)
    {
        int prev = -1;  // previous non-zero tile
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                continue;  // skip empty tiles
            }
            if (prev == -1)
            {
                prev = j;  // remember previous non-zero tile
            }
            else if (board[i][prev] == board[i][j])
            {
                // merge tiles if they have the same value
                *score += board[i][j] * 2;
                board[i][prev] = board[i][j] * 2;
                board[i][j] = 0;
                prev = -1;  // reset prev for next pair
            }
            else
            {
                // move tile to empty slot
                board[i][prev+1] = board[i][j];
                board[i][j] = 0;
                prev += 1;  // update prev
            }
        }
    }
}

void moveRight(int board[][4], int* score)
{
    for (int i = 0; i < 4; i++)
    {
        int prev = -1;  // previous non-zero tile
        for (int j = 3; j >= 0; j--)
        {
            if (board[i][j] == 0)
            {
                continue;  // skip empty tiles
            }
            if (prev == -1)
            {
                prev = j;  // remember previous non-zero tile
            }
            else if (board[i][prev] == board[i][j])
            {
                // merge tiles if they have the same value
                *score += board[i][j] * 2;
                board[i][prev] = board[i][j] * 2;
                board[i][j] = 0;
                prev = -1;  // reset prev for next pair
            }
            else
            {
                // move tile to empty slot
                board[i][prev-1] = board[i][j];
                board[i][j] = 0;
                prev -= 1;  // update prev
            }
        }
    }
}

void moveUp(int board[][4], int* score)
{
    for (int j = 0; j < 4; j++)
    {
        int prev = -1;  // previous non-zero tile
        for (int i = 0; i < 4; i++)
        {
            if (board[i][j] == 0)
            {
                continue;  // skip empty tiles
            }
            if (prev == -1)
            {
                prev = i;  // remember previous non-zero tile
            }
            else if (board[prev][j] == board[i][j])
            {
                // merge tiles if they have the same value
                *score += board[i][j] * 2;
                board[prev][j] = board[i][j] * 2;
                board[i][j] = 0;
                prev = -1;  // reset prev for next pair
            }
            else
            {
                // move tile to empty slot
                board[prev+1][j] = board[i][j];
                board[i][j] = 0;
                prev += 1;  // update prev
            }
        }
    }
}

void moveDown(int board[][4], int* score)
{
    for (int j = 0; j < 4; j++)
    {
        int prev = -1;  // previous non-zero tile
        for (int i = 3; i >= 0; i--)
        {
            if (board[i][j] == 0)
            {
                continue;  // skip empty tiles
            }
            if (prev == -1)
            {
                prev = i;  // remember previous non-zero tile
            }
            else if (board[prev][j] == board[i][j])
            {
                // merge tiles if they have the same value
                *score += board[i][j] * 2;
                board[prev][j] = board[i][j] * 2;
                board[i][j] = 0;
                prev = -1;  // reset prev for next pair
            }
            else
            {
                // move tile to empty slot
                board[prev-1][j] = board[i][j];
                board[i][j] = 0;
                prev -= 1;  // update prev
            }
        }
    }
}