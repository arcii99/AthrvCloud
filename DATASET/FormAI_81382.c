//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include <stdio.h>
#include <math.h>

#define G 6.67428e-11 //Gravitational constant
#define INTERVAL 0.01 //Time interval for simulation in seconds

struct vector{ //Vector structure to hold x, y and z components
    double x;
    double y;
    double z;
};

struct planet{ //Planet structure to hold position, velocity and mass
    char name[20];
    double mass;
    struct vector position;
    struct vector velocity;
};

void update_position(struct planet *p){ //Function to update position of planet using velocity
    p->position.x += p->velocity.x * INTERVAL;
    p->position.y += p->velocity.y * INTERVAL;
    p->position.z += p->velocity.z * INTERVAL;
}

void update_velocity(struct planet *p, struct planet *q){ //Function to update velocity of planet using gravitational force
    double distance = sqrt(pow(q->position.x - p->position.x, 2) + pow(q->position.y - p->position.y, 2) + pow(q->position.z - p->position.z, 2)); //Calculate distance between two planets
    double force = G * p->mass * q->mass / pow(distance, 2); //Calculate gravitational force between two planets
    struct vector direction; //Calculate direction of force
    direction.x = (q->position.x - p->position.x) / distance;
    direction.y = (q->position.y - p->position.y) / distance;
    direction.z = (q->position.z - p->position.z) / distance;
    p->velocity.x += direction.x * force / p->mass * INTERVAL; //Update velocity of planet using force and time interval
    p->velocity.y += direction.y * force / p->mass * INTERVAL;
    p->velocity.z += direction.z * force / p->mass * INTERVAL;
}

int main(){
    struct planet planets[3] = { //Initialize three planets
        {"Planet 1", 5.97e24, {0, 0, 0}, {0, 0, 0}},
        {"Planet 2", 6.42e23, {3.84e8, 0, 0}, {0, 1022, 0}},
        {"Planet 3", 1.898e27, {0, 7.78e8, 0}, {13170, 0, 0}}
    };
    int steps = 100000; //100000 steps for simulation
    int i, j, k;
    for(i=0; i<steps; i++){ //Loop for simulation steps
        for(j=0; j<3; j++){ //Loop for each planet
            for(k=j+1; k<3; k++){ //Loop for every pair of planets to calculate gravitational force
                update_velocity(&planets[j], &planets[k]);
                update_velocity(&planets[k], &planets[j]);
            }
            update_position(&planets[j]); //Update position of planet based on new velocity
        }
        //Output positions after each simulation step
        printf("Positions after step %d:\n", i+1);
        for(j=0; j<3; j++){
            printf("%s: (%.2f, %.2f, %.2f)\n", planets[j].name, planets[j].position.x, planets[j].position.y, planets[j].position.z);
        }
        printf("\n");
    }
    return 0;
}