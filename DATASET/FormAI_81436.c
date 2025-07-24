//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#define SIZE 10

void bucketSort(int array[], int n)
{
    // Create n empty buckets
    int bucket[SIZE][SIZE] = {0};
 
    // Sort each element of the array into its respective bucket
    for (int i = 0; i < n; i++)
    {
        int index = array[i] / SIZE;
        for (int j = 0; j < SIZE; j++)
        {
            if (bucket[index][j] == 0)
            {
                bucket[index][j] = array[i];
                break;
            }
        }
    }
 
    // Sort each bucket
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = j + 1; k < SIZE; k++)
            {
                if (bucket[i][j] > bucket[i][k])
                {
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }
 
    // Concatenate the buckets
    int index = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (bucket[i][j] != 0)
            {
                array[index] = bucket[i][j];
                index++;
            }
        }
    }
}

int main()
{
    int array[SIZE] = {29, 25, 3, 49, 9, 37, 21, 43, 17, 31};
 
    printf("Before sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
 
    bucketSort(array, SIZE);
 
    printf("After sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
 
    return 0;
}