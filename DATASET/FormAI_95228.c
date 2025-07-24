//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>

void explore_planet(int num_planet) {
    if (num_planet == 0) {
        printf("You are back on Earth!\n");
    } else {
        printf("Exploring planet %d...\n", num_planet);
        explore_planet(num_planet - 1);
        printf("Returning from planet %d...\n", num_planet);
    }
}

int main() {
    printf("Welcome to the Space Adventure!\n");
    printf("You will be visiting 5 planets.\n");
    explore_planet(5);
    printf("Thanks for exploring space with me.\n");
    return 0;
}