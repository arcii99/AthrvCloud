//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include<stdio.h>
#include<stdlib.h>

void bucketSort(int arr[], int n)
{
    int i, j, k;
    int min_val = arr[0], max_val = arr[0];
    int num_buckets, bucket_size;
    for(i=0;i<n;i++)
    {
        if(arr[i]<min_val)
            min_val = arr[i];
        if(arr[i]>max_val)
            max_val = arr[i];
    }
    num_buckets = max_val/5 - min_val/5 + 1;
    bucket_size = 5;
    int *buckets[num_buckets];
    for(i=0;i<num_buckets;i++)
        buckets[i] = (int*)calloc(bucket_size,sizeof(int));
    for(i=0;i<n;i++)
    {
        int bucket_index = (arr[i]/bucket_size) - (min_val/bucket_size);
        for(j=0;j<bucket_size;j++)
        {
            if(buckets[bucket_index][j]==0)
            {
                buckets[bucket_index][j] = arr[i];
                break;
            }
        }
    }
    for(i=0;i<num_buckets;i++)
    {
        for(j=0;j<bucket_size;j++)
        {
            for(k=0;k<bucket_size-1;k++)
            {
                if(buckets[i][k]>buckets[i][k+1])
                {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k+1];
                    buckets[i][k+1] = temp;
                }
            }
        }
    }
    int index = 0;
    for(i=0;i<num_buckets;i++)
    {
        for(j=0;j<bucket_size;j++)
        {
            if(buckets[i][j]!=0)
                arr[index++] = buckets[i][j];
        }
    }
    for(i=0;i<num_buckets;i++)
        free(buckets[i]);
}
int main()
{
    int arr[] = {23,12,45,67,43,25,10,67,82,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    bucketSort(arr,n);
    printf("\nSorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    return 0;
}