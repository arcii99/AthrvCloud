//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

#define ARRAY_SIZE 10000000 // define the size of the array
#define CYCLES 10 // define the number of times to run the test

clock_t start, end; // define the clock variables

int main() {

    int i, j, index, temp;
    double elapsed_time;

    int arr[ARRAY_SIZE]; // define an array of the size ARRAY_SIZE

    // fill up the array with random integers
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // run the speed test CYCLES times and take the average time
    for (j = 0; j < CYCLES; j++) {

        start = clock(); // start the clock

        // perform some simple operations on the array that takes some time
        for (i = 0; i < ARRAY_SIZE; i++) {
            if (i % 2 == 0) {
                arr[i] = pow(arr[i], 2);
            } else {
                index = rand() % ARRAY_SIZE;
                temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
        }

        end = clock(); // stop the clock

        elapsed_time += ((double) (end - start)) / CLOCKS_PER_SEC; // calculate the elapsed time
    }

    printf("Average time taken = %f seconds", elapsed_time / CYCLES); // print the average time

    return 0;
}