//FormAI DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result, user_answer, correct_answers = 0;
    char operators[4] = {'+', '-', '*', '/'};
    srand(time(0)); // seed random number generator with current time

    for (int i = 0; i < 10; i++) {
        num1 = rand() % 100; // generate random numbers between 0 and 99
        num2 = rand() % 100;
        operation = rand() % 4; // select a random operator from operators array
        printf("\nWhat is %d %c %d? ", num1, operators[operation], num2);
        scanf("%d", &user_answer);
        switch(operation) {
            case 0:
                // addition
                result = num1 + num2;
                break;
            case 1:
                // subtraction
                result = num1 - num2;
                break;
            case 2:
                // multiplication
                result = num1 * num2;
                break;
            case 3:
                // division
                result = num1 / num2;
                break;          
        }
        if (user_answer == result) {
            printf("Correct!");
            correct_answers++;
        } else {
            printf("Incorrect. The answer is %d", result);
        }
    }
    printf("\nYou answered %d out of 10 questions correctly.", correct_answers);
    return 0;
}