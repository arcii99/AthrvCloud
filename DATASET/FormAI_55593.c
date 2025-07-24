//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int result;

    result = (((((a * b) / c ) + d) % 3) * 10) / 2;

    printf("What is the result of (((((%d * %d) / %d ) + %d) %% 3) * 10) / 2 ?\n", a, b, c, d);
    printf("Hint: it's a whole number between 0 and 14.\n");
    printf("Your answer: ");

    int answer;
    scanf("%d", &answer);

    if(answer == result) {
        printf("Congratulations, you got the right answer!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", result);
    }

    return 0;
}