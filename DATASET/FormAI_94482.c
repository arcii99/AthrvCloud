//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct to hold information about a weapon
struct Weapon {
    char name[MAX_SIZE];
    int damage;
    int range;
};

// Function to display the information of a given weapon
void display_weapon(struct Weapon weapon) {
    printf("%s (DMG: %d, Range: %d)\n", weapon.name, weapon.damage, weapon.range);
}

// Function to find the weapon with the highest damage
struct Weapon find_best_weapon(struct Weapon weapons[], int num_weapons) {
    struct Weapon best_weapon = weapons[0];
    for (int i = 1; i < num_weapons; i++) {
        if (weapons[i].damage > best_weapon.damage) {
            best_weapon = weapons[i];
        }
    }
    return best_weapon;
}

int main() {

    // Creating some weapons
    struct Weapon sword;
    strcpy(sword.name, "Sword");
    sword.damage = 10;
    sword.range = 2;
    struct Weapon axe;
    strcpy(axe.name, "Axe");
    axe.damage = 12;
    axe.range = 3;
    struct Weapon mace;
    strcpy(mace.name, "Mace");
    mace.damage = 8;
    mace.range = 1;

    // Adding the weapons to an array
    struct Weapon weapons[] = {sword, axe, mace};

    // Displaying all the weapons
    printf("All weapons:\n");
    for (int i = 0; i < 3; i++) {
        display_weapon(weapons[i]);
    }

    // Finding the best weapon
    struct Weapon best_weapon = find_best_weapon(weapons, 3);
    printf("\nBest weapon:\n");
    display_weapon(best_weapon);

    return 0;
}