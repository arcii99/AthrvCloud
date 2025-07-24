//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

void recursive_function(int num)
{
    if (num <= 0)
    {
        printf("Oops! Invalid input. Please enter a positive number.\n");
        return;
    }

    if (num == 1)
    {
        printf("Haha! You wanted to see a recursive program and all you get is a boring value of 1. :P\n");
        return;
    }

    printf("You entered %d. Let's see what happens when we call the function again...\n", num);

    recursive_function(num - 1);

    printf("Now let's multiply %d by %d.\n", num, num - 1);

    int result = num * (num - 1);

    printf("The answer is %d! Ta-da! Was that worth all the recursion? :D\n", result);
}

int main()
{
    printf("Welcome to the recursive program of ultimate boredom! :P\n");
    printf("Please enter a positive integer to start the recursion: ");

    int num;

    scanf("%d", &num);

    recursive_function(num);

    return 0;
}