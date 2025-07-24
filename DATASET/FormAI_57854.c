//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

#define BUCKET_SIZE 10

int compare(int a, int b){
    return (a < b) ? -1 : (int)(a > b);
}

void bucketSort(int *arr, int size){
    int i, j;
    int max_val = arr[0];
    for(i = 1; i < size; i++)
        max_val = (max_val < arr[i]) ? arr[i] : max_val;

    int num_buckets = max_val / BUCKET_SIZE + 1;
    int **buckets = (int **)malloc(sizeof(int *) * num_buckets);
    for(i = 0; i < num_buckets; i++)
        buckets[i] = (int *)malloc(sizeof(int) * size);

    int *bucket_sizes = (int *)calloc(num_buckets, sizeof(int));

    for(i = 0; i < size; i++){
        int k = arr[i] / BUCKET_SIZE;
        buckets[k][bucket_sizes[k]++] = arr[i];
    }

    for(i = 0; i < num_buckets; i++){
        for(j = 0; j < bucket_sizes[i]; j++){
            int k = j;
            while(k > 0 && compare(buckets[i][k - 1], buckets[i][k]) > 0){
                int temp = buckets[i][k];
                buckets[i][k] = buckets[i][k - 1];
                buckets[i][k - 1] = temp;
                k--;
            }
        }
    }

    int index = 0;
    for(i = 0; i < num_buckets; i++){
        for(j = 0; j < bucket_sizes[i]; j++){
            arr[index++] = buckets[i][j];
        }
    }

    for(i = 0; i < num_buckets; i++)
        free(buckets[i]);
    free(buckets);
    free(bucket_sizes);
}

int main(){
    int arr[] = { 19, 53, 29, 30, 89, 35, 17, 33, 8, 65, 45, 62, 91, 18, 82 };
    int size = sizeof(arr) / sizeof(*arr);
    printf("Input array:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, size);
    printf("Sorted array:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}