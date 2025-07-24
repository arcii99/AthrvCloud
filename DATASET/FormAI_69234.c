//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand(time(NULL)); // seed random number generator with current time
    int num1, num2, ans, userAns, score=0;

    printf("Welcome to the Online Examination System!\n\n");

    for(int i=1; i<=10; i++) {
        num1 = rand()%100; // generate first random number between 0 and 99
        num2 = rand()%100; // generate second random number between 0 and 99
        ans = num1 + num2; // calculate correct answer

        printf("Question %d: %d + %d = ", i, num1, num2);
        scanf("%d", &userAns);

        if(userAns == ans) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %d.\n", ans);
        }
    }

    printf("\nYour score is: %d/10", score);
    if(score >= 8) {
        printf("\nGreat job, you passed the exam!");
    } else {
        printf("\nSorry, you did not pass the exam. Better luck next time!");
    }

    return 0;
}