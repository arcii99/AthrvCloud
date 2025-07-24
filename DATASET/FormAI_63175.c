//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include<stdio.h>

void bubble_sort(int a[], int n) {
    int i, j, temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void print_array(int a[], int n) {
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Before Sorting: ");
    print_array(a, n);

    bubble_sort(a, n);
    
    printf("After Sorting: ");
    print_array(a, n);
    return 0;
}