//FormAI DATASET v1.0 Category: Benchmarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between the specified range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int size; // size of the array to be generated
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; // declare an array of size 'size'

    srand(time(NULL)); // seed the random number generator

    // generate random numbers and fill the array
    for(int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(1, 100);
    }

    // print the generated array
    printf("The generated array is:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // calculate the sum of all elements in the array and measure the time taken
    clock_t t1 = clock();
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    clock_t t2 = clock();
    
    printf("The sum of all elements is: %d\n", sum);
    printf("Time taken to calculate the sum: %f seconds\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    
    return 0;
}