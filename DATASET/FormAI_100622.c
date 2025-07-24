//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 50

int main() {

    printf("Welcome to Procedural Space Adventure!\n\n");

    char name[MAX_INPUT_SIZE];
    printf("What's your name, adventurer?\n");
    fgets(name, MAX_INPUT_SIZE, stdin);

    //remove newline character at the end of input
    name[strcspn(name, "\n")] = 0;

    printf("Greetings, %s! Your adventure begins now.\n\n", name);

    int health = 100;
    int credits = 100;
    int fuel = 100;

    while (health > 0 && fuel > 0) {
        printf("You have %d health points, %d credits, and %d units of fuel.\n", health, credits, fuel);
        printf("Choose your next destination:\n\n");
        printf("1. Explore a planet\n");
        printf("2. Travel to a nearby star system\n");
        printf("3. Visit a space station\n");
        printf("4. Refuel your ship\n");
        printf("5. Quit game\n");

        char input[MAX_INPUT_SIZE];
        fgets(input, MAX_INPUT_SIZE, stdin);

        //remove newline character at the end of input
        input[strcspn(input, "\n")] = 0;

        int choice = atoi(input);
        switch (choice) {
            case 1:
                printf("You have landed on an unknown planet!\n");
                printf("You encounter strange alien creatures.\n");

                int outcome = rand() % 3;
                if (outcome == 0) {
                    printf("You thankfully make it out alive.\n");
                } else if (outcome == 1) {
                    printf("You were attacked and lost 20 health points.\n");
                    health -= 20;
                } else {
                    printf("You discover a valuable mineral and earn 50 credits.\n");
                    credits += 50;
                }

                fuel -= 10;
                break;
            case 2:
                printf("You jump to hyperspace and travel to a new star system.\n");

                outcome = rand() % 3;
                if (outcome == 0) {
                    printf("Your journey was uneventful.\n");
                } else if (outcome == 1) {
                    printf("You encountered space pirates and lost 30 credits.\n");
                    credits -= 30;
                } else {
                    printf("You discovered a new planet and gained 10 fuel units.\n");
                    fuel += 10;
                }

                fuel -= 20;
                break;
            case 3:
                printf("You dock at a busy space station.\n");

                outcome = rand() % 3;
                if (outcome == 0) {
                    printf("You purchase valuable upgrades for your ship and lose 50 credits.\n");
                    credits -= 50;
                } else if (outcome == 1) {
                    printf("You get scammed by a shady merchant and lose 10 credits.\n");
                    credits -= 10;
                } else {
                    printf("You sell some of your minerals for 25 credits.\n");
                    credits += 25;
                }

                health += 10;
                break;
            case 4:
                printf("You refuel your ship with 50 credits.\n");
                fuel += 50;
                credits -= 50;
                break;
            case 5:
                printf("Thanks for playing Procedural Space Adventure, %s!\n", name);
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }

        //check if health or fuel have reached 0
        if (health <= 0) {
            printf("You have died. Game over.\n");
            exit(0);
        } else if (fuel <= 0) {
            printf("Your ship has run out of fuel. Game over.\n");
            exit(0);
        }
    }

    return 0;
}