//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int recursive_function(int n)
{
    if(n<=0)
    {
        printf("I'm sorry, I cannot compute negative numbers!\n");
        return -1;
    }
    else if(n==1)
    {
        printf("You only have 1 item, why do you need recursion?!\n");
        return 1;
    }
    else if(n==2)
    {
        printf("I guess recursion can be helpful for 2 items, but not really necessary...\n");
        return 1;
    }
    else
    {
        printf("Let's dive into some recursion!\n");
        return recursive_function(n-1) + recursive_function(n-2);
    }
}

int main()
{
    int n;
    printf("Hello, I am a comedic recursion bot!\n");
    printf("How many items would you like to calculate?\n");
    scanf("%d", &n);

    printf("Calculating %d items...\n", n);
    int result = recursive_function(n);

    if(result != -1)
    {
        printf("The result is %d! Hope you had fun with recursion!\n", result);
    }

    return 0;
}