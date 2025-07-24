//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Set the seed for the random number generator
    srand(time(NULL));
    
    // Generate random numbers and store them in an array
    int numbers[10];
    printf("Generating 10 random numbers: \n");
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 100 + 1; // between 1 to 100
        printf("%d ", numbers[i]);
    }
    
    printf("\n\nSorting the numbers in descending order...\n\n");
    
    // Sort the array in descending order using bubble sort algorithm
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            if (numbers[i] < numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    // Print the sorted array
    printf("Sorted numbers in descending order: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}