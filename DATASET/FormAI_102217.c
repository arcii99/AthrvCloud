//FormAI DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>

int invasive_search(int arr[], int n, int key) {
    int i, j;
    for (i = 0, j = n-1; i < j;) {
        if (arr[i] == key) {
            printf("Key found at index %d\n", i);
            return i;
        }
        if (arr[j] == key) {
            printf("Key found at index %d\n", j);
            return j;
        }
        i++;
        j--;
    }
    if (i == j && arr[i] == key) {
        printf("Key found at index %d\n", i);
        return i;
    }
    printf("Key not found!\n");
    return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 7;
    invasive_search(arr, 10, key);
    return 0;
}