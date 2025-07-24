//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define G 6.674e-11                   // Universal Gravitational Constant
#define DELTA_T 3600                   // Time step in seconds

struct planet {
    char name[20];
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
};

void initialize_planet(struct planet *p, char name[20], double mass, 
            double position[3], double velocity[3]) {
    int i;
    for(i=0; i<3; i++) {
        p->position[i] = position[i];
        p->velocity[i] = velocity[i];
        p->acceleration[i] = 0;
    }
    p->mass = mass;
    strcpy(p->name, name);
}

double calculate_separation(double r_i[], double r_j[]) {
    double separation = 0;
    int i;
    for(i=0; i<3; i++)
        separation += pow((r_i[i]-r_j[i]), 2);
    return sqrt(separation);
}

void calculate_acceleration(struct planet *p, struct planet *q) {
    double r[3], r_mag;
    int i;
    for(i=0; i<3; i++) r[i] = q->position[i] - p->position[i];
    r_mag = calculate_separation(p->position, q->position);
    double acceleration_magnitude = (G*q->mass) / pow(r_mag, 2);
    for(i=0; i<3; i++)
        p->acceleration[i] += acceleration_magnitude*(r[i]/r_mag);
}

void update_velocity(struct planet *p) {
    int i;
    for(i=0; i<3; i++)
        p->velocity[i] += p->acceleration[i]*DELTA_T;
}

void update_position(struct planet *p) {
    int i;
    for(i=0; i<3; i++)
        p->position[i] += p->velocity[i]*DELTA_T;
}

int main() {
    struct planet planets[3];
    double pos_mercury[3] = {46e9, 0, 0};
    double pos_earth[3] = {147e9, 0, 0};
    double pos_mars[3] = {207e9, 0, 0};
    double vel_earth[3] = {0, 29.29e3, 0};
    double vel_mercury[3] = {0, 47.87e3, 0};
    double vel_mars[3] = {0, 24.077e3, 0};
   
    initialize_planet(&planets[0], "Mercury", 3.3e23, pos_mercury, vel_mercury);
    initialize_planet(&planets[1], "Earth", 5.97e24, pos_earth, vel_earth);
    initialize_planet(&planets[2], "Mars", 6.42e23, pos_mars, vel_mars);
    
    int i, j, steps = 365*24*3600/DELTA_T;
    for(i=0; i<steps; i++) {
        for(j=0; j<3; j++) {
            planets[j].acceleration[0] = 0;
            planets[j].acceleration[1] = 0;
            planets[j].acceleration[2] = 0;
            
            int k;
            for(k=0; k<3; k++) {
                if(j==k) continue;
                calculate_acceleration(&planets[j], &planets[k]);
            }
        }
        for(j=0; j<3; j++) {
            update_velocity(&planets[j]);
            update_position(&planets[j]);
        }
    }
    
    for(i=0; i<3; i++)
        printf("%s has final position: (%g, %g, %g)\n", planets[i].name,
            planets[i].position[0], planets[i].position[1], planets[i].position[2]);

    return 0;
}