//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize seed
    
    int fortune = rand() % 10 + 1; //randomly generate a number between 1 and 10

    printf("\n\nWelcome to the Automated Fortune Teller! \n\n");

    //determine fortune based on randomly generated number
    switch (fortune)
    {
        case 1:
            printf("It is certain that good things are coming your way!\n");
            break;
        case 2:
            printf("This is a great time for new beginnings. Expect good things to happen!\n");
            break;
        case 3:
            printf("You are destined to do great things. Keep moving forward and success is guaranteed!\n");
            break;
        case 4:
            printf("Don't worry about the future. Everything will work out just fine.\n");
            break;
        case 5:
            printf("You are incredibly talented and capable. Believe in yourself and anything is possible!\n");
            break;
        case 6:
            printf("Your hard work and dedication will pay off in ways you can't even imagine!\n");
            break;
        case 7:
            printf("Don't be afraid to take risks and try new things. You have the power to achieve great things!\n");
            break;
        case 8:
            printf("Keep your focus on your goals and success will follow.\n");
            break;
        case 9:
            printf("Your kindness and generosity will lead to unexpected treasure in your life.\n");
            break;
        case 10:
            printf("Your future is as bright as the sun. Keep shining and spreading positivity wherever you go!\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller. Have a wonderful day!\n");

    return 0;
}