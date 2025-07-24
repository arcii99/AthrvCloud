//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81

struct Coordinate {
    double x;
    double y;
    double z;
};

struct Planet {
    char name[100];
    double mass;
    struct Coordinate pos;
    struct Coordinate velocity;
    struct Coordinate acceleration;
};

void calculateAcceleration(struct Planet *planet, struct Planet *planets, int n) {
    double distance, force;
    for(int i = 0; i < n; i++) {
        if(strcmp(planet->name, planets[i].name) != 0) {
            distance = sqrt(pow(planets[i].pos.x - planet->pos.x, 2) +
                            pow(planets[i].pos.y - planet->pos.y, 2) +
                            pow(planets[i].pos.z - planet->pos.z, 2));
            
            force = G * planet->mass * planets[i].mass / pow(distance, 2);
            
            planet->acceleration.x += force / planet->mass * (planets[i].pos.x - planet->pos.x) / distance;
            planet->acceleration.y += force / planet->mass * (planets[i].pos.y - planet->pos.y) / distance;
            planet->acceleration.z += force / planet->mass * (planets[i].pos.z - planet->pos.z) / distance;
        }
    }
}

void updateVelocity(struct Planet *planet, double dt) {
    planet->velocity.x += planet->acceleration.x * dt;
    planet->velocity.y += planet->acceleration.y * dt;
    planet->velocity.z += planet->acceleration.z * dt;
}

void updatePosition(struct Planet *planet, double dt) {
    planet->pos.x += planet->velocity.x * dt;
    planet->pos.y += planet->velocity.y * dt;
    planet->pos.z += planet->velocity.z * dt;
}

int main() {
    printf("Welcome to the Planet Gravity Simulation!\n");
    printf("Please enter the number of planets: ");
    int n;
    scanf("%d", &n);
    struct Planet planets[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter the name of planet %d: ", i+1);
        scanf("%s", planets[i].name);
        printf("Enter the mass of planet %d (in kg): ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter the x-coordinate of planet %d: ", i+1);
        scanf("%lf", &planets[i].pos.x);
        printf("Enter the y-coordinate of planet %d: ", i+1);
        scanf("%lf", &planets[i].pos.y);
        printf("Enter the z-coordinate of planet %d: ", i+1);
        scanf("%lf", &planets[i].pos.z);
        printf("Enter the x-component of velocity of planet %d (in m/s): ", i+1);
        scanf("%lf", &planets[i].velocity.x);
        printf("Enter the y-component of velocity of planet %d (in m/s): ", i+1);
        scanf("%lf", &planets[i].velocity.y);
        printf("Enter the z-component of velocity of planet %d (in m/s): ", i+1);
        scanf("%lf", &planets[i].velocity.z);
    }
    
    double dt;
    printf("Enter the time step (in s): ");
    scanf("%lf", &dt);
    
    int t;
    printf("Enter the number of time steps: ");
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < n; j++) {
            planets[j].acceleration.x = 0;
            planets[j].acceleration.y = 0;
            planets[j].acceleration.z = 0;
            calculateAcceleration(&planets[j], planets, n);
        }
        
        for(int j = 0; j < n; j++) {
            updateVelocity(&planets[j], dt);
            updatePosition(&planets[j], dt);
            
            printf("%s current position: (%.2lf, %.2lf, %.2lf)\n", planets[j].name, planets[j].pos.x, planets[j].pos.y, planets[j].pos.z);
        }
        printf("\n");
    }
    
    return 0;
}