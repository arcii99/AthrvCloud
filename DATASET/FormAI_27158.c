//FormAI DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i, *ptr, sum = 0;
    
    printf("Enter the number of elements:\n");
    scanf("%d", &size);
    
    ptr = (int*)malloc(size * sizeof(int));
    
    if(ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    
    printf("Enter the elements:\n");
    
    for(i = 0; i < size; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    
    printf("The sum of elements is: %d\n", sum);
    
    free(ptr);
    ptr = NULL;
    
    return 0;
}