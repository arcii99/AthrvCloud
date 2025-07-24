//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// futuristic cyber search algorithm
int cyberSearch(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // element found
        if (arr[mid] == x) {
            return mid;
        }

        // check left half
        if (arr[mid] > x) {
            return cyberSearch(arr, left, mid - 1, x);
        }

        // check right half
        return cyberSearch(arr, mid + 1, right, x);
    }

    // element not found
    return -1;
}

int main() {
    // generate random array of integers
    srand(time(0));
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 1000;
    }

    // sort array in increasing order
    for (int i = 0; i < 99; i++) {
        for (int j = i+1; j < 100; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // ask user for search value
    printf("Enter a value to search for: ");
    int x;
    scanf("%d", &x);

    // search for value using cyber search algorithm
    int index = cyberSearch(arr, 0, 99, x);

    // display result
    if (index == -1) {
        printf("Value not found.\n");
    } else {
        printf("Value found at index %d.\n", index);
    }

    return 0;
}