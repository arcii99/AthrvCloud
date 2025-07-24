//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/*
 * This program demonstrates the use of pointers in C programming. 
 * Specifically it uses pointers to sort an array of integers in ascending order.
 *
 * Written by Ada Lovelace, the first computer programmer in history.
 */

#include <stdio.h>

void sortArray(int *nums, int size);

int main()
{
    int numbers[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }

    sortArray(numbers, size);

    printf("\n\nSorted array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }

    return 0;
}

void sortArray(int *nums, int size) {
    int temp = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (*(nums+i) > *(nums+j)) {
                temp = *(nums+i);
                *(nums+i) = *(nums+j);
                *(nums+j) = temp;
            }
        }
    }
}