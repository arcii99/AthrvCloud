//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void initialize_array(int *array, int size){
    for(int i=0; i<size; ++i){
        array[i] = rand() % size;
    }
}

void print_array(int *array, int size){
    printf("Array:\n");
    for(int i=0; i<size; ++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertion_sort(int *array, int size){
    for(int i=1; i<size; ++i){
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
}

void merge(int *array, int left, int mid, int right){
    int len1 = mid - left + 1;
    int len2 = right - mid;

    int *left_array = (int*) malloc(len1 * sizeof(int));
    int *right_array = (int*) malloc(len2 * sizeof(int));

    for(int i=0; i<len1; ++i){
        left_array[i] = array[left + i];
    }
    for(int i=0; i<len2; ++i){
        right_array[i] = array[mid + 1 + i];
    }

    int i=0, j=0, k=left;
    while(i<len1 && j<len2){
        if(left_array[i] <= right_array[j]){
            array[k] = left_array[i];
            ++i;
        }
        else{
            array[k] = right_array[j];
            ++j;
        }
        ++k;
    }

    while(i<len1){
        array[k] = left_array[i];
        ++i;
        ++k;
    }

    while(j<len2){
        array[k] = right_array[j];
        ++j;
        ++k;
    }

    free(left_array);
    free(right_array);
}

void merge_sort(int *array, int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        merge_sort(array, left, mid);
        merge_sort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

int main(){
    int array[ARRAY_SIZE];

    srand(time(NULL)); // seed for random number generator
    initialize_array(array, ARRAY_SIZE);

    printf("Initial Array:\n");
    print_array(array, ARRAY_SIZE);

    printf("\nInsertion Sort:\n");
    clock_t insertion_start = clock();
    insertion_sort(array, ARRAY_SIZE);
    clock_t insertion_end = clock();
    print_array(array, ARRAY_SIZE);
    printf("Insertion Sort Time: %lf seconds\n", (double)(insertion_end - insertion_start) / CLOCKS_PER_SEC);

    initialize_array(array, ARRAY_SIZE); // reinitialize array
    printf("\nMerge Sort:\n");
    clock_t merge_start = clock();
    merge_sort(array, 0, ARRAY_SIZE-1);
    clock_t merge_end = clock();
    print_array(array, ARRAY_SIZE);
    printf("Merge Sort Time: %lf seconds\n", (double)(merge_end - merge_start) / CLOCKS_PER_SEC);

    return 0;
}