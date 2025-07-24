//FormAI DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int n;

    printf("Enter the number of elements (maximum %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ARRAY_SIZE) {
        printf("Error: Invalid input\n");
        return -1;
    }

    // generate random values for the array
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Initial array:\n");
    print_array(arr, n);

    printf("Sorting array using bubble sort...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}