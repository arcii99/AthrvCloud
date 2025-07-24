//FormAI DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// function to generate a random array
void generate_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// searching function using linear search algorithm
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// searching function using binary search algorithm
int binary_search(int arr[], int l, int r, int key) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            return binary_search(arr, l, mid - 1, key);
        }
        else {
            return binary_search(arr, mid + 1, r, key);
        }
    }
    return -1;
}

int main() {
    int n = 10;
    int arr[n];
    
    // generate the array
    generate_array(arr, n);
    printf("Original Array:\n");
    print_array(arr, n);
    
    // linear search example
    int key = 50;
    int index = linear_search(arr, n, key);
    if (index == -1) {
        printf("%d not found in the array\n", key);
    }
    else {
        printf("%d found at index %d\n", key, index);
    }
    
    // binary search example
    key = 10;
    int l = 0;
    int r = n - 1;
    index = binary_search(arr, l, r, key);
    if (index == -1) {
        printf("%d not found in the array\n", key);
    }
    else {
        printf("%d found at index %d\n", key, index);
    }
    
    return 0;
}