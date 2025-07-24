//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

typedef struct celestial_body{
    char name[20];
    double mass; // in kg
    double diameter; // in km
    double x_pos; // in km
    double y_pos; // in km
    double x_vel; // in km/s
    double y_vel; // in km/s
} CelestialBody;

CelestialBody* initializeSun();
CelestialBody* initializeMercury();
CelestialBody* initializeVenus();
CelestialBody* initializeEarth();
CelestialBody* initializeMars();
CelestialBody* initializeJupiter();
CelestialBody* initializeSaturn();
CelestialBody* initializeUranus();
CelestialBody* initializeNeptune();

double calculateDistance(CelestialBody* body1, CelestialBody* body2);
double calculateGravitationalForce(CelestialBody* body1, CelestialBody* body2);
void updateVelocityAndPosition(CelestialBody* body, double forceX, double forceY, double timeStep);

int main(){
    CelestialBody* sun = initializeSun();
    CelestialBody* mercury = initializeMercury();
    CelestialBody* venus = initializeVenus();
    CelestialBody* earth = initializeEarth();
    CelestialBody* mars = initializeMars();
    CelestialBody* jupiter = initializeJupiter();
    CelestialBody* saturn = initializeSaturn();
    CelestialBody* uranus = initializeUranus();
    CelestialBody* neptune = initializeNeptune();

    CelestialBody* celestialBodies[9] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};

    double timeStep = 0.1; // in days
    double simulationDuration = 365*10; // in days

    int numSteps = simulationDuration / timeStep;

    for(int i = 1; i <= numSteps; i++){
        // update each celestial body's position and velocity
        for(int j = 0; j < 9; j++){
            CelestialBody* body1 = celestialBodies[j];
            double forceXTotal = 0;
            double forceYTotal = 0;
            for(int k = 0; k < 9; k++){
                if(j == k){
                    continue;
                }
                CelestialBody* body2 = celestialBodies[k];
                double distance = calculateDistance(body1, body2);
                double force = calculateGravitationalForce(body1, body2);
                double forceX = force * (body2->x_pos - body1->x_pos) / distance;
                double forceY = force * (body2->y_pos - body1->y_pos) / distance;
                forceXTotal += forceX;
                forceYTotal += forceY;
            }
            updateVelocityAndPosition(body1, forceXTotal, forceYTotal, timeStep);
        }
    }

    // print final positions
    for(int i = 0; i < 9; i++){
        CelestialBody* body = celestialBodies[i];
        printf("%s: (%.2f, %.2f)\n", body->name, body->x_pos, body->y_pos);
    }

    // free memory
    for(int i = 0; i < 9; i++){
        free(celestialBodies[i]);
    }

    return 0;
}

CelestialBody* initializeSun(){
    CelestialBody* sun = malloc(sizeof(CelestialBody));
    sun->mass = 1.989 * pow(10, 30);
    sun->diameter = 1392000;
    sun->x_pos = 0;
    sun->y_pos = 0;
    sun->x_vel = 0;
    sun->y_vel = 0;
    sprintf(sun->name, "Sun");
    return sun;
}

CelestialBody* initializeMercury(){
    CelestialBody* mercury = malloc(sizeof(CelestialBody));
    mercury->mass = 3.285 * pow(10, 23);
    mercury->diameter = 4878;
    mercury->x_pos = -46 * pow(10, 6);
    mercury->y_pos = 0;
    mercury->x_vel = 0;
    mercury->y_vel = 58.98;
    sprintf(mercury->name, "Mercury");
    return mercury;
}

CelestialBody* initializeVenus(){
    CelestialBody* venus = malloc(sizeof(CelestialBody));
    venus->mass = 4.867 * pow(10, 24);
    venus->diameter = 12104;
    venus->x_pos = 107.48 * pow(10, 6);
    venus->y_pos = 0;
    venus->x_vel = 0;
    venus->y_vel = -35.02;
    sprintf(venus->name, "Venus");
    return venus;
}

CelestialBody* initializeEarth(){
    CelestialBody* earth = malloc(sizeof(CelestialBody));
    earth->mass = 5.972 * pow(10, 24);
    earth->diameter = 12756;
    earth->x_pos = 147.09 * pow(10, 6);
    earth->y_pos = 0;
    earth->x_vel = 0;
    earth->y_vel = 29.78;
    sprintf(earth->name, "Earth");
    return earth; 
}

CelestialBody* initializeMars(){
    CelestialBody* mars = malloc(sizeof(CelestialBody));
    mars->mass = 6.39 * pow(10, 23);
    mars->diameter = 6792;
    mars->x_pos = -206.62 * pow(10, 6);
    mars->y_pos = 0;
    mars->x_vel = 0;
    mars->y_vel = -24.077;
    sprintf(mars->name, "Mars");
    return mars;
}

CelestialBody* initializeJupiter(){
    CelestialBody* jupiter = malloc(sizeof(CelestialBody));
    jupiter->mass = 1.898 * pow(10, 27);
    jupiter->diameter = 142984;
    jupiter->x_pos = -740.52 * pow(10, 6);
    jupiter->y_pos = 0;
    jupiter->x_vel = 0;
    jupiter->y_vel = -13.07;
    sprintf(jupiter->name, "Jupiter");
    return jupiter;
}

CelestialBody* initializeSaturn(){
    CelestialBody* saturn = malloc(sizeof(CelestialBody));
    saturn->mass = 5.683 * pow(10, 26);
    saturn->diameter = 120536;
    saturn->x_pos = 1349.83 * pow(10, 6);
    saturn->y_pos = 0;
    saturn->x_vel = 0;
    saturn->y_vel = 9.672;
    sprintf(saturn->name, "Saturn");
    return saturn;
}

CelestialBody* initializeUranus(){
    CelestialBody* uranus = malloc(sizeof(CelestialBody));
    uranus->mass = 8.681 * pow(10, 25);
    uranus->diameter = 51118;
    uranus->x_pos = -2741.3 * pow(10, 6);
    uranus->y_pos = 0;
    uranus->x_vel = 0;
    uranus->y_vel = -6.835;
    sprintf(uranus->name, "Uranus");
    return uranus;
}

CelestialBody* initializeNeptune(){
    CelestialBody* neptune = malloc(sizeof(CelestialBody));
    neptune->mass = 1.024 * pow(10, 26);
    neptune->diameter = 49528;
    neptune->x_pos = 4454.9 * pow(10, 6);
    neptune->y_pos = 0;
    neptune->x_vel = 0;
    neptune->y_vel = 5.477;
    sprintf(neptune->name, "Neptune");
    return neptune;
}

double calculateDistance(CelestialBody* body1, CelestialBody* body2){
    double xDiff = body2->x_pos - body1->x_pos;
    double yDiff = body2->y_pos - body1->y_pos;
    double distance = sqrt(xDiff*xDiff + yDiff*yDiff);
    return distance;
}

double calculateGravitationalForce(CelestialBody* body1, CelestialBody* body2){
    double distance = calculateDistance(body1, body2);
    double gravitationalForce = (6.67*pow(10,-11) * body1->mass * body2->mass) / (distance*distance);
    return gravitationalForce;
}

void updateVelocityAndPosition(CelestialBody* body, double forceX, double forceY, double timeStep){
    double accelerationX = forceX / body->mass;
    double accelerationY = forceY / body->mass;
    body->x_vel += accelerationX * timeStep * 24 * 3600;
    body->y_vel += accelerationY * timeStep * 24 * 3600;
    body->x_pos += body->x_vel * timeStep * 24 * 3600;
    body->y_pos += body->y_vel * timeStep * 24 * 3600;
}