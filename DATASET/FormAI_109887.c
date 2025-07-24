//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble_sort(int a[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        printf("After iterating %d times: ", i+1);
        print_array(a, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int*) malloc(sizeof(int) * n);

    printf("Enter the elements:\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Before sorting: ");
    print_array(a, n);

    bubble_sort(a, n);

    printf("After sorting: ");
    print_array(a, n);

    free(a);
    return 0;
}