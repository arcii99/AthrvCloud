//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Recursive function to generate random numbers within a given range
void randomNumbers(int min, int max)
{
    // Base case
    if (min > max) {
        return;
    }
    
    int num = (rand() % (max - min + 1)) + min; // Generate random number within the range
    
    printf("%d ", num); // Print the generated number
    
    randomNumbers(min, num - 1); // Recurse with the left half of the range
    
    randomNumbers(num + 1, max); // Recurse with the right half of the range
}

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    int min, max;
    
    printf("Enter the minimum and maximum values of the range:\n");
    scanf("%d %d", &min, &max);
    
    printf("The random numbers within the range %d to %d are:\n", min, max);
    
    randomNumbers(min, max); // Call the recursive function
    
    return 0;
}