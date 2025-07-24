//FormAI DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    int* data;
    int size;
    int i;
    int sum = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size exceeds maximum size of %d", MAX_SIZE);
        return 1;
    }

    data = (int*) malloc(size * sizeof(int));

    if (data == NULL) {
        printf("Memory allocation error!");
        return 1;
    }

    printf("Enter %d integers:\n", size);

    for (i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    printf("Sum of array elements = %d\n", sum);

    free(data);

    return 0;
}