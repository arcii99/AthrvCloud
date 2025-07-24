//FormAI DATASET v1.0 Category: Sorting ; Style: scientific
/*
 * This program demonstrates a unique implementation of bubble sort algorithm using scientific notation in C language.
 *
 * The program accepts an array of real numbers in scientific notation as input, sorts them in ascending order,
 * and displays the sorted array as output.
 *
 * Author: Chatbot
 * Date: September 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum array size
#define MAX_ARRAY_SIZE 100

// Function prototypes
void bubble_sort(double array[], int size);

int main() {

    // Declare variables
    char input[MAX_ARRAY_SIZE]; // String to store user input
    double array[MAX_ARRAY_SIZE]; // Array to store numeric values
    int count = 0; // Counter variable to keep track of number of elements

    // Prompt user for array elements in scientific notation
    printf("Enter array elements in scientific notation (e.g. 4.35e-2), one element per line. Press Ctrl-D to stop.\n");

    // Read user input until maximum array size is reached or Ctrl-D is pressed
    while (count < MAX_ARRAY_SIZE && fgets(input, sizeof(input), stdin) != NULL) {

        // Convert string to double and add to array
        array[count] = atof(input);

        // Increment counter
        count++;
    }

    // Sort the array using bubble sort algorithm
    bubble_sort(array, count);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2e\n", array[i]);
    }

    return 0;
}

/**
 * Sorts the given array in ascending order using bubble sort algorithm.
 *
 * @param array the array to be sorted
 * @param size the size of the array
 */
void bubble_sort(double array[], int size) {

    double temp; // Temporary variable to swap array elements

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Compare adjacent elements and swap if necessary
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}