//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int array[10][10], i, j, m, n, searchKey, found=0;

    printf("Enter the number of rows and columns for the array (max 10) : ");
    scanf("%d %d", &m, &n);

    printf("\nEnter the elements of the array : \n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter the element at position (%d,%d) : ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("\nEnter the element to be searched : ");
    scanf("%d", &searchKey);

    printf("\nSearching for the element %d in the array...\n", searchKey);

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(array[i][j] == searchKey)
            {
                found = 1;
                printf("Element %d found at position (%d,%d)\n", searchKey, i, j);
            }
        }
    }

    if(found == 1)
    {
        printf("\nThe element %d is present in the array.\n", searchKey);
    }
    else
    {
        printf("\nThe element %d is not present in the array.\n", searchKey);
    }

    return 0;
}