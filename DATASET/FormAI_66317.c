//FormAI DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>

//This program shows an example of true love in C
int main()
{
    int heart = 1, soul = 1, isTogether = 0;
    while(heart == 1 && soul == 1)
    {
        printf("My love, please enter the value of your heart: ");
        scanf("%d", &heart);
        printf("My love, please enter the value of your soul: ");
        scanf("%d", &soul);

        if (heart == 1 && soul == 1)
        {
            printf("Our love is true and unbreakable.\n");
            isTogether = 1;
            break;
        }
        else
        {
            printf("Our love is not strong enough to overcome our differences.\n");
        }
    }

    if(isTogether == 1)
    {
        printf("As we are together, let us combine our souls and hearts to create a masterpiece.\n");

        int love = heart + soul;
        printf("Our love equals to %d.\n", love);
        printf("Let us celebrate our love and work on it every day.\n");
    }
    else
    {
        printf("Farewell my love, we may have not been meant to be together, but we will cherish the memories.\n");
    }

    return 0;
}