//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>

int donaldKnuthSearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int jump = 1;
    
    while (left <= right) {
        int mid = left + ((right - left) / jump);
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
            jump *= 2;
        }
        else {
            right = mid - 1;
            jump *= 2;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 19;
    int index = donaldKnuthSearch(arr, n, x);
    if (index != -1) {
        printf("%d found at index %d", x, index);
    }
    else {
        printf("%d not found in the array", x);
    }
    return 0;
}