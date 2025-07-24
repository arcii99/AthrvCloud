//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void welcome();
void menu();
void startAdventure();
void roomOne();
void roomTwo();
void roomThree();
void roomFour();
void roomFive();
int getInput(char *choice, char *options[], int numOptions);

// Main function
int main() {
    welcome();
    menu();

    return 0;
}

// Function to welcome the player
void welcome() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You find yourself in a dark room with no memory of how you got here.\n");
    printf("Can you find a way out?\n\n");
}

// Function to display the main menu
void menu() {
    char *menuOptions[3] = {"Start Adventure", "Instructions", "Quit Game"};
    char choice;
    int selection;

    do {
        selection = getInput(&choice, menuOptions, 3);

        switch (selection) {
            case 1:
                startAdventure();
                break;
            case 2:
                printf("Instructions:\n\n");
                printf("Use the commands \"North\", \"South\", \"East\" or \"West\" to move through the rooms.\n");
                printf("Type \"Inventory\" to see what items you have collected.\n");
                printf("Type \"Use\" followed by an item name to use an item.\n\n");
                break;
            case 3:
                printf("Thanks for playing, goodbye!\n");
                exit(0);
                break;
        }
    } while (1);
}

// Function to start the adventure game
void startAdventure() {
    printf("You open the door and find yourself in a brightly lit room.\n");
    printf("There are four doors leading to different directions.\n");
    printf("Where would you like to go?\n\n");

    char *roomOptions[4] = {"North", "South", "East", "West"};
    char choice;
    int selection;

    do {
        selection = getInput(&choice, roomOptions, 4);

        switch (selection) {
            case 1:
                roomOne();
                break;
            case 2:
                roomTwo();
                break;
            case 3:
                roomThree();
                break;
            case 4:
                roomFour();
                break;
        }
    } while (1);
}

// First room
void roomOne() {
    printf("You are in a small dark room with a locked door to the east.\n");
    printf("There is a key on a table in the middle of the room.\n");
    printf("What do you do?\n\n");

    char *roomOptions[3] = {"Take Key", "Go West", "Inventory"};
    char choice;
    int selection;

    do {
        selection = getInput(&choice, roomOptions, 3);

        switch (selection) {
            case 1:
                printf("You take the key from the table.\n\n");
                break;
            case 2:
                printf("You can't go that way.\n\n");
                break;
            case 3:
                printf("You have no items.\n\n");
                break;
        }
    } while (selection != 1);

    roomTwo();
}

// Second room
void roomTwo() {
    printf("You are in a room with a large chest in the middle.\n");
    printf("There is a door to the south and a locked door to the east.\n");
    printf("What do you do?\n\n");

    char *roomOptions[4] = {"Open Chest", "Go South", "Go West", "Inventory"};
    char choice;
    int selection;

    do {
        selection = getInput(&choice, roomOptions, 4);

        switch (selection) {
            case 1:
                printf("You open the chest and find a lantern and a note.\n");
                printf("The note says \"Use the lantern to light the way.\"\n");
                printf("You take the lantern and the note.\n\n");
                break;
            case 2:
                printf("You go south and find yourself in a larger room.\n\n");
                roomThree();
                break;
            case 3:
                printf("You go west and find yourself back in the first room.\n\n");
                roomOne();
                break;
            case 4:
                printf("You have a key and a lantern.\n\n");
                break;
        }
    } while (selection != 1);

    roomFour();
}

// Third room
void roomThree() {
    printf("You are in a large room with a huge machine in the middle.\n");
    printf("There are two doors leading to the north and the east.\n");
    printf("The machine has a lever on the side and a sign that says \"Pull the lever to turn on the power\".\n\n");
    printf("What do you do?\n\n");

    char *roomOptions[5] = {"Pull Lever", "Go North", "Go East", "Go South", "Inventory"};
    char choice;
    int selection;

    do {
        selection = getInput(&choice, roomOptions, 5);

        switch (selection) {
            case 1:
                printf("You pull the lever and the machine whirs to life.\n");
                printf("The lights flicker on and the locked door to the east unlocks.\n\n");
                break;
            case 2:
                printf("You go north and find yourself in a dark corridor.\n\n");
                roomFive();
                break;
            case 3:
                printf("You go east and find yourself in a room with a huge hole in the ground.\n\n");
                roomFour();
                break;
            case 4:
                printf("You can't go that way.\n\n");
                break;
            case 5:
                printf("You have a key and a lantern.\n\n");
                break;
        }
    } while (selection != 1);
}

// Fourth room
void roomFour() {
    printf("You are in a dark room with a huge hole in the ground.\n");
    printf("There is a door to the north and a locked door to the east.\n");
    printf("What do you do?\n\n");

    char *roomOptions[4] = {"Go North", "Go East", "Use Lantern", "Inventory"};
    char choice;
    int selection;

    do {
        selection = getInput(&choice, roomOptions, 4);

        switch (selection) {
            case 1:
                printf("You go north and find yourself in a large room.\n\n");
                roomThree();
                break;
            case 2:
                printf("The door is locked.\n\n");
                break;
            case 3:
                printf("You use the lantern to light the way.\n\n");
                break;
            case 4:
                printf("You have a key and a lantern.\n\n");
                break;
        }
    } while (selection != 1);
}

// Fifth room
void roomFive() {
    printf("You are in a dark corridor with two doors, one to the north and one to the west.\n");
    printf("What do you do?\n\n");

    char *roomOptions[3] = {"Go North", "Go West", "Inventory"};
    char choice;
    int selection;

    do {
        selection = getInput(&choice, roomOptions, 3);

        switch (selection) {
            case 1:
                printf("You go north and find yourself in a large room.\n\n");
                roomThree();
                break;
            case 2:
                printf("You go west and find yourself back in the second room.\n\n");
                roomTwo();
                break;
            case 3:
                printf("You have a key and a lantern.\n\n");
                break;
        }
    } while (1);
}

// Function to get player input
int getInput(char *choice, char *options[], int numOptions) {
    char input[20];
    int i;

    printf("Available options: ");

    for (i = 0; i < numOptions; i++) {
        printf("%s", options[i]);

        if (i < numOptions - 1) {
            printf(", ");
        }
    }

    printf("\n\n");

    do {
        printf("Enter your choice: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0;
        *choice = toupper(input[0]);

        for (i = 0; i < numOptions; i++) {
            if (*choice == toupper(options[i][0])) {
                return i + 1;
            }
        }

        printf("Invalid choice, please try again.\n\n");
    } while (1);
}