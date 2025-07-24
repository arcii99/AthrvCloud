//FormAI DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int ammo = 15;
    int enemies = 10;
    int damage = 25;

    printf("You have %d bullets in your gun to kill %d enemies.\n", ammo, enemies);
    printf("Each bullet does %d damage to an enemy.\n", damage);

    int total_damage = ammo & (enemies * damage);

    if (total_damage >= enemies * damage) {
        printf("You killed all the enemies with %d bullets left.\n", ammo - (enemies * damage));
    } else {
        printf("You didn't have enough bullets to kill all the enemies.\n");
    }

    return 0;
}