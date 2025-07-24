//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>

const int PLANET_COUNT = 5;
const int PLANET_RADIUS = 50;
const int SHIP_SPEED = 10;

// Generate a random location within the boundaries of the universe
int random_location(int boundary) {
    return rand() % boundary;
}

// Check if the ship collides with a planet
int check_collision(int ship_location_x, int ship_location_y, int planet_locations_x[], int planet_locations_y[]) {
    int is_collision = 0;
    for (int i = 0; i < PLANET_COUNT; i++) {
        int distance = sqrt(pow(ship_location_x - planet_locations_x[i], 2) + pow(ship_location_y - planet_locations_y[i], 2));
        if (distance <= PLANET_RADIUS) {
            is_collision = 1;
            break;
        }
    }
    return is_collision;
}

int main() {
    // Generate the x and y coordinates of each planet
    int planet_locations_x[PLANET_COUNT];
    int planet_locations_y[PLANET_COUNT];
    for (int i = 0; i < PLANET_COUNT; i++) {
        planet_locations_x[i] = random_location(1000);
        planet_locations_y[i] = random_location(1000);
    }

    int ship_location_x = random_location(1000);
    int ship_location_y = random_location(1000);
    int score = 0;

    while (1) {
        // Print the current score and ship location
        printf("Score: %d\n", score);
        printf("Ship location: (%d, %d)\n", ship_location_x, ship_location_y);

        // Ask the user where they want to go
        printf("Where would you like to go? (up/down/left/right)\n");
        char direction[10];
        scanf("%s", direction);

        // Move the ship in the chosen direction
        if (strcmp(direction, "up") == 0) {
            ship_location_y -= SHIP_SPEED;
        } else if (strcmp(direction, "down") == 0) {
            ship_location_y += SHIP_SPEED;
        } else if (strcmp(direction, "left") == 0) {
            ship_location_x -= SHIP_SPEED;
        } else if (strcmp(direction, "right") == 0) {
            ship_location_x += SHIP_SPEED;
        }

        // Check if the ship has collided with a planet
        if (check_collision(ship_location_x, ship_location_y, planet_locations_x, planet_locations_y)) {
            // If there is a collision, end the game
            printf("Oh no! You crashed into a planet and lost.\n");
            break;
        } else {
            // Otherwise, increase the score and continue the game
            score++;
        }
    }

    return 0;
}