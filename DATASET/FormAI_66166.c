//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int) time(NULL));
    int a = rand() % 100;
    int b = rand() % 100;

    printf("Solve the following equation:\n%d + %d = ?\n", a, b);

    int answer;
    scanf("%d", &answer);

    int result = a + b;
    if (answer == result) {
        printf("Congratulations! You answered correctly!\n");
        printf("Your math skills are superb.\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", result);
        printf("Don't worry, keep practicing and you'll get better.\n");
    }

    printf("\nNow let's solve another tricky equation.\n");
    printf("What is the value of PI to the 7th decimal place? (Hint: use math.h)\n");

    double pi = 3.14159265;
    double user_pi;
    scanf("%lf", &user_pi);

    if (user_pi == pi) {
        printf("You're a math genius!\n");
    } else {
        printf("Sorry, the correct answer is %.7lf.\n", pi);
        printf("Don't worry, math can be challenging but with practice, you'll master it.\n");
    }

    return 0;
}