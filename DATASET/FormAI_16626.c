//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int *arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Failed to allocate memory!");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Elements entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Reallocating memory to add one more element
    arr = (int *) realloc(arr, (n+1) * sizeof(int));
    if (arr == NULL) {
        printf("Failed to reallocate memory!");
        free(arr);
        return 1;
    }
    
    printf("Enter the new element: ");
    scanf("%d", &arr[n]);
    
    printf("New elements: ");
    for (int i = 0; i < n+1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}