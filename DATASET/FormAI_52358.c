//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>

/* Constants */
#define SHIELD_MAX 100
#define FUEL_MAX 1000
#define ENEMY_NUM 5

/* Structures */
struct Ship {
    int shield;
    int fuel;
};

struct Planet {
    char name[20];
    int distance;
};

struct Enemy {
    char name[20];
    int weapon_power;
    int shield_power;
};

/* Function Prototypes */
void travel(struct Ship *ship, struct Planet planet);
void battle(struct Ship *ship, struct Enemy enemy);
void refuel(struct Ship *ship);
void repair(struct Ship *ship);

/* Main Function */
int main()
{
    printf("Welcome to the Procedural Space Adventure!\n");

    struct Ship player_ship;
    player_ship.shield = SHIELD_MAX;
    player_ship.fuel = FUEL_MAX;

    struct Planet planets[3];
    strcpy(planets[0].name, "Alderaan");
    planets[0].distance = 50;

    strcpy(planets[1].name, "Tatooine");
    planets[1].distance = 75;

    strcpy(planets[2].name, "Hoth");
    planets[2].distance = 100;

    struct Enemy enemies[ENEMY_NUM];
    strcpy(enemies[0].name, "Darth Vader");
    enemies[0].weapon_power = 90;
    enemies[0].shield_power = 80;

    strcpy(enemies[1].name, "Boba Fett");
    enemies[1].weapon_power = 80;
    enemies[1].shield_power = 70;

    strcpy(enemies[2].name, "Stormtrooper");
    enemies[2].weapon_power = 50;
    enemies[2].shield_power = 40;

    strcpy(enemies[3].name, "Emperor Palpatine");
    enemies[3].weapon_power = 100;
    enemies[3].shield_power = 90;

    strcpy(enemies[4].name, "Jabba the Hutt");
    enemies[4].weapon_power = 60;
    enemies[4].shield_power = 50;

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Travel to a planet\n");
        printf("2. Battle an enemy\n");
        printf("3. Refuel\n");
        printf("4. Repair shield\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nWhich planet would you like to travel to?\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s (Distance: %d)\n", i+1, planets[i].name, planets[i].distance);
                }
                int planet_choice;
                scanf("%d", &planet_choice);
                travel(&player_ship, planets[planet_choice-1]);
                break;
            case 2:
                printf("\nWhich enemy would you like to battle?\n");
                for (int i = 0; i < ENEMY_NUM; i++) {
                    printf("%d. %s (Weapon Power: %d, Shield Power: %d)\n", i+1, enemies[i].name, enemies[i].weapon_power, enemies[i].shield_power);
                }
                int enemy_choice;
                scanf("%d", &enemy_choice);
                battle(&player_ship, enemies[enemy_choice-1]);
                break;
            case 3:
                refuel(&player_ship);
                break;
            case 4:
                repair(&player_ship);
                break;
            case 5:
                printf("\nThank you for playing the Procedural Space Adventure!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

/* Function Definitions */

void travel(struct Ship *ship, struct Planet planet)
{
    int fuel_cost = planet.distance / 10;
    if (ship->fuel >= fuel_cost) {
        ship->fuel -= fuel_cost;
        printf("\nYou have successfully traveled to %s. Fuel remaining: %d\n", planet.name, ship->fuel);
    } else {
        printf("\nNot enough fuel to travel. Please refuel.\n");
    }
}

void battle(struct Ship *ship, struct Enemy enemy)
{
    int player_attack = rand() % 50 + 50;
    int enemy_attack = rand() % enemy.weapon_power + 50;
    printf("\nYour attack power: %d\n", player_attack);
    printf("%s's attack power: %d\n", enemy.name, enemy_attack);

    if (player_attack > enemy.shield_power) {
        printf("You have defeated %s!\n", enemy.name);
    } else {
        printf("Oh no! %s has defeated you!\n", enemy.name);
        ship->shield -= enemy_attack;
    }
}

void refuel(struct Ship *ship)
{
    int fuel_needed = FUEL_MAX - ship->fuel;
    int cost = fuel_needed * 2;
    if (cost <= 100) {
        if (cost > 0) {
            ship->fuel += fuel_needed;
            printf("\nRefueled. Fuel remaining: %d\n", ship->fuel);
        } else {
            printf("\nFuel tank is already full.\n");
        }
    } else {
        printf("\nCannot afford to refuel.\n");
    }
}

void repair(struct Ship *ship)
{
    int repair_needed = SHIELD_MAX - ship->shield;
    int cost = repair_needed * 3;
    if (cost <= 100) {
        if (cost > 0) {
            ship->shield += repair_needed;
            printf("\nRepaired. Shield remaining: %d\n", ship->shield);
        } else {
            printf("\nShield is already at full strength.\n");
        }
    } else {
        printf("\nCannot afford to repair shield.\n");
    }
}