//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define a Bucket for Sorting
struct bucket {
    int count;
    int* value_arr;
};

// Function to sort the given array using bucket sort
void bucket_sort(int arr[], int n, int bucket_count)
{
    int min_value = arr[0], max_value = arr[0];
    
    // Find the minimum and maximum values in the array
    for(int i=1; i<n; i++) {
        if(arr[i] < min_value) {
            min_value = arr[i];
        } else if(arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    
    // Calculate the range and the size of each bucket
    double range = (double)(max_value - min_value + 1) / bucket_count;
    struct bucket* buckets = (struct bucket*)calloc(bucket_count, sizeof(struct bucket)); 
    
    for(int i=0; i<bucket_count; i++) {
        buckets[i].count = 0;
        buckets[i].value_arr = (int*)malloc(n * sizeof(int));
    }
    
    // Place array elements in their respective bucket
    for(int i=0; i<n; i++) {
        int bucket_index = (int)((arr[i] - min_value) / range);
        if(bucket_index >= bucket_count) {
            bucket_index = bucket_count - 1;
        }
        buckets[bucket_index].value_arr[buckets[bucket_index].count++] = arr[i];
    }
    
    // Sort each bucket using Insertion Sort and concatenate the sorted buckets
    int k = 0;
    for(int i=0; i<bucket_count; i++) {
        int j = 0, count = buckets[i].count;
        int *values = buckets[i].value_arr;
        for(int j=1;j<count;j++) {
            int key = values[j];
            int k = j-1;
            while(k>=0 && values[k]>key) {
                values[k+1] = values[k];
                k--;
            }
            values[k+1] = key;
            k = k + 1;
        }

        for(int j=0; j<count; j++) {
            arr[k++] = values[j];
        }
        free(values);
    }
    free(buckets);
}

int main()
{
    int arr[] = {31, 23, 2, 17, 26, 22, 18, 5, 12, 40, 14, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int bucket_count = 4;
    printf("Original Array : ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n, bucket_count);
    printf("Bucket Sorted Array : ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}