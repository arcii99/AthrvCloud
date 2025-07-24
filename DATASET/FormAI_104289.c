//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = NULL;
    int num, i, sum = 0;
    
    printf("Enter the number of integers to be entered: ");
    scanf("%d", &num);
    
    // Allocate memory for num integers
    ptr = (int*) malloc(num * sizeof(int));
    
    // Check for memory allocation error
    if(ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    
    // Enter num integers
    printf("Enter %d integers:\n", num);
    for(i = 0; i < num; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    
    printf("The integers entered are: ");
    for(i = 0; i < num; i++) {
        printf("%d ", *(ptr + i));
    }
    
    printf("\nThe sum of the integers is %d.\n", sum);
    
    // Free the allocated memory
    free(ptr);
    
    return 0;
}