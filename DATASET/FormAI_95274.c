//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 30

// function to convert string to lower case
void toLowerCase(char *string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int choice = 0;

    printf("Welcome to the Adventure Game!\n\n");

    while (1) {
        printf("Choose your adventure: \n");
        printf("1. The Haunted Mansion\n");
        printf("2. The Lost Island\n");
        printf("3. Quit\n\n");

        // get user input and convert to lower case
        printf("Enter your choice: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        toLowerCase(input);

        // convert input string to integer
        choice = atoi(input);

        // process user input
        switch(choice) {
            case 1:
                printf("\nYou enter a haunted mansion. What do you want to do?\n");
                printf("1. Go upstairs\n");
                printf("2. Go downstairs\n");
                printf("3. Explore the garden\n");
                printf("4. Leave the mansion\n\n");

                printf("Enter your choice: ");
                fgets(input, MAX_INPUT_LENGTH, stdin);
                toLowerCase(input);

                choice = atoi(input);

                switch (choice) {
                    case 1:
                        printf("\nYou encounter a ghost and run back downstairs.\n");
                        break;

                    case 2:
                        printf("\nYou find a hidden room with treasure!\n");
                        break;

                    case 3:
                        printf("\nYou find a beautiful rose garden, but all the roses are dead.\n");
                        break;

                    case 4:
                        printf("\nYou leave the mansion but feel like you missed something.\n");
                        break;

                    default:
                        printf("\nInvalid choice.\n");
                        break;
                }
                break;

            case 2:
                printf("\nYou are on a lost island. What do you want to do?\n");
                printf("1. Explore the jungle\n");
                printf("2. Swim in the ocean\n");
                printf("3. Build a shelter\n");
                printf("4. Search for food\n\n");

                printf("Enter your choice: ");
                fgets(input, MAX_INPUT_LENGTH, stdin);
                toLowerCase(input);

                choice = atoi(input);

                switch (choice) {
                    case 1:
                        printf("\nYou encounter a dangerous predator and barely escape.\n");
                        break;

                    case 2:
                        printf("\nYou swim too far out and get lost in the ocean.\n");
                        break;

                    case 3:
                        printf("\nYou build a shelter but it collapses during a storm.\n");
                        break;

                    case 4:
                        printf("\nYou find some coconuts and a freshwater source. You survive!\n");
                        break;

                    default:
                        printf("\nInvalid choice.\n");
                        break;
                }
                break;

            case 3:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}