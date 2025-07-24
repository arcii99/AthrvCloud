//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include<stdio.h>
#include<time.h>

int main()
{
    int arr[100000];
    int i,j,temp,n;

    //Populating the array with some random numbers
    for(i=0;i<100000;i++)
        arr[i] = rand()%10000;

    //Timing the Bubble Sort Algorithm
    clock_t t;
    t = clock();
    for(i=0;i<99999;i++)
    {
        for(j=0;j<99999-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    t = clock()-t;

    //Printing the sorted array
    printf("Sorted Array: ");
    for(i=0;i<100000;i++)
        printf("%d ",arr[i]);

    //Printing the execution time
    printf("\nExecution Time for Bubble Sort: %ld microseconds",t);

    return 0;
}