//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen(){
    system("clear");
}

int main() {
    clearScreen();
    printf("\n\n");
    printf("Welcome to the Post-apocalyptic world\n\n");
    printf("You wake up in a deserted town outside of a building,\n");
    printf("and you are one of the few remaining survivors of the nuclear disaster.\n");
    printf("You are hungry, thirsty and alone. What do you wish to do? \n");

    // Initial Variables
    int hunger = 10;
    int thirst = 10;
    int health = 10;

    char input[50];
    int choice;

    // Game Loop
    while(health > 0) {
        printf("\n\n");
        printf("What would you like to do? \n");
        printf("1 - Search the building for supplies \n");
        printf("2 - Go outside to look for food and water \n");
        printf("3 - Stay put, rest and try to conserve energy \n\n");

        fgets(input, 50, stdin);
        choice = atoi(input);

        switch(choice) {
            case 1:
                clearScreen();
                printf("You scavenge the building for supplies and find some food and water.\n");
                hunger -= 2;
                thirst -= 2;
                health += 1;
                break;
            case 2:
                clearScreen();
                printf("You leave the building and search for food and water.\n");
                hunger -= 1;
                thirst -= 3;
                health -= 1;
                break;
            case 3:
                clearScreen();
                printf("You rest and try to conserve energy.\n");
                hunger -= 1;
                thirst -= 1;
                health += 1;
                break;
            default:
                clearScreen();
                printf("Invalid input. Try again.\n");
                continue;
        }

        // Check Health and Energy Levels
        if(hunger <= 0 || thirst <= 0) {
            clearScreen();
            printf("You have died of starvation or dehydration. Game Over. \n");
            break;
        }
        else if(health <= 0) {
            clearScreen();
            printf("You have died. Game Over. \n");
            break;
        }
        else if(hunger <= 3 || thirst <= 3) {
            clearScreen();
            printf("You are getting hungry and thirsty. Find food and water soon. \n");

            // Random Chance of Finding Supplies
            if(rand() % 3 == 0) {
                printf("You have found some food and water! (You got lucky!) \n");
                hunger += 2;
                thirst += 2;
            }
        }

        // Display Current Levels
        printf("\n\n");
        printf("Current Hunger Level: %d\n", hunger);
        printf("Current Thirst Level: %d\n", thirst);
        printf("Current Health Level: %d\n", health);
    }

    return 0;
}