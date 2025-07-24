//FormAI DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding the random number generator
    int diceRoll = rand() % 6 + 1; // rolling the dice range from 1 to 6
    
    printf("Welcome to the post-apocalyptic dice game!\n");
    printf("You are wandering through a desolate wasteland, scavenging for supplies.\n");
    printf("Suddenly, you come across a group of survivors, and they challenge you to a game of dice.\n\n");
    
    printf("You roll the dice...\n\n");
    
    switch(diceRoll)
    {
        case 1:
            printf("Oh no! You rolled a one. The group of survivors laugh at your misfortune.\n");
            break;
        case 2:
            printf("You rolled a two. Not great, but not terrible.\n");
            break;
        case 3:
            printf("You rolled a three. Things are starting to look up.\n");
            break;
        case 4:
            printf("You rolled a four. The survivors look a little nervous.\n");
            break;
        case 5:
            printf("You rolled a five. The survivors are intimidated by your luck.\n");
            break;
        case 6:
            printf("You rolled a six! The survivors are in awe of your incredible luck.\n");
            break;
        default:
            printf("Something went wrong. Please try again.\n");
    }
    
    return 0;
}