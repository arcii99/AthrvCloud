//FormAI DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the Cyberpunk Math Exercise Program!\n");

    /* Generate two random numbers */
    int num1 = rand() % 1000 + 1;
    int num2 = rand() % 1000 + 1;

    /* Print the numbers and give instructions */
    printf("\nYour first number is: %d\n", num1);
    printf("\nYour second number is: %d\n", num2);
    printf("\nNow it's time to do some cyber math! Enter your answer below:\n");

    /* Calculate and check the answer */
    int correct_answer = sqrt(pow(num1, 2) + pow(num2, 2));
    int user_answer;
    scanf("%d", &user_answer);

    if (user_answer == correct_answer) {
        printf("\nCongratulations! You solved the equation correctly!\n");
    } else {
        printf("\nSorry, that's incorrect. The correct answer is %d\n", correct_answer);
    }

    return 0;
}