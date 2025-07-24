//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  
    
    int dayOfYear = rand() % 366;

    char* season;
    if (dayOfYear >= 80 && dayOfYear < 172) {
        season = "Spring";
    } else if (dayOfYear >= 172 && dayOfYear < 264) {
        season = "Summer";
    } else if (dayOfYear >= 264 && dayOfYear < 355) {
        season = "Autumn";
    } else {
        season = "Winter";
    }

    double temperature = (rand() % 60) - 20;
    
    int hasSpaceShip = rand() % 2;
    int hasLaserGun = rand() % 2;
    int hasReinforcements = rand() % 2;
    
    int alienProbabilityPercent = (int)((20 + (abs(temperature) * 1.3)) / ((hasSpaceShip + 1) * (hasLaserGun + 1) * (hasReinforcements + 1)));
    
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    printf("It is currently %s and the temperature is %.2f degrees Celsius.\n", season, temperature);
    printf("You%s have a spaceship.\n", hasSpaceShip ? "" : " don't");
    printf("You%s have a laser gun.\n", hasLaserGun ? "" : " don't");
    printf("You%s have reinforcements.\n", hasReinforcements ? "" : " don't");
    printf("There is a %d%% chance of an alien invasion!\n", alienProbabilityPercent);
    
    return 0;
}