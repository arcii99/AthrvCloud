//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); //seed the random number generator with current time

    int n = 1000000; //number of elements in the array
    int* arr = (int*) malloc(n * sizeof(int)); //allocate memory for the array

    //initialize the array with random values between 0 and 99
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    clock_t start = clock(); //start the timer

    //sort the array using bubble sort algorithm
    int temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    clock_t end = clock(); //end the timer
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; //calculate the time taken in seconds

    printf("Sorted array of %d elements in %f seconds!\n", n, time_taken);

    free(arr); //free the memory allocated for the array

    return 0;
}