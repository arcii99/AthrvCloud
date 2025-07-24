//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *ptr;
    int num, i, sum = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    
    ptr = (int*) malloc(num * sizeof(int)); // Memory allocation
    
    if(ptr == NULL) { // Checking if the allocation is successful
        printf("Memory allocation failed!\n");
        exit(0);
    }
    
    printf("Enter the elements: ");
    for(i=0; i<num; i++) {
        scanf("%d", ptr+i); // Storing input values into the dynamic memory
    }
    
    for(i=0; i<num; i++) {
        sum += *(ptr+i); // Accessing the values stored in the dynamic memory
    }
    
    printf("The sum of the elements is: %d\n", sum);
    
    free(ptr); // Freeing up the dynamically allocated memory
    
    return 0;
}