//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>

int surprise_search(int arr[], int n, int x) {
    // are you ready for a surprise?
    int i = 0;
    while (i < n && arr[i] != x) {
        i++;
    }
    if (i == n) {
        printf("Surprise! You didn't find %d in the array!", x);
        // don't be too disappointed
        return -1;
    } else {
        printf("Surprise! You found %d at index %d in the array!", x, i);
        // ta-da!
        return i;
    }
}

int main() {
    int arr[] = {9, 7, 3, 5, 2, 1, 8, 4, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    
    // let's see if we can find our surprise!
    int result = surprise_search(arr, n, x);
    if (result == -1) {
        printf("\nBetter luck next time!\n");
    } else {
        printf("\nWoohoo! We found our surprise!\n");
    }
    
    return 0;
}