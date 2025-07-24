//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_HEALTH 100

struct spaceship {
    int health;
    int power;
    int fuel;
    int location;
};

struct enemy {
    int health;
    int power;
    int location;
};

int generate_random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

void print_ship_status(struct spaceship player) {
    printf("------ Spaceship Status ------\n");
    printf("Health: %d\n", player.health);
    printf("Power: %d\n", player.power);
    printf("Fuel: %d\n", player.fuel);
    printf("Location: %d\n", player.location);
    printf("------------------------------\n");
}

int main() {
    struct spaceship player = {MAX_HEALTH, 50, 100, 0};
    struct enemy enemy[MAX_ENEMIES];
    int i, choice;

    printf("Welcome to the Procedural Space Adventure!\n");

    for (i = 0; i < MAX_ENEMIES; i++) {
        enemy[i].health = generate_random_number(50, 100);
        enemy[i].power = generate_random_number(10, 20);
        enemy[i].location = generate_random_number(1, 100);
    }

    while (player.health > 0 && player.fuel > 0) {
        printf("------------------------------\n");
        printf("You are currently at location %d.\n", player.location);
        printf("What would you like to do?\n");
        printf("1. Travel to a new location\n");
        printf("2. Refuel the ship\n");
        printf("3. Attack an enemy\n");
        printf("4. Quit the game\n");
        printf("------------------------------\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (player.fuel > 0) {
                    player.fuel -= 10;
                    player.location = generate_random_number(1, 100);
                    printf("You have traveled to location %d.\n", player.location);
                    for (i = 0; i < MAX_ENEMIES; i++) {
                        if (enemy[i].location == player.location) {
                            printf("You have encountered an enemy!\n");
                            printf("Enemy health: %d\n", enemy[i].health);
                            printf("Enemy power: %d\n", enemy[i].power);
                        }
                    }
                } else {
                    printf("You do not have enough fuel to travel.\n");
                }
                break;
            case 2:
                player.fuel = 100;
                printf("You have refueled the ship.\n");
                break;
            case 3:
                for (i = 0; i < MAX_ENEMIES; i++) {
                    if (enemy[i].location == player.location) {
                        printf("You have attacked the enemy!\n");
                        enemy[i].health -= player.power;
                        if (enemy[i].health <= 0) {
                            printf("You have defeated the enemy!\n");
                            player.health += 10;
                            enemy[i].location = generate_random_number(1, 100);
                            printf("The enemy has relocated to location %d.\n", enemy[i].location);
                        } else {
                            printf("Enemy health: %d\n", enemy[i].health);
                            printf("Enemy power: %d\n", enemy[i].power);
                            player.health -= enemy[i].power;
                            printf("Your health: %d\n", player.health);
                            if (player.health <= 0) {
                                printf("You have been defeated by the enemy.\n");
                                exit(0);
                            }
                        }
                    }
                }
                break;
            case 4:
                printf("Quitting the game.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }

        if (player.health > MAX_HEALTH) {
            player.health = MAX_HEALTH;
        }

        print_ship_status(player);
    }

    if (player.health <= 0) {
        printf("You have run out of health and died.\n");
    } else if (player.fuel <= 0) {
        printf("You have run out of fuel and are stranded in space.\n");
    }

    return 0;
}