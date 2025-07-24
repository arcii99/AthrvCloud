//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;  // declare a pointer
    int n, i;

    printf("Enter the number of values to be stored: ");
    scanf("%d", &n);

    // dynamically allocate memory
    ptr = (int*) malloc(n * sizeof(int));

    // check if memory allocation was successful
    if(ptr == NULL) {
        printf("Memory allocation failed. Exiting program...\n");
        exit(1);
    }

    // ask user for input values
    for(i = 0; i < n; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &ptr[i]);
    }

    // print the values inputted by the user
    printf("The values you inputted are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // free the dynamically allocated memory
    free(ptr);
    printf("\nMemory freed successfully.\n");

    return 0;
}