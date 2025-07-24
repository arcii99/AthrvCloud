//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 5

void bucket_sort(int *arr);

int main()
{
    int arr[ARRAY_SIZE] = {7, 3, 5, 1, 6, 8, 4, 9, 2, 0};

    bucket_sort(arr);

    printf("Sorted array: ");
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucket_sort(int *arr)
{
    int buckets[BUCKET_SIZE][BUCKET_SIZE] = {{0}};
    int bucket_count[BUCKET_SIZE] = {0};

    for(int i=0; i<ARRAY_SIZE; i++)
    {
        int bucket_index = arr[i] / BUCKET_SIZE;
        int index = bucket_count[bucket_index];
        buckets[bucket_index][index] = arr[i];
        bucket_count[bucket_index]++;

        while (index > 0 && buckets[bucket_index][index] < buckets[bucket_index][index-1])
        {
            int temp = buckets[bucket_index][index];
            buckets[bucket_index][index] = buckets[bucket_index][index-1];
            buckets[bucket_index][index-1] = temp;
            index--;
        }
    }

    int index = 0;
    for(int i=0; i<BUCKET_SIZE; i++)
    {
        for(int j=0; j<bucket_count[i]; j++)
        {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}