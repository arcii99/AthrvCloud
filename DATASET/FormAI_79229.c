//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>

/* Define custom compare function for sorting integers in descending order */
int compareIntDesc(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 > num2) {
        return -1;
    } else if (num1 < num2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    /* Prompt user for input */
    printf("Enter the number of elements in the array: ");
    int size;
    scanf("%d", &size);
    
    /* Create array with user-specified size */
    int arr[size];
    
    /* Prompt user to enter array elements */
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* Sort array in descending order using custom compare function */
    qsort(arr, size, sizeof(int), compareIntDesc);
    
    /* Print sorted array */
    printf("Sorted array in descending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}