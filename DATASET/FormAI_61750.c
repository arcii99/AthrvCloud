//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;
    char name[20];
    printf("Welcome to the Automated Fortune Teller! What is your name?\n");
    scanf("%s", name);
    printf("Hello %s, please think of a number between 1 and 10.\n", name);
    srand(time(0));
    num = rand() % 10 + 1;
    switch(num)
    {
        case 1:
            printf("Your future looks bright!\n");
            break;
        case 2:
            printf("You will soon embark on a new adventure.\n");
            break;
        case 3:
            printf("Financial stability is in your near future.\n");
            break;
        case 4:
            printf("Be cautious in your relationships, as there may be some hidden motives.\n");
            break;
        case 5:
            printf("You will find success in your current endeavors.\n");
            break;
        case 6:
            printf("Avoid making big decisions at this time, as the outcome may not be what you expect.\n");
            break;
        case 7:
            printf("Good news is on the horizon.\n");
            break;
        case 8:
            printf("Take some time for yourself, as rest and relaxation are needed.\n");
            break;
        case 9:
            printf("New beginnings are in your future, embrace them with open arms.\n");
            break;
        case 10:
            printf("You will encounter some obstacles, but with determination and perseverance, you will overcome them.\n");
            break;
        default:
            printf("Error! Please enter a number between 1 and 10.\n");
    }
    return 0;
}