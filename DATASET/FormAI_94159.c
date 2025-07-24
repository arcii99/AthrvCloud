//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>

int recursive(int n)
{
    if (n == 0)
        return 1;
    else
        return n * recursive(n - 1);
}

int main()
{
    int n;

    printf("Can you guess what number I am thinking of?\n");
    scanf("%d", &n);

    int result = recursive(n);

    printf("Here's a hint: The result of %d! is %d\n", n, result);
    printf("But that's not the number I'm thinking of. Keep guessing!\n");

    if (result % 2 == 0)
        printf("Hint: The number is even.\n");
    else
        printf("Hint: The number is odd.\n");

    if (result > 100)
        printf("Hint: The number is greater than 100.\n");
    else if (result > 50)
        printf("Hint: The number is between 50 and 100.\n");
    else
        printf("Hint: The number is less than 50.\n");

    printf("Enter your guess: ");
    scanf("%d", &n);

    if (n == result)
        printf("Congratulations! You guessed the correct number!\n");
    else
        printf("Sorry, that was not the correct number. Try again!\n");

    return 0;
}