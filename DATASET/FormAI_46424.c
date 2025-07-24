//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int main() {

    // create an array of random integers
    int arr[ARRAY_SIZE];
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // calculate the sum of even numbers in the array
    int sum = 0;
    for(int i=0; i<ARRAY_SIZE; i++) {
        if(arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    // print the sum
    printf("The sum of even numbers in the array is: %d\n", sum);

    return 0;
}