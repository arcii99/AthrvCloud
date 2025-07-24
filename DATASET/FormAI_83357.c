//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    int c = rand() % 10 + 1;
    int d = rand() % 10 + 1;

    printf("\nWelcome to the Happy Math Quiz!\n\n");
    printf("Today's quiz is all about Adding and Multiplying\n");
    printf("Are you ready? Let's go!\n");

    printf("\nQuestion 1: What is the result of %d + %d * %d?\n", a, b, c);
    int ans1 = a + b * c;

    printf("\nEnter your answer: ");
    int userAns1;
    scanf("%d", &userAns1);

    if (userAns1 == ans1) {
        printf("\nGreat job! You got the correct answer!\n");
    } else {
        printf("\nOops! The correct answer is %d. Better luck next time!\n", ans1);
    }

    printf("\nQuestion 2: What is the result of (%d * %d) + %d\n", b, c, d);
    int ans2 = b * c + d;

    printf("\nEnter your answer: ");
    int userAns2;
    scanf("%d", &userAns2);

    if (userAns2 == ans2) {
        printf("\nAwesome! You got it right!\n");
    } else {
        printf("\nSorry! The correct answer is %d. Keep trying!\n", ans2);
    }

    printf("\nCongratulations! You have completed the Happy Math Quiz!\n");

    return 0;
}