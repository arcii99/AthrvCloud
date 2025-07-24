//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns, i, j;
    printf("Enter the number of rows and columns for your surreal matrix: ");
    scanf("%d %d", &rows, &columns);

    int matrix[rows][columns], sum = 0;

    printf("Enter the integer elements of your surreal matrix:\n");

    for(i=0; i<rows; i++)
        for(j=0; j<columns; j++)
            scanf("%d", &matrix[i][j]);

    printf("\nYour surreal matrix is:\n");

    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
            sum += matrix[i][j];
        }
        printf("\n");
    }

    printf("\nThe sum of all the elements in your surreal matrix is %d\n", sum);

    int randomIndex = rand() % rows;
    int randomRow[columns];

    for(j=0; j<columns; j++) {
        randomRow[j] = matrix[randomIndex][j];
    }

    printf("\nA random 'surreal' row from your matrix is:\n");

    for(j=0; j<columns; j++) {
        printf("%d ", randomRow[j]);
    }

    printf("\n\nThank you for indulging in the surreal matrix madness!\n");

    return 0;
}