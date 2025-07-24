//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int option;

    //To generate random numbers
    srand((unsigned)time(NULL));

    //Displaying options
    printf("MENU\n");
    printf("1. Ask a Question\n");
    printf("2. Exit\n");

    //Taking input from user
    printf("Enter your option: ");
    scanf("%d", &option);

    //Checking user's choice
    if(option == 1)
    {
        //Generating random number between 1 and 10
        int randomNumber = rand() % 10 + 1;

        //Displaying answer based on random number
        switch(randomNumber)
        {
            case 1:
                printf("Yes, definitely\n");
                break;
            case 2:
                printf("Without a doubt\n");
                break;
            case 3:
                printf("Most likely\n");
                break;
            case 4:
                printf("Outlook good\n");
                break;
            case 5:
                printf("Signs point to yes\n");
                break;
            case 6:
                printf("Reply hazy, try again\n");
                break;
            case 7:
                printf("Ask again later\n");
                break;
            case 8:
                printf("Better not tell you now\n");
                break;
            case 9:
                printf("Cannot predict now\n");
                break;
            case 10:
                printf("Don't count on it\n");
                break;
        }
    }
    else if(option == 2)
    {
        //User wants to exit
        printf("Goodbye!");
    }
    else
    {
        //Invalid option
        printf("Invalid option!");
    }

    return 0;
}