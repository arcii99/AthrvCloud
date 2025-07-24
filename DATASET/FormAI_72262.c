//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_MOVES 15

// Function that generates random coordinates for the target destination
void generateDestinationCoordinates(int* targetX, int* targetY) {
    *targetX = rand() % MAP_SIZE;
    *targetY = rand() % MAP_SIZE;
}

// Function that calculates the distance between the current position and the destination
float calculateDistance(int currentX, int currentY, int targetX, int targetY) {
    int deltaX = targetX - currentX;
    int deltaY = targetY - currentY;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

// Function that prints the map with the current position and destination marked
void printMap(int currentX, int currentY, int targetX, int targetY) {
    printf("+");
    for (int i = 0; i < MAP_SIZE; i++) {
        printf("-");
    }
    printf("+\n");

    for (int j = 0; j < MAP_SIZE; j++) {
        printf("|");
        for (int i = 0; i < MAP_SIZE; i++) {
            if (i == currentX && j == currentY) {
                printf("C");
            } else if (i == targetX && j == targetY) {
                printf("T");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    printf("+");
    for (int i = 0; i < MAP_SIZE; i++) {
        printf("-");
    }
    printf("+\n");
}

int main()
{
    int currentX = 0;
    int currentY = 0;
    int targetX, targetY;
    float distance;

    srand(time(NULL)); // Seed the random number generator

    generateDestinationCoordinates(&targetX, &targetY);

    printf("Welcome to Retro GPS Navigation Simulation!\n");
    printf("Your objective is to reach the target destination marked as T on the map.\n");
    printf("You can move up, down, left and right using the arrow keys on your keyboard.\n");
    printf("You have %d moves to reach the destination. Good luck!\n", MAX_MOVES);

    printMap(currentX, currentY, targetX, targetY);

    for (int i = 1; i <= MAX_MOVES; i++)
    {
        char move;

        printf("Move %d: ", i);
        scanf(" %c", &move);

        switch (move)
        {
            case 'w':
                currentY--;
                break;
            case 's':
                currentY++;
                break;
            case 'a':
                currentX--;
                break;
            case 'd':
                currentX++;
                break;
            default:
                printf("Invalid move. Try again.\n");
                i--; // Do not count this move
                continue;
        }

        distance = calculateDistance(currentX, currentY, targetX, targetY);

        if (currentX < 0 || currentY < 0 ||
            currentX >= MAP_SIZE || currentY >= MAP_SIZE)
        {
            printf("Out of bounds. Game over.\n");
            break;
        }
        else if (distance == 0)
        {
            printf("Congratulations! You have reached the destination in %d moves.\n", i);
            break;
        }
        else
        {
            printf("Distance to destination: %.2f\n", distance);
        }

        printMap(currentX, currentY, targetX, targetY);
    }

    printf("Game over. Press any key to exit.\n");
    getchar(); // Wait for user input before exiting
    return 0;
}