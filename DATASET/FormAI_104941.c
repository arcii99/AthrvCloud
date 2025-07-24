//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global constants
#define SPACE_SIZE 100
#define MAX_ENEMIES 5

// Aliens struct declaration
typedef struct {
    int x;
    int y;
    int health;
    int damage;
} Alien;

// Function declarations
void initializeSpace(char space[], int size);
void updateSpace(char space[], int size, int playerX, int enemiesX[]);
void printSpace(char space[], int size);
bool isGameover(int enemiesX[], int playerX, int size, Alien aliens[]);
void initializeAliens(Alien aliens[]);
void updateAliens(int enemiesX[], int size, Alien aliens[]);
void printAliens(Alien aliens[]);

int main() {
    // Set random seed
    srand(time(NULL));

    // Variable declarations
    char space[SPACE_SIZE];
    int playerX = SPACE_SIZE/2;
    int enemiesX[MAX_ENEMIES];
    Alien aliens[MAX_ENEMIES];

    // Initialize space and aliens
    initializeSpace(space, SPACE_SIZE);
    initializeAliens(aliens);

    // Populate enemies positions randomly
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemiesX[i] = rand() % SPACE_SIZE;
    }

    // Game loop
    while (!isGameover(enemiesX, playerX, SPACE_SIZE, aliens)) {
        // Clear console
        system("clear");

        // Update and print space
        updateSpace(space, SPACE_SIZE, playerX, enemiesX);
        printSpace(space, SPACE_SIZE);

        // Update and print aliens
        updateAliens(enemiesX, SPACE_SIZE, aliens);
        printAliens(aliens);

        // Ask for player input and move player
        printf("\nMove left or right: ");
        char input;
        scanf("%c", &input);
        if (input == 'a') {
            playerX--;
        } else if (input == 'd') {
            playerX++;
        }
    }

    // Game over message
    printf("\nGame over!\n");

    // Wait and exit
    getchar();
    return 0;
}

// Initializes space with empty spaces
void initializeSpace(char space[], int size) {
    for (int i = 0; i < size; i++) {
        space[i] = ' ';
    }
    space[size-1] = '\0';
}

// Updates space with player and enemies positions
void updateSpace(char space[], int size, int playerX, int enemiesX[]) {
    // Add player
    space[playerX] = 'P';

    // Add enemies
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemiesX[i] >= 0 && enemiesX[i] < size) {
            space[enemiesX[i]] = 'E';
        }
    }
}

// Prints space
void printSpace(char space[], int size) {
    printf("%s\n", space);
}

// Checks if game is over
bool isGameover(int enemiesX[], int playerX, int size, Alien aliens[]) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemiesX[i] < 0 || enemiesX[i] >= size) {
            continue;
        }
        // Check if player hits an enemy
        if (playerX == enemiesX[i]) {
            // Update alien health
            aliens[i].health--;
            if (aliens[i].health <= 0) {
                enemiesX[i] = -1;
            }
            return false;
        }
        // Check if enemy hits the player
        if (enemiesX[i] == playerX) {
            return true;
        }
    }
    return false;
}

// Initializes aliens with random health and damage
void initializeAliens(Alien aliens[]) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        aliens[i].x = 0;
        aliens[i].y = 0;
        aliens[i].health = rand() % 5 + 1;
        aliens[i].damage = rand() % 3 + 1;
    }
}

// Updates aliens positions randomly
void updateAliens(int enemiesX[], int size, Alien aliens[]) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        // Skip alien if dead
        if (enemiesX[i] < 0 || enemiesX[i] >= size) {
            continue;
        }

        // Move alien randomly
        int direction = rand() % 3 - 1;
        enemiesX[i] += direction;

        // Check for collision with other enemy or player
        for (int j = 0; j < MAX_ENEMIES; j++) {
            if (i != j && enemiesX[i] == enemiesX[j]) {
                enemiesX[i] -= direction;
                break;
            }
        }

        // Check for collision with player
        if (enemiesX[i] == 0) {
            printf("\nAlien hit! Damage: %d\n", aliens[i].damage);
        }
    }
}

// Prints aliens health and damage
void printAliens(Alien aliens[]) {
    printf("\n");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (aliens[i].health > 0) {
            printf("Alien %d - Health: %d, Damage: %d\n", i+1, aliens[i].health, aliens[i].damage);
        }
    }
}