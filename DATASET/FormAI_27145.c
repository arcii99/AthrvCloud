//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: visionary
#include <stdio.h>

#define ARRAY_SIZE 1000000

// This program efficiently sorts an array of integers using the merge sort algorithm

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    
    while(i < left_size && j < right_size) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    while(i < left_size) {
        arr[k++] = left[i++];
    }
    
    while(j < right_size) {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int len) {
    if(len < 2) {
        return;
    }
    
    int mid = len/2;
    int left[mid], right[len-mid];
    
    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for(int i = mid; i < len; i++) {
        right[i-mid] = arr[i];
    }
    
    merge_sort(left, mid);
    merge_sort(right, len-mid);
    merge(arr, left, mid, right, len-mid);
}

int main() {
    int arr[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = ARRAY_SIZE - i;
    }
    
    merge_sort(arr, ARRAY_SIZE);
    
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}