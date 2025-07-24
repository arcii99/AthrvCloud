//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between two given values
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate two random numbers between 1 and 10
    int num1 = generateRandomNumber(1, 10);
    int num2 = generateRandomNumber(1, 10);
    
    // Print the problem and get user input
    printf("What is the solution to %d * %d?\n", num1, num2);
    int solution;
    scanf("%d", &solution);
    
    // Compute the correct answer
    int correctAnswer = num1 * num2;
    
    // Check if the solution is correct and print appropriate message
    if (solution == correctAnswer) {
        printf("Congratulations! You got the correct answer.\n");
    } else {
        printf("Oops! The correct answer was %d.\n", correctAnswer);
    }
    
    return 0;
}