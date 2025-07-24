//FormAI DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81

int main()
{
    // Define variables
    double mass, radius, height, velocity, kineticEnergy, potentialEnergy, totalTime, timeInterval;
    double area, volume, density, buoyantForce, dragForce, netForce, acceleration, terminalVelocity;
    double altitude, initialAltitude, velocityX, velocityY, accelerationX, accelerationY, time;
    double angle, initialVelocity, initialVelocityX, initialVelocityY, displacementX, displacementY;

    // Get inputs
    printf("Enter mass in kg: ");
    scanf("%lf", &mass);

    printf("Enter radius in m: ");
    scanf("%lf", &radius);

    printf("Enter height in m: ");
    scanf("%lf", &height);

    printf("Enter initial velocity in m/s: ");
    scanf("%lf", &velocity);

    printf("Enter angle of launch in radians: ");
    scanf("%lf", &angle);

    printf("Enter time interval in s: ");
    scanf("%lf", &timeInterval);

    printf("Enter total time in s: ");
    scanf("%lf", &totalTime);

    // Calculate area and volume
    area = M_PI * radius * radius;
    volume = area * height;

    // Calculate density
    density = mass / volume;

    // Calculate buoyant force
    buoyantForce = density * volume * GRAVITY;

    // Calculate drag force
    dragForce = 0.5 * density * velocity * velocity * area * 0.47; // 0.47 is drag coefficient for sphere

    // Calculate net force
    netForce = buoyantForce - dragForce - mass * GRAVITY;

    // Calculate acceleration
    acceleration = netForce / mass;

    // Calculate terminal velocity
    terminalVelocity = sqrt((2 * mass * GRAVITY) / (density * area * 0.47));

    // Print results
    printf("Area: %lf m^2\n", area);
    printf("Volume: %lf m^3\n", volume);
    printf("Density: %lf kg/m^3\n", density);
    printf("Buoyant Force: %lf N\n", buoyantForce);
    printf("Drag Force: %lf N\n", dragForce);
    printf("Net Force: %lf N\n", netForce);
    printf("Acceleration: %lf m/s^2\n", acceleration);
    printf("Terminal Velocity: %lf m/s\n", terminalVelocity);

    // Calculate and print kinetic and potential energy
    kineticEnergy = 0.5 * mass * velocity * velocity;
    potentialEnergy = mass * GRAVITY * height;
    printf("Kinetic Energy: %lf J\n", kineticEnergy);
    printf("Potential Energy: %lf J\n", potentialEnergy);

    // Projectile motion simulation
    initialVelocity = velocity;
    initialVelocityX = initialVelocity * cos(angle);
    initialVelocityY = initialVelocity * sin(angle);
    initialAltitude = 0;
    displacementX = 0;
    displacementY = initialAltitude;

    for (time = 0; time <= totalTime; time += timeInterval) {

        velocityX = initialVelocityX;
        accelerationX = 0;
        velocityY = initialVelocityY + (accelerationY * timeInterval);
        accelerationY = GRAVITY;
        altitude = initialAltitude + (initialVelocityY * timeInterval) + (0.5 * accelerationY * timeInterval * timeInterval);

        printf("Time: %lf s, Altitude: %lf m, DisplacementX: %lf m, DisplacementY: %lf m\n", time, altitude, displacementX, displacementY);

        initialVelocityY = velocityY;
        initialAltitude = altitude;
    }

    return 0;
}