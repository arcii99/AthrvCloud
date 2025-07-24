//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>

/* Define the size of the array */
#define SIZE 8

/* Define the array elements */
int ary[] = { 5, 2, 8, 4, 1, 9, 3, 7 };

/* Function to print out the current array */
void print_array(int *ptr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", ptr[i]);
    printf("\n");
}

/* Function to sort the array in ascending order */
void sort_array(int *ptr, int size) {
    int temp, i, j;
    /* Bubble sort algorithm */
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (ptr[j] > ptr[j + 1]) {
                /* Swap the elements */
                temp = ptr[j + 1];
                ptr[j + 1] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

int main() {
    printf("The original array is:\n"); 
    print_array(ary, SIZE);

    printf("Sorting the array in ascending order...\n"); 
    sort_array(ary, SIZE);

    printf("The array after sorting is:\n"); 
    print_array(ary, SIZE);

    return 0;
}