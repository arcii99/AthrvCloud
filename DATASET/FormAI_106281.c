//FormAI DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int* arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed");
        return 0;
    } 

    for (int i = 0; i < n; i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    free(arr);

    printf("The sum of the array elements is : %d", sum);
    return 0;
}