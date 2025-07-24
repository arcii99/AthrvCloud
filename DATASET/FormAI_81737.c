//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Generate seed for random number generator

    // Declare variables
    int num1, num2, answer, userAnswer;
    char operator;

    // Loop 10 times for 10 math problems
    for(int i=1; i<=10; i++) {
        // Generate 2 random numbers between 1 and 10
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Randomly select operator between +, -, and *
        int operatorNum = rand() % 3;
        if(operatorNum == 0) {
            operator = '+';
            answer = num1 + num2;
        } else if(operatorNum == 1) {
            operator = '-';
            answer = num1 - num2;
        } else {
            operator = '*';
            answer = num1 * num2;
        }

        // Ask user to solve problem
        printf("Problem %d: What is %d %c %d?\n", i, num1, operator, num2);
        scanf("%d", &userAnswer);

        // Check if answer is correct
        if(userAnswer == answer) {
            printf("Correct!\n\n");
        } else {
            printf("Incorrect. The answer is %d.\n\n", answer);
        }
    }

    return 0;
}