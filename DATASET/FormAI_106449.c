//FormAI DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //Declare Variables
    int matrix[3][3], sum=0, i, j, determinant;

    //Get Matrix elements
    printf("Please enter the elements of a 3x3 matrix: \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    //Display Matrix
    printf("\nThe entered matrix is:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    //Calculate Determinant
    determinant = (matrix[0][0]*matrix[1][1]*matrix[2][2]) + (matrix[0][1]*matrix[1][2]*matrix[2][0]) + (matrix[0][2]*matrix[1][0]*matrix[2][1]) - (matrix[0][2]*matrix[1][1]*matrix[2][0]) - (matrix[0][0]*matrix[1][2]*matrix[2][1]) - (matrix[0][1]*matrix[1][0]*matrix[2][2]);

    //Display Determinant
    printf("\nThe determinant of the matrix is %d\n", determinant);

    return 0;

}