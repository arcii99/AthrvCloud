//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed with current time

    int num1 = rand() % 100; // Generate random number between 0-99
    int num2 = rand() % 100; // Generate another random number between 0-99

    printf("Let's play a game! You have two numbers: %d and %d\n", num1, num2);
    printf("Try to multiply them together without using the multiplication symbol.\n");

    int userAnswer;
    scanf("%d", &userAnswer); // Get user's answer
    
    int correctAnswer = num1 * num2; // Calculate correct answer
    
    if (userAnswer == correctAnswer) {
        printf("Congratulations! You're a math genius!\n");
    } else {
        printf("Oops, that's not quite right. The correct answer is %d.\n", correctAnswer);
    }

    printf("Let's try something else. You have two numbers again: %d and %d\n", num1, num2);
    printf("This time, try to find the quotient without using the division symbol.\n");

    scanf("%d", &userAnswer); // Get user's answer

    correctAnswer = num1 / num2; // Calculate correct answer

    if (userAnswer == correctAnswer) {
        printf("Wow, you really know your stuff!\n");
    } else {
        printf("Oops, that's not quite right. The correct answer is %d.\n", correctAnswer);
    }

    printf("Thanks for playing!\n");
    return 0;
}