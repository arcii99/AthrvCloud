//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding the random number generator
    int arr_size = 1000000;
    int* my_array = malloc(arr_size * sizeof(int)); // allocating space for the array
    if (my_array == NULL) {
        printf("Error: Allocation of memory failed.\n");
        return 1;
    }

    // filling the array with random numbers from 0-100
    for (int i = 0; i < arr_size; i++) {
        my_array[i] = rand() % 101;
    }

    // starting the timer
    clock_t start_time = clock();

    // sorting the array using bubble sort
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            if (my_array[j] > my_array[j + 1]) {
                int temp = my_array[j];
                my_array[j] = my_array[j + 1];
                my_array[j + 1] = temp;
            }
        }
    }

    // ending the timer and calculating the total execution time
    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // printing the sorted array and the total execution time
    printf("Sorted Array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\nTotal Execution Time: %f seconds\n", total_time);

    // freeing the memory allocated for the array
    free(my_array);

    return 0;
}