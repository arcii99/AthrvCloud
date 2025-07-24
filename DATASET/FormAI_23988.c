//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 1000000

int main()
{
    int i;
    double start_time, end_time;

    /* Create a random array of SIZE */
    int *arr = (int *)malloc(SIZE * sizeof(int));
    srand(time(NULL));

    for(i=0; i<SIZE; i++)
        arr[i] = rand() % 10000;

    /* Calculate time taken for sorting the array */
    start_time = (double)clock() / CLOCKS_PER_SEC;
    quick_sort(arr, 0, SIZE-1);
    end_time = (double)clock() / CLOCKS_PER_SEC;

    printf("Time taken = %lf seconds\n", end_time - start_time);

    return 0;
}

/* Quick sort implementation */
void quick_sort(int *arr, int start, int end)
{
    int pivot, i, j, temp;

    if(start < end)
    {
        pivot = start;
        i = start;
        j = end;

        while(i < j)
        {
            while(arr[i] <= arr[pivot] && i < end)
                i++;

            while(arr[j] > arr[pivot])
                j--;

            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quick_sort(arr, start, j-1);
        quick_sort(arr, j+1, end);
    }
}