//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, ans, guess, tries = 0;
    srand(time(NULL));
    a = rand() % 20 + 1;
    b = rand() % 20 + 1;
    ans = a + b;
    printf("Welcome to the Math Quiz Game!\n");
    printf("You will be given an addition problem to solve.\n");
    printf("You will have three tries to get the correct answer.\n");
    printf("If you fail to answer correctly three times, you lose.\n");
    printf("Let's begin!\n");
    do {
        printf("What is %d + %d? ", a, b);
        scanf("%d", &guess);
        tries++;
        if (guess == ans) {
            printf("Correct!\n");
            printf("It took you %d tries to get the answer.\n", tries);
            return 0;
        } else {
            printf("Incorrect answer.\n");
        }
    } while (tries < 3);
    printf("You failed to answer correctly three times.\n");
    printf("The answer was %d.\n", ans);
    return 0;
}