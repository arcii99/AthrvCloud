//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int score = 0;

int main() {
    srand(time(NULL));
    printf("Welcome to the Genious Game!\n\n");
    printf("Here is your first question:\n\n");

    char op;
    int num1, num2;

    while (1) {
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;
        op = rand() % 3 == 0 ? '+' : '-';

        printf("%d %c %d = ", num1, op, num2);

        int answer;
        scanf("%d", &answer);

        if (op == '+') {
            if (answer == num1 + num2) {
                score++;
                printf("Correct! Your score is now %d.\n", score);
            } else {
                printf("Wrong! Game over. Your final score was %d.\n", score);
                break;
            }
        } else {
            if (answer == num1 - num2) {
                score++;
                printf("Correct! Your score is now %d.\n", score);
            } else {
                printf("Wrong! Game over. Your final score was %d.\n", score);
                break;
            }
        }
        printf("Here is your next question:\n\n");
    }

    return 0;
}