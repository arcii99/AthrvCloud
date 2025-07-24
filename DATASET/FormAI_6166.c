//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Intergalactic Space Adventure!\n");
    printf("You are about to embark on a journey through the vastness of space!\n");

    char playerName[20];
    printf("Firstly, what's your name, space cadet? ");
    scanf("%s", playerName);

    printf("\nAh, so you are %s!\n\n", playerName);

    int age;
    printf("What is your age? ");
    scanf("%d", &age);

    if(age < 18){
        printf("Sorry, %s. You are too young to embark on this adventure. Come back when you are older!\n", playerName);
        return 0;
    }

    printf("\nExcellent! Let us continue with the adventure.\n");

    printf("You are the captain of the spaceship 'Enterprise'.\n");
    printf("Your mission is to explore uncharted territories in the galaxy.\n");
    printf("You must navigate through asteroid fields and battle hostile alien species to complete your mission.\n");

    srand(time(NULL));
    int randomNumber = rand()%100 + 1;

    printf("You must make a choice now, captain.\n");
    printf("There are three doors in front of you, numbered 1, 2, and 3.\n");
    printf("Choose a number between 1 and 3: ");
    int playerChoice;
    scanf("%d", &playerChoice);

    if(playerChoice == randomNumber){
        printf("Congratulations, %s! You have chosen the correct door and have won a brand new spaceship!\n", playerName);
    }else{
        printf("Unfortunately, %s, you have chosen the wrong door and have been attacked by hostile aliens. The 'Enterprise' is destroyed.\n", playerName);
    }
    printf("Game over.\n");
    return 0;
}