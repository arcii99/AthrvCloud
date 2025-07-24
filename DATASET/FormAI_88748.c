//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

int c_search(int arr[], int n, int x) {
    int i = 0;
    while (i < n && arr[i] != x)
        i += abs(arr[i] - x);
 
    if (i < n) return i;
    return -1;
}

int main() {
    int n, i, x, res;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements in the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the key element to search: ");
    scanf("%d", &x);
    
    res = c_search(arr, n, x);
    
    if (res >= 0)
        printf("Element %d is present at index %d\n", x, res);
    else
        printf("Element %d is not present in the array\n", x);
    
    return 0;
}