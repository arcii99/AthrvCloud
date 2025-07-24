//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define X_SIZE 80
#define Y_SIZE 22
#define PI 3.14159265

struct CelestialObject {
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
    double mass;
    double radius;
} sun, mercury, earth, mars;

void drawSystem();
void drawObject(struct CelestialObject object, char *symbol);
void calculateGravity(struct CelestialObject *first, struct CelestialObject *second);

int main() {

    sun.x_pos = X_SIZE/2;
    sun.y_pos = Y_SIZE/2;
    sun.x_vel = 0;
    sun.y_vel = 0;
    sun.mass = 50000;
    sun.radius = 5;

    mercury.x_pos = X_SIZE/2 + 10;
    mercury.y_pos = Y_SIZE/2;
    mercury.x_vel = 0;
    mercury.y_vel = -0.4;
    mercury.mass = 5;
    mercury.radius = 2;

    earth.x_pos = X_SIZE/2 + 20;
    earth.y_pos = Y_SIZE/2;
    earth.x_vel = 0;
    earth.y_vel = -0.35;
    earth.mass = 10;
    earth.radius = 3;

    mars.x_pos = X_SIZE/2 + 30;
    mars.y_pos = Y_SIZE/2;
    mars.x_vel = 0;
    mars.y_vel = -0.3;
    mars.mass = 7;
    mars.radius = 2.5;

    while(1) {
        usleep(100000);
        drawSystem();
    }

    return 0;
}

void drawSystem() {
    char display[Y_SIZE][X_SIZE];
    int i, j;

    // Initialize display
    for(i = 0; i < Y_SIZE; i++) {
        for(j = 0; j < X_SIZE; j++) {
            display[i][j] = ' ';
        }
    }

    // Draw objects
    drawObject(sun, "O");
    drawObject(mercury, "m");
    drawObject(earth, "e");
    drawObject(mars, "M");

    // Print display
    system("clear");
    for(i = 0; i < Y_SIZE; i++) {
        for(j = 0; j < X_SIZE; j++) {
            printf("%c", display[i][j]);
        }
        printf("\n");
    }

    // Calculate gravity
    calculateGravity(&sun, &mercury);
    calculateGravity(&sun, &earth);
    calculateGravity(&sun, &mars);
    calculateGravity(&mercury, &earth);
    calculateGravity(&mercury, &mars);
    calculateGravity(&earth, &mars);
}

void drawObject(struct CelestialObject object, char *symbol) {
    // Get position and radius
    int x = round(object.x_pos);
    int y = round(object.y_pos);
    int radius = object.radius;

    // Draw object
    int i, j;
    for(i = y - radius; i <= y + radius; i++) {
        if(i >= 0 && i < Y_SIZE) {
            for(j = x - radius; j <= x + radius; j++) {
                if(j >= 0 && j < X_SIZE) {
                    if(sqrt((i - y)*(i - y) + (j - x)*(j - x)) <= radius) {
                        printf("%c", *symbol);  // Update display
                    }
                }
            }
        }
    }
    printf("\n");
}

void calculateGravity(struct CelestialObject *first, struct CelestialObject *second) {
    double G = 6.6743e-11; // Gravitational constant
    double dx = second->x_pos - first->x_pos;
    double dy = second->y_pos - first->y_pos;
    double distance = sqrt(dx*dx + dy*dy);
    double force = G * first->mass * second->mass / (distance*distance);
    double accel_first = force / first->mass;
    double accel_second = force / second->mass;
    double angle = atan2(dy, dx);
    first->x_vel += accel_first * cos(angle);
    first->y_vel += accel_first * sin(angle);
    second->x_vel -= accel_second * cos(angle);
    second->y_vel -= accel_second * sin(angle);
    first->x_pos += first->x_vel;
    first->y_pos += first->y_vel;
    second->x_pos += second->x_vel;
    second->y_pos += second->y_vel;
}