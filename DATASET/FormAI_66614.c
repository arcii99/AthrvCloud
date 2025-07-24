//FormAI DATASET v1.0 Category: Random ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;

    printf("Let's have some fun!\n");
    printf("Can you guess the sum of %d and %d?\n", num1, num2);

    int guess;
    scanf("%d", &guess);

    int sum = num1 + num2;

    if (guess == sum)
    {
        printf("Congratulations, you got it right! You're a natural!\n");
    }
    else
    {
        while (guess != sum)
        {
            printf("Oh no, that's not right. Try again.\n");
            scanf("%d", &guess);
        }
        printf("Finally, you got it right! Great job!\n");
    }

    return 0;
}