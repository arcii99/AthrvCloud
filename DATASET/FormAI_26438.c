//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define G 9.81

typedef struct {
    double mass;
    double radius;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
} Planet;

double calculateDistance(Planet planet1, Planet planet2) {
    return sqrt(pow(planet2.x_pos - planet1.x_pos, 2) + pow(planet2.y_pos - planet1.y_pos, 2));
}

double calculateGravity(Planet planet1, Planet planet2) {
    return (G * planet1.mass * planet2.mass) / pow(calculateDistance(planet1, planet2), 2);
}

double calculateAcceleration(double gravity, Planet planet) {
    return gravity / planet.mass;
}

void updateVelocity(Planet *planet, double acceleration, double delta_time) {
    planet->x_vel += acceleration * delta_time;
    planet->y_vel += acceleration * delta_time;
}

void updatePosition(Planet *planet, double delta_time) {
    planet->x_pos += planet->x_vel * delta_time;
    planet->y_pos += planet->y_vel * delta_time;
}

void simulateGravity(Planet *planet, int n_planets, double delta_time, int n_steps) {
    for(int step = 0; step < n_steps; step++) {
        for(int i = 0; i < n_planets; i++) {
            Planet current_planet = planet[i];
            double total_gravity = 0.0;
            
            for(int j = 0; j < n_planets; j++) {
                if(i != j) {
                    Planet other_planet = planet[j];
                    double gravity = calculateGravity(current_planet, other_planet);
                    total_gravity += gravity;
                    
                    double acceleration = calculateAcceleration(gravity, current_planet);
                    updateVelocity(&planet[i], acceleration, delta_time);
                }
            }
            
            double acceleration = calculateAcceleration(total_gravity, current_planet);
            updateVelocity(&planet[i], acceleration, delta_time);
            updatePosition(&planet[i], delta_time);
        }
    }
}

int main() {
    Planet earth = {5.9736E24, 6371E3, 0.0, 0.0, 0.0, 0.0};
    Planet moon = {7.342E22, 1737E3, 3.844E8, 0.0, 0.0, 1022.0};
    
    Planet planets[] = {earth, moon};
    
    int n_planets = 2;
    double delta_time = 0.1;
    int n_steps = 1000;
    
    simulateGravity(planets, n_planets, delta_time, n_steps);
    
    for(int i = 0; i < n_planets; i++) {
        printf("Planet %d\n", i);
        printf("  x_pos: %f\n", planets[i].x_pos);
        printf("  y_pos: %f\n", planets[i].y_pos);
        printf("  x_vel: %f\n", planets[i].x_vel);
        printf("  y_vel: %f\n", planets[i].y_vel);
    }
    
    return 0;
}