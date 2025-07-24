//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int search(int arr[], int n, int key){
    int low = 0, high = (n - 1), mid, found = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            found = 1;
            break;
        } else if (arr[mid] > key){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found) {
        return mid;
    } else {
        return -1;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int index = search(arr, n, key);

    if (index == -1) {
        printf("Element not found.");
    } else {
        printf("Element found at index %d.", index);
    }

    return 0;
}