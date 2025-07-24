//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: accurate
#include<stdio.h>
#include<math.h>

#define G 9.81   // Acceleration due to gravity on Earth's surface in m/s^2

// Structure defining a planet
struct Planet {
    char name[20];
    double mass;
    double radius;
};

// Calculates the gravitational force between two planets
double calculateForce(struct Planet* p1, struct Planet* p2, double distance) {
    double force = (G * p1->mass * p2->mass) / pow(distance, 2);
    return force;
}

// Calculates the gravitational acceleration experienced by a planet due to another planet
double calculateAcceleration(struct Planet* p1, struct Planet* p2, double distance) {
    double force = calculateForce(p1, p2, distance);
    double acceleration = force / p1->mass;
    return acceleration;
}

// Calculates the distance between two planets
double calculateDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
    return distance;
}

// Simulates the behavior of planets under gravity
void simulate(struct Planet* planets, int numPlanets, double timeStep, int numSteps) {
    double x[numPlanets], y[numPlanets], z[numPlanets];  // Arrays to store x, y, z positions of planets
    double vx[numPlanets], vy[numPlanets], vz[numPlanets]; // Arrays to store x, y, z components of velocity of planets
    double ax[numPlanets], ay[numPlanets], az[numPlanets]; // Arrays to store x, y, z components of acceleration of planets
    
    // Initialize the position and velocity arrays of the planets
    for(int i=0; i<numPlanets; i++) {
        x[i] = y[i] = z[i] = 0;
        vx[i] = vy[i] = vz[i] = 0;
    }
    
    // Initialize the acceleration arrays of the planets using mutual gravity
    for(int i=0; i<numPlanets; i++) {
        double axi=0, ayi=0, azi=0;
        for(int j=0; j<numPlanets; j++) {
            if(i==j)
                continue;
            double distance = calculateDistance(x[i], y[i], z[i], x[j], y[j], z[j]);
            double acceleration = calculateAcceleration(&planets[j], &planets[i], distance);
            axi += acceleration * (x[j] - x[i]) / distance;
            ayi += acceleration * (y[j] - y[i]) / distance;
            azi += acceleration * (z[j] - z[i]) / distance;
        }
        ax[i] = axi;
        ay[i] = ayi;
        az[i] = azi;
    }
    
    // Simulate the motion of the planets for numSteps time steps
    for(int step=0; step<numSteps; step++) {
        
        // Update the positions of the planets
        for(int i=0; i<numPlanets; i++) {
            x[i] += vx[i] * timeStep + 0.5 * ax[i] * pow(timeStep, 2);
            y[i] += vy[i] * timeStep + 0.5 * ay[i] * pow(timeStep, 2);
            z[i] += vz[i] * timeStep + 0.5 * az[i] * pow(timeStep, 2);
        }

        // Update the velocities of the planets
        for(int i=0; i<numPlanets; i++) {
            vx[i] += ax[i] * timeStep;
            vy[i] += ay[i] * timeStep;
            vz[i] += az[i] * timeStep;
        }
        
        // Calculate the new acceleration using mutual gravity
        for(int i=0; i<numPlanets; i++) {
            double axi=0, ayi=0, azi=0;
            for(int j=0; j<numPlanets; j++) {
                if(i==j)
                    continue;
                double distance = calculateDistance(x[i], y[i], z[i], x[j], y[j], z[j]);
                double acceleration = calculateAcceleration(&planets[j], &planets[i], distance);
                axi += acceleration * (x[j] - x[i]) / distance;
                ayi += acceleration * (y[j] - y[i]) / distance;
                azi += acceleration * (z[j] - z[i]) / distance;
            }
            ax[i] = axi;
            ay[i] = ayi;
            az[i] = azi;
        }
        
        // Print the positions of the planets
        printf("Time step %d:\n", step+1);
        for(int i=0; i<numPlanets; i++) {
            printf("%s: (%.2f, %.2f, %.2f)\n", planets[i].name, x[i], y[i], z[i]);
        }
        printf("\n");
    }

}

int main() {
    // Define two planets
    struct Planet earth = {"Earth", 5.97e24, 6378.1e3};
    struct Planet moon = {"Moon", 7.34e22, 1737.1e3};
    
    // Simulate the motion of the planets for 10 time steps of 1 day each
    int numSteps = 10;
    double timeStep = 24*60*60; // 1 day in seconds
    struct Planet planets[] = {earth, moon};
    int numPlanets = sizeof(planets)/sizeof(planets[0]);
    simulate(planets, numPlanets, timeStep, numSteps);
    
    return 0;
}