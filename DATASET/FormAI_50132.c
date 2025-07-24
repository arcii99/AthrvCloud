//FormAI DATASET v1.0 Category: Data mining ; Style: energetic
#include<stdio.h>

int main()
{
    int i, j, n, m;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);

    // Dynamically allocate memory for 2D array
    int** array = (int**) malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++)
        array[i] = (int*) malloc(sizeof(int) * m);

    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    // Data mining algorithm starts here
    printf("The sparse matrix representation is:\n");
    for(i = 0; i < n; i++)
    {
        int count = 0;
        for(j = 0; j < m; j++)
        {
            if(array[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, array[i][j]);
                count++;
            }
        }
        if(count == 0)
            printf("Row %d has no non-zero elements\n", i);
    }

    // Free dynamically allocated memory
    for(i = 0; i < n; i++)
        free(array[i]);
    free(array);

    return 0;
}