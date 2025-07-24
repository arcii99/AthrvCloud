//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>

int main()
{
    printf("Holy cow, I can't believe how easy it is to do matrix operations with C!\n");
    printf("I mean, look at this: \n\n");

    int matrix1[2][3] = {{1, 2, 3},
                         {4, 5, 6}};

    int matrix2[2][3] = {{7, 8, 9},
                         {10, 11, 12}};

    printf("Matrix 1: \n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2: \n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\nAdding matrices 1 and 2... \n");
    int sum[2][3];
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nResulting matrix: \n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    printf("\nMultiplying matrices 1 and 2... \n");
    int product[2][3];
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            product[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }

    printf("\nResulting matrix: \n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    printf("\n\nWoohoo! That was so easy. I'm blown away. C truly is a powerful language. Bye for now!\n");

    return 0;
}