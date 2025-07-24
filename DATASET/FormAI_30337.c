//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

int player_health = 100;

void introduction()
{
    printf("Welcome to Adventure Island!\n");
    printf("You have been stranded on an island and you must survive and find a way to escape.\n");
}

void show_help()
{
    printf("List of Commands:\n");
    printf("help - Display this help message\n");
    printf("look - Examine your surroundings\n");
    printf("eat - Eat some food to restore your health\n");
    printf("explore - Go on an adventure\n");
    printf("quit - Quit the game\n");
}

void print_prompt()
{
    printf("\n>>> ");
}

void handle_input(char input[])
{
    if (strcmp(input, "help") == 0)
    {
        show_help();
    }
    else if (strcmp(input, "look") == 0)
    {
        printf("You are on a deserted island. You see trees, sand, and water.\n");
    }
    else if (strcmp(input, "eat") == 0)
    {
        printf("You eat some coconuts and your health is restored.\n");
        player_health = 100;
    }
    else if (strcmp(input, "explore") == 0)
    {
        int rand_num = rand() % 3;
        if (rand_num == 0)
        {
            printf("You found a boat and escaped the island! You win!\n");
            exit(0);
        }
        else if (rand_num == 1)
        {
            printf("You were attacked by a group of monkeys. You lose 20 health.\n");
            player_health -= 20;
        }
        else if (rand_num == 2)
        {
            printf("You found a cave. Inside the cave, you found a treasure chest with food and water. Your health is restored.\n");
            player_health = 100;
        }
    }
    else if (strcmp(input, "quit") == 0)
    {
        printf("Game over. Goodbye!\n");
        exit(0);
    }
    else
    {
        printf("Invalid command. Type 'help' for a list of commands.\n");
    }
}

int main()
{
    char input[MAX_INPUT_LENGTH];
    introduction();
    show_help();
    while (true)
    {
        printf("Your health is %d.\n", player_health);
        print_prompt();
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        handle_input(input);
    }
    return 0;
}