//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int arr[100], x, n, i, f = 0, l, m;
 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    printf("\nEnter the element to be searched: ");
    scanf("%d", &x);

    qsort(arr, n, sizeof(int), cmpfunc);

    l = n - 1;
 
    while (f <= l) {
        m = (f + l) / 2;
 
        if (arr[m] < x)
            f = m + 1;
 
        else if (arr[m] == x) {
            printf("\nElement found at index %d\n", m+1);
            break;
        }
 
        else
            l = m - 1;
    }

    printf("\n");
    if(f > l)
        printf("Element not found in the array\n");

    return 0;
}