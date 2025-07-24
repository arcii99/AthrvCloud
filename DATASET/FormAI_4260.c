//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a random integer between two values
int getRandom(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main() {
    // Initialize variables
    int fuel = 1000;
    int shields = 100;
    int damage = 0;
    int distance = 0;
    int alienHealth = 100;
    
    srand(time(0)); // Seed random number generator
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a starship traveling through unknown territory.\n");
    printf("Your goal is to explore as much of the galaxy as possible without running out of fuel or losing your ship.\n\n");
    
    // Main game loop
    while (fuel > 0 && shields > 0) {
        // Display current stats
        printf("Fuel: %d\n", fuel);
        printf("Shields: %d\n", shields);
        printf("Damage: %d\n", damage);
        printf("Distance traveled: %d\n\n", distance);
        
        // Generate a random encounter
        int encounter = getRandom(1, 10);
        if (encounter <= 5) {
            // Player encounters a planet
            int planetFuel = getRandom(100, 500);
            printf("You have encountered a planet!\n");
            printf("You refuel your spaceship with %d units of fuel.\n\n", planetFuel);
            fuel += planetFuel;
        } else if (encounter <= 8) {
            // Player encounters an asteroid field
            int asteroidDamage = getRandom(50, 100);
            printf("You have encountered an asteroid field!\n");
            printf("Your spaceship takes %d points of damage.\n\n", asteroidDamage);
            damage += asteroidDamage;
        } else {
            // Player encounters an alien ship
            int alienDamage = getRandom(25, 50);
            printf("You have encountered an alien ship!\n");
            printf("You engage in battle with the alien.\n");
            
            // Battle loop
            while (alienHealth > 0 && shields > 0) {
                // Player attacks alien ship
                int playerAttack = getRandom(25, 50);
                printf("You attack the alien ship for %d points of damage.\n", playerAttack);
                alienHealth -= playerAttack;
                
                // Alien ship attacks player
                int alienAttack = getRandom(25, 50);
                printf("The alien ship attacks you for %d points of damage.\n\n", alienAttack);
                shields -= alienAttack;
            }
            
            if (alienHealth <= 0) {
                // Player wins battle
                int alienFuel = getRandom(100, 200);
                printf("You have defeated the alien ship!\n");
                printf("You salvage %d units of fuel from the alien ship.\n\n", alienFuel);
                fuel += alienFuel;
            } else {
                // Player loses battle
                printf("Your spaceship has been destroyed by the alien ship.\n");
                printf("Game over!\n\n");
                
                return 0;
            }
        }
        
        // Update distance traveled
        int travelDistance = getRandom(50, 100);
        distance += travelDistance;
        printf("You have traveled %d light years.\n\n", travelDistance);
        
        // Consume fuel
        int fuelConsumed = getRandom(50, 100);
        fuel -= fuelConsumed;
        
        // Repair damage
        int repair = getRandom(25, 50);
        damage -= repair;
        if (damage < 0) {
            damage = 0;
        }
        
        // Recharge shields
        int shieldRecharge = getRandom(25, 50);
        shields += shieldRecharge;
        if (shields > 100) {
            shields = 100;
        }
    }
    
    // Player has run out of fuel or lost their ship
    if (fuel <= 0) {
        printf("You have run out of fuel and are stranded in space.\n");
    } else {
        printf("Your spaceship has been destroyed.\n");
    }
    
    // Display final stats
    printf("Final stats:\n");
    printf("Distance traveled: %d\n", distance);
    printf("Total fuel remaining: %d\n", fuel);
    printf("Damage sustained: %d\n", damage);
    printf("Shields remaining: %d\n\n", shields);
    
    return 0;
}