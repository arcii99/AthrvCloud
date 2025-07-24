//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

void print_board(bool board[][COLUMNS], int points);
void initialize_board(bool board[][COLUMNS]);
int get_random_number(int min, int max);
bool shoot(bool board[][COLUMNS], int row, int column);

int main(void)
{
    srand(time(NULL));
    bool board[ROWS][COLUMNS];
    int points = 0;
    int shots = 0;

    initialize_board(board);
    print_board(board, points);
    printf("Welcome to the Battleship game!\n");

    while (points < 5) {
        int row = get_random_number(0, ROWS - 1);
        int column = get_random_number(0, COLUMNS - 1);
        if (!board[row][column]) {
            if (shoot(board, row, column)) {
                printf("You hit a ship!\n");
                points++;
            } else {
                printf("You missed.\n");
            }
            shots++;
        }
    }

    printf("Congratulations! You sank all the ships with %d shots.\n", shots);

    return 0;
}

void print_board(bool board[][COLUMNS], int points)
{
    printf("Points: %d\n", points);
    printf("\n   ");
    for (int i = 0; i < COLUMNS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j]) {
                printf("O ");
            } else {
                printf("~ ");
            }
        }
        printf("\n");
    }
}

void initialize_board(bool board[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = false;
        }
    }
    for (int i = 0; i < 5; i++) {
        int row = get_random_number(0, ROWS - 1);
        int column = get_random_number(0, COLUMNS - 1);
        if (!board[row][column]) {
            board[row][column] = true;
        } else {
            i--;  // try again
        }
    }
}

int get_random_number(int min, int max)
{
    return min + rand() % (max - min + 1);
}

bool shoot(bool board[][COLUMNS], int row, int column)
{
    if (board[row][column]) {
        board[row][column] = false;
        return true;
    } else {
        return false;
    }
}