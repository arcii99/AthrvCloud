//FormAI DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, a, b, c, answer, user_answer, correct_count = 0;
    char operator;

    srand(time(NULL));  // seed random number generator

    for (i = 1; i <= 10; i++) {
        // generate random math expression
        a = rand() % 10 + 1;  // random number between 1 and 10
        b = rand() % 10 + 1;
        c = rand() % 10 + 1;
        operator = rand() % 3;  // random operator
        switch (operator) {
            case 0:  // addition
                answer = a + b + c;
                printf("%d + %d + %d = ", a, b, c);
                break;
            case 1:  // subtraction
                answer = a - b - c;
                printf("%d - %d - %d = ", a, b, c);
                break;
            case 2:  // multiplication
                answer = a * b * c;
                printf("%d * %d * %d = ", a, b, c);
                break;
        }

        // get user's answer
        scanf("%d", &user_answer);

        // check if user's answer is correct
        if (user_answer == answer) {
            printf("Your answer is correct!\n");
            correct_count++;
        } else {
            printf("Your answer is incorrect. The correct answer is %d.\n", answer);
        }
    }

    // print user's score
    printf("You answered %d out of 10 questions correctly.\n", correct_count);

    return 0;
}