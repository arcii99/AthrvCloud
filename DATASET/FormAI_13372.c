//FormAI DATASET v1.0 Category: Random ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int random_num = rand()%100; //generating a random number between 0-99
    printf("Welcome to the Happy Random Number Generator!!!\n");
    printf("***********************************************************\n");
    printf("Let's generate some positive vibes with a random number!!!\n");
    printf("The number is.....drum roll please.....%d!!!\n", random_num);
    printf("***********************************************************\n");
    printf("Isn't that awesome!? Let's do it again!!\n");
    printf("***********************************************************\n");
    random_num = rand()%100;
    printf("The next number is......%d!!!\n", random_num);
    printf("***********************************************************\n");
    printf("Wow! We are on a roll! Let's keep generating random numbers\n");
    printf("***********************************************************\n");
    for(int i=0;i<5;i++) //generating 5 more random numbers
    {
        random_num = rand()%100;
        printf("The random number is......%d!!!\n", random_num);
    }
    printf("***********************************************************\n");
    printf("That was so much fun!!! Let's do it one more time....\n");
    printf("***********************************************************\n");
    random_num = rand()%100;
    printf("The last random number is.....%d!!!\n", random_num);
    printf("***********************************************************\n");
    printf("Hope you had a great time!! Come again for some more happy vibes!\n");
    printf("***********************************************************\n");
    return 0;
}