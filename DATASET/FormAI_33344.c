//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int i, num1, num2, answer;
    srand(time(0));

    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given 10 random addition problems to solve.\n\n");

    for(i = 1; i <= 10; i++) {
        num1 = rand() % 50 + 1; // generate random numbers between 1 and 50
        num2 = rand() % 50 + 1;
        printf("Question %d: What is %d + %d?\n", i, num1, num2);
        scanf("%d", &answer);

        if(answer == num1 + num2) {
            printf("Correct! +10 points.\n");
            score += 10;
        }
        else {
            printf("Incorrect. The correct answer was %d.\n", num1 + num2);
        }
        printf("Your current score is: %d\n\n", score);
    }

    printf("Congratulations, you have completed the Math Exercise Program!\n");
    printf("Your final score is: %d\n", score);

    return 0;
}