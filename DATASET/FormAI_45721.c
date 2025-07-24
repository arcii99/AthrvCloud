//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RESOURCES 10
#define MAX_PLANETS 5
#define MAX_SHIP_CAPACITY 5

typedef struct {
    char name[20];
    int resources[MAX_RESOURCES];
} Planet;

typedef struct {
    int current_planet;
    int resources[MAX_RESOURCES];
} Ship;

void print_planet_info(Planet planets[], int current_planet) {
    printf("You are currently on planet %s.\n", planets[current_planet].name);
    printf("Resources available:\n");
    for (int i=0; i<MAX_RESOURCES; i++) {
        printf("%d units of %c\n", planets[current_planet].resources[i], 65+i);
    }
}

void print_ship_info(Ship ship) {
    printf("Your ship currently contains:\n");
    for (int i=0; i<MAX_RESOURCES; i++) {
        printf("%d units of %c\n", ship.resources[i], 65+i);
    }
}

int main() {
    srand(time(NULL)); // initialize random seed
    
    Planet planets[MAX_PLANETS];
    strcpy(planets[0].name, "Alderaan");
    planets[0].resources[0] = 50;
    planets[0].resources[1] = 0;
    planets[0].resources[2] = 0;
    
    strcpy(planets[1].name, "Tatooine");
    planets[1].resources[0] = 10;
    planets[1].resources[1] = 20;
    planets[1].resources[2] = 30;
    
    strcpy(planets[2].name, "Naboo");
    planets[2].resources[0] = 0;
    planets[2].resources[1] = 40;
    planets[2].resources[2] = 10;
    
    strcpy(planets[3].name, "Coruscant");
    planets[3].resources[0] = 5;
    planets[3].resources[1] = 5;
    planets[3].resources[2] = 5;
    
    strcpy(planets[4].name, "Yavin IV");
    planets[4].resources[0] = 0;
    planets[4].resources[1] = 0;
    planets[4].resources[2] = 50;
    
    Ship ship;
    ship.current_planet = 0; // start on Alderaan
    for (int i=0; i<MAX_RESOURCES; i++) {
        ship.resources[i] = 0; // initialize resources to 0
    }
    
    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Print planet information\n");
        printf("2. Print ship information\n");
        printf("3. Travel to a new planet\n");
        printf("4. Gather resources on current planet\n");
        printf("5. Sell resources on current planet\n");
        printf("6. Quit game\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                print_planet_info(planets, ship.current_planet);
                break;
            case 2:
                print_ship_info(ship);
                break;
            case 3:
                printf("Which planet would you like to travel to?\n");
                for (int i=0; i<MAX_PLANETS; i++) {
                    if (i != ship.current_planet) {
                        printf("%d. %s\n", i+1, planets[i].name);
                    }
                }
                int planet_choice;
                scanf("%d", &planet_choice);
                if (planet_choice < 1 || planet_choice > MAX_PLANETS || planet_choice == ship.current_planet+1) {
                    printf("Invalid choice. Please choose a valid planet number.\n");
                } else {
                    printf("Traveling to %s...\n", planets[planet_choice-1].name);
                    ship.current_planet = planet_choice-1;
                    printf("You have arrived on %s.\n", planets[ship.current_planet].name);
                }
                break;
            case 4:
                printf("Gathering resources on %s...\n", planets[ship.current_planet].name);
                for (int i=0; i<MAX_RESOURCES; i++) {
                    int amount = rand() % (planets[ship.current_planet].resources[i]+1);
                    ship.resources[i] += amount;
                    planets[ship.current_planet].resources[i] -= amount;
                }
                printf("Resources gathered.\n");
                break;
            case 5:
                printf("Selling resources on %s...\n", planets[ship.current_planet].name);
                int total_money = 0;
                for (int i=0; i<MAX_RESOURCES; i++) {
                    total_money += ship.resources[i]*(i+1); // value each resource at its index+1
                    ship.resources[i] = 0; // sell all resources on the ship
                }
                printf("You earned %d credits.\n", total_money);
                break;
            case 6:
                printf("Quitting game...\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid number.\n");
                break;
        }
        printf("\n");
    } while (choice != 6);
    
    return 0;
}