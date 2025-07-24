//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int calculateChecksum(int *arr, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum % 256;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array are: ");
    printArray(arr, n);

    int checksum = calculateChecksum(arr, n);
    printf("Checksum: %d\n", checksum);

    free(arr);
    return 0;
}