//FormAI DATASET v1.0 Category: Random ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL)); //initialize random seed

    printf("Welcome to my random joke generator program! Hold on tight, you're in for a ride!\n");
    printf("Please press 'Enter' to continue...\n");

    getchar(); //wait for user to press Enter

    printf("Knock, knock.\n");

    if(rand() % 2) //generate random number between 0 and 1
    {
        printf("Who's there?\n");
        printf("Boo.\n");
        printf("Boo who?\n");
        printf("Don't cry, it's just a joke!\n");
    }
    else
    {
        printf("Who's there?\n");
        printf("Iva.\n");
        printf("Iva who?\n");
        printf("I've a sore hand from knocking!\n");
    }

    printf("Please press 'Enter' for another joke...\n");
    getchar(); //wait for user to press Enter

    printf("Why did the programmer quit his job?\n");

    if(rand() % 2) //generate another random number between 0 and 1
    {
        printf("I give up, why?\n");
        printf("Because he didn't get arrays!\n");
    }
    else
    {
        printf("Ha ha, why?\n");
        printf("Because he didn't like bugs in his code!\n");
    }

    printf("Please press 'Enter' for one more...\n");
    getchar(); //wait for user to press Enter

    printf("Why was the computer cold?\n");

    if(rand() % 2) //generate yet another random number between 0 and 1
    {
        printf("I'm not sure, why?\n");
        printf("Because it left its Windows open!\n");
    }
    else
    {
        printf("That's a good one, why?\n");
        printf("Because it left its Java running all night!\n");
    }

    printf("Thanks for using my random joke generator program! Remember to bookmark it for all your future comedy needs!\n");

    return 0;
}