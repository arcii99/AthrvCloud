//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G_CONST 6.674E-11 // Gravitational constant

// Structure for storing planet properties
typedef struct {
    char* name;
    double mass;
    double radius;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
} Planet;

// Function to calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p1.x_pos - p2.x_pos, 2) + pow(p1.y_pos - p2.y_pos, 2));
}

int main() {
    // Set seed for random number generator
    srand(time(NULL));

    // Define solar system
    Planet sun = {"Sun", 1.989E30, 696340000, 0, 0, 0, 0};
    Planet mercury = {"Mercury", 3.285E23, 2439700, 57910000000, 0, 0, 47890};
    Planet venus = {"Venus", 4.867E24, 6051800, 108200000000, 0, 0, 35020};
    Planet earth = {"Earth", 5.972E24, 6371000, 149600000000, 0, 0, 29290};
    Planet mars = {"Mars", 6.39E23, 3389500, 227940000000, 0, 0, 21970};
    Planet jupiter = {"Jupiter", 1.898E27, 69911000, 778330000000, 0, 0, 12440};
    Planet saturn = {"Saturn", 5.683E26, 58232000, 1424600000000, 0, 0, 9080};
    Planet uranus = {"Uranus", 8.681E25, 25362000, 2873550000000, 0, 0, 6490};
    Planet neptune = {"Neptune", 1.024E26, 24622000, 4495100000000, 0, 0, 5400};

    // Controlled variables
    double time_step = 86400;  // 1 day
    int running = 1;
    int count = 0;
    double max_distance = 0;

    // Simulate solar system
    while (running) {
        // Print out planet positions
        printf("Day: %d\n", count);
        printf("%s: (%f, %f)\n", sun.name, sun.x_pos, sun.y_pos);
        printf("%s: (%f, %f)\n", mercury.name, mercury.x_pos, mercury.y_pos);
        printf("%s: (%f, %f)\n", venus.name, venus.x_pos, venus.y_pos);
        printf("%s: (%f, %f)\n", earth.name, earth.x_pos, earth.y_pos);
        printf("%s: (%f, %f)\n", mars.name, mars.x_pos, mars.y_pos);
        printf("%s: (%f, %f)\n", jupiter.name, jupiter.x_pos, jupiter.y_pos);
        printf("%s: (%f, %f)\n", saturn.name, saturn.x_pos, saturn.y_pos);
        printf("%s: (%f, %f)\n", uranus.name, uranus.x_pos, uranus.y_pos);
        printf("%s: (%f, %f)\n", neptune.name, neptune.x_pos, neptune.y_pos);

        // Calculate planet accelerations
        double a_mercury = G_CONST * sun.mass / pow(distance(mercury, sun), 2);
        double a_venus = G_CONST * sun.mass / pow(distance(venus, sun), 2);
        double a_earth = G_CONST * sun.mass / pow(distance(earth, sun), 2);
        double a_mars = G_CONST * sun.mass / pow(distance(mars, sun), 2);
        double a_jupiter = G_CONST * sun.mass / pow(distance(jupiter, sun), 2);
        double a_saturn = G_CONST * sun.mass / pow(distance(saturn, sun), 2);
        double a_uranus = G_CONST * sun.mass / pow(distance(uranus, sun), 2);
        double a_neptune = G_CONST * sun.mass / pow(distance(neptune, sun), 2);

        // Update planet positions and velocities
        mercury.x_vel += a_mercury * time_step;
        mercury.y_vel += a_mercury * time_step;
        mercury.x_pos += mercury.x_vel * time_step;
        mercury.y_pos += mercury.y_vel * time_step;

        venus.x_vel += a_venus * time_step;
        venus.y_vel += a_venus * time_step;
        venus.x_pos += venus.x_vel * time_step;
        venus.y_pos += venus.y_vel * time_step;

        earth.x_vel += a_earth * time_step;
        earth.y_vel += a_earth * time_step;
        earth.x_pos += earth.x_vel * time_step;
        earth.y_pos += earth.y_vel * time_step;

        mars.x_vel += a_mars * time_step;
        mars.y_vel += a_mars * time_step;
        mars.x_pos += mars.x_vel * time_step;
        mars.y_pos += mars.y_vel * time_step;

        jupiter.x_vel += a_jupiter * time_step;
        jupiter.y_vel += a_jupiter * time_step;
        jupiter.x_pos += jupiter.x_vel * time_step;
        jupiter.y_pos += jupiter.y_vel * time_step;

        saturn.x_vel += a_saturn * time_step;
        saturn.y_vel += a_saturn * time_step;
        saturn.x_pos += saturn.x_vel * time_step;
        saturn.y_pos += saturn.y_vel * time_step;

        uranus.x_vel += a_uranus * time_step;
        uranus.y_vel += a_uranus * time_step;
        uranus.x_pos += uranus.x_vel * time_step;
        uranus.y_pos += uranus.y_vel * time_step;

        neptune.x_vel += a_neptune * time_step;
        neptune.y_vel += a_neptune * time_step;
        neptune.x_pos += neptune.x_vel * time_step;
        neptune.y_pos += neptune.y_vel * time_step;

        // Check for collision between any two planets
        if (distance(mercury, venus) <= mercury.radius + venus.radius) {
            printf("%s and %s have collided!\n", mercury.name, venus.name);
            running = 0;
        }
        if (distance(mercury, earth) <= mercury.radius + earth.radius) {
            printf("%s and %s have collided!\n", mercury.name, earth.name);
            running = 0;
        }
        if (distance(mercury, mars) <= mercury.radius + mars.radius) {
            printf("%s and %s have collided!\n", mercury.name, mars.name);
            running = 0;
        }
        if (distance(mercury, jupiter) <= mercury.radius + jupiter.radius) {
            printf("%s and %s have collided!\n", mercury.name, jupiter.name);
            running = 0;
        }
        if (distance(mercury, saturn) <= mercury.radius + saturn.radius) {
            printf("%s and %s have collided!\n", mercury.name, saturn.name);
            running = 0;
        }
        if (distance(mercury, uranus) <= mercury.radius + uranus.radius) {
            printf("%s and %s have collided!\n", mercury.name, uranus.name);
            running = 0;
        }
        if (distance(mercury, neptune) <= mercury.radius + neptune.radius) {
            printf("%s and %s have collided!\n", mercury.name, neptune.name);
            running = 0;
        }
        if (distance(venus, earth) <= venus.radius + earth.radius) {
            printf("%s and %s have collided!\n", venus.name, earth.name);
            running = 0;
        }
        if (distance(venus, mars) <= venus.radius + mars.radius) {
            printf("%s and %s have collided!\n", venus.name, mars.name);
            running = 0;
        }
        if (distance(venus, jupiter) <= venus.radius + jupiter.radius) {
            printf("%s and %s have collided!\n", venus.name, jupiter.name);
            running = 0;
        }
        if (distance(venus, saturn) <= venus.radius + saturn.radius) {
            printf("%s and %s have collided!\n", venus.name, saturn.name);
            running = 0;
        }
        if (distance(venus, uranus) <= venus.radius + uranus.radius) {
            printf("%s and %s have collided!\n", venus.name, uranus.name);
            running = 0;
        }
        if (distance(venus, neptune) <= venus.radius + neptune.radius) {
            printf("%s and %s have collided!\n", venus.name, neptune.name);
            running = 0;
        }
        if (distance(earth, mars) <= earth.radius + mars.radius) {
            printf("%s and %s have collided!\n", earth.name, mars.name);
            running = 0;
        }
        if (distance(earth, jupiter) <= earth.radius + jupiter.radius) {
            printf("%s and %s have collided!\n", earth.name, jupiter.name);
            running = 0;
        }
        if (distance(earth, saturn) <= earth.radius + saturn.radius) {
            printf("%s and %s have collided!\n", earth.name, saturn.name);
            running = 0;
        }
        if (distance(earth, uranus) <= earth.radius + uranus.radius) {
            printf("%s and %s have collided!\n", earth.name, uranus.name);
            running = 0;
        }
        if (distance(earth, neptune) <= earth.radius + neptune.radius) {
            printf("%s and %s have collided!\n", earth.name, neptune.name);
            running = 0;
        }
        if (distance(mars, jupiter) <= mars.radius + jupiter.radius) {
            printf("%s and %s have collided!\n", mars.name, jupiter.name);
            running = 0;
        }
        if (distance(mars, saturn) <= mars.radius + saturn.radius) {
            printf("%s and %s have collided!\n", mars.name, saturn.name);
            running = 0;
        }
        if (distance(mars, uranus) <= mars.radius + uranus.radius) {
            printf("%s and %s have collided!\n", mars.name, uranus.name);
            running = 0;
        }
        if (distance(mars, neptune) <= mars.radius + neptune.radius) {
            printf("%s and %s have collided!\n", mars.name, neptune.name);
            running = 0;
        }
        if (distance(jupiter, saturn) <= jupiter.radius + saturn.radius) {
            printf("%s and %s have collided!\n", jupiter.name, saturn.name);
            running = 0;
        }
        if (distance(jupiter, uranus) <= jupiter.radius + uranus.radius) {
            printf("%s and %s have collided!\n", jupiter.name, uranus.name);
            running = 0;
        }
        if (distance(jupiter, neptune) <= jupiter.radius + neptune.radius) {
            printf("%s and %s have collided!\n", jupiter.name, neptune.name);
            running = 0;
        }
        if (distance(saturn, uranus) <= saturn.radius + uranus.radius) {
            printf("%s and %s have collided!\n", saturn.name, uranus.name);
            running = 0;
        }
        if (distance(saturn, neptune) <= saturn.radius + neptune.radius) {
            printf("%s and %s have collided!\n", saturn.name, neptune.name);
            running = 0;
        }
        if (distance(uranus, neptune) <= uranus.radius + neptune.radius) {
            printf("%s and %s have collided!\n", uranus.name, neptune.name);
            running = 0;
        }

        // Find maximum distance between any two planets
        if (distance(sun, mercury) > max_distance) {
            max_distance = distance(sun, mercury);
        }
        if (distance(sun, venus) > max_distance) {
            max_distance = distance(sun, venus);
        }
        if (distance(sun, earth) > max_distance) {
            max_distance = distance(sun, earth);
        }
        if (distance(sun, mars) > max_distance) {
            max_distance = distance(sun, mars);
        }
        if (distance(sun, jupiter) > max_distance) {
            max_distance = distance(sun, jupiter);
        }
        if (distance(sun, saturn) > max_distance) {
            max_distance = distance(sun, saturn);
        }
        if (distance(sun, uranus) > max_distance) {
            max_distance = distance(sun, uranus);
        }
        if (distance(sun, neptune) > max_distance) {
            max_distance = distance(sun, neptune);
        }

        // Add some spicy dialogue between our planets
        if (count == 14) {
            printf("\n");
            printf("%s: Oh, fair and radiant sun, how I bask in your warm embrace.\n", mercury.name);
            printf("%s: Begone, small and insignificant planet! I have no time for your foolishness.\n", sun.name);
            printf("%s: What say you, Venus? Surely you too must appreciate the sun's splendor.\n", mercury.name);
            printf("%s: I do not concern myself with such trivial matters. I prefer to focus on my own beauty.\n", venus.name);
            printf("%s: Ah, but do not forget my charm, dear Venus. I am truly the most beautiful of them all.\n", earth.name);
            printf("%s: Please, Earth. You may be pleasant enough to look at, but you cannot compare to my elegance.\n", venus.name);
            printf("%s: And what of my might, my strength? Who among us can match the power of Mars?\n", mars.name);
            printf("%s: Your violence does not impress me, Mars. It is only through cooperation and harmony that we thrive.\n", earth.name);
            printf("%s: I must agree with Earth. Our unity gives us strength, unlike your petty conflicts, Mars.\n", neptune.name);
            printf("%s: Silence, all of you! Your petty squabbles are nothing compared to my grandeur and majesty!\n", jupiter.name);
            printf("%s: Do not be so quick to underestimate our power, Jupiter. It is together that we are strongest.\n", saturn.name);
            printf("%s: Hear, hear! Unity is key, especially in these times of uncertainty.\n", uranus.name);
            printf("%s: Yes, let us not forget our bonds. It is only together that we can succeed.\n", neptune.name);
            printf("\n");
        }

        // Increment day counter
        count++;

        // Add random perturbations to planet velocities
        mercury.x_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        mercury.y_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        venus.x_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        venus.y_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        earth.x_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        earth.y_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        mars.x_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        mars.y_vel += ((rand() % 1000) / 1000.0) * 1000 - 500;
        jupiter.x_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
        jupiter.y_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
        saturn.x_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
        saturn.y_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
        uranus.x_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
        uranus.y_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
        neptune.x_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
        neptune.y_vel += ((rand() % 1000) / 1000.0) * 10000 - 5000;
    }

    // Print out final maximum distance
    printf("Maximum distance between any two planets: %f meters.\n", max_distance);

    return 0;
}