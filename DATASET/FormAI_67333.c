//FormAI DATASET v1.0 Category: Game ; Style: complete
#include<stdio.h> // stdio.h header file for standard input and output

int main() // main function
{
    int n; // integer variable
    printf("Enter the size of the square matrix: "); // display message
    scanf("%d", &n); // read input from user

    int arr[n][n]; // declaration of 2d array

    printf("\nMatrix elements: \n"); // display message

    // loop for getting matrix elements
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("Enter a[%d][%d]: ",i,j); // display message
            scanf("%d",&arr[i][j]); // read input element
        }
        printf("\n"); // add new line for each iteration
    }

    printf("\nMatrix: \n"); // display message

    // loop for printing matrix elements
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t",arr[i][j]); // print element with tab space
        }
        printf("\n"); // add new line for each iteration
    }

    printf("\nDiagonal elements: "); // display message

    // loop for getting diagonal elements
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i][i]); // print diagonal element
    }

    return 0; // program executed successfully
}