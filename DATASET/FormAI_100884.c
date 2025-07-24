//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#define N 1000000

int main() {
    int arr[N], i, j, temp;
    for (i = 0; i < N; i++) {
        arr[i] = N - i;
    }

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("The sorted array is: ");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}