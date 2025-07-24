//FormAI DATASET v1.0 Category: Physics simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.6743e-11
#define EARTH_RADIUS 6.371e6
#define EARTH_MASS 5.972e24
#define EARTH_DENSITY 5515

struct Vector3D {
    double x;
    double y;
    double z;
};

double calcDistance(struct Vector3D pos1, struct Vector3D pos2);
double calcForce(double mass1, double mass2, double distance);
double calcPressure(double mass, double volume);
double calcDensity(double mass, double radius);

int main() {
    struct Vector3D earthPos = {0, 0, 0};
    struct Vector3D moonPos = {384400000, 0, 0};
    
    double earthForce, moonForce, earthMoonDistance, earthMoonForce;
    double earthMass = EARTH_MASS;
    double moonMass = 7.3477e22;
    double earthDensity = EARTH_DENSITY;
    double earthRadius = EARTH_RADIUS;
    double moonDensity = 3340;
    double moonRadius = 1737400;
    
    earthMoonDistance = calcDistance(earthPos, moonPos);
    earthForce = calcForce(earthMass, moonMass, earthMoonDistance);
    moonForce = calcForce(moonMass, earthMass, earthMoonDistance);
    
    printf("The gravitational force between Earth and Moon is %.2f N\n", earthForce);
    printf("The gravitational force between Moon and Earth is %.2f N\n", moonForce);
    
    earthMoonForce = sqrt(pow(earthForce, 2) + pow(moonForce, 2));
    printf("The total force between Earth and Moon is %.2f N\n", earthMoonForce);
    
    double earthVolume = 4.0/3 * M_PI * pow(earthRadius, 3);
    double moonVolume = 4.0/3 * M_PI * pow(moonRadius, 3);
    
    double earthDensityCalc = calcDensity(earthMass, earthRadius);
    double moonDensityCalc = calcDensity(moonMass, moonRadius);
    
    double earthPressure = calcPressure(earthMass, earthVolume);
    double moonPressure = calcPressure(moonMass, moonVolume);
    
    printf("The density of Earth is %.2f kg/m^3\n", earthDensityCalc);
    printf("The density of Moon is %.2f kg/m^3\n", moonDensityCalc);
    
    printf("The pressure on Earth's surface is %.2f Pa\n", earthPressure);
    printf("The pressure on Moon's surface is %.2f Pa\n", moonPressure);
    
    return 0;
}

double calcDistance(struct Vector3D pos1, struct Vector3D pos2) {
    double x = pow(pos1.x - pos2.x, 2);
    double y = pow(pos1.y - pos2.y, 2);
    double z = pow(pos1.z - pos2.z, 2);
    return sqrt(x + y + z);
}

double calcForce(double mass1, double mass2, double distance) {
    return GRAV_CONST * (mass1 * mass2) / pow(distance, 2);
}

double calcPressure(double mass, double volume) {
    double surfaceArea = 4 * M_PI * pow(EARTH_RADIUS, 2);
    return calcForce(mass, EARTH_MASS, EARTH_RADIUS) / surfaceArea;
}

double calcDensity(double mass, double radius) {
    return mass / (4.0/3 * M_PI * pow(radius, 3));
}