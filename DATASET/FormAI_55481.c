//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen() {
    system("clear || cls");
}

int main() {
    char input[20];
    int choice;
    int health = 100;
    int money = 100;

    clearScreen();
    printf("\t\t=== Welcome to the Adventure Game! ===\n\n");
    printf("You find yourself in a dark forest. You don't know how you got here.\n");
    printf("You have 100 health points and 100 coins to start with.\n");
    printf("Your goal is to find your way out of the forest.\n\n");

    while (health > 0) {
        printf("What would you like to do?\n");
        printf("1. Look for a path\n");
        printf("2. Eat something\n");
        printf("3. Collect items\n");
        printf("4. Check status\n");
        printf("5. Quit game\n");

        do {
            printf("Enter your choice: ");
            fgets(input, sizeof(input), stdin);
            choice = atoi(input);
        } while (choice <= 0 || choice >= 6);

        switch (choice) {
            case 1:
                printf("You search for a path through the forest.\n");
                printf("After a while, you find two paths: one to the left and one to the right.\n");
                printf("Which way do you want to go (left or right)? ");
                fgets(input, sizeof(input), stdin);

                if (strcmp(input, "left\n") == 0) {
                    printf("You follow the path to the left and come across a river.\n");
                    printf("You can swim across (which is dangerous) or find a bridge.\n");
                    printf("Do you want to swim or find the bridge (swim or bridge)? ");
                    fgets(input, sizeof(input), stdin);

                    if (strcmp(input, "swim\n") == 0) {
                        health -= 20;
                        printf("You try to swim across the river but the current is too strong.\n");
                        printf("You lose 20 health points and have %d health points left.\n", health);
                        printf("You make it to the other side, but barely.\n");
                    } else if (strcmp(input, "bridge\n") == 0) {
                        printf("You find a bridge and cross it safely.\n");
                    } else {
                        printf("Invalid choice.\n");
                    }
                } else if (strcmp(input, "right\n") == 0) {
                    printf("You follow the path to the right and come across a cave.\n");
                    printf("Do you want to enter the cave (yes or no)? ");
                    fgets(input, sizeof(input), stdin);

                    if (strcmp(input, "yes\n") == 0) {
                        printf("You enter the cave and find a treasure chest.\n");
                        printf("Inside the chest you find 50 coins.\n");
                        money += 50;
                    } else if (strcmp(input, "no\n") == 0) {
                        printf("You decide not to enter the cave.\n");
                    } else {
                        printf("Invalid choice.\n");
                    }
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 2:
                printf("You look through your bag and find some food.\n");
                printf("You eat some of the food and regain 10 health points.\n");
                health += 10;

                if (health > 100) {
                    health = 100;
                }

                printf("You now have %d health points.\n", health);
                break;
            case 3:
                printf("You search the forest for items.\n");
                printf("You find a potion and a sword.\n");
                printf("Do you want to drink the potion or take the sword (potion or sword)? ");
                fgets(input, sizeof(input), stdin);

                if (strcmp(input, "potion\n") == 0) {
                    printf("You drink the potion and regain 25 health points.\n");
                    health += 25;

                    if (health > 100) {
                        health = 100;
                    }

                    printf("You now have %d health points.\n", health);
                } else if (strcmp(input, "sword\n") == 0) {
                    printf("You take the sword and equip it.\n");
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 4:
                printf("Your current status:\n");
                printf("Health: %d\n", health);
                printf("Coins: %d\n", money);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        if (health <= 0) {
            clearScreen();
            printf("Game Over.\n");
        } else {
            printf("Press any key to continue...");
            getchar();
            clearScreen();
        }
    }

    return 0;
}