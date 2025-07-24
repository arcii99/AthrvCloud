//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int currentX = 0;
    int currentY = 0;
    int fuel = 100;
    int distanceFromEarth = 0;
    int alienCount = 0;
    srand(time(NULL));

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are currently at location (%d,%d) and have %d units of fuel left.\n", currentX, currentY, fuel);

    while(fuel > 0) {
        int distance = rand() % 10;
        int direction = rand() % 4;
        alienCount += rand() % 3;

        if(direction == 0) { //move North
            currentY += distance;
            fuel -= distance;
            printf("You moved %d units to the North.\n", distance);
        }
        else if(direction == 1) { //move East
            currentX += distance;
            fuel -= distance;
            printf("You moved %d units to the East.\n", distance);
        }
        else if(direction == 2) { //move South
            currentY -= distance;
            fuel -= distance;
            printf("You moved %d units to the South.\n", distance);
        }
        else { //move West
            currentX -= distance;
            fuel -= distance;
            printf("You moved %d units to the West.\n", distance);
        }

        if(currentX == 0 && currentY == 0) {
            printf("You have returned to the starting point.\n");
        }

        distanceFromEarth = abs(currentX) + abs(currentY);

        if(distanceFromEarth > 10 && distanceFromEarth <= 20 && alienCount > 5) {
            printf("Warning: You have encountered %d aliens!\n", alienCount);
            printf("You must fight to survive!\n");
            fuel -= 30;
        }
        else if(distanceFromEarth > 20) {
            printf("Warning: You are lost in space and have run out of fuel.\n");
            printf("You are unlikely to survive.\n");
            fuel = 0;
        }

        printf("You are currently at location (%d,%d) and have %d units of fuel left.\n", currentX, currentY, fuel);
    }

    printf("Game Over!\n");

    return 0;
}