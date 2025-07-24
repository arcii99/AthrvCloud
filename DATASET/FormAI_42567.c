//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program generates a random equation containing addition, subtraction, multiplication and division 
// of two integers within a given range and asks the user to solve it.

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int min = 1, max = 100; // Define the range of possible numbers
    char operators[4] = {'+', '-', '*', '/'}; // Define the four possible operators
    
    // Generate two random numbers and an operator
    int num1 = (rand() % (max - min + 1)) + min;
    int num2 = (rand() % (max - min + 1)) + min;
    char op = operators[rand() % 4];
    
    // Print the equation and ask the user to solve it
    printf("What is the value of %d %c %d?\n", num1, op, num2);
    int userAnswer;
    scanf("%d", &userAnswer);
    
    // Compute the correct answer
    int correctAnswer;
    switch(op) {
        case '+':
            correctAnswer = num1 + num2;
            break;
        case '-':
            correctAnswer = num1 - num2;
            break;
        case '*':
            correctAnswer = num1 * num2;
            break;
        case '/':
            correctAnswer = num1 / num2;
            break;
    }
    
    // Check if the user's answer is correct and print the result
    if(userAnswer == correctAnswer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", correctAnswer);
    }
    
    return 0;
}