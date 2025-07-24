//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, user_answer;
    srand(time(0)); // seed the random number generator
    
    num1 = rand() % 50 + 1; // generate random numbers between 1 and 50
    num2 = rand() % 50 + 1;
    answer = num1 + num2; // calculate the answer
    
    printf("Welcome, brave knight, to the Math Challenge!\n"); // medieval-style greeting

    printf("What is the sum of %d and %d?\n", num1, num2);
    
    while (1) {
        printf("Your answer: ");
        if (scanf("%d", &user_answer) != 1) { // check for invalid input
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        else if (user_answer == answer) {
            printf("Correct, you are a worthy knight!\n");
            break;
        }
        else {
            printf("Wrong answer, try again!\n");
        }
    }
    
    return 0;
}