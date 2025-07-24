//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int response;
    char name[20];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s!\n", name);

    srand(time(NULL));

    do
    {
        printf("\nWhat do you wish to know today?\n");
        printf("1. Love\n2. Money\n3. Career\n4. Health\n5. Future\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &response);

        switch(response)
        {
            case 1:
                printf("\nYou will soon find the love of your life!\n");
                break;
            case 2:
                printf("\nMoney is coming your way, keep your eyes open!\n");
                break;
            case 3:
                printf("\nYour career is destined for greatness, keep up the good work!\n");
                break;
            case 4:
                printf("\nYour health is excellent, keep taking care of yourself!\n");
                break;
            case 5:
                printf("\nYour future is full of possibilities, choose wisely!\n");
                break;
            case 6:
                printf("\nGoodbye %s! May good fortune follow you!\n", name);
                break;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }

    } while(response != 6);

    return 0;
}