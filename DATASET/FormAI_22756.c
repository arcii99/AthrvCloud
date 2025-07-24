//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>

// Function to apply searching algorithm using mathematical formula
int searching_algorithm(int arr[], int n, int x) {
    int i = 0, j;

    while (i < n) {
        j = i + sqrt(n);

        // If the current element is greater than x, search in the previous sqrt(n) elements
        if (arr[j - 1] >= x) {
            while (i < j) {
                if (arr[i] == x)
                    return i;
                i++;
            }
            return -1;
        }

        // If not, move the index by sqrt(n) to search further
        i = j;
    }

    // If element is not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 5, 7, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 18;
    int index = searching_algorithm(arr, n, x);

    if (index != -1)
        printf("Element %d is present at index %d in the given array.", x, index);
    else
        printf("Element %d is not present in the given array.", x);

    return 0;
}