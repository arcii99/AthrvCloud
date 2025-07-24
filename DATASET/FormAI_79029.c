//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 //size of given array
#define BUCKET_SIZE 5 //size of each bucket


void bucket_sort(int arr[], int n)
{
    int i, j, k;
    int min_val = arr[0], max_val = arr[0];
    int bucket_count;

    for (i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    bucket_count = (max_val - min_val) / BUCKET_SIZE + 1;
    int buckets[bucket_count][BUCKET_SIZE];

    for (i = 0; i < bucket_count; i++) {
        for (j = 0; j < BUCKET_SIZE; ++j) {
            buckets[i][j] = -1;
        }
    }

    for (i = 0; i < n; i++) {
        int bucket_id = (arr[i] - min_val) / BUCKET_SIZE;
        for (j = 0; j < BUCKET_SIZE; ++j) {
            if (buckets[bucket_id][j] == -1) {
                buckets[bucket_id][j] = arr[i];
                break;
            }
        }
    }

    for (i = 0; i < bucket_count; i++) {
        int index = 0;
        for (j = 0; j < BUCKET_SIZE; ++j) {
            if (buckets[i][j] != -1) {
                arr[index++] = buckets[i][j];
            } else {
                break;
            }
        }
    }
}
//function to print a given array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[SIZE] = { 13, 24, 31, 44, 55, 66, 72, 86, 94, 100};

    printf("Unsorted Array:\n");
    print_array(arr, SIZE);

    bucket_sort(arr, SIZE);

    printf("Sorted Array:\n");
    print_array(arr, SIZE);

    return 0;
}