//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: paranoid
#include <stdio.h>

// function to scan for any nearby alien ships
int scan_for_ships() {
    int alien_ships = 0;
    printf("Scanning for alien ships...\n");
    // randomly generate the number of alien ships detected
    alien_ships = rand() % 10;
    printf("%d alien ship(s) detected...\n", alien_ships);
    return alien_ships;
}

// function to engage the thrusters and move the ship
void engage_thrusters() {
    printf("Engaging thrusters...\n");
    // randomly generate a speed between 1 and 10
    int speed = rand() % 10 + 1;
    printf("Thrusters engaged at speed %d...\n", speed);
}

// function to fire lasers at enemy ships
void fire_lasers(int enemy_ships) {
    printf("Firing lasers...\n");
    // randomly determine the accuracy of the lasers
    int accuracy = rand() % 10;
    if (accuracy < 3) {
        printf("Lasers missed their targets...\n");
    } else {
        printf("Lasers hit %d enemy ship(s)...\n", enemy_ships);
    }
}

int main() {
    printf("Starting space adventure...\n");
    int alien_ships_detected = scan_for_ships();
    if (alien_ships_detected > 0) {
        printf("Enemy ships detected!\n");
        engage_thrusters();
        fire_lasers(alien_ships_detected);
    } else {
        printf("No enemy ships detected... phew!\n");
    }

    printf("Paranoid mode activated...\n");
    int paranoid = 1;
    while (paranoid) {
        // randomly determine if an alien ship is approaching
        int approaching = rand() % 2;
        if (approaching) {
            printf("ALIEN SHIP APPROACHING! EVASIVE MANEUVERS!\n");
            engage_thrusters();
            fire_lasers(1);
        } else {
            printf("No alien ships detected... yet.\n");
        }
    }
    return 0;
}