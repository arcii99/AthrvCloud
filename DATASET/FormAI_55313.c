//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned) time(NULL)); //initialize random seed
    int random_num = rand() % 4; //generate random number between 0 and 3
    
    printf("Welcome to the Automated Fortune Teller!\n");

    switch(random_num)
    {
        case 0:
            printf("You will have good luck today!\n");
            break;
        case 1:
            printf("You will meet someone new today!\n");
            break;
        case 2:
            printf("Your hard work will pay off soon!\n");
            break;
        case 3:
            printf("You will make an important decision today!\n");
            break;
        default:
            printf("Uh oh, something went wrong!\n");
            break;
    }

    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}