//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

// A function to perform linear search on an array of integers
int linearSearch(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

// A function to perform binary search on an array of integers
int binarySearch(int arr[], int left, int right, int key){
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] < key)
            left = mid + 1;
        else if(arr[mid] > key)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main(){
    int arr[10] = {13, 5, 18, 32, 20, 9, 15, 8, 4, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 23;
    
    // Perform linear search
    int index = linearSearch(arr, size, key);
    if(index != -1)
        printf("Linear search: Found at index %d\n", index);
    else
        printf("Linear search: Not found\n");
    
    // Sort the array
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Perform binary search
    index = binarySearch(arr, 0, size - 1, key);
    if(index != -1)
        printf("Binary search: Found at index %d\n", index);
    else
        printf("Binary search: Not found\n");
    
    return 0;
}