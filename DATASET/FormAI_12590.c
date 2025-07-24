//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare function prototypes
void generateRandomSpaceName(char[]);
void generateRandomPlanetName(char[]);
void generateRandomAstronautName(char[]);
void generateRandomAlienName(char[]);
void printIntro();
void embarkOnJourney();
void landOnPlanet(char[]);
void meetAlien(char[]);
void fallInLove(char[]);

int main() {
    srand(time(NULL));  // Set random seed using time
    
    printIntro();  // Print intro
    
    embarkOnJourney();  // Start the adventure
    
    return 0;
}

void generateRandomSpaceName(char spaceName[]) {
    char* spaceNames[] = {"Andromeda", "Orion", "Virgo", "Pegasus", "Canis Major", "Bootes", "Draco", "Hercules", "Cassiopeia"};
    int numNames = 9;  // Number of names in spaceNames array
    int index = rand() % numNames;  // Generate random index
    strcpy(spaceName, spaceNames[index]);  // Copy value of random index to spaceName
}

void generateRandomPlanetName(char planetName[]) {
    char* planetNames[] = {"Astralis", "Elysium", "Galaxia", "Nebula", "Celestia", "Lyra", "Aurora", "Stella", "Nova"};
    int numNames = 9;  // Number of names in planetNames array
    int index = rand() % numNames;  // Generate random index
    strcpy(planetName, planetNames[index]);  // Copy value of random index to planetName
}

void generateRandomAstronautName(char astronautName[]) {
    char* astronautNames[] = {"Neil", "Buzz", "Yuri", "Sally", "Valentina", "Kalpana", "Guion", "Ellison", "Buzz"};
    int numNames = 9;  // Number of names in astronautNames array
    int index = rand() % numNames;  // Generate random index
    strcpy(astronautName, astronautNames[index]);  // Copy value of random index to astronautName
}

void generateRandomAlienName(char alienName[]) {
    char* alienNames[] = {"Xkryl", "Zaxok", "Gurth", "Wryth", "Jorox", "Krilt", "Zorlux", "Xyrtil", "Zolux"};
    int numNames = 9;  // Number of names in alienNames array
    int index = rand() % numNames;  // Generate random index
    strcpy(alienName, alienNames[index]);  // Copy value of random index to alienName
}

void printIntro() {
    char spaceName[20];
    generateRandomSpaceName(spaceName);
    printf("\nThe year is 2069 and humanity has finally discovered a way to travel through space faster than ever before.\n");
    printf("You are part of the crew on the spaceship %s.\n", spaceName);
    printf("Your mission is to explore new planets and make contact with intelligent life forms.\n\n");
}

void embarkOnJourney() {
    char planetName[20];
    generateRandomPlanetName(planetName);
    printf("After months of travelling through space, you and your crew have finally reached a new planet - %s.\n", planetName);
    printf("The ship has landed and you take your first steps on the planet's surface.\n\n");
    landOnPlanet(planetName);
}

void landOnPlanet(char planetName[]) {
    char astronautName[20];
    generateRandomAstronautName(astronautName);
    printf("%s: \"Wow, the atmosphere here is completely different from Earth.\"\n", astronautName);
    printf("You start to explore the planet and soon come across a strange alien creature.\n\n");
    meetAlien(planetName);
}

void meetAlien(char planetName[]) {
    char alienName[20];
    generateRandomAlienName(alienName);
    printf("Alien: \"Greetings, humans. I am %s, leader of the %s beings.\"\n", alienName, planetName);
    printf("You and the alien exchange information about each other's cultures and beliefs.\n");
    printf("As time goes on, you find yourself growing closer to the alien and soon realize that you have fallen in love.\n\n");
    fallInLove(alienName);
}

void fallInLove(char alienName[]) {
    char astronautName[20];
    generateRandomAstronautName(astronautName);
    printf("%s: \"I never thought I would find love on an alien planet.\"\n", astronautName);
    printf("You and %s spend the rest of your time on the planet together, exploring and learning more about each other's worlds.\n", alienName);
    printf("Eventually, the time comes for you to return home, but you know that you will always have a special place in your heart for the %s beings and the love you found there.\n", alienName);
}