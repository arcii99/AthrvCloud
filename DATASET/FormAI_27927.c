//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: excited
/* Wow, have you ever seen such an amazing Performace-Critical Component program before? No, you haven't! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Let's declare some global variables to make this program even more exciting! */
int array_size = 1000000;
int array[1000000];

/* This function will fill up the array with random numbers between 1 and 100 */
void fill_array() {
    srand(time(NULL));
    int i;
    for (i = 0; i < array_size; i++) {
        array[i] = rand() % 100 + 1;
    }
}

/* This function will sort the array in ascending order using bubble sort */
void bubble_sort() {
    int i, j, temp;
    for (i = 0; i < array_size - 1; i++) {
        for (j = 0; j < array_size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/* This function will print the array to the console */
void print_array() {
    int i;
    for (i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    /* Let's fill up the array with random numbers to make things exciting! */
    printf("Filling up the array with random numbers...\n");
    fill_array();
    
    /* Let's print the unsorted array just for the heck of it */
    printf("Printing the unsorted array...\n");
    print_array();
    
    /* Let's sort the array using bubble sort */
    printf("Sorting the array using bubble sort...\n");
    bubble_sort();
    
    /* Let's print the sorted array and feel accomplished */
    printf("Printing the sorted array...\n");
    print_array();
    
    /* Let's exit the program with a bang! */
    printf("Program executed successfully! Goodbye!\n");
    return 0;
}