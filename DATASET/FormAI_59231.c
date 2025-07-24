//FormAI DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int scavengers = 27; // initial number of scavengers
    int guns = 8; // initial number of guns
    int bullets = 463; // initial number of bullets
    int shelter = 2; // initial number of shelters
    int scav_per_shelter = 8; // number of scavengers per shelter
    int max_damage = 50; // maximum damage a gun can cause
    int min_damage = 20; // minimum damage a gun can cause
    int total_scav = shelter * scav_per_shelter; // total number of scavengers in all shelters
    int total_gun_damage = 0; // total damage done by all guns
    int bullet_usage = 0; // total number of bullets used

    // calculate damage done by each gun and total damage
    for (int i = 1; i <= guns; i++) {
        int damage = (i % 2 == 0) ? max_damage : min_damage; // alternate between max and min damage
        total_gun_damage += (damage * (i % 3 == 0 ? 2 : 1)); // triple the damage on every third gun
    }

    // calculate bullets used and remaining bullets
    for (int i = 1; i <= total_scav; i++) {
        int bullets_used = (i % 2 == 0 ? 10 : 5); // use 10 bullets on every even scavenger, 5 on every odd scavenger
        bullet_usage += bullets_used;

        if (bullet_usage > bullets) { // if out of bullets, break loop
            printf("Out of bullets!\n");
            break;
        }
    }

    int scavengers_lost = (int)(bullet_usage / 2.5); // calculate number of scavengers lost based on bullet usage
    scavengers -= scavengers_lost; // subtract lost scavengers from initial number

    // calculate total number of guns and remaining guns after damage done
    int total_guns = guns * ((total_scav - scavengers_lost) / scav_per_shelter);
    int guns_lost = (guns - total_guns) < 0 ? 0 : guns - total_guns;

    // output final results
    printf("Initial Scavengers: %d\n", scavengers);
    printf("Scavengers Lost: %d\n", scavengers_lost);
    printf("Remaining Scavengers: %d\n", scavengers - scavengers_lost);
    printf("Initial Guns: %d\n", guns);
    printf("Guns Lost: %d\n", guns_lost);
    printf("Remaining Guns: %d\n", total_guns);
    printf("Initial Bullets: %d\n", bullets);
    printf("Bullets Used: %d\n", bullet_usage);
    printf("Remaining Bullets: %d\n", bullets - bullet_usage);

    return 0;
}