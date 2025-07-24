//FormAI DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int recursive_sum(int arr[], int size) {
    if (size == 0) {
        return 0;
    } else {
        return arr[size - 1] + recursive_sum(arr, size - 1);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = recursive_sum(arr, size);
    printf("The sum of the array is %d\n", sum);
    return 0;
}