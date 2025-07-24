//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
 
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
 
    int L[n1], M[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];
 
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
 
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = M[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        A[k] = M[j];
        j++;
        k++;
    }
}
 
void merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
 
int main() {
    int arr[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, arr_size - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    return 0;
}