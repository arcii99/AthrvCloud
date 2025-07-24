//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void explorePlanet(int planetNum, int fuel);

int main() {
    int fuel = 100;
    printf("Welcome to the Procedural Space Adventure!\n\n");
    srand(time(NULL));
    int randomPlanet = rand() % 10 + 1;
    explorePlanet(randomPlanet, fuel);
    return 0;   
}

void explorePlanet(int planetNum, int fuel) {
    printf("You are now on planet %d\n", planetNum);
    printf("You have %d fuel remaining\n", fuel);
    if (fuel <= 0) {
        printf("You are out of fuel! Game over.\n");
        return;
    }
    printf("Do you want to explore this planet? (y/n) ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("Exploring planet %d...\n", planetNum);
        int foundFuel = rand() % 10 + 1;
        int foundAliens = rand() % 2;
        if (foundAliens) {
            printf("Uh oh, you encountered hostile aliens on this planet!\n");
            printf("You must flee to a different planet.\n");
            int newPlanet = rand() % 10 + 1;
            explorePlanet(newPlanet, fuel - 20);
        } else {
            printf("You found %d fuel on this planet!\n", foundFuel);
            fuel += foundFuel;
            printf("You now have %d fuel.\n", fuel);
            printf("Do you want to explore another planet? (y/n) ");
            scanf(" %c", &choice);
            if (choice == 'y') {
                int newPlanet = rand() % 10 + 1;
                explorePlanet(newPlanet, fuel - 10);
            }
        }
    } else {
        printf("Leaving planet %d...\n", planetNum);
    }
}