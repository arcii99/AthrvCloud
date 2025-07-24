//FormAI DATASET v1.0 Category: Sorting ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, size_t n){
    srand(time(NULL));
    if(n > 1){
        size_t i;
        for(i = 0; i < n - 1; i++){
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

void bubble_sort(int *arr, size_t n){
    for(size_t i = 0; i < n - 1; i++){
        for(size_t j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
}

int main(){
    int arr[] = {23, 67, 89, 12, 45, 90, 34, 17, 56, 100};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    shuffle(arr, n);
    printf("Before Sorting:\n");
    for(size_t i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, n);
    printf("After Sorting:\n");
    for(size_t i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}