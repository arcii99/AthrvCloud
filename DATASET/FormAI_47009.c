//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5; // number of integers to allocate memory for
    int* numbers = (int*) malloc(n * sizeof(int)); // dynamically allocate memory for n integers

    if (numbers == NULL) { // ensure the memory allocation was successful
        printf("Memory allocation failed."); // print error message
        return 0; // exit program
    }

    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1; // assign values to each integer in the array
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i]; // calculate the sum of the integers in the array
    }

    printf("The sum of the first %d integers is %d\n", n, sum);

    int m = 8; // number of integers to reallocate memory for
    int* new_numbers = (int*) realloc(numbers, m * sizeof(int)); // reallocate memory for m integers

    if (new_numbers == NULL) { // ensure the memory reallocation was successful
        free(numbers); // free the previously allocated memory
        printf("Memory reallocation failed."); // print error message
        return 0; // exit program
    }

    numbers = new_numbers; // assign the newly allocated memory to the numbers pointer

    for (int i = n; i < m; i++) {
        numbers[i] = i + 1; // assign values to each integer in the newly allocated memory block
    }

    sum = 0;
    for (int i = 0; i < m; i++) {
        sum += numbers[i]; // calculate the sum of the integers in the newly allocated memory block
    }

    printf("The sum of the first %d integers is %d\n", m, sum);

    free(numbers); // free the dynamically allocated memory

    return 0; // exit program
}