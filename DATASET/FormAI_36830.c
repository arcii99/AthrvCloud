//FormAI DATASET v1.0 Category: Random ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    int i, j, temp;
    int numbers[10];
    
    // Generate 10 random numbers between 0 and 100
    for (i = 0; i < 10; i++) {
        numbers[i] = rand() % 101;
    }
    
    // Sort the numbers in ascending order using bubble sort
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (numbers[j] > numbers[j+1]) {
                // Swap the numbers if they are not in order
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    
    // Print the sorted list of numbers
    printf("The list of 10 random numbers between 0 and 100 in ascending order:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}