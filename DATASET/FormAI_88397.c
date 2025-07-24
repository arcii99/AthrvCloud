//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>

int funkyrecursive(int n)
{
    if(n==0 || n==1)
    {
        printf("We have reached the base case! Hooray!\n");
        return n;
    }
    else if(n%2 == 0)
    {
        printf("We have an even number %d, let's take it to the next level!\n", n);
        return funkyrecursive(n/2) + n;
    }
    else if(n%3 == 0)
    {
        printf("We have a multiple of 3 %d, let's spice it up!\n", n);
        return funkyrecursive(n/3) * n;
    }
    else if(n%5 == 0)
    {
        printf("We have a multiple of 5 %d, let's go wild!\n", n);
        return funkyrecursive(n/5) - n;
    }
    else
    {
        printf("We have a funky number %d, but we can handle it!\n", n);
        return funkyrecursive(n-1) + funkyrecursive(n-2);
    }
}

int main()
{
    int user_input;
    printf("Let's get funky! Enter a number: ");
    scanf("%d", &user_input);
    printf("The funky result of %d is: %d", user_input, funkyrecursive(user_input));
    return 0;
}