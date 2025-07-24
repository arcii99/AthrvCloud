//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include<stdio.h>

void bucketSort(int arr[], int n)
{
    // Create 10 buckets
    int bucket[10][10], bucket_count[10];
    
    // Get maximum number in the array
    int max_val = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max_val)
        {
            max_val = arr[i];
        }   
    }

    // Count the number of digits in max_val
    int digit_count = 0;
    while(max_val != 0)
    {
        digit_count++;
        max_val /= 10;
    }

    // Iterate through each digit
    for(int digit = 1; digit <= digit_count; digit++)
    {
        // Initialize bucket_count for each bucket to 0
        for(int i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }

        // Place each element in the appropriate bucket
        for(int i = 0; i < n; i++)
        {
            int bucket_index = (arr[i] / (int)pow(10, digit - 1)) % 10;
            bucket[bucket_index][bucket_count[bucket_index]++] = arr[i];
        }

        // Place the elements of each bucket back into the array
        int index = 0;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < bucket_count[i]; j++)
            {
                arr[index++] = bucket[i][j];
            }
        }
    }
}

int main()
{
    int arr[] = {3, 7, 1, 9, 55, 22, 4, 11, 67, 89, 100, 31};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}