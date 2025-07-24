//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

void recursive_function(int count)
{
    if(count==0)
    {
        printf("Boom! Your computer is about to explode.\n");
        printf("Just kidding, recursion is awesome!\n");
        return;
    }
    printf("Recursive function call number %d, beep boop boop.\n", count);
    recursive_function(count-1);
}

int main()
{
    printf("This is a program that illustrates the power of recursion.\n");
    printf("Sit back, relax, and enjoy the ride.\n");
    printf("Press any key to start the function.\n");
    getchar();
    recursive_function(10);
    printf("That was fun, right?\n");
    printf("You want more? Okay, let's go.\n");
    recursive_function(5);
    printf("Told you recursion is awesome.\n");
    return 0;
}