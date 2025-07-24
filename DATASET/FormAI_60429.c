//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, result, count = 0;
    srand(time(NULL));

    printf("*** Math Exercise Program ***\n");
    printf("Answer the following 10 math exercises:\n");

    while (count < 10) {

        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        operator = rand() % 4;

        switch (operator) {
            case 0:
                printf("%d + %d = ", num1, num2);
                answer = num1 + num2;
                break;
            case 1:
                printf("%d - %d = ", num1, num2);
                answer = num1 - num2;
                break;
            case 2:
                printf("%d * %d = ", num1, num2);
                answer = num1 * num2;
                break;
            case 3:
                printf("%d / %d = ", num1, num2);
                answer = num1 / num2;
                break;
        }

        scanf("%d", &result);

        if (result == answer) {
            printf("Correct!\n");
            count++;
        } else {
            printf("Wrong :( The correct answer is %d\n", answer);
        }
    }

    printf("Congratulations, you have completed all the exercises!\n");
    return 0;
}