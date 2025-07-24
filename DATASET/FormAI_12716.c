//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: imaginative
#include <stdio.h>

#define NUM_PLANETS 8

struct Planet {
    char name[20];
    double mass; //in kg
    double distance; //in km
    double orbital_period; //in Earth days
};

void simulate_year(struct Planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double angle = planets[i].orbital_period / 365.25 * 2 * 3.14159;
        planets[i].distance = planets[i].distance * cos(angle);
    }
}

int main() {
    struct Planet planets[NUM_PLANETS] = {
        {"Mercury", 3.285e23, 7.22e7, 88.0},
        {"Venus", 4.867e24, 1.08e8, 224.7},
        {"Earth", 5.972e24, 1.5e8, 365.25},
        {"Mars", 6.39e23, 2.28e8, 687.0},
        {"Jupiter", 1.898e27, 7.78e8, 4331.0},
        {"Saturn", 5.683e26, 1.43e9, 10747.0},
        {"Uranus", 8.681e25, 2.87e9, 30589.0},
        {"Neptune", 1.024e26, 4.5e9, 59800.0},
    };
    
    int years;
    printf("Enter the number of years to simulate: ");
    scanf("%d", &years);
    
    for (int i = 0; i < years; i++) {
        simulate_year(planets);
    }
    
    printf("\n\nSimulation Results:\n");
    printf("Planet\t\tDistance from Sun (km)\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%-10s\t%.2lf\n", planets[i].name, planets[i].distance);
    }
    
    return 0;
}