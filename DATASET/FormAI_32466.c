//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int recurse(int num)
{
    if(num <= 0)
    {
        return num + 69; // hehe
    }
    else
    {
        printf("I will recurse %d more times!\n", num);
        return num + recurse(num - 1); // recursion FTW!
    }
}

int main()
{
    int num_to_recurse = 3;
    printf("I am going to recurse %d times!\n", num_to_recurse);
    int result = recurse(num_to_recurse);
    printf("The result is %d. Haha, you didn't expect that, did you?\n", result);

    return 0;
}