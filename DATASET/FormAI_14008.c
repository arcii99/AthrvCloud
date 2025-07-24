//FormAI DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, *ptr, i, sum = 0;

    //configurable size of array
    printf("Enter number of elements: ");
    scanf("%d", &size);

    //dynamic memory allocation
    ptr = (int*)malloc(size * sizeof(int));

    //check if memory allocation was successful or not
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    //read user input values and calculate sum
    printf("Enter elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    //print array elements and sum
    printf("The elements you entered are: ");
    for (i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\nThe sum is: %d\n", sum);

    //free allocated memory
    free(ptr);

    return 0;
}