//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define G 6.67384e-11     // Gravitational constant
#define PI 3.14159265359  // Pi constant
#define DAY 86400         // Number of seconds in a day

// Structure defining a celestial body
typedef struct {
    char name[20];
    double mass;
    double radius;
    double position[3];  // x, y, and z coordinates
    double velocity[3];  // vx, vy, and vz components
    double acceleration[3];  // ax, ay, and az components
} body;

// Function to calculate the distance between two celestial bodies
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}

// Function to calculate the gravitational force between two celestial bodies
double force(double m1, double m2, double dist) {
    return (G * m1 * m2) / pow(dist, 2);
}

int main() {
    // Creating objects for the Sun and the planets
    body sun = {"Sun", 1.989e30, 696340000, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    body mercury = {"Mercury", 3.285e23, 2440000, {0, -57909000000, 0}, {47000, 0, 0}, {0, 0, 0}};
    body venus = {"Venus", 4.87e24, 6052000, {0, -108200000000, 0}, {35000, 0, 0}, {0, 0, 0}};
    body earth = {"Earth", 5.97e24, 6378000, {0, -149600000000, 0}, {30000, 0, 0}, {0, 0, 0}};
    body mars = {"Mars", 6.39e23, 3396000, {0, -227940000000, 0}, {24000, 0, 0}, {0, 0, 0}};
    body jupiter = {"Jupiter", 1.898e27, 71492000, {0, -778369000000, 0}, {13000, 0, 0}, {0, 0, 0}};
    body saturn = {"Saturn", 5.68e26, 60268000, {0, -1427034000000, 0}, {9000, 0, 0}, {0, 0, 0}};
    body uranus = {"Uranus", 8.68e25, 25559000, {0, -2870660000000, 0}, {6835, 0, 0}, {0, 0, 0}};
    body neptune = {"Neptune", 1.02e26, 24746000, {0, -4498252900000, 0}, {5477, 0, 0}, {0, 0, 0}};
    
    // Array of all the celestial bodies
    body bodies[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};
    
    // Simulation time
    double time = 0;
    double end_time = 365 * 100;  // 100 Earth years
    
    // Time step
    double dt = DAY;
    
    // Output interval
    double out_interval = 1;  // Output every day
    
    // Open data file for writing
    FILE *fp;
    fp = fopen("solarsystem.csv", "w");
    fprintf(fp, "Time (days),Sun x,Sun y,Sun z,Mercury x,Mercury y,Mercury z,Venus x,Venus y,Venus z,Earth x,Earth y,Earth z,Mars x,Mars y,Mars z,Jupiter x,Jupiter y,Jupiter z,Saturn x,Saturn y,Saturn z,Uranus x,Uranus y,Uranus z,Neptune x,Neptune y,Neptune z\n");
    
    // Simulation loop
    while (time <= end_time) {
        // Output current state
        if (fmod(time, out_interval) == 0) {
            printf("Time: %f\n", time/DAY);
            for (int i = 0; i < 9; i++) {
                printf("%s - Position: (%f, %f, %f)\n", bodies[i].name, bodies[i].position[0], bodies[i].position[1], bodies[i].position[2]);
            }
            printf("\n");
            
            // Write data to file
            fprintf(fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", time/DAY, sun.position[0], sun.position[1], sun.position[2], mercury.position[0], mercury.position[1], mercury.position[2], venus.position[0], venus.position[1], venus.position[2], earth.position[0], earth.position[1], earth.position[2], mars.position[0], mars.position[1], mars.position[2], jupiter.position[0], jupiter.position[1], jupiter.position[2], saturn.position[0], saturn.position[1], saturn.position[2], uranus.position[0], uranus.position[1], uranus.position[2], neptune.position[0], neptune.position[1], neptune.position[2]);
        }
        
        // Update acceleration for each celestial body
        for (int i = 0; i < 9; i++) {
            double ax = 0, ay = 0, az = 0;
            
            for (int j = 0; j < 9; j++) {
                if (i == j) continue;
                
                double dist = distance(bodies[i].position[0], bodies[i].position[1], bodies[i].position[2], bodies[j].position[0], bodies[j].position[1], bodies[j].position[2]);
                
                double f = force(bodies[i].mass, bodies[j].mass, dist);
                
                ax += f * (bodies[j].position[0] - bodies[i].position[0]) / dist / bodies[i].mass;
                ay += f * (bodies[j].position[1] - bodies[i].position[1]) / dist / bodies[i].mass;
                az += f * (bodies[j].position[2] - bodies[i].position[2]) / dist / bodies[i].mass;
            }
            
            bodies[i].acceleration[0] = ax;
            bodies[i].acceleration[1] = ay;
            bodies[i].acceleration[2] = az;
        }
        
        // Update velocity and position for each celestial body
        for (int i = 0; i < 9; i++) {
            bodies[i].velocity[0] += bodies[i].acceleration[0] * dt;
            bodies[i].velocity[1] += bodies[i].acceleration[1] * dt;
            bodies[i].velocity[2] += bodies[i].acceleration[2] * dt;
            
            bodies[i].position[0] += bodies[i].velocity[0] * dt;
            bodies[i].position[1] += bodies[i].velocity[1] * dt;
            bodies[i].position[2] += bodies[i].velocity[2] * dt;
        }
        
        // Increment time
        time += dt;
    }
    
    // Close data file
    fclose(fp);
    
    return 0;
}