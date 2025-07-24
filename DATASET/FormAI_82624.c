//FormAI DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Creating a random number array using rand() function
    int array[100];
    srand(time(0));
    for (int i=0; i<100; i++) {
        array[i] = rand() % 1000;
    }

    // Printing out the original array
    printf("Original array: ");
    for (int i=0; i<100; i++) {
        printf("%d ", array[i]);
    }

    // Finding the minimum and maximum values in the array
    int min = array[0], max = array[0];
    for (int i=1; i<100; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Printing out the minimum and maximum values
    printf("\nMinimum value: %d", min);
    printf("\nMaximum value: %d", max);

    // Calculating the average value of the array
    float sum = 0;
    for (int i=0; i<100; i++) {
        sum += array[i];
    }
    float avg = sum / 100;

    // Printing out the average value
    printf("\nAverage value: %.2f", avg);

    // Finding all the values in the array greater than the average value
    printf("\nValues greater than average: ");
    for (int i=0; i<100; i++) {
        if (array[i] > avg) {
            printf("%d ", array[i]);
        }
    }

    // Finding all the values in the array less than the average value
    printf("\nValues less than average: ");
    for (int i=0; i<100; i++) {
        if (array[i] < avg) {
            printf("%d ", array[i]);
        }
    }

    return 0;
}