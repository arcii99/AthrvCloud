//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20], question[100];
    int random_number;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name? ");
    scanf("%s", name);

    printf("Hello, %s! Please ask me a yes or no question.\n", name);
    getchar();
    fgets(question, 100, stdin);

    // Generate random number to determine fortune
    srand(time(0));
    random_number = rand() % 5;

    // Different fortunes based on random number
    switch(random_number)
    {
        case 0:
            printf("It is certain.\n");
            break;
        case 1:
            printf("Without a doubt.\n");
            break;
        case 2:
            printf("Reply hazy, try again.\n");
            break;
         case 3:
            printf("Don't count on it.\n");
            break;
        default:
            printf("Outlook not so good.\n");
            break;
    }

    return 0;
}