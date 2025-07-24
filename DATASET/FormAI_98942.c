//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int *array, int size);

int main() {
    int array[] = {4, 5, 1, 8, 2, 9, 3, 6, 7, 0};
    int size = sizeof(array) / sizeof(array[0]);
  
    bucket_sort(array, size);
  
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
  
    return 0;
}

void bucket_sort(int *array, int size) {
    int *buckets[BUCKET_SIZE];
    
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }
    
    // put elements in the corresponding buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / BUCKET_SIZE;
        
        if (buckets[bucket_index] == NULL) {
            buckets[bucket_index] = malloc(sizeof(int));
            *(buckets[bucket_index]) = array[i];
        }
        else {
            int bucket_size = sizeof(buckets[bucket_index]) / sizeof(buckets[bucket_index][0]);
            buckets[bucket_index] = realloc(buckets[bucket_index], (bucket_size + 1) * sizeof(int));
            *(buckets[bucket_index] + bucket_size) = array[i];
        }
    }
    
    // sort elements in each bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i] != NULL) {
            int bucket_size = sizeof(buckets[i]) / sizeof(buckets[i][0]);
            for (int j = 0; j < bucket_size - 1; j++) {
                for (int k = j + 1; k < bucket_size; k++) {
                    if (*(buckets[i] + k) < *(buckets[i] + j)) {
                        int tmp = *(buckets[i] + j);
                        *(buckets[i] + j) = *(buckets[i] + k);
                        *(buckets[i] + k) = tmp;
                    }
                }
            }
        }
    }
    
    // merge sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i] != NULL) {
            int bucket_size = sizeof(buckets[i]) / sizeof(buckets[i][0]);
            for (int j = 0; j < bucket_size; j++) {
                array[index++] = *(buckets[i] + j);
            }
            free(buckets[i]);
        }
    }
}