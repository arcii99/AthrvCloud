//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, ans, userAns, totalQues = 0, correctAns = 0, i;
    srand(time(0)); // initialize random seed

    printf("\nWelcome to the Math Exercise Program!\n");

    while (1) {
        // generate 2 random numbers between 0 and 99
        num1 = rand() % 100;
        num2 = rand() % 100;
        ans = num1 + num2;

        printf("\nWhat is %d + %d? ", num1, num2);
        scanf("%d", &userAns);
        totalQues++;

        if (userAns == ans) {
            correctAns++;
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct answer is %d.\n", ans);
        }

        if (totalQues == 10) {
            printf("\nYou have completed 10 questions!\n");
            printf("Your score is: %d/%d\n", correctAns, totalQues);
            printf("\nDo you want to play again? (y/n): ");
            char again;
            scanf(" %c", &again);
            if (again == 'y' || again == 'Y') {
                totalQues = 0;
                correctAns = 0;
                continue; // start a new round of questions
            } else {
                printf("Thanks for playing!\n");
                break;
            }
        }
    }

    return 0;
}