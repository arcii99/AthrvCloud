//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 5

void bucket_sort(int arr[ARRAY_SIZE]);

int main() {

    // Surrealist elements via initialization
    srand(time(NULL)); // randomize seed
    int arr[ARRAY_SIZE] = {0}; 
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100; // populate array with randomized digits
        printf("%d ", arr[i]); // print original unsorted array
    }
    printf("\n\n");
    
    bucket_sort(arr); // function call to perform bucket sort
    
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]); // print sorted bucket
    }
    printf("\n");
    
    return 0;
}

void bucket_sort(int arr[ARRAY_SIZE]) {
    
    // Surrealist elements via set-up
    int bucket[BUCKET_SIZE][ARRAY_SIZE] = {0}; 
    int bucket_count[BUCKET_SIZE] = {0}; 
    
    for(int i = 0; i < ARRAY_SIZE; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE; // determine which bucket the element belongs to
        int element_index = bucket_count[bucket_index]; // set the index in the corresponding bucket
        bucket[bucket_index][element_index] = arr[i]; // add element to bucket
        bucket_count[bucket_index]++; // increment counter for that bucket
    }
    
    // Surrealist elements via sorting of the buckets
    for(int i = 0; i < BUCKET_SIZE; i++) { // go through each bucket
        for(int j = 0; j < bucket_count[i]; j++) { // go through each element in bucket
            for(int k = j+1; k < bucket_count[i]; k++) { 
                if(bucket[i][j] > bucket[i][k]) { // compare elements to sort them in ascending order
                    int temp = bucket[i][j]; // perform swap
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }
    
    // Surrealist elements via flattening of the buckets into the original array
    int index = 0;
    for(int i = 0; i < BUCKET_SIZE; i++) { // go through each bucket
        for(int j = 0; j < bucket_count[i]; j++) { // go through each element in bucket
            arr[index] = bucket[i][j]; // flatten bucket into the original array
            index++; // increment index
        }
    }
}