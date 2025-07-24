//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

//Function to perform bucket sort
void bucketSort(float arr[], int n)
{
    int i, j;
    //Create n buckets
    int bucket[n];
    //Initialize all buckets with 0 items
    memset(bucket, 0, sizeof(bucket));
    //Put array elements in different buckets
    for (i = 0; i < n; i++)
    {
        int bucket_index = n * arr[i];
        bucket[bucket_index]++;
    }
    //Sort individual buckets
    for (i = 0; i < n; i++)
    {
        //Insertion sort for each bucket
        for (j = 0; j < bucket[i]; j++)
        {
            int k;
            float temp = arr[j];
            //Find correct position of current bucket element in the array
            for (k = j - 1; k >= 0 && arr[k] > temp; k--)
            {
                arr[k + 1] = arr[k];
            }
            arr[k + 1] = temp;
        }
    }
}

int main()
{
    float values[MAX_INPUT_SIZE];
    char input[MAX_INPUT_SIZE];
    int total_values = 0;
    printf("Enter the values to be sorted: ");
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " ");
    while(token != NULL)
    {
        values[total_values++] = atof(token);
        token = strtok(NULL, " ");
    }
    bucketSort(values, total_values);
    printf("Sorted values: ");
    int i;
    for(i = 0; i < total_values; i++)
    {
        printf("%.2f ", values[i]);
    }
    printf("\n");
    return 0;
}