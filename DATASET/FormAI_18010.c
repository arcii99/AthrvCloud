//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int num1 = rand() % 100 + 1; // generate a random number between 1 and 100
    int num2 = rand() % 100 + 1; // generate another random number between 1 and 100

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("Today's exercise is all about finding the sum and average of two numbers.\n");
    printf("The two numbers we will be using are %d and %d.\n\n", num1, num2);

    int sum = num1 + num2; // calculate the sum of the two numbers
    float average = (float)sum / 2; // calculate the average of the two numbers

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The average of %d and %d is %.1f.\n\n", num1, num2, average);

    printf("Now it's your turn! Please enter two numbers.\n");

    int input1, input2;
    scanf("%d %d", &input1, &input2);

    int answer_sum = input1 + input2; // calculate the sum of the two input numbers
    float answer_average = (float)answer_sum / 2; // calculate the average of the two input numbers

    printf("\nThe sum of %d and %d is %d.\n", input1, input2, answer_sum);

    if(answer_sum == sum) {
        printf("Congratulations! You got the correct answer for the sum.\n");
    } else {
        printf("Sorry, the answer for the sum is incorrect. The actual answer is %d.\n", sum);
    }

    printf("\nThe average of %d and %d is %.1f.\n", input1, input2, answer_average);

    if(answer_average == average) {
        printf("Well done! You got the correct answer for the average.\n");
    } else {
        printf("Oops, the answer for the average is incorrect. The actual answer is %.1f.\n", average);
    }

    printf("\nThanks for participating in today's Math Exercise Program!\n");

    return 0;
}