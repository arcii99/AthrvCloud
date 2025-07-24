//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

// Returns a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Swaps two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sorts the given array using bubble sort algorithm
void bubbleSort(int arr[]) {
    int i, j;
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Calculates the sum of all elements in the given array
int calculateSum(int arr[]) {
    int i, sum = 0;
    for (i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[N], i;
    
    // Seed the random number generator
    srand(time(0));
    
    // Populate the array with random numbers between -100 and 100
    for (i = 0; i < N; i++) {
        arr[i] = getRandomNumber(-100, 100);
    }
    
    // Sort the array using bubble sort
    bubbleSort(arr);
    
    // Calculate the sum of all elements in the array
    int sum = calculateSum(arr);
    
    printf("Sum of all elements in the array: %d\n", sum);
    
    return 0;
}