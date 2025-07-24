//FormAI DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COLUMN 4

void print_board(char board[ROW][COLUMN])
{
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n\n");
    }
}

int main()
{
    srand(time(NULL));

    char board[ROW][COLUMN] = {{'1', '2', '3', '4'},
                               {'5', '6', '7', '8'},
                               {'1', '2', '3', '4'},
                               {'5', '6', '7', '8'}};

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            int r = rand() % ROW;
            int c = rand() % COLUMN;

            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }

    print_board(board);

    return 0;
}