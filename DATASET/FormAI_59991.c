//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979

struct planet {
    char name[20];
    float distance;
    float speed;
    float angle;
};

typedef struct planet Planet;

void drawPlanet(float x, float y, float r) {
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            if (sqrt(i*i + j*j) <= r) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawOrbit(float radius) {
    for (float i = 0; i <= 2*PI; i += 0.05) {
        float x = cos(i) * radius;
        float y = sin(i) * radius;
        printf(" ");
        printf(".");
        printf(" ");
    }
    printf("\n");
}

int main() {
    Planet sun = {"Sun", 0, 0, 0};
    Planet mercury = {"Mercury", 20, 2, 0};
    Planet venus = {"Venus", 30, 1.5, 0};
    Planet earth = {"Earth", 40, 1, 0};
    Planet mars = {"Mars", 50, 0.8, 0};
    Planet jupiter = {"Jupiter", 80, 0.5, 0};

    Planet planets[6] = {mercury, venus, earth, mars, jupiter};

    int time = 0;
    float angle = 0;

    while(1) {
        printf("\033[0;0H\033[2J");

        // update planet angle
        for (int i = 0; i < 5; i++) {
            planets[i].angle += planets[i].speed;
            if (planets[i].angle >= 2*PI) {
                planets[i].angle = 0;
            }
        }

        // draw sun
        printf("\033[33m");
        drawPlanet(50, 15, 5);
        printf("\033[0m");

        // draw orbits
        for (int i = 0; i < 5; i++) {
            drawOrbit(planets[i].distance);
        }

        // draw planets
        for (int i = 0; i < 5; i++) {
            float x = cos(planets[i].angle) * planets[i].distance + 50;
            float y = sin(planets[i].angle) * planets[i].distance + 15;
            printf("\033[%d;%df", (int)y, (int)x);
            printf("\033[32m");
            drawPlanet(x, y, 2);
            printf("\033[0m");
        }

        // update time
        time++;
        if (time >= 1000) {
            time = 0;
        }

        // delay
        usleep(50000);
    }

    return 0;
}