//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int choice;
    char question[255];
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your question:\n");
    scanf("%[^\n]s", question);
    getchar(); //to clear the input buffer
    
    srand(time(NULL)); //seeding the srand function with time
    
    printf("\nThinking...\n");
    sleep(3); //wait for 3 seconds to create suspense
    
    choice = rand() % 10; //generating a random number between 0 and 9
    
    switch(choice)
    {
        case 0:
            printf("\nMy sources say no.\n");
            break;
        case 1:
            printf("\nReply hazy, try again.\n");
            break;
        case 2:
            printf("\nBetter not tell you now.\n");
            break;
        case 3:
            printf("\nOutlook not so good.\n");
            break;
        case 4:
            printf("\nCannot predict now.\n");
            break;
        case 5:
            printf("\nDon't count on it.\n");
            break;
        case 6:
            printf("\nSigns point to yes.\n");
            break;
        case 7:
            printf("\nYes.\n");
            break;
        case 8:
            printf("\nVery doubtful.\n");
            break;
        case 9:
            printf("\nConcentrate and ask again.\n");
            break;
        default:
            printf("\nError: Invalid choice.\n");
            break;
    }
    
    printf("\nThank you for using the Automated Fortune Teller!\n");
    return 0;
}