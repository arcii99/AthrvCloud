//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Generate an array of random numbers */
void generate_rand_nums(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

/* Print the array of numbers */
void print_arr(int *arr, int n) {
    int i;
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Bubble sort the array */
void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* Call the functions to generate an array of random numbers and sort it using bubble sort */
int main() {
    int n = 10;
    int arr[n];
    printf("Generating a random array of %d numbers: ", n);
    generate_rand_nums(arr, n);
    print_arr(arr, n);
    printf("\nSorting the array using bubble sort...");
    bubble_sort(arr, n);
    print_arr(arr, n);

    return 0;
}