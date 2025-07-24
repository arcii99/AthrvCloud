//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void recursive_function(int num);

int main()
{
    int num;
    printf("Hey there! Enter any positive integer to start the magic :D ");
    scanf("%d", &num);
    if(num < 1)
    {
        printf("Seriously? Enter something greater than 0. Try again :/ ");
        scanf("%d", &num);
    }
    printf("\n\nLet's see some magic\n\n\n");
    recursive_function(num);
    printf("\n\n\nHaha, that was funny, right? See you soon! :)\n\n\n");
    return 0;
}

void recursive_function(int num)
{
    if(num == 1)
    {
        printf("%d, ", num);
        return;
    }
    else if(num == 2)
    {
        printf("%d and ", num);
    }
    else
    {
        printf("%d, ", num);
    }
    recursive_function(num-1);
}