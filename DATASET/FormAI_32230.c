//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>

// function to display introspective messages
void display_message(char* message) {
    printf("[INTROSPECTION]: %s\n", message);
}

// function to display error messages
void display_error(char* message) {
    printf("[ERROR]: %s\n", message);
    exit(1);
}

// function to check if the player has enough fuel
int has_enough_fuel(int fuel, int distance) {
    if (fuel < distance * 2) {
        display_error("Not enough fuel to complete the journey!");
    }
    return 1;
}

// function to check if the landed planet is habitable
int is_planet_habitable() {
    display_message("Analyzing planet...");
    // planet analysis code goes here
    int habitable = 1; // for the sake of example, assume the planet is habitable
    if (!habitable) {
        display_error("Planet is not habitable! Find another planet.");
    }
    return 1;
}

// main function
int main() {
    // display intro message
    display_message("Welcome to Procedural Space Adventure!");

    // variables
    int fuel = 100;
    int distance_to_planet = 50;

    // check if player has enough fuel
    has_enough_fuel(fuel, distance_to_planet);

    // travel to planet
    display_message("Traveling to planet...");
    fuel -= distance_to_planet;
    display_message("Arrived at planet.");

    // check if planet is habitable
    is_planet_habitable();

    // return success
    display_message("Mission complete.");
    return 0;
}