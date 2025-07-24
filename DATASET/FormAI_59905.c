//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

void bucketSort(float arr[], int n)
{
    int i, j;
    float value;
    int **bucket;
    bucket = malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        bucket[i] = malloc(n*sizeof(int));
        
    for(i=0;i<n;i++)
    {
        int count = 0;
        value = arr[i];
        for(j=0;j<n;j++)
        {
            if(bucket[j][count] == -10)
                break;
            if(bucket[j][count] < value)
                continue;
            else
            {
                while(bucket[j][count] == value)
                    count++;
                while(bucket[j][count] > -10 && bucket[j][count] < value)
                    count++;
                break;
            }
        }
        for(int k=j;k<n;k++)
        {
            int temp = bucket[k][count];
            bucket[k][count] = value;
            value = temp;
            if(value == -10)
                break;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(bucket[j][i] == -10)
                break;
            printf("%f ", bucket[j][i]);
        }
    }
}

int main()
{
    float arr[] = {0.56, 0.68, 0.81, 0.07, 0.31, 0.59};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Elements before sorting: ");
    for(int i=0;i<n;i++)
        printf("%f ", arr[i]);
    bucketSort(arr, n);
    return 0;
}