//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(NULL));

    // Define constants
    const int MAX_PLANETS = 5;
    const int MAX_RESOURCES = 10;
    const int MAX_SPACE_SHIPS = 3;

    // Initialize variables
    int num_planets = rand() % MAX_PLANETS + 1;
    int num_resources = rand() % MAX_RESOURCES + 1;
    int num_space_ships = rand() % MAX_SPACE_SHIPS + 1;

    // Generate planet names
    char planet_names[num_planets][50];
    char consonants[] = "BCDFGHJKLMNPQRSTVWXYZ";
    char vowels[] = "AEIOU";
    for (int i = 0; i < num_planets; i++) {
        int num_syllables = rand() % 4 + 1;
        for (int j = 0; j < num_syllables; j++) {
            // Generate consonant
            int con_index = rand() % 20;
            char con = consonants[con_index];

            // Generate vowel
            int vow_index = rand() % 5;
            char vow = vowels[vow_index];

            // Build syllable
            char syllable[3] = {con, vow, '\0'};

            // Append syllable to name
            strcat(planet_names[i], syllable);
        }
    }

    // Print planet names
    printf("The planets in this galaxy are: ");
    for (int i = 0; i < num_planets; i++) {
        printf("%s ", planet_names[i]);
    }
    printf("\n\n");

    // Generate resources
    char resources[num_resources][20];
    char types[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < num_resources; i++) {
        int type_index = rand() % 26;
        char type = types[type_index];
        int quantity = rand() % 100 + 1;
        sprintf(resources[i], "%c%d", type, quantity);
    }

    // Print resources
    printf("The resources in this galaxy are: ");
    for (int i = 0; i < num_resources; i++) {
        printf("%s ", resources[i]);
    }
    printf("\n\n");

    // Generate space ships
    struct SpaceShip {
        char name[50];
        int max_speed;
        int max_cargo;
    };

    struct SpaceShip space_ships[num_space_ships];
    char ship_names[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < num_space_ships; i++) {
        // Generate ship name
        int name_index = rand() % 26;
        char name = ship_names[name_index];
        sprintf(space_ships[i].name, "SS%c%d", name, i+1);

        // Generate ship stats
        space_ships[i].max_speed = rand() % 1000 + 1;
        space_ships[i].max_cargo = rand() % 1000 + 1;
    }

    // Print space ships
    printf("The space ships in this galaxy are: ");
    for (int i = 0; i < num_space_ships; i++) {
        printf("%s (max speed: %d, max cargo: %d) ", space_ships[i].name, space_ships[i].max_speed, space_ships[i].max_cargo);
    }
    printf("\n");

    return 0;
}