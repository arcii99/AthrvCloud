//FormAI DATASET v1.0 Category: Checkers Game ; Style: romantic
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board();
void display_board();
void move_piece(int x1, int y1, int x2, int y2);

int main()
{
    int turn = 1, xp, yp, x, y;
    char p;

    initialize_board();

    do
    {
        printf("\nTurn %d:\n", turn);
        display_board();

        if (turn % 2 == 1)
            printf("\nPlayer 1's Turn (Lowercase pieces)\n");
        else
            printf("\nPlayer 2's Turn (Uppercase pieces)\n");

        printf("Enter coordinates of piece to move: ");
        scanf("%d%d", &xp, &yp);

        printf("Enter coordinates to move to: ");
        scanf("%d%d", &x, &y);

        move_piece(xp - 1, yp - 1, x - 1, y - 1);

        turn++;
    } while(1);

    return 0;
}

void initialize_board()
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if ((i + j) % 2 == 0 && i < 3) // place player 1's pieces
                board[i][j] = 'x';
            else if ((i + j) % 2 == 0 && i > 4) // place player 2's pieces
                board[i][j] = 'O';
            else
                board[i][j] = '-';
        }
    }
}

void display_board()
{
    int i, j;
    printf("\n   ");

    for (i = 1; i <= BOARD_SIZE; i++)
        printf("%d ", i);

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i + 1);

        for (j = 0; j < BOARD_SIZE; j++)
            printf("%c ", board[i][j]);

        printf("\n");
    }

    printf("\n");
}

void move_piece(int x1, int y1, int x2, int y2)
{
    char p = board[x1][y1];
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (board[x2][y2] == '-') // check if destination is empty
    {
        if (p == 'x') // lowercase piece
        {
            if (dy == 1 && (dx == -1 || dx == 1)) // single diagonal move
            {
                board[x1][y1] = '-';
                board[x2][y2] = p;
            }
            else if (dy == 2 && dx == -2 && board[x1-1][y1+1] == 'O') // jump move to the left
            {
                board[x1][y1] = '-';
                board[x1-1][y1+1] = '-';
                board[x2][y2] = p;
            }
            else if (dy == 2 && dx == 2 && board[x1+1][y1+1] == 'O') // jump move to the right
            {
                board[x1][y1] = '-';
                board[x1+1][y1+1] = '-';
                board[x2][y2] = p;
            }
            else
            {
                printf("Invalid move!\n");
            }
        }
        else if (p == 'O') // uppercase piece
        {
            if (dy == -1 && (dx == -1 || dx == 1)) // single diagonal move
            {
                board[x1][y1] = '-';
                board[x2][y2] = p;
            }
            else if (dy == -2 && dx == -2 && board[x1-1][y1-1] == 'x') // jump move to the left
            {
                board[x1][y1] = '-';
                board[x1-1][y1-1] = '-';
                board[x2][y2] = p;
            }
            else if (dy == -2 && dx == 2 && board[x1+1][y1-1] == 'x') // jump move to the right
            {
                board[x1][y1] = '-';
                board[x1+1][y1-1] = '-';
                board[x2][y2] = p;
            }
            else
            {
                printf("Invalid move!\n");
            }
        }
        else
        {
            printf("Invalid move!\n"); // not a valid piece
        }
    }
    else
    {
        printf("Destination not empty!\n"); // destination already occupied
    }
}