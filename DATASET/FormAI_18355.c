//FormAI DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

void fileSynchronizer(int a[], int b[], int n) {
    int i = 0, j = 0;
    while (i < n && j < n) {
        printf("%d ", min(a[i], b[j]));
        if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    while (i < n) {
        printf("%d ", a[i++]);
    }
    while (j < n) {
        printf("%d ", b[j++]);
    }
}

int main() {
    int n;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);
    int a[n], b[n];
    printf("Enter the elements of array A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the elements of array B: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    printf("The synchronized array is: ");
    fileSynchronizer(a, b, n);
    return 0;
}