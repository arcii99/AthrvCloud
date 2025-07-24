//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function declarations
void print_intro();
void start_adventure();
void print_game_over();
void print_win();
int roll_dice();
int make_choice();

int main()
{
    print_intro();
    start_adventure();
    return 0;
}

// prints the introduction to the game
void print_intro()
{
    printf("Hello adventurer! Welcome to the Ada Lovelace adventure game.\n");
    printf("You are about to embark on an exciting journey filled with puzzles, challenges, and thrills.\n");
    printf("Are you ready to begin?\n\n");
}

// starts the adventure game
void start_adventure()
{
    int choice = 0;
    int dice_roll = 0;
    srand(time(NULL)); // seed the random number generator

    // start of game
    printf("You find yourself in a room with two doors.\n");
    choice = make_choice();
    if(choice == 1)
    {
        printf("You chose door 1. It leads to a dark hallway.\n");
        printf("You hear strange noises in the distance.\n");
        printf("You see a torch on the wall. Do you want to take it? (1 for yes, 2 for no)\n");
        choice = make_choice();
        if(choice == 1)
        {
            printf("You take the torch and proceed down the hallway.\n");
            printf("You see a chest at the end of the hallway. Do you want to open it? (1 for yes, 2 for no)\n");
            choice = make_choice();
            if(choice == 1)
            {
                printf("You open the chest and find a key inside.\n");
                printf("You continue down the hallway and come across a door.\n");
                printf("You use the key to unlock the door and step outside into the sunlight.\n");
                print_win();
            }
            else
            {
                printf("You decide to leave the chest alone.\n");
                printf("You continue down the hallway and come across a door.\n");
                printf("You try to open the door but it is locked.\n");
                printf("You turn around and head back the way you came.\n");
                print_game_over();
            }
        }
        else
        {
            printf("You decide not to take the torch.\n");
            printf("You continue down the hallway and come across a door.\n");
            printf("You try to open the door but it is locked.\n");
            printf("You turn around and head back the way you came.\n");
            print_game_over();
        }
    }
    else
    {
        printf("You chose door 2. It leads to a room filled with treasure.\n");
        printf("You see a treasure chest in front of you. Do you want to open it? (1 for yes, 2 for no)\n");
        choice = make_choice();
        if(choice == 1)
        {
            printf("You open the chest and find a map inside.\n");
            printf("You examine the map and see that it leads to a hidden exit.\n");
            printf("You follow the map and find the hidden exit.\n");
            printf("You step outside into the sunlight.\n");
            print_win();
        }
        else
        {
            printf("You decide not to open the chest.\n");
            printf("You explore the room and find a door.\n");
            dice_roll = roll_dice();
            printf("You roll the dice and get %d.\n", dice_roll);
            if(dice_roll > 3)
            {
                printf("You use your luck to open the door and step outside into the sunlight.\n");
                print_win();
            }
            else
            {
                printf("You try to open the door but it is locked.\n");
                printf("You turn around and head back the way you came.\n");
                print_game_over();
            }
        }
    }
}

// prints game over message and exits program
void print_game_over()
{
    printf("Game over! You have failed the Ada Lovelace adventure game.\n");
    exit(0);
}

// prints win message and exits program
void print_win()
{
    printf("Congratulations! You have completed the Ada Lovelace adventure game.\n");
    exit(0);
}

// returns a random number between 1 and 6
int roll_dice()
{
    return (rand() % 6) + 1;
}

// prompts the user to make a choice and returns the choice
int make_choice()
{
    int choice = 0;
    do 
    {
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
    } while(choice != 1 && choice != 2);
    return choice;
}