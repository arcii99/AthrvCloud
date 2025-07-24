//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int input, lucky_number;
    srand(time(0));
    lucky_number = rand() % 10 + 1;

    printf("Welcome to the automated fortune teller! \n");
    printf("What is your name?\n");
    scanf("%s", &input);
    printf("\n");

    printf("Greetings, %s! \n", &input);
    printf("Are you curious about what the universe has planned for you in the love department? \n");
    printf("Pick a number from 1 to 10 and I will give you your love fortune: \n");
    scanf("%d", &input);

    if (input == lucky_number)
    {
        printf("Congratulations, the stars have aligned for you! You are destined to find your soulmate soon. \n");
    }
    else if (input < lucky_number)
    {
        printf("Don't worry, there is still hope! Keep an open mind and heart, and love will find you. \n");
    }
    else if (input > lucky_number)
    {
        printf("You may have to put in some extra effort, but love will be worth the wait. Keep your head up! \n");
    }
    else
    {
        printf("I'm sorry, I didn't catch that. Please try again with a number from 1 to 10. \n");
    }

    printf("Thank you for using the automated fortune teller! Good luck in love, %s. \n", &input);

    return 0;
}