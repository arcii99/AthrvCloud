//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Minimum and Maximum distance of planets from the sun in millions of km */
#define MIN_DISTANCE 36
#define MAX_DISTANCE 578

/* Minimum and Maximum sizes of planets in thousands of km */
#define MIN_SIZE 4879
#define MAX_SIZE 142984

/* Number of planets in the solar system */
#define NUM_PLANETS 8

/* Struct to hold information about each planet */
typedef struct Planet {
    char name[20];
    int distance;   // millions of km from the sun
    int size;       // thousands of km in diameter
} Planet;

/* Function to generate a random distance for each planet */
int generateDistance() {
    return (rand() % (MAX_DISTANCE - MIN_DISTANCE + 1)) + MIN_DISTANCE;
}

/* Function to generate a random size for each planet */
int generateSize() {
    return (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;
}

/* Function to initialize the solar system with random distances and sizes */
void initializeSolarSystem(Planet solarSystem[]) {
    strcpy(solarSystem[0].name, "Mercury");
    solarSystem[0].distance = generateDistance();
    solarSystem[0].size = generateSize();

    strcpy(solarSystem[1].name, "Venus");
    solarSystem[1].distance = generateDistance();
    solarSystem[1].size = generateSize();

    strcpy(solarSystem[2].name, "Earth");
    solarSystem[2].distance = generateDistance();
    solarSystem[2].size = generateSize();

    strcpy(solarSystem[3].name, "Mars");
    solarSystem[3].distance = generateDistance();
    solarSystem[3].size = generateSize();

    strcpy(solarSystem[4].name, "Jupiter");
    solarSystem[4].distance = generateDistance();
    solarSystem[4].size = generateSize();

    strcpy(solarSystem[5].name, "Saturn");
    solarSystem[5].distance = generateDistance();
    solarSystem[5].size = generateSize();

    strcpy(solarSystem[6].name, "Uranus");
    solarSystem[6].distance = generateDistance();
    solarSystem[6].size = generateSize();

    strcpy(solarSystem[7].name, "Neptune");
    solarSystem[7].distance = generateDistance();
    solarSystem[7].size = generateSize();
}

/* Function to print information about each planet in the solar system */
void printSolarSystem(Planet solarSystem[]) {
    printf("Name\tDistance from Sun (Million km)\tSize (Thousand km in diameter)\n");

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s\t%d\t\t\t\t%d\n", solarSystem[i].name, solarSystem[i].distance, solarSystem[i].size);
    }
}

int main() {
    srand(time(NULL)); //seed random number generator
    Planet solarSystem[NUM_PLANETS];

    initializeSolarSystem(solarSystem);
    printSolarSystem(solarSystem);

    return 0;
}