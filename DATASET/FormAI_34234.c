//FormAI DATASET v1.0 Category: Math exercise ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char operators[4] = {'+', '-', '*', '/'}; // array of operators
    srand(time(NULL)); // seed for random generation
    int num1 = rand() % 100; // generate random num1 between 0 to 99
    int num2 = rand() % 100; // generate random num2 between 0 to 99
    char operator = operators[rand() % 4]; // random operator
    int answer; // user input answer
    int result; // actual result of the equation
    
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
    }
    
    printf("Solve the following equation:\n\n");
    printf("%d %c %d = ", num1, operator, num2);
    scanf("%d", &answer);
    
    if (answer == result) { // if user input is correct
        printf("\nCongratulations! You solved the equation correctly!\n");
    } else {
        printf("\nSorry, the correct answer is %d.\n", result);
    }
    
    return 0;
}