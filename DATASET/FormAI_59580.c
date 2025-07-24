//FormAI DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // generate two random numbers
    srand(time(0));
    int num1 = rand() % 100;
    int num2 = rand() % 100;

    // display the equation for the user to solve
    printf("Solve the following equation for x: %d + x = %d\n", num1, num2);

    // prompt user for their answer
    int userAnswer;
    scanf("%d", &userAnswer);

    // check if the user's answer is correct
    if (userAnswer == (num2 - num1)) {
        printf("Congratulations! Your answer is correct!");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.", (num2 - num1));
    }

    return 0;
}