//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cryptic
#include <stdio.h>

void decrypt(int arr[], int n) {
    int i, j, k; // declare variables

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                arr[i*n + j] = 1;
                // assign border elements with 1
            }
            printf("%d ", arr[i*n + j]);
            // print elements in each row
        }
        printf("\n");
    }
    for (i = 1; i < n-1; i++) {
        for (j = 1; j < n-1; j++) {
            arr[i*n + j] = 0;
            // assign inner elements with 0
        }
    }
    for (i = 2; i < n-2; i++) {
        for (j=2; j < n-2; j++) {
            arr[i*n + j] = -1;
            // assign diagonal 2nd element from edge as -1
        }
    }
    k = n-3;
    for (i = 1; i < n-2; i++) {
        arr[i*n + k--] = -1; // assign diagonal
    }
}

int main() {
    int n, i, j;
    int arr[1000];

    printf("Input size of the pattern: ");
    scanf("%d", &n); // input size of pattern

    decrypt(arr, n); // decrypt pattern using function 

    return 0;
}