//FormAI DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter the number of integers you want to allocate memory for: ");
    scanf("%d", &n);
    printf("Allocating memory for %d integers...\n\n", n);

    // Allocate memory for n integers and store the address in ptr
    int *ptr = (int*) malloc(n * sizeof(int));

    // Check if memory was successfully allocated by checking if ptr is NULL
    if (ptr == NULL) {
        printf("Error: Memory allocation failed. Exiting program...\n");
        exit(1);
    }

    // Prompt user to enter the integers and store them in the allocated memory
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &*(ptr+i));
    }

    // Display the integers
    printf("\n\nThe integers you entered are: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr+i));
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}