//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* define the bucket size */
#define BUCKET_SIZE 10

/* define the bucket structure */
struct bucket {
    int data[BUCKET_SIZE];
    int count;
};

/* function to perform bucket sort */
void bucket_sort(int arr[], int n) {
    int i, j, k;
    struct bucket buckets[BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].count = 0;
    }
    /* distribute the elements of the input array to the appropriate buckets */
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        if (bucket_index >= BUCKET_SIZE) {
            bucket_index = BUCKET_SIZE - 1;
        }
        buckets[bucket_index].data[buckets[bucket_index].count++] = arr[i];
    }
    /* sort each bucket */
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < buckets[i].count - 1; j++) {
            for (k = 0; k < buckets[i].count - j - 1; k++) {
                if (buckets[i].data[k] > buckets[i].data[k + 1]) {
                    int temp = buckets[i].data[k];
                    buckets[i].data[k] = buckets[i].data[k + 1];
                    buckets[i].data[k + 1] = temp;
                }
            }
        }
    }
    /* concatenate the sorted buckets */
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].data[j];
        }
    }
}

/* function to print an array */
void print_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int n = 100;
    int arr[100];
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    printf("Unsorted array:\n");
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}