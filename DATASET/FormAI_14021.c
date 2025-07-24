//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;

    float result;

    printf("Welcome to the mystical world of surreal math!\n");
    printf("Please calculate the following equation:\n");
    printf("cos(%d) * sqrt(%d) + tan(%d) * %d + abs(sin(%d))\n", num1, num2, num1, num2, num2);

    scanf("%f", &result);

    float answer = cos(num1) * sqrt(num2) + tan(num1) * num2 + fabs(sin(num2));

    if (result == answer) {
        printf("Congratulations! You have solved the equation and unlocked the magical door to the next realm!\n");
    } else {
        printf("Oh no! Your answer is incorrect. Please try again and enter the correct result to continue on your journey.\n");
    }

    return 0;
}