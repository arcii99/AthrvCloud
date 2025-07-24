//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Memory Manager!\n");
    printf("This program will demonstrate how to manage memory dynamically in C.\n");

    int* ptr = NULL;
    int num_elements, sum = 0;

    printf("How many elements do you want to store in the array?: ");
    scanf("%d", &num_elements);

    ptr = (int*) malloc(num_elements * sizeof(int));

    if (ptr == NULL) {
        printf("Failed to allocate memory. Exiting program.\n");
        exit(0);
    } else {
        printf("Memory allocation successful!\n");
    }

    printf("Please enter %d integers to store in the array:\n", num_elements);

    for (int i = 0; i < num_elements; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    printf("The sum of all integers in the array is: %d\n", sum);

    free(ptr);
    printf("Memory freed successfully!\n");

    return 0;
}