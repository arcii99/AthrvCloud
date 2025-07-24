//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your mission is to explore the galaxy and collect valuable resources!\n");

    delay(1);

    printf("Initializing spacecraft systems...\n");

    delay(2);

    int fuel = 100;
    int oxygen = 100;
    int food = 100;
    int resources = 0;

    while (1) {
        printf("\nChoose your next action:\n");
        printf("1. Travel to another planet\n");
        printf("2. Gather resources on current planet\n");
        printf("3. Check spacecraft systems\n");
        printf("4. Quit game\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (fuel >= 20 && oxygen >= 10 && food >= 5) {
                    printf("Traveling to a new planet...\n");

                    delay(3);

                    printf("Arrived at new planet!\n");

                    fuel -= 20;
                    oxygen -= 10;
                    food -= 5;

                    int resource_yield = rand() % 101;

                    if (resource_yield < 50) {
                        printf("Found no resources on this planet.\n");
                    } else if (resource_yield < 90) {
                        int num_resources = rand() % 6 + 5;
                        printf("Found %d resources on this planet!\n", num_resources);
                        resources += num_resources;
                    } else {
                        printf("Found a rare artifact on this planet worth 50 resources!\n");
                        resources += 50;
                    }
                } else {
                    printf("Not enough resources to travel to a new planet!\n");
                }

                break;
            case 2:
                if (fuel >= 5 && oxygen >= 5 && food >= 5) {
                    printf("Gathering resources on current planet...\n");

                    delay(2);

                    int resource_yield = rand() % 101;

                    if (resource_yield < 25) {
                        printf("Found no resources on this planet.\n");
                    } else if (resource_yield < 75) {
                        int num_resources = rand() % 4 + 2;
                        printf("Found %d resources on this planet!\n", num_resources);
                        resources += num_resources;
                        oxygen -= 5;
                        food -= 3;
                    } else {
                        printf("Found a rare mineral deposit on this planet worth 10 resources!\n");
                        resources += 10;
                        oxygen -= 5;
                        food -= 3;
                    }
                } else {
                    printf("Not enough resources to gather resources on current planet!\n");
                }

                break;
            case 3:
                printf("\nCurrent spacecraft status:\n");
                printf("Fuel: %d\n", fuel);
                printf("Oxygen: %d\n", oxygen);
                printf("Food: %d\n", food);
                printf("Resources: %d\n", resources);

                break;
            case 4:
                printf("Thanks for playing Procedural Space Adventure!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }

        fuel -= 5;
        oxygen -= 2;
        food -= 1;

        if (fuel <= 0 || oxygen <= 0 || food <= 0) {
            printf("\nYou have run out of resources and perished in space!\n");
            exit(0);
        }
    }

    return 0;
}