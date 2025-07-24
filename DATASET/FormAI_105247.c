//FormAI DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>

void knight(int level);

int main()
{
    printf("Greetings, brave knight! \n\n");
    printf("I am Sir Recursive, a skilled programmer.\n\n");
    printf("Are you interested in a demonstration of my talents?\n\n");

    knight(5);

    printf("Impressed, I see. Until next time, brave knight!\n\n");

    return 0;
}

void knight(int level)
{
    if(level == 0)
    {
        printf("Huzzah! We have reached the end of our journey.\n\n");
    }
    else
    {
        printf("We are at level %d of our quest. Onward!\n", level);
        knight(level - 1);
        printf("We have completed level %d. Now back to the village!\n", level);
    }
}