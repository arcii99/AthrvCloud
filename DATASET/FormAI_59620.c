//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>

#define N 9

int grid[N][N];

int row_has_number(int r, int n)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[r][i] == n)
            return 1;
    }

    return 0;
}

int col_has_number(int c, int n)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][c] == n)
            return 1;
    }

    return 0;
}

int box_has_number(int r, int c, int n)
{
    int box_r = r - (r % 3);
    int box_c = c - (c % 3);

    for (int i = box_r; i < box_r + 3; i++)
    {
        for (int j = box_c; j < box_c + 3; j++)
        {
            if (grid[i][j] == n)
                return 1;
        }
    }

    return 0;
}

int is_valid(int r, int c, int n)
{
    return !row_has_number(r, n) && !col_has_number(c, n) && !box_has_number(r, c, n);
}

void print_grid()
{
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", grid[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int solve_sudoku()
{
    int row = -1;
    int col = -1;
    int empty = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;

                empty = 1;
                break;
            }
        }

        if (empty)
            break;
    }

    if (!empty)
        return 1;

    for (int n = 1; n <= N; n++)
    {
        if (is_valid(row, col, n))
        {
            grid[row][col] = n;

            if (solve_sudoku())
                return 1;

            grid[row][col] = 0;
        }
    }

    return 0;
}

int main()
{
    // Initialize grid
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set initial values
    grid[0][1] = 7;
    grid[0][3] = 3;
    grid[0][4] = 4;
    grid[0][6] = 9;
    grid[1][2] = 8;
    grid[1][3] = 2;
    grid[1][5] = 7;
    grid[2][2] = 3;
    grid[2][3] = 8;
    grid[2][5] = 5;
    grid[2][7] = 6;
    grid[3][0] = 6;
    grid[3][3] = 9;
    grid[3][4] = 7;
    grid[3][5] = 2;
    grid[3][8] = 8;
    grid[4][0] = 1;
    grid[4][8] = 6;
    grid[5][0] = 8;
    grid[5][3] = 7;
    grid[5][4] = 6;
    grid[5][5] = 1;
    grid[5][8] = 2;
    grid[6][1] = 2;
    grid[6][3] = 5;
    grid[6][5] = 9;
    grid[6][7] = 7;
    grid[7][3] = 4;
    grid[7][5] = 3;
    grid[7][6] = 1;
    grid[7][7] = 9;
    grid[8][2] = 5;
    grid[8][4] = 1;
    grid[8][6] = 3;
    grid[8][7] = 2;

    print_grid();

    if (solve_sudoku())
    {
        printf("Solution found!\n");
        print_grid();
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}