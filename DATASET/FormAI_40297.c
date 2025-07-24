//FormAI DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>

/* Let's create a program to sort an array of integers in ascending order using the Bubble Sort algorithm. */

int main() {

    printf("Welcome to the Bubble Sort Program!");

    int arr[10];
    int i, j, temp;

    printf("\nEnter 10 integers to be sorted: ");

    /* Get input integers */
    for(i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }

    /* Implementing Bubble Sort algorithm */
    for(i = 0; i < 9; ++i) {
        for(j = 0; j < 9-i; ++j) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted array in ascending order using Bubble Sort: \n");

    /* Print sorted array */
    for(i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}