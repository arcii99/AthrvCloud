//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G_CONST 6.6743e-11 //Gravitational constant

struct planet {
    double x_pos;
    double y_pos;
    double mass;
    double x_vel;
    double y_vel;
    double x_acc;
    double y_acc;
};

struct planet create_planet(double x, double y, double m, double vx, double vy) {
    struct planet p;
    p.x_pos = x;
    p.y_pos = y;
    p.mass = m;
    p.x_vel = vx;
    p.y_vel = vy;
    p.x_acc = 0;
    p.y_acc = 0;
    return p;
}

double calculate_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

void calculate_gravity(struct planet *p1, struct planet *p2) {
    double r = calculate_distance(p1->x_pos, p1->y_pos, p2->x_pos, p2->y_pos);
    double f = G_CONST * p1->mass * p2->mass / (r*r);
    double a = f / p1->mass;
    double ax = a * (p2->x_pos - p1->x_pos) / r;
    double ay = a * (p2->y_pos - p1->y_pos) / r;
    p1->x_acc += ax;
    p1->y_acc += ay;
}

void update_velocity(struct planet *p, double dt) {
    p->x_vel += p->x_acc * dt;
    p->y_vel += p->y_acc * dt;
}

void update_position(struct planet *p, double dt) {
    p->x_pos += p->x_vel * dt;
    p->y_pos += p->y_vel * dt;
}

int main() {
    srand(time(NULL)); //Seed random generator with current time
    
    int num_planets = 5;
    struct planet planets[num_planets];
    
    for(int i=0; i<num_planets; i++) {
        double x = rand() % 100 + 1;
        double y = rand() % 100 + 1;
        double m = rand() % 1000 + 1;
        double vx = rand() % 10 + 1;
        double vy = rand() % 10 + 1;
        planets[i] = create_planet(x, y, m, vx, vy);
    }
    
    double dt = 0.01; //Timestep
    double t = 0; //Simulation time
    int num_steps = 10000; //Number of simulation steps
    
    for(int i=0; i<num_steps; i++) {
        //Calculate gravitational forces
        for(int j=0; j<num_planets; j++) {
            for(int k=j+1; k<num_planets; k++) {
                calculate_gravity(&planets[j], &planets[k]);
            }
        }
        
        //Update velocities and positions
        for(int j=0; j<num_planets; j++) {
            update_velocity(&planets[j], dt);
            update_position(&planets[j], dt);
            
            //Reset acceleration
            planets[j].x_acc = 0;
            planets[j].y_acc = 0;
        }
        
        t += dt;
    }
    
    //Print final planet positions
    printf("Final planet positions:\n");
    for(int i=0; i<num_planets; i++) {
        printf("Planet %d: x=%.2f y=%.2f\n", i+1, planets[i].x_pos, planets[i].y_pos);
    }
    
    return 0;
}