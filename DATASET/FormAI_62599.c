//FormAI DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#define ROW 2
#define COL 3

void matrix_multiply(int a[ROW][COL], int b[COL][ROW], int result[ROW][ROW]);

int main()
{
    int a[ROW][COL] = {{1, 1, 1}, {2, 2, 2}};
    int b[COL][ROW] = {{1, 2}, {1, 2}, {1, 2}};
    int result[ROW][ROW];
    matrix_multiply(a, b, result);
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < ROW; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void matrix_multiply(int a[ROW][COL], int b[COL][ROW], int result[ROW][ROW])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < ROW; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < COL; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}