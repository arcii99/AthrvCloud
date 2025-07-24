//FormAI DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int num1 = rand() % 101;
    int num2 = rand() % 101;

    printf("Welcome to the Brave Math Exercise Program!\n\n");
    printf("Today's task is to find the sum of two numbers.\n");
    printf("The first number is: %d\n", num1);
    printf("The second number is: %d\n\n", num2);

    int answer;
    printf("Please enter your answer: ");
    scanf("%d", &answer);

    if (answer == (num1 + num2)) {
        printf("\nCongratulations! You got the correct answer.\n\n");
    } else {
        printf("\nOh no! The correct answer was %d. Better luck next time!\n\n", num1 + num2);
    }

    printf("Thank you for participating in the Brave Math Exercise Program.\n");
    printf("We look forward to seeing you again soon!\n");

    return 0;
}