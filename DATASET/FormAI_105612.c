//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for holding spaceship data
typedef struct {
    int speed;
    int fuel;
    int shield;
} Spaceship;

// Function to initialize spaceship data
void init_spaceship(Spaceship *ship) {
    ship->speed = 0;
    ship->fuel = 100;
    ship->shield = 100;
}

// Function to activate spaceship engines
void activate_engines(Spaceship *ship) {
    printf("Engines activated.\n");
    ship->speed = 10;
    ship->fuel -= 10;
}

// Function to activate spaceship shields
void activate_shields(Spaceship *ship) {
    printf("Shields activated.\n");
    ship->shield = 100;
    ship->fuel -= 5;
}

// Function to simulate an asteroid hit
void asteroid_hit(Spaceship *ship) {
    printf("Asteroid hit detected.\n");
    ship->shield -= 30;
    if (ship->shield < 0) {
        ship->shield = 0;
    }
}

int main() {
    Spaceship ship;
    init_spaceship(&ship);
    srand(time(NULL));
    int asteroid_count = 0;
    
    // Main game loop
    while (ship.fuel > 0 && ship.shield > 0) {
        // Generate random events
        int event = rand() % 3;
        if (event == 0) {
            activate_engines(&ship);
        } else if (event == 1) {
            activate_shields(&ship);
        } else {
            asteroid_hit(&ship);
            asteroid_count++;
        }
        
        // Print spaceship data
        printf("Speed: %d\n", ship.speed);
        printf("Fuel: %d\n", ship.fuel);
        printf("Shield: %d\n", ship.shield);
        printf("Asteroid count: %d\n", asteroid_count);
    }
    
    // End of game
    if (ship.fuel <= 0) {
        printf("Out of fuel. Game over.\n");
    } else {
        printf("Shield depleted. Game over.\n");
    }
    
    return 0;
}