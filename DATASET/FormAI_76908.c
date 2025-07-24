//FormAI DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>

void bubbleSort(int array[], int size) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - 1 - i; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int binarySearch(int array[], int size, int find) {
    int left = 0, right = size - 1, mid;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(array[mid] == find)
            return mid;
        else if(array[mid] < find)
            left = mid + 1;
        else
            right = mid - 1;    
    }
    return -1;
}

int main() {
    int arr[10] = {4, 9, 2, 10, 5, 8, 1, 7, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int find = 7;
    bubbleSort(arr, size);
    int index = binarySearch(arr, size, find);
    if(index == -1)
        printf("%d not found in the array\n", find);
    else
        printf("%d found at index %d\n", find, index);
    return 0;
}