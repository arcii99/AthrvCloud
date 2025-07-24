//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initialize(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '~';
        }
    }
}

void display(char board[ROWS][COLS])
{
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d  ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void simulate(char board[ROWS][COLS], int direction)
{
    int x, y;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'O') {
                x = i;
                y = j;
                board[i][j] = '~';
                break;
            }
        }
    }

    switch (direction) {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
    }

    if (x < 0) {
        x = ROWS - 1;
    } else if (x >= ROWS) {
        x = 0;
    }

    if (y < 0) {
        y = COLS - 1;
    } else if (y >= COLS) {
        y = 0;
    }

    board[x][y] = 'O';
}

int main()
{
    char board[ROWS][COLS];
    int direction;
    initialize(board);
    srand(time(NULL));
    board[rand() % ROWS][rand() % COLS] = 'O';
    display(board);

    while (1) {
        printf("Enter the direction you want to simulate (1 = up, 2 = down, 3 = left, 4 = right): ");
        scanf("%d", &direction);
        simulate(board, direction);
        system("clear||cls");
        display(board);
    }

    return 0;
}