//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int response;

    srand(time(NULL));
    
    printf("\n\tWelcome to the C Automated Fortune Teller!\n\n");

    while(1)
    {
        printf("Think of a question about your future and press enter to continue...\n");
        getchar();

        response = rand() % 10 + 1;

        switch(response)
        {
            case 1:
                printf("\n\tI predict that you will find yourself in a situation that requires pants.\n");
                break;
            case 2:
                printf("\n\tYour future is foggy... but it looks like there's pizza in it.\n");
                break;
            case 3:
                printf("\n\tYou will have a sudden urge to dance awkwardly in public.\n");
                break;
            case 4:
                printf("\n\tCats. So many cats. So much cat hair. Beware.\n");
                break;
            case 5:
                printf("\n\tYour future holds many high fives, but also many letdowns. Choose wisely.\n");
                break;
            case 6:
                printf("\n\tI predict that you will eat a sandwich. It will be glorious.\n");
                break;
            case 7:
                printf("\n\tYour future will be filled with a never-ending pile of dirty dishes. Sorry.\n");
                break;
            case 8:
                printf("\n\tI sense that you will find a new favorite song today. Sing it loud and proud.\n");
                break;
            case 9:
                printf("\n\tYour future holds a lot of confusion, but don't worry, you'll figure it out eventually.\n");
                break;
            case 10:
                printf("\n\tI predict that you will have a sudden desire to learn how to use nunchucks. Careful with those things.\n");
                break;
            default:
                printf("\n\tOops, it looks like something went wrong. Please try again later.\n");
                break;
        }

        printf("\nPress any key to ask another question, or press 'q' to quit...\n");

        if(getchar() == 'q')
        {
            break;
        }
    }

    printf("\n\tThanks for playing! Good luck with your future!\n\n");

    return 0;
}