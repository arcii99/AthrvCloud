//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num, fortune;
    srand(time(0));    //seeding random number generator

    printf("Welcome to Automated Fortune Teller! \n\n");

    printf("Please enter a number between 1 and 5: ");
    scanf("%d", &num);

    if(num < 1 || num > 5)
    {
        printf("Invalid Input!\n");
        return 0;
    }
    
    fortune = rand() % 5 + 1;    //generate random number between 1 and 5
    
    switch(fortune)
    {
        case 1:
            printf("Your future is looking bright.\n");
            break;
        case 2:
            printf("You will soon meet someone special.\n");
            break;
        case 3:
            printf("You will face some challenges, but you will overcome them.\n");
            break;
        case 4:
            printf("A great opportunity is coming your way.\n");
            break;
        case 5:
            printf("You will receive unexpected good news.\n");
            break;
    }

    return 0;
}