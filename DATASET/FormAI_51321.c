//FormAI DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

// function to perform linear search
int linearSearch(int arr[], int size, int element) {
    for(int i=0 ; i<size ; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// function to perform binary search
int binarySearch(int arr[], int size, int element) {
    int low = 0;
    int high = size-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == element) {
            return mid;
        }
        else if(element < arr[mid]) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {1, 3, 5, 6, 8, 9, 10, 11, 14, 16};
    int element = 5;

    printf("Array: ");
    for(int i=0 ; i<10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nElement to search: %d\n", element);

    int linearSearchResult = linearSearch(arr, 10, element);
    if(linearSearchResult == -1) {
        printf("Linear Search: Element not found\n");
    }
    else {
        printf("Linear Search: Element found at index %d\n", linearSearchResult);
    }

    int binarySearchResult = binarySearch(arr, 10, element);
    if(binarySearchResult == -1) {
        printf("Binary Search: Element not found\n");
    }
    else {
        printf("Binary Search: Element found at index %d\n", binarySearchResult);
    }

    return 0;
}