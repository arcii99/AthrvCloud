//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 1.0 // gravitational constant
#define TIME_INTERVAL 0.001 // time interval for simulation
#define SCREEN_WIDTH 80 // console screen width
#define SCREEN_HEIGHT 40 // console screen height
#define PIXEL_SIZE 2 // size of each block in pixel

typedef struct planet { // structure of a planet
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass; // mass
    char symbol; // symbol to represent in console output
} Planet;

void update_acceleration(Planet *p, Planet *planets, int n) { // update acceleration of a planet
    double fx, fy, r;
    p->ax = p->ay = 0; // reset acceleration
    for(int i = 0; i < n; i++) { // loop through all planets
        if(p == &planets[i]) continue; // skip own planet
        r = sqrt(pow(p->x - planets[i].x, 2) + pow(p->y - planets[i].y, 2)); // distance between two planets
        fx = G * p->mass * planets[i].mass / pow(r, 2) * (planets[i].x - p->x) / r; // force in x direction
        fy = G * p->mass * planets[i].mass / pow(r, 2) * (planets[i].y - p->y) / r; // force in y direction
        p->ax += fx / p->mass; // update acceleration in x direction
        p->ay += fy / p->mass; // update acceleration in y direction
    }
}

void update_velocity(Planet *p) { // update velocity of a planet
    p->vx += p->ax * TIME_INTERVAL; // update velocity in x direction
    p->vy += p->ay * TIME_INTERVAL; // update velocity in y direction
}

void update_position(Planet *p) { // update position of a planet
    p->x += p->vx * TIME_INTERVAL; // update position in x direction
    p->y += p->vy * TIME_INTERVAL; // update position in y direction
}

void draw_pixel(char c) { // draw a pixel in console output
    for(int i = 0; i < PIXEL_SIZE; i++)
        putchar(c);
}

void clear_screen() { // clear console screen
    system("cls");
}

void display(Planet *planets, int n) { // display all planets in console output
    clear_screen();

    for(int i = 0; i < n; i++) {
        int x = planets[i].x * SCREEN_WIDTH;
        int y = planets[i].y * SCREEN_HEIGHT;
        if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) continue; // skip if planet is outside screen
        x /= PIXEL_SIZE;
        y /= PIXEL_SIZE;
        for(int j = 0; j < PIXEL_SIZE; j++) { // draw a square of pixels to represent a planet
            for(int k = 0; k < PIXEL_SIZE; k++)
                draw_pixel(planets[i].symbol);
            putchar('\n');
        }
    }

    fflush(stdout); // flush output
}

int main() {
    int n;
    printf("Enter number of planets (2-9): ");
    scanf("%d", &n);

    if(n < 2 || n > 9) { // only allow 2-9 planets
        printf("Invalid number of planets!\n");
        return 1;
    }

    Planet planets[n];

    for(int i = 0; i < n; i++) { // initialize each planet
        planets[i].mass = rand() / (double)RAND_MAX * 10 + 1; // random mass between 1 to 10
        planets[i].x = rand() / (double)RAND_MAX;
        planets[i].y = rand() / (double)RAND_MAX;
        planets[i].vx = rand() / (double)RAND_MAX * 2 - 1; // random velocity between -1 to 1
        planets[i].vy = rand() / (double)RAND_MAX * 2 - 1;
        planets[i].symbol = '0' + i + 1; // use number to represent planet (1-9)
    }

    while(1) { // simulation loop
        for(int i = 0; i < n; i++) {
            update_acceleration(&planets[i], planets, n);
            update_velocity(&planets[i]);
            update_position(&planets[i]);
        }

        display(planets, n);

        for(int i = 0; i < n; i++)
            if(planets[i].x < 0 || planets[i].x > 1 || planets[i].y < 0 || planets[i].y > 1)
                planets[i].vx = -planets[i].vx; // bounce back if hits wall

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) { // check for collision
                double d = sqrt(pow(planets[i].x - planets[j].x, 2) + pow(planets[i].y - planets[j].y, 2));
                if(d < (planets[i].mass + planets[j].mass) / 2.0) { // collision happens
                    double m1 = planets[i].mass, m2 = planets[j].mass;
                    double vx1 = planets[i].vx, vy1 = planets[i].vy;
                    double vx2 = planets[j].vx, vy2 = planets[j].vy;
                    planets[i].vx = (m1 - m2) / (m1 + m2) * vx1 + 2 * m2 / (m1 + m2) * vx2; // update velocity using momentum conservation
                    planets[i].vy = (m1 - m2) / (m1 + m2) * vy1 + 2 * m2 / (m1 + m2) * vy2;
                    planets[j].vx = 2 * m1 / (m1 + m2) * vx1 + (m2 - m1) / (m1 + m2) * vx2;
                    planets[j].vy = 2 * m1 / (m1 + m2) * vy1 + (m2 - m1) / (m1 + m2) * vy2;                   
                }
            }

        usleep(TIME_INTERVAL * 1000000); // wait for next frame
    }
}