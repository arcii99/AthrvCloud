//FormAI DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>

// Function that takes an array and its size and returns the sum of the elements
int array_sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function that takes two arrays and their sizes and returns a new array that is the concatenation of the input arrays
int* array_concatenate(int arr1[], int n1, int arr2[], int n2) {
    int new_length = n1 + n2;
    int* new_arr = malloc(sizeof(int) * new_length);
    for (int i = 0; i < n1; i++) {
        new_arr[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        new_arr[n1+i] = arr2[i];
    }
    return new_arr;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};

    int sum_a = array_sum(a, 5);
    int sum_b = array_sum(b, 5);

    printf("Sum of a: %d\n", sum_a);
    printf("Sum of b: %d\n", sum_b);

    int* new_arr = array_concatenate(a, 5, b, 5);

    printf("Concatenation of a and b: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    free(new_arr);

    return 0;
}