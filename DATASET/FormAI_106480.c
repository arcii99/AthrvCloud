//FormAI DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>

int search(int arr[], int n, int x) {     // Searching function
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {     // Main function
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = search(arr, n, x);
    if(result == -1) {
        printf("%d not found in the array.\n", x);
    } else {
        printf("%d found at index %d.\n", x, result);
    }
    return 0;
}