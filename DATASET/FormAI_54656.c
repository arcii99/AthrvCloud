//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    srand(time(0)); // Initialize random number generator

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of a question and enter 'y' to continue or 'n' to exit: ");

    char answer;
    scanf(" %c", &answer);

    while (answer == 'y')
    {
        int fortune = rand() % 10; // Generate a random number between 0 and 9

        switch(fortune)
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
                printf("Signs point to yes.\n");
                break;
            case 9:
                printf("Very doubtful.\n");
                break;
        }

        printf("Do you have another question? Enter 'y' to continue or 'n' to exit: ");
        scanf(" %c", &answer);
    }
    
    printf("Thank you for using the Automated Fortune Teller!");

    return 0;
}