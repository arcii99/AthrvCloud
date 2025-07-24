//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

void recursiveFunction(int num)
{
    if(num == 0)
    {
        printf("\n\n");
        return;
    }
    else
    {
        recursiveFunction(num - 1);
        printf("I'm a recursive function that's a little bit funny!\n");
    }
}

int main()
{
    printf("Are you ready to laugh? \n");
    printf("Of course you are, you are running a C program!\n");
    printf("So lets start with a recursive function that's really quite yummy! \n\n");
    
    int num = 10;
    // Let's call the recursive function
    recursiveFunction(num);

    printf("Did you find it funny? Maybe not, but I must admit it's quite stunning!\n");
    printf("So let's do it again, but this time let's include some punning! \n\n");
    
    num = 15;
    // Once more, let's call the recursive function
    recursiveFunction(num);

    printf("Ha ha ha! That's hilarious. You must admit, this program is quite ingenious! \n");
    printf("Now it's your turn, go ahead and write some funny code, tough genius! \n");

    return 0;
}