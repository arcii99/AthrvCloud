//FormAI DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main() {
    double mass, velocity, momentum;
    const double SPEED_OF_LIGHT = 299792458;
    const double PI = acos(-1.0);
    const double GRAVITY_ACCELERATION = 9.81;
    
    printf("Welcome to Sherlock Holmes' physics simulation program!\n");
    printf("Please enter the mass and velocity of the object.\n");
    scanf("%lf%lf", &mass, &velocity);
    
    momentum = mass * velocity;
    printf("The object's momentum is %.2lf.\n", momentum);
    
    double force = momentum / (1.0 / 1000000000.0);
    printf("The exerted force on the object when decelerating to 0 within 1 nanosecond is %.2lf N.\n", force);
    
    double distance = (velocity * velocity) / (2 * GRAVITY_ACCELERATION);
    printf("If the object was thrown vertically upward, it would reach %.2lf meters high before falling back to Earth.\n", distance);
    
    double kinetic_energy = (mass * pow(velocity, 2)) / 2;
    printf("The object's kinetic energy is %.2lf Joules.\n", kinetic_energy);
    
    double relativistic_mass = mass / sqrt(1 - pow((velocity / SPEED_OF_LIGHT), 2));
    printf("At this velocity, the object's relativistic mass is %.2lf kg.\n", relativistic_mass);
    
    double arc_length = 2 * PI * distance / 4;
    printf("If the object was thrown at a 45-degree angle, it would travel a quarter circle's arc length equivalent to %.2lf meters.\n", arc_length);
    
    return 0;
}