//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char player_name[20];
    int lucky_number, random_number;
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    printf("Hello there, %s!\n", player_name);

    printf("Which lucky number do you prefer, %s? (1-10)\n", player_name);
    scanf("%d", &lucky_number);
    printf("You have selected %d as your lucky number.\n", lucky_number);

    printf("Now it's time to check if you're lucky today...\n");
    
    random_number = rand() % 10 + 1;
    if (random_number == lucky_number)
    {
        printf("Congratulations, %s! You are very lucky today!\n", player_name);
        printf("You will receive a surprise gift soon.\n");
    }
    else
    {
        printf("Sorry, %s. Today is not your lucky day. Try again tomorrow.\n", player_name);
    }
    return 0;
}