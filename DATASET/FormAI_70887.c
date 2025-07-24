//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    printf("Welcome to the Adventure Game!\n");
    printf("What is your name?\n");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Hello, %s! Are you ready to start your adventure?\n", name);
    printf("You find yourself in a dark forest. You have no idea how you got there or where to go. What do you do?\n");
    printf("Type 'help' for a list of commands.\n");

    char command[20];
    while (1) {
        printf("> ");
        fgets(command, 20, stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "help") == 0) {
            printf("List of Commands:\n");
            printf("'look' - inspect your surroundings\n");
            printf("'north', 'south', 'east', or 'west' - move in that direction\n");
            printf("'inventory' - check your inventory\n");
            printf("'quit' - quit the game\n");
        }
        else if (strcmp(command, "look") == 0) {
            printf("You are in a dark forest. The trees are tall and the underbrush is thick. You can hear birds chirping in the distance.\n");
        }
        else if (strcmp(command, "north") == 0) {
            printf("You head north, but the underbrush is too thick to make progress. You turn back.\n");
        }
        else if (strcmp(command, "east") == 0) {
            printf("You head east, but you come across a river that is too wide to cross. You turn back.\n");
        }
        else if (strcmp(command, "south") == 0) {
            printf("You head south and come across a small village. The villagers welcome you and offer you a warm meal.\n");
        }
        else if (strcmp(command, "west") == 0) {
            printf("You head west and come across a bandit camp. They attack you on sight and you barely escape with your life.\n");
        }
        else if (strcmp(command, "inventory") == 0) {
            printf("You have nothing in your inventory.\n");
        }
        else if (strcmp(command, "quit") == 0) {
            printf("Quitting game...\n");
            break;
        }
        else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}