//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 1000000

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        if (arr[mid] == x) 
            return mid; 

        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 

        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
}

void fill_array(int arr[], int size) 
{
    for (int i=0; i<size; i++) {
        arr[i] = i;
    }
}

bool test_search(int arr[], int size, int search_key)
{
    clock_t start = clock();
    int index = binarySearch(arr, 0, size-1, search_key);
    clock_t end = clock();

    if (index == -1) {
        printf("Search key not found in the array!");
        return false;
    } else {
        printf("Search key found at index %d", index);
    }

    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nBinary search took %f seconds to execute\n", time_taken);

    if (time_taken > 0.001) {
        printf("Binary search took too long to execute!\n");
        return false;
    }

    printf("Binary search passed the performance test!\n");
    return true;
}

int main()
{
    int arr[SIZE];
    fill_array(arr, SIZE);
    int search_key = 1234456;

    if(!test_search(arr, SIZE, search_key)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}