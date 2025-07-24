//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator

    int num1 = rand() % 10 + 1; // generate random number 1
    int num2 = rand() % 10 + 1; // generate random number 2
    int ans = num1 + num2; // calculate the answer

    printf("Welcome to the Math Game!\n\n");
    printf("You will be given two random numbers to add together.\n");
    printf("Your task is to give the correct answer.\n\n");

    printf("Here is your first number: %d\n", num1);
    printf("Here is your second number: %d\n\n", num2);
    printf("What is the answer to %d + %d?\n", num1, num2);

    int userAns;
    scanf("%d", &userAns); // read user's answer

    if (userAns == ans) { // check if answer is correct
        printf("\nWell done, your answer is correct!\n");
    } else {
        printf("\nSorry, your answer is incorrect.\n");
        printf("The correct answer is %d.\n", ans);
    }

    printf("\nThanks for playing the Math Game!\n");

    return 0;
}