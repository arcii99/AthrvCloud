//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: puzzling
#include<stdio.h>
#include<math.h>

int main(){
    double G = 6.6743 * pow(10, -11);

    double simTime = 365.0 * 24.0 * 3600.0; //1 year in seconds
    double timeStep = 1000.0; //1 second

    double sunMass = 1.98855 * pow(10, 30);
    double earthMass = 5.97219 * pow(10, 24);
    double moonMass = 7.342 * pow(10, 22);

    double sunRadius = 696340000;
    double earthRadius = 6371000;
    double moonRadius = 1737100;

    double earthVelocity = 29780;
    double moonVelocity = 1023;

    double distanceEarthSun = 149600000000;
    double distanceMoonEarth = 384400000;

    double earthAngle = 0;
    double moonAngle = 0;

    int i;
    double earthX, earthY, moonX, moonY;
    double earthVelocityX, earthVelocityY, moonVelocityX, moonVelocityY;
    double earthAccelerationX, earthAccelerationY, moonAccelerationX, moonAccelerationY;

    for(i=0; i<simTime/timeStep; i++){
        earthAngle = i * (2 * M_PI) / (simTime/timeStep);
        moonAngle = earthAngle * 13.0;

        earthX = distanceEarthSun * cos(earthAngle);
        earthY = distanceEarthSun * sin(earthAngle);

        moonX = earthX + (distanceMoonEarth * cos(moonAngle));
        moonY = earthY + (distanceMoonEarth * sin(moonAngle));

        double earthDistance = sqrt(pow(earthX, 2) + pow(earthY, 2));
        double moonDistance = sqrt(pow(moonX-earthX, 2) + pow(moonY-earthY, 2));

        double earthForce = G * (earthMass * sunMass) / pow(earthDistance, 2);
        double moonForce = G * (moonMass * earthMass) / pow(moonDistance, 2);

        double earthAcceleration = earthForce / earthMass;
        double moonAcceleration = moonForce / moonMass;

        earthAccelerationX = earthAcceleration * (earthX / earthDistance);
        earthAccelerationY = earthAcceleration * (earthY / earthDistance);
        moonAccelerationX = moonAcceleration * ((moonX - earthX) / moonDistance);
        moonAccelerationY = moonAcceleration * ((moonY - earthY) / moonDistance);

        earthVelocityX += earthAccelerationX * timeStep;
        earthVelocityY += earthAccelerationY * timeStep;
        moonVelocityX += moonAccelerationX * timeStep;
        moonVelocityY += moonAccelerationY * timeStep;

        earthX += earthVelocityX * timeStep;
        earthY += earthVelocityY * timeStep;
        moonX += moonVelocityX * timeStep;
        moonY += moonVelocityY * timeStep;

        printf("Position of Earth (x,y) at time %i: (%f,%f) meters from center of sun\n", i, earthX, earthY);
        printf("Position of Moon (x,y) at time %i: (%f,%f) meters from center of earth\n", i, moonX-earthX, moonY-earthY);

        if(sqrt(pow(earthX, 2) + pow(earthY, 2)) <= sunRadius){
            printf("The Earth has collided with the sun and has exploded. The Solar System is no more.\n");
            break;
        }

        if(sqrt(pow(moonX-earthX, 2) + pow(moonY-earthY, 2)) <= earthRadius + moonRadius){
            printf("The Moon has collided with the Earth and the moon's debris is now orbiting the Earth.\n");
            moonMass = 0;
        }
    }

    printf("The simulation has ended. The Solar System will continue to function normally.\n");

    return 0;
}