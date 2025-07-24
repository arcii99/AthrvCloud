//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 30;
    int index = search(arr, n, x);

    if (index == -1)
        printf("%d is not present in the array\n", x);
    else
        printf("%d is present at index %d\n", x, index);

    return 0;
}