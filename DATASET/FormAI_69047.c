//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: paranoid
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 9

struct planet {
    char name[10];
    double mass;
    double radius;
    double x;
    double y;
    double vx;
    double vy;
};

double gravitational_force(double m1, double m2, double r);
void simulate_system(struct planet p[]);
void print_system(struct planet p[]);

int main() {
    struct planet solar_system[NUM_PLANETS] = {
        {"Mercury", 3.3e23, 2439.7e3, 0.0, 57.91e9, 0.0, 47.87e3},
        {"Venus", 4.87e24, 6051.8e3, 0.0, 108.2e9, 0.0, 35.0e3},
        {"Earth", 5.97e24, 6371.0e3, 0.0, 149.6e9, 0.0, 29.8e3},
        {"Mars", 6.42e23, 3389.5e3, 0.0, 227.9e9, 0.0, 24.1e3},
        {"Jupiter", 1.90e27, 69911.e3, 0.0, 778.6e9, 0.0, 13.1e3},
        {"Saturn", 5.68e26, 58232.e3, 0.0, 1433.e9, 0.0, 9.7e3},
        {"Uranus", 8.68e25, 25362.e3, 0.0, 2872.e9, 0.0, 6.8e3},
        {"Neptune", 1.02e26, 24622.e3, 0.0, 4495.e9, 0.0, 5.4e3},
        {"Pluto", 1.31e22, 1184.e3, 0.0, 5906.e9, 0.0, 4.7e3}
    };
    
    simulate_system(solar_system);
    print_system(solar_system);

    return 0;
}

double gravitational_force(double m1, double m2, double r) {
    double G = 6.6743e-11;
    return G * m1 * m2 / pow(r, 2);
}

void simulate_system(struct planet p[]) {
    double t_step = 86400.0; // One day in seconds
    double t_max = 365.25 * 86400 * 5; // Five years
    int i, j;
    
    for(double t = 0.0; t < t_max; t += t_step) {
        // Update positions
        for(i = 0; i < NUM_PLANETS; i++) {
            for(j = 0; j < NUM_PLANETS; j++) {
                if(i == j) {
                    continue;
                }
                
                double r = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
                double f = gravitational_force(p[i].mass, p[j].mass, r);
                
                double theta = atan2(p[i].y - p[j].y, p[i].x - p[j].x);
                double fx = -f * cos(theta);
                double fy = -f * sin(theta);
                
                p[i].vx += fx / p[i].mass * t_step;
                p[i].vy += fy / p[i].mass * t_step;
            }
            
            p[i].x += p[i].vx * t_step;
            p[i].y += p[i].vy * t_step;
        }
    }
}

void print_system(struct planet p[]) {
    printf("%-10s %-10s %-10s %-10s\n", "Planet", "X (km)", "Y (km)", "Velocity (km/s)");
    for(int i = 0; i < NUM_PLANETS; i++) {
        printf("%-10s %-10.2f %-10.2f %-10.2f\n", p[i].name, p[i].x / 1e9, p[i].y / 1e9, sqrt(pow(p[i].vx, 2) + pow(p[i].vy, 2)) / 1e3);
    }
}