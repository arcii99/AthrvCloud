//FormAI DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cyberSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("*           Welcome to Cyber Sort 2099            *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");

    printf("\nsorting in progress...\n");

    srand(time(NULL));
    int n = 100;
    int arr[n];
    int i;

    for(i = 0; i < n; i++) {
        arr[i] = rand();
    }

    cyberSort(arr, n);

    printf("\nsorting complete!\n");

    printf("\nResults:\n\n");
    for(i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    printf("\nThank you for using Cyber Sort 2099\n");

    return 0;
}