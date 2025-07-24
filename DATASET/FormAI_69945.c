//FormAI DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int* ptr = NULL;
    int n, i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    /* Allocate memory dynamically */
    ptr = (int*)malloc(n * sizeof(int));
    
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &ptr[i]);
    }
    
    printf("The array elements are: ");
    for(i=0; i<n; i++) {
        printf("%d ", ptr[i]);
    }
    
    /* Deallocate memory */
    free(ptr);
    
    return 0;
}