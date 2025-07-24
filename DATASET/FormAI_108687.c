//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ARRAY_SIZE 1000000           // constant for array size
#define BUCKET_SIZE 100              // constant for bucket size
#define MAX_VALUE ARRAY_SIZE / 10    // constant for maximum value in array

void print_array(int arr[], int size) {   //function to print array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int n) {

    int num_buckets = (MAX_VALUE / BUCKET_SIZE) + 1;  //determine number of buckets needed
    
    int buckets[num_buckets][BUCKET_SIZE], bucket_size[num_buckets];
    #pragma omp parallel for
    for (int i = 0; i < num_buckets; i++) {   //initialize buckets to size 0
        bucket_size[i] = 0;
    }

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {  //distribute elements to buckets
        int bucket_index = arr[i] / BUCKET_SIZE;
        buckets[bucket_index][bucket_size[bucket_index]] = arr[i];
        bucket_size[bucket_index]++;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_buckets; i++) {   //sort elements in each bucket using insertion sort
        int j, k, temp;
        for (j = 1; j < bucket_size[i]; j++) {
            temp = buckets[i][j];
            for (k = j - 1; k >= 0 && buckets[i][k] > temp; k--) {
                buckets[i][k + 1] = buckets[i][k];
            }
            buckets[i][k + 1] = temp;
        }
    }

    int index = 0;
    #pragma omp parallel for
    for (int i = 0; i < num_buckets; i++) {    //copy sorted elements from each bucket into main array
        for (int j = 0; j < bucket_size[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

}

int main() {
    srand(time(NULL));
    int arr[ARRAY_SIZE];

    printf("Unsorted Array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    print_array(arr, ARRAY_SIZE);

    clock_t start_time = clock();
    bucket_sort(arr, ARRAY_SIZE);
    clock_t end_time = clock();

    double time_taken = ((double)end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nSorted Array: \n");
    print_array(arr, ARRAY_SIZE);
    printf("Bucket sort took %lf seconds to execute \n", time_taken);

    return 0;
}