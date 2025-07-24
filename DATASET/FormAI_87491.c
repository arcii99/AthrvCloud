//FormAI DATASET v1.0 Category: Robot movement control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define NUM_ROBOTS 2

// Declare struct for robots
typedef struct {
    int x;
    int y;
} Robot;

// Declare functions
void createMap(char arr[][MAP_SIZE]);
void printMap(char arr[][MAP_SIZE], Robot *robots);
void moveRobots(char arr[][MAP_SIZE], Robot *robots);
void attack(Robot *attacker, Robot *victim);

// Main function
int main(void) {

    // Seed random number generator
    srand(time(NULL));

    // Declare and initialize map array
    char map[MAP_SIZE][MAP_SIZE];
    createMap(map);

    // Declare and initialize robots
    Robot robots[NUM_ROBOTS] = {
        {rand() % MAP_SIZE, rand() % MAP_SIZE},
        {rand() % MAP_SIZE, rand() % MAP_SIZE}
    };

    // Game loop
    int round = 1;
    while (1) {

        // Print map and robots
        printf("Round %d:\n", round++);
        printMap(map, robots);

        // Move robots
        moveRobots(map, robots);

        // Check for robot collisions
        for (int i = 0; i < NUM_ROBOTS; ++i) {
            for (int j = i + 1; j < NUM_ROBOTS; ++j) {
                if (robots[i].x == robots[j].x && robots[i].y == robots[j].y) {
                    attack(&robots[i], &robots[j]);
                }
            }
        }
    }

    return 0;
}

// Function to create initial map
void createMap(char arr[][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            arr[i][j] = '.';
        }
    }
}

// Function to print map and robots
void printMap(char arr[][MAP_SIZE], Robot *robots) {
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            // Print robot if it is present
            int robot_here = 0;
            for (int k = 0; k < NUM_ROBOTS; ++k) {
                if (robots[k].x == i && robots[k].y == j) {
                    printf("%c ", k + 'A');
                    robot_here = 1;
                    break;
                }
            }
            if (!robot_here) {
                printf("%c ", arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move robots
void moveRobots(char arr[][MAP_SIZE], Robot *robots) {
    for (int i = 0; i < NUM_ROBOTS; ++i) {
        // Get random direction to move
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                if (robots[i].x > 0) {
                    robots[i].x--;
                }
                break;
            case 1:
                if (robots[i].x < MAP_SIZE - 1) {
                    robots[i].x++;
                }
                break;
            case 2:
                if (robots[i].y > 0) {
                    robots[i].y--;
                }
                break;
            case 3:
                if (robots[i].y < MAP_SIZE - 1) {
                    robots[i].y++;
                }
                break;
        }
    }
}

// Function to simulate robot attack
void attack(Robot *attacker, Robot *victim) {
    int damage = rand() % 5 + 1;
    printf("Robot %c attacked robot %c and dealt %d damage!\n", 
        attacker - victim > 0 ? 'B' : 'A',
        attacker - victim > 0 ? 'A' : 'B',
        damage
    );
    victim->x = rand() % MAP_SIZE;
    victim->y = rand() % MAP_SIZE;
}