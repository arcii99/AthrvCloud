//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

void bucketSort(float arr[], int n){
    int i, j;  
    float *buckets[n];
    for (i = 0; i < n; i++){
        buckets[i] = NULL;
    }
    for (i = 0; i < n; i++){
        int index = n*arr[i];
        if (buckets[index] == NULL){
            buckets[index] = (float*)malloc(sizeof(float));
            buckets[index][0] = arr[i];
        } else {
            int bucket_size = sizeof(buckets[index])/sizeof(buckets[index][0]);
            buckets[index] = (float*)realloc(buckets[index], (bucket_size+1)*sizeof(float));
            buckets[index][bucket_size] = arr[i];
        }
    }
    int k=0;
    for (i = 0; i < n; i++){
        if (buckets[i] != NULL){
            int bucket_size = sizeof(buckets[i])/sizeof(buckets[i][0]);
            insertion_sort(buckets[i], bucket_size);
            for (j = 0; j < bucket_size; j++){
                arr[k++] = buckets[i][j];
            }
        }
    }
}

void insertion_sort(float arr[], int n){
    int i,j;
    float key;
    for (i = 1 ; i < n ; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    float arr[n];
    for (i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%f", &arr[i]);
    }
    bucketSort(arr, n);
    printf("\nThe sorted array is: ");
    for (i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}