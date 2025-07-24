//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

int arr[MAX];

void quicksort(int left, int right)
{
    int i, j, pivot, temp;

    if(left < right)
    {
        pivot = left;
        i = left;
        j = right;

        while(i < j)
        {
            while(arr[i] <= arr[pivot] && i < right)
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

        quicksort(left, j-1);
        quicksort(j+1, right);
    }
}

int main()
{
    srand(time(NULL));
    for(int i = 0; i < MAX; i++)
        arr[i] = rand() % MAX;

    clock_t t;
    t = clock();

    quicksort(0, MAX-1);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Data sorted in %f seconds\n", time_taken);
    return 0;
}