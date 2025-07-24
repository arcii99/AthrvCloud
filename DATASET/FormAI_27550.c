//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber;
    char question[100];
    
    srand(time(NULL));
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please ask your question (yes or no questions only): ");
    fgets(question, sizeof question, stdin);

    randomNumber = rand() % 10;

    if (randomNumber <= 2)
    {
        printf("It is certain.\n");
    }
    else if (randomNumber <= 4)
    {
        printf("It is decidedly so.\n");
    }
    else if (randomNumber <= 6)
    {
        printf("Reply hazy, try again.\n");
    }
    else if (randomNumber <= 8)
    {
        printf("Don't count on it.\n");
    }
    else
    {
        printf("Outlook not so good.\n");
    }

    return 0;
}