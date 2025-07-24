//FormAI DATASET v1.0 Category: Funny ; Style: portable
#include <stdio.h>

int main() {
    // create an array of integers
    int arr[5] = {1, 2, 3, 4, 5};

    // print out the initial array
    printf("Initial Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    // swap the first and last element of the array
    int temp = arr[0];
    arr[0] = arr[4];
    arr[4] = temp;

    // print out the array after swapping
    printf("\nArray after swapping first and last element: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    // create a variable to hold the sum of the array
    int sum = 0;

    // loop through the array and add up the elements
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    // print out the sum of the array
    printf("\nThe sum of the array is: %d\n", sum);

    return 0;
}