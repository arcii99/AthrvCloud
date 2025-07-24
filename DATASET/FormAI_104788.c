//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define the maximum length for input and output */
#define MAX_INPUT_LENGTH 50
#define MAX_OUTPUT_LENGTH 100

/* Define the maximum number of planets that can be generated */
#define MAX_PLANETS 10

/* Define the maximum number of aliens that can be generated */
#define MAX_ALIENS 15

/* Define the structure for a planet */
struct Planet {
    char name[MAX_INPUT_LENGTH];
    int distance;
    int resources;
};

/* Define the structure for an alien */
struct Alien {
    char name[MAX_INPUT_LENGTH];
    int resource_value;
};

/* Function to generate a random integer between a minimum and maximum value */
int generate_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Function to generate a random string for the planet or alien name */
void generate_random_string(char *str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < size - 1; i++) {
        size_t index = generate_random(0, strlen(charset)-1);
        str[i] = charset[index];
    }
    str[size-1] = '\0';
}

/* Function to initialize a planet */
void initialize_planet(struct Planet *planet) {
    generate_random_string(planet->name, MAX_INPUT_LENGTH);
    planet->distance = generate_random(1, 100);
    planet->resources = generate_random(1, 10);
}

/* Function to print a planet */
void print_planet(struct Planet planet) {
    printf("Planet '%s' is %d light years away and has %d resources.\n", planet.name, planet.distance, planet.resources);
}

/* Function to initialize an alien */
void initialize_alien(struct Alien *alien) {
    generate_random_string(alien->name, MAX_INPUT_LENGTH);
    alien->resource_value = generate_random(1, 5);
}

/* Function to print an alien */
void print_alien(struct Alien alien) {
    printf("Alien '%s' has a resource value of %d.\n", alien.name, alien.resource_value);
}

/* Main function */
int main() {
    /* Set the random seed based on the current time */
    srand(time(NULL));

    /* Generate the planets */
    struct Planet planets[MAX_PLANETS];
    for (int i = 0; i < MAX_PLANETS; i++) {
        initialize_planet(&planets[i]);
        print_planet(planets[i]);
    }

    /* Generate the aliens */
    struct Alien aliens[MAX_ALIENS];
    for (int i = 0; i < MAX_ALIENS; i++) {
        initialize_alien(&aliens[i]);
        print_alien(aliens[i]);
    }

    /* Find the closest planet */
    struct Planet closest_planet = planets[0];
    for (int i = 1; i < MAX_PLANETS; i++) {
        if (planets[i].distance < closest_planet.distance) {
            closest_planet = planets[i];
        }
    }

    /* Print the closest planet */
    printf("The closest planet to Earth is '%s', %d light years away and has %d resources.\n", closest_planet.name, closest_planet.distance, closest_planet.resources);

    /* Print a welcome message */
    printf("Welcome to the space adventure game! You are on a mission to collect as many resources as possible.\n");

    /* Initialize the player's resources */
    int player_resources = 0;

    /* Start the game loop */
    while (1) {
        /* Print the player's resources */
        printf("You currently have %d resources.\n", player_resources);

        /* Get the user's choice */
        char choice[MAX_INPUT_LENGTH];
        printf("What do you want to do? Type 'explore' to travel to a planet or 'trade' to trade with an alien.\n");
        fgets(choice, MAX_INPUT_LENGTH, stdin);

        /* Trim the newline character from the input */
        choice[strcspn(choice, "\n")] = 0;

        /* Handle the user's choice */
        if (strcmp(choice, "explore") == 0) {
            /* Get a random planet */
            struct Planet planet = planets[generate_random(0, MAX_PLANETS-1)];

            /* Calculate the distance to the planet */
            int distance = planet.distance - closest_planet.distance;

            /* Print the planet information */
            printf("You have traveled %d light years to the planet '%s'.\n", distance, planet.name);
            printf("The planet has %d resources.\n", planet.resources);

            /* Add the planet's resources to the player's resources */
            player_resources += planet.resources;

            /* Update the closest planet if this planet is closer */
            if (distance < closest_planet.distance) {
                closest_planet = planet;
                printf("Congratulations! You have found a new closest planet to Earth!\n");
            }
        } else if (strcmp(choice, "trade") == 0) {
            /* Get a random alien */
            struct Alien alien = aliens[generate_random(0, MAX_ALIENS-1)];

            /* Print the alien information */
            printf("You have encountered an alien named '%s'.\n", alien.name);
            printf("The alien has a resource value of %d.\n", alien.resource_value);

            /* Ask the player if they want to trade */
            char trade_choice[MAX_INPUT_LENGTH];
            printf("Do you want to trade with the alien? Type 'yes' or 'no'.\n");
            fgets(trade_choice, MAX_INPUT_LENGTH, stdin);

            /* Trim the newline character from the input */
            trade_choice[strcspn(trade_choice, "\n")] = 0;

            /* Handle the player's choice */
            if (strcmp(trade_choice, "yes") == 0) {
                /* Calculate the trade amount */
                int trade_amount = generate_random(1, 5) * alien.resource_value;

                /* Print the trade amount */
                printf("You have traded with the alien and received %d resources.\n", trade_amount);

                /* Add the trade amount to the player's resources */
                player_resources += trade_amount;
            } else {
                printf("You have decided not to trade with the alien.\n");
            }
        } else {
            printf("Invalid choice, please try again.\n");
        }

        /* Check if the player has won */
        if (player_resources >= 50) {
            printf("Congratulations, you have collected 50 resources and completed your mission!\n");
            break;
        }
    }

    return 0;
}