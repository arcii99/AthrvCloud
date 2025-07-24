//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the average of elements in an array
double calculate_average(int num_elements, int *array) {
    int sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += array[i];
    }
    double avg = (double) sum / num_elements;
    return avg;
}

// Function to generate random integers between 1 and 100 and store them in an array
void generate_random_integers(int num_elements, int *array) {
    srand(time(NULL)); // seed random number generator with current time
    for (int i = 0; i < num_elements; i++) {
        array[i] = rand() % 100 + 1; // generate random integer between 1 and 100
    }
}

int main() {
    int num_elements = 1000000; // number of elements in the array
    int *array = (int*) malloc(num_elements * sizeof(int)); // allocate memory for array

    generate_random_integers(num_elements, array); // generate random integers and store them in the array

    clock_t start = clock(); // start the clock to measure execution time

    double avg = calculate_average(num_elements, array); // calculate the average of elements in the array

    clock_t end = clock(); // end the clock
    
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate the time taken in seconds

    printf("The average of the elements in the array is: %f\n", avg);
    printf("Time taken by the program is %f seconds\n", time_taken);

    free(array); // deallocate the memory used for the array

    return 0;
}