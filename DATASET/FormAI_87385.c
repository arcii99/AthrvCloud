//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // set up the game
    srand(time(NULL));
    int health = 100;
    int fuel = 1000;
    int credits = 0;
    int location = 0;

    // welcome the player
    printf("Welcome to Procedural Space Adventure! Your goal is to explore the unknown depths of space.\n");

    // game loop
    while (health > 0 && fuel > 0) {
        // display player stats
        printf("Location: %d\n", location);
        printf("Health: %d\n", health);
        printf("Fuel: %d\n", fuel);
        printf("Credits: %d\n\n", credits);

        // ask the player what they want to do
        printf("What do you want to do?\n");
        printf("1. Fly to a new location\n");
        printf("2. Mine for resources\n");
        printf("3. Trade with other ships\n");
        printf("4. Upgrade your ship\n");
        printf("5. Quit the game\n");
        int choice;
        scanf("%d", &choice);

        // handle player's choice
        switch(choice) {
            case 1:
                // fly to a new location
                int distance = rand() % 100 + 1;
                printf("You travel %d light-years and arrive at a new location.\n\n", distance);
                location += distance;
                fuel -= distance * 10;
                break;

            case 2:
                // mine for resources
                int ores = rand() % 5 + 1;
                printf("You mine for resources and find %d ores.\n\n", ores);
                credits += ores * 10;
                break;

            case 3:
                // trade with other ships
                int offer = rand() % 1000 + 1;
                printf("Another ship offers to buy your resources for %d credits.\n", offer);
                printf("Do you accept?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                int accept;
                scanf("%d", &accept);
                if (accept == 1) {
                    credits += offer;
                }
                printf("\n");
                break;

            case 4:
                // upgrade ship
                int upgrade_cost = 500;
                printf("You can upgrade your ship for %d credits.\n", upgrade_cost);
                printf("Do you want to upgrade?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                int upgrade_choice;
                scanf("%d", &upgrade_choice);
                if (upgrade_choice == 1) {
                    credits -= upgrade_cost;
                    fuel += 500;
                }
                printf("\n");
                break;

            case 5:
                // quit the game
                printf("Thanks for playing!\n");
                return 0;

            default:
                // invalid input
                printf("Invalid input! Try again.\n\n");
                break;
        }

        // random event: asteroid hit
        if (rand() % 20 == 0) {
            printf("Your ship was hit by an asteroid!\n");
            int damage = rand() % 50 + 1;
            health -= damage;
            printf("You take %d damage.\n\n", damage);
        }

        // random event: alien encounter
        if (rand() % 30 == 0) {
            printf("You encountered an alien ship!\n");
            int offer = rand() % 1000 + 1;
            printf("They offer to buy your resources for %d credits.\n", offer);
            printf("Do you accept?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int accept;
            scanf("%d", &accept);
            if (accept == 1) {
                credits += offer;
            }
            printf("\n");
        }
    }

    // game over
    printf("GAME OVER!\n");
    if (health <= 0) {
        printf("Your ship was destroyed. :(\n");
    } else {
        printf("You ran out of fuel. :(\n");
    }

    return 0;
}