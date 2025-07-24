//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num1 = rand() % 10;
    int num2 = rand() % 10;

    printf("What is the result of %d * %d?\n", num1, num2);

    int answer;
    scanf("%d", &answer);

    int result = num1 * num2;

    if (answer == result) {
        printf("Congratulations! You got it right!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", result);
    }

    printf("Let's try another one! What is the result of %d + %d?\n", num1, num2);

    scanf("%d", &answer);

    result = num1 + num2;

    if (answer == result) {
        printf("Awesome! You got it!\n");
    } else {
        printf("Incorrect. The answer is %d.\n", result);
    }

    printf("One more! What is the result of %d - %d?\n", num1, num2);

    scanf("%d", &answer);

    result = num1 - num2;

    if (answer == result) {
        printf("Great job! You're really good at this!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", result);
    }

    return 0;
}