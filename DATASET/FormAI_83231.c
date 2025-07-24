//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define WIDTH 100
#define HEIGHT 50
#define MAX_DIST 10000
#define YEAR 365.25

struct planet {
    char symbol;
    double x, y;
    double speed, angle;
    double radius, distance;
    double year_length;
};

int main(void) {
    srand(time(NULL)); // Used to randomize direction and starting position

    struct planet sun = {'O', WIDTH/2, HEIGHT/2, 0, 0, 15, 0, 0};
    struct planet earth = {'E', 0, 0, 0, 0, 5, 80, YEAR};

    // Generate random position and direction for the Earth
    int direction = rand() % 2; // Randomized direction
    if (direction == 0) {
        earth.x = 0;
        earth.angle = rand() % 90;
    } else {
        earth.x = WIDTH;
        earth.angle = rand() % 90 + 90;
    }
    earth.y = sun.y - earth.distance * sin(earth.angle * PI / 180);

    // Set initial speed of Earth based on distance to sun
    earth.speed = 2 * PI * earth.distance / (YEAR * 24 * 60 * 60);

    // Simulation loop
    for (int i = 0; i < MAX_DIST; i++) {
        // Calculate new position of Earth using circular motion equations
        double theta = earth.angle * PI / 180;
        double new_x = earth.speed * cos(theta);
        double new_y = earth.speed * sin(theta);
        earth.x += new_x;
        earth.y += new_y;

        // Print the solar system to the screen
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                char symbol = ' ';
                double dist = sqrt(pow(x - sun.x, 2) + pow(y - sun.y, 2));

                if (dist < sun.radius) {
                    symbol = sun.symbol;
                } else if (dist > earth.distance - earth.radius && dist < earth.distance + earth.radius) {
                    symbol = earth.symbol;
                }

                printf("%c", symbol);
            }
            printf("\n");
        }

        // Adjust angle of Earth for next iteration
        earth.angle += earth.speed * YEAR / earth.year_length;

        // Wait for some time to simulate one day passing in the simulation
        for (long int j = 0; j < 20000000; j++);
    }

    return 0;
}