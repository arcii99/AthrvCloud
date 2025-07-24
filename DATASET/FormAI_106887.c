//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

int brave_search(int array[], int size, int key) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == key) {
            return mid;
        }
        if (array[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(array) / sizeof(int);
    int key = 9;
    printf("The index of %d is %d\n", key, brave_search(array, size, key));
    key = 16;
    printf("The index of %d is %d\n", key, brave_search(array, size, key));
    return 0;
}