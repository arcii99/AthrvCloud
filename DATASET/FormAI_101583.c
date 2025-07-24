//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int health = 100;
int ammo = 50;
int enemyHealth = 50;
int enemyDamage = 10;

void printStats() {
    printf("Health: %d\n", health);
    printf("Ammo: %d\n", ammo);
}

int main() {
    char input[20];
    printf("*** Welcome to the Futuristic Adventure Game! ***\n");
    printf("You find yourself in a desolate, futuristic city. The buildings tower above you, but everything is quiet...\n");
    printf("What do you do?\n");
    printf("> ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = 0;
    while (strcmp(input, "quit") != 0) {
        if (strcmp(input, "look") == 0) {
            printf("You look around, but everything appears to be abandoned.\n");
        }
        else if (strcmp(input, "search") == 0) {
            printf("You search the area and find an ammo box.\n");
            ammo += 10;
        }
        else if (strcmp(input, "shoot") == 0) {
            if (ammo > 0) {
                enemyHealth -= enemyDamage;
                printf("You shoot the enemy, dealing %d damage!\n", enemyDamage);
                printf("Enemy health: %d\n", enemyHealth);
                ammo--;
            }
            else {
                printf("You don't have any ammo left!\n");
            }
        }
        else if (strcmp(input, "heal") == 0) {
            if (health < 100) {
                health += 20;
                printf("You heal yourself, restoring 20 health.\n");
                printf("Health: %d\n", health);
            }
            else {
                printf("You are already at full health!\n");
            }
        }
        else {
            printf("Invalid command.\n");
        }
        
        if (enemyHealth <= 0) {
            printf("You have defeated the enemy!\n");
            printf("Congratulations! You have survived the futuristic city.\n");
            return 0;
        }
        
        if (health <= 0) {
            printf("You have died...\n");
            return 0;
        }
        
        printStats();
        printf("> ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0;
    }
    
    printf("Thanks for playing!\n");
    return 0;
}