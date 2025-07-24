//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include<stdio.h>
#include<math.h>

// Constants
#define G 6.6743 * pow(10,-11)
#define TIME_STEPS 1000
#define DELTA_T 1000

// Structures
struct body{
    double x;
    double y;
    double z;
    double mass;
    double vx;
    double vy;
    double vz;
};

// Function prototypes
void update_velocity(struct body* b1, struct body* b2, double* ax, double* ay, double* az);
void update_position(struct body* b, double ax, double ay, double az);
double distance(struct body* b1, struct body* b2);
double acceleration(double distance, double mass1, double mass2);

// Main function
int main(){
    struct body planet1, planet2, planet3;
    double ax1, ay1, az1, ax2, ay2, az2, ax3, ay3, az3;
    int i;

    // Initializing the planets
    planet1.x = 100000;
    planet1.y = 0;
    planet1.z = 0;
    planet1.mass = 5.97 * pow(10,24);
    planet1.vx = 0;
    planet1.vy = 10000;
    planet1.vz = 0;

    planet2.x = -100000;
    planet2.y = 0;
    planet2.z = 0;
    planet2.mass = 5.97 * pow(10,24);
    planet2.vx = 0;
    planet2.vy = -10000;
    planet2.vz = 0;

    planet3.x = 0;
    planet3.y = 0;
    planet3.z = 50000;
    planet3.mass = 6.39 * pow(10,23);
    planet3.vx = 5000;
    planet3.vy = 0;
    planet3.vz = 0;

    // Running simulation
    for(i = 0; i < TIME_STEPS; i++){
        // Calculating acceleration
        ax1 = ay1 = az1 = ax2 = ay2 = az2 = ax3 = ay3 = az3 = 0;
        update_velocity(&planet1, &planet2, &ax1, &ay1, &az1);
        update_velocity(&planet1, &planet3, &ax1, &ay1, &az1);
        update_velocity(&planet2, &planet1, &ax2, &ay2, &az2);
        update_velocity(&planet2, &planet3, &ax2, &ay2, &az2);
        update_velocity(&planet3, &planet1, &ax3, &ay3, &az3);
        update_velocity(&planet3, &planet2, &ax3, &ay3, &az3);

        // Updating positions
        update_position(&planet1, ax1, ay1, az1);
        update_position(&planet2, ax2, ay2, az2);
        update_position(&planet3, ax3, ay3, az3);
    }

    // Printing final positions
    printf("Planet 1: %f %f %f\n", planet1.x, planet1.y, planet1.z);
    printf("Planet 2: %f %f %f\n", planet2.x, planet2.y, planet2.z);
    printf("Planet 3: %f %f %f\n", planet3.x, planet3.y, planet3.z);

    return 0;
}

// Function to calculate acceleration and update velocity
void update_velocity(struct body* b1, struct body* b2, double* ax, double* ay, double* az){
    double dist = distance(b1, b2);
    double acc = acceleration(dist, b1->mass, b2->mass);
    *ax += acc * (b2->x - b1->x) / dist;
    *ay += acc * (b2->y - b1->y) / dist;
    *az += acc * (b2->z - b1->z) / dist;
    b1->vx += (*ax) * DELTA_T;
    b1->vy += (*ay) * DELTA_T;
    b1->vz += (*az) * DELTA_T;
}

// Function to update position
void update_position(struct body* b, double ax, double ay, double az){
    b->x += b->vx * DELTA_T + 0.5 * ax * pow(DELTA_T, 2);
    b->y += b->vy * DELTA_T + 0.5 * ay * pow(DELTA_T, 2);
    b->z += b->vz * DELTA_T + 0.5 * az * pow(DELTA_T, 2);
}

// Function to calculate distance between two planets
double distance(struct body* b1, struct body* b2){
    return sqrt(pow((b1->x - b2->x), 2) + pow((b1->y - b2->y), 2) + pow((b1->z - b2->z), 2));
}

// Function to calculate gravitational acceleration between two planets
double acceleration(double distance, double mass1, double mass2){
    return G * mass1 * mass2 / pow(distance, 2);
}