//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int[], int);

int main() {
    srand(time(NULL));
    int arr[10];

    printf("Unsorted array: ");
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\nSorting...\n");
    bucketSort(arr, 10);

    printf("\nSorted array: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int size){
    int i, j;
    int* bucket = (int*) malloc(size * sizeof(int));
    int min_val = arr[0];
    int max_val = arr[0];

    for(i = 1; i < size; i++) {
        min_val = (arr[i] < min_val) ? arr[i] : min_val;
        max_val = (arr[i] > max_val) ? arr[i] : max_val;
    }

    int bucket_size = (max_val - min_val) / size + 1;
    int num_buckets = (max_val - min_val) / bucket_size + 1;

    int** buckets = (int**) malloc(num_buckets * sizeof(int*));
    for(i = 0; i < num_buckets; i++){
        buckets[i] = (int*) malloc(bucket_size * sizeof(int));
        for(j = 0; j < bucket_size; j++){
            buckets[i][j] = -1;
        }
    }

    for(i = 0; i < size; i++){
        int bi = (arr[i] - min_val) / bucket_size;
        int bj = 0;
        while(buckets[bi][bj] != -1){
            bj++;
        }
        buckets[bi][bj] = arr[i];
    }

    int index = 0;
    for(i = 0; i < num_buckets; i++){
        for(j = 0; j < bucket_size; j++){
            if(buckets[i][j] != -1){
                bucket[index++] = buckets[i][j];
            }
        }
    }

    for(i = 0; i < num_buckets; i++){
        free(buckets[i]);
    }
    free(buckets);

    printf("Bucket array: ");
    for(i = 0; i < size; i++){
        printf("%d ", bucket[i]);
    }

    for(i = 0; i < size; i++){
        arr[i] = bucket[i];
    }

    free(bucket);
}