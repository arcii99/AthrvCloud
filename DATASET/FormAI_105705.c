//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void clearScreen();
void displayIntro();
void generatePlanets(char *planetNames[], int numPlanets);
int launchGame(int numPlanets, char *planetNames[]);
void planetMenu(char *planetName);
void explorePlanet(char *planetName);
void minePlanet(char *planetName);

int main() {
    // Seed random number generator for use later
    srand(time(NULL)); 

    char *planetNames[] = {
        "Arcturus",
        "Betelgeuse",
        "Ceti Alpha V",
        "Dagobah",
        "Ego",
        "Fhloston",
        "Gotham",
        "Hoth",
        "Icarus",
        "Jupiter",
        "Krypton",
        "Luna",
        "Mars",
        "Neptune",
        "Orion",
        "Pandora",
        "Quasar",
        "Rigel",
        "Serenity",
        "Tatooine",
        "Uranus",
        "Vulcan",
        "Wadiya",
        "Xandar",
        "Yavin IV",
        "Zephyr"
    };
    int numPlanets = sizeof(planetNames) / sizeof(char *);

    clearScreen();
    displayIntro();

    int playAgain = 1;
    while (playAgain) {
        generatePlanets(planetNames, numPlanets);
        int choice = launchGame(numPlanets, planetNames);

        if (choice == 1) {
            playAgain = 1;
            clearScreen();
        } else {
            playAgain = 0;
            printf("\nThank you for playing!\n");
        }
    }
    return 0;
}

// Function to clear the screen and reset the cursor position
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// Function to display the game intro
void displayIntro() {
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("Space adventure is the ultimate adventure game where you travel across the galaxy\n");
    printf("to explore strange new worlds, to seek out new life and new civilizations,\n");
    printf("to boldly go where no one has gone before. Good luck and have fun!\n\n");
    printf("Press enter to begin.\n");
    getchar();
    clearScreen();
}

// Function to randomly shuffle the array of planet names
void generatePlanets(char *planetNames[], int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        int randomIndex = rand() % numPlanets;
        char *temp = planetNames[i];
        planetNames[i] = planetNames[randomIndex];
        planetNames[randomIndex] = temp;
    }
}

// Function to launch the game and select a planet to visit
int launchGame(int numPlanets, char *planetNames[]) {
    printf("Here are the planets available to visit:\n\n");
    for (int i = 0; i < numPlanets; i++) {
        printf("%d. %s\n", i+1, planetNames[i]);
    }
    printf("%d. Exit game\n", numPlanets+1);

    int choice = 0;
    int maxChoice = numPlanets + 1;
    while (choice < 1 || choice > maxChoice) {
        printf("\nEnter the number of the planet you would like to visit (1-%d): ", maxChoice);
        scanf("%d", &choice);
        if (choice < 1 || choice > maxChoice) {
            printf("Invalid choice.\n");
        }
    }

    if (choice == maxChoice) {
        return 2;
    } else {
        clearScreen();
        planetMenu(planetNames[choice-1]);
        return 1;
    }
}

// Function to display the planet menu
void planetMenu(char *planetName) {
    printf("Welcome to %s!\n", planetName);
    printf("What would you like to do?\n");
    printf("1. Explore the planet\n");
    printf("2. Mine resources\n");
    printf("3. Return to planet selection\n");

    int choice = 0;
    while (choice < 1 || choice > 3) {
        printf("\nEnter the number of your choice (1-3): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Invalid choice.\n");
        }
    }

    switch(choice) {
        case 1:
            explorePlanet(planetName);
            break;
        case 2:
            minePlanet(planetName);
            break;
        case 3:
            clearScreen();
            break;
    }
}

// Function to explore the planet
void explorePlanet(char *planetName) {
    printf("You explore %s and discover many strange and wonderful things.\n", planetName);
    printf("Unfortunately, you got lost and couldn't find your way back to your ship.\n");
    printf("You died. Game over. Try again?\n");

    printf("\nPress enter to continue.\n");
    getchar();
}

// Function to mine the planet for resources
void minePlanet(char *planetName) {
    printf("You mine %s for resources and find an abundance of valuable materials.\n", planetName);
    printf("You get rich and retire to a life of luxury. Congratulations, you win!\n");

    printf("\nPress enter to continue.\n");
    getchar();
}