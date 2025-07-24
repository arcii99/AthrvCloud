//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int recursive_funny(int num)
{
    if(num == 0)
    {
        printf("You have reached the end of your recursion journey!\n");
        return 0;
    }
    else if(num == 1)
    {
        printf("You have reached the base case! Now the fun begins...\n");
        return 1;
    }
    else if(num % 2 == 0)
    {
        printf("We have an even number here! Let's divide it by 2 and see what happens...\n");
        return (recursive_funny(num/2));
    }
    else
    {
        printf("We have an odd number here! Let's do some math and make it even...\n");
        return (recursive_funny(num*3 + 1));
    }
}

int main()
{
    int num;
    srand(time(0));
    num = rand() % 50 + 1;
    printf("Welcome to the Recursive Fun House! You have been assigned the number %d...\n", num);
    printf("Let's see what kind of recursion magic we can come up with!\n");
    printf("Ready? Let's go!\n\n");
    recursive_funny(num);
    printf("\nCongratulations, you have made it out of the Recursive Fun House alive!\n");
    return 0;
}