//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Struct for the spaceship */
typedef struct spaceship {
    char name[20];
    int fuel;
    int health;
    int shield;
    int laser_power;
} Spaceship;

/* Function prototype for encounter with alien */
void alien_encounter(Spaceship ship);

int main() {
    /* Declare and initialise spaceship */
    Spaceship ship = {"USS Enterprise", 100, 100, 100, 50};
    
    /* Declare variables for game loop */
    int playing = 1;
    int choice;
    
    /* Seed random number generator */
    srand(time(0));
    
    /* Game loop */
    while (playing) {
        /* Display spaceship status */
        printf("%s status:\n", ship.name);
        printf("Fuel: %d\n", ship.fuel);
        printf("Health: %d\n", ship.health);
        printf("Shield: %d\n", ship.shield);
        printf("Laser power: %d\n", ship.laser_power);
        
        /* Display menu */
        printf("Choose an option:\n");
        printf("1. Travel to another planet\n");
        printf("2. Encounter with alien\n");
        printf("3. Refuel spaceship\n");
        printf("4. Repair spaceship\n");
        printf("5. Quit game\n");
        
        /* Read user's choice */
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: /* Travel to another planet */
                /* Decrease fuel randomly */
                int fuel_loss = rand() % 10 + 1;
                ship.fuel -= fuel_loss;
                printf("Travelling to another planet...\n");
                printf("Lost %d fuel.\n", fuel_loss);
                break;
            case 2: /* Encounter with alien */
                printf("Encountering alien...\n");
                alien_encounter(ship);
                break;
            case 3: /* Refuel spaceship */
                printf("Refuelling spaceship...\n");
                ship.fuel = 100;
                printf("Spaceship refuelled.\n");
                break;
            case 4: /* Repair spaceship */
                printf("Repairing spaceship...\n");
                ship.health = 100;
                ship.shield = 100;
                printf("Spaceship repaired.\n");
                break;
            case 5: /* Quit game */
                playing = 0;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}

/* Function definition for encounter with alien */
void alien_encounter(Spaceship ship) {
    /* Calculate alien's health and laser power randomly */
    int alien_health = rand() % 100 + 1;
    int alien_laser_power = rand() % 50 + 1;
    
    /* Display alien's health and laser power */
    printf("Alien's health: %d\n", alien_health);
    printf("Alien's laser power: %d\n", alien_laser_power);
    
    /* Decrease spaceship's health and shield based on alien's laser power */
    int damage = rand() % alien_laser_power + 1;
    ship.health -= damage;
    ship.shield -= damage;
    printf("%s takes %d damage.\n", ship.name, damage);
    
    /* Decrease alien's health based on spaceship's laser power */
    int alien_damage = rand() % ship.laser_power + 1;
    alien_health -= alien_damage;
    printf("Alien takes %d damage.\n", alien_damage);
    
    /* Check if either spaceship or alien has died */
    if (ship.health <= 0) {
        printf("%s has been destroyed.\n", ship.name);
    } else if (alien_health <= 0) {
        printf("Alien has been defeated.\n");
    } else {
        /* Continue encounter if neither has died */
        alien_encounter(ship);
    }
}