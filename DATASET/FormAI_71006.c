//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePlanets() {
    // Generate random number of planets
    int numPlanets = rand() % 10 + 1;
    printf("Number of planets in the system: %d\n", numPlanets);
    
    // Generate each planet
    for(int i=1; i<=numPlanets; i++) {
        printf("\n-------\n");
        printf("Planet %d:\n", i);
        
        // Generate random properties for the planet
        int size = rand() % 3;
        switch(size) {
            case 0:
                printf("Size: small\n");
                break;
            case 1:
                printf("Size: medium\n");
                break;
            case 2:
                printf("Size: large\n");
                break;
        }
        
        int environment = rand() % 3;
        switch(environment) {
            case 0:
                printf("Environment: rocky\n");
                break;
            case 1:
                printf("Environment: gaseous\n");
                break;
            case 2:
                printf("Environment: aquatic\n");
                break;
        }
        
        int habitable = rand() % 2;
        if(habitable == 0) {
            printf("Habitable: no\n");
        } else {
            printf("Habitable: yes\n");
        }
    }
}

void startGame() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Generating random solar system...\n");
    
    // Seed random number generator with current time
    srand(time(NULL));
    
    // Generate random properties for the solar system
    int age = rand() % 10 + 1;
    int size = rand() % 3;
    char* type;
    switch(size) {
        case 0:
            type = "small";
            break;
        case 1:
            type = "medium";
            break;
        case 2:
            type = "large";
            break;
    }
    
    // Display solar system properties
    printf("Age: %d billion years\n", age);
    printf("Size: %s\n", type);
    
    // Generate planets in the solar system
    generatePlanets();
    
    printf("\nThanks for playing Procedural Space Adventure!\n");
}

int main() {
    startGame();
    return 0;
}