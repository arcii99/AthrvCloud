//FormAI DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#define N 10

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[N] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int target = 11;
    int index = linearSearch(arr, N, target);
    if (index != -1) {
        printf("Index of %d in the array is %d using Linear Search\n", target, index);
    } else {
        printf("Could not find %d in the array using Linear Search\n", target);
    }

    target = 13;
    index = binarySearch(arr, N, target);
    if (index != -1) {
        printf("Index of %d in the array is %d using Binary Search\n", target, index);
    } else {
        printf("Could not find %d in the array using Binary Search\n", target);
    }

    target = 17;
    index = interpolationSearch(arr, N, target);
    if (index != -1) {
        printf("Index of %d in the array is %d using Interpolation Search\n", target, index);
    } else {
        printf("Could not find %d in the array using Interpolation Search\n", target);
    }

    return 0;
}