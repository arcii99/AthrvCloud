//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000000

int main() {

    int* array = malloc(N * sizeof(int)); // Dynamically allocate memory for the array
    if(array == NULL){
        printf("Memory allocation failed!!!");
        return 1;
    }

    // Initialize the array with random integers between 1 to 100
    srand(time(NULL));
    for(int i=0; i<N; i++){
        array[i] = rand() % 100 + 1;
    }

    // Compute the sum of all the integers in the array
    int sum = 0;
    for(int i=0; i<N; i++){
        sum += array[i];
    }

    printf("Sum of all integers in the array: %d\n", sum);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}