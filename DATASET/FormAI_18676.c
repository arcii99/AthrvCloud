//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>

#define SUDOKU_SIZE 9

int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];

int is_safe(int row, int col, int num)
{
    // Check row
    for (int c = 0; c < SUDOKU_SIZE; c++)
        if (puzzle[row][c] == num)
            return 0;

    // Check column
    for (int r = 0; r < SUDOKU_SIZE; r++)
        if (puzzle[r][col] == num)
            return 0;

    // Check subgrid
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (puzzle[subgrid_row + r][subgrid_col + c] == num)
                return 0;

    return 1;
}

int solve_sudoku(int row, int col)
{
    if (row == SUDOKU_SIZE)
        return 1;

    if (puzzle[row][col] != 0)
    {
        if (col == SUDOKU_SIZE - 1)
            return solve_sudoku(row + 1, 0);
        else
            return solve_sudoku(row, col + 1);
    }

    for (int num = 1; num <= SUDOKU_SIZE; num++)
    {
        if (is_safe(row, col, num))
        {
            puzzle[row][col] = num;
            if (col == SUDOKU_SIZE - 1)
            {
                if (solve_sudoku(row + 1, 0))
                    return 1;
            }
            else
            {
                if (solve_sudoku(row, col + 1))
                    return 1;
            }
        }
    }

    puzzle[row][col] = 0;
    return 0;
}

void print_sudoku()
{
    printf("|--------------|\n");
    for (int r = 0; r < SUDOKU_SIZE; r++)
    {
        printf("|");
        for (int c = 0; c < SUDOKU_SIZE; c++)
        {
            if (puzzle[r][c] != 0)
                printf("%d", puzzle[r][c]);
            else
                printf(".");
            if ((c + 1) % 3 == 0)
                printf("|");
        }
        printf("\n");
        if ((r + 1) % 3 == 0)
            printf("|--------------|\n");
    }
}

int main()
{
    // Set up initial puzzle
    puzzle[0][0] = 5;
    puzzle[0][1] = 3;
    puzzle[0][4] = 7;
    puzzle[1][0] = 6;
    puzzle[1][3] = 1;
    puzzle[1][4] = 9;
    puzzle[1][5] = 5;
    puzzle[2][1] = 9;
    puzzle[2][2] = 8;
    puzzle[2][7] = 6;
    puzzle[3][0] = 8;
    puzzle[3][4] = 6;
    puzzle[3][8] = 3;
    puzzle[4][0] = 4;
    puzzle[4][3] = 8;
    puzzle[4][5] = 3;
    puzzle[4][8] = 1;
    puzzle[5][0] = 7;
    puzzle[5][4] = 2;
    puzzle[5][8] = 6;
    puzzle[6][1] = 6;
    puzzle[6][6] = 2;
    puzzle[6][7] = 8;
    puzzle[7][3] = 4;
    puzzle[7][4] = 1;
    puzzle[7][5] = 9;
    puzzle[7][8] = 5;
    puzzle[8][4] = 8;
    puzzle[8][7] = 7;
    puzzle[8][8] = 9;

    print_sudoku();
    printf("\nSolving...\n\n");
    solve_sudoku(0, 0);
    print_sudoku();

    return 0;
}