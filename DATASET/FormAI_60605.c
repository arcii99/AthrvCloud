//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int ans;
    srand(time(0));
    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Please think of a question and enter any number to receive your answer.\n");
    scanf("%d", &ans);
    switch(rand() % 10)
    {
        case 0:
            printf("It is certain.\n");
            break;
        case 1:
            printf("Without a doubt.\n");
            break;
        case 2:
            printf("You may rely on it.\n");
            break;
        case 3:
            printf("Yes, definitely.\n");
            break;
        case 4:
            printf("It is decidedly so.\n");
            break;
        case 5:
            printf("As I see it, yes.\n");
            break;
        case 6:
            printf("Most likely.\n");
            break;
        case 7:
            printf("Outlook good.\n");
            break;
        case 8:
            printf("Yes.\n");
            break;
        case 9:
            printf("Signs point to yes.\n");
            break;
    }
    return 0;
}