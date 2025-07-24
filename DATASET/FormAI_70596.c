//FormAI DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

float computeDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

float computeForce(float mass1, float mass2, float distance) {
    float G = 6.67408 * pow(10, -11);
    return (G * mass1 * mass2) / pow(distance, 2);
}

float computeAcceleration(float force, float mass) {
    return force / mass;
}

float computeVelocity(float acceleration, float time) {
    return acceleration * time;
}

float computePosition(float initialPosition, float initialVelocity, float acceleration, float time, float theta) {
    float xComponent = initialVelocity * cos(theta);
    float yComponent = initialVelocity * sin(theta) - (0.5 * 9.81 * pow(time, 2));

    return initialPosition + (xComponent * time) + (0.5 * acceleration * pow(time, 2));
}

int main() {
    float m1, m2, x1, y1, x2, y2;
    printf("Enter details of first object:\n");
    printf("Enter mass: ");
    scanf("%f", &m1);
    printf("Enter x-coordinate: ");
    scanf("%f", &x1);
    printf("Enter y-coordinate: ");
    scanf("%f", &y1);

    printf("Enter details of second object:\n");
    printf("Enter mass: ");
    scanf("%f", &m2);
    printf("Enter x-coordinate: ");
    scanf("%f", &x2);
    printf("Enter y-coordinate: ");
    scanf("%f", &y2);

    float distance = computeDistance(x1, y1, x2, y2);
    printf("Distance between objects: %.2f meters\n", distance);

    float force = computeForce(m1, m2, distance);
    printf("Force between objects: %.2f newtons\n", force);

    printf("Enter mass of third object: ");
    float m3;
    scanf("%f", &m3);

    float acceleration = computeAcceleration(force, m3);
    printf("Acceleration on third object: %.2f m/s^2\n", acceleration);

    printf("Enter time: ");
    float time;
    scanf("%f", &time);

    float velocity = computeVelocity(acceleration, time);
    printf("Velocity of third object after %.2f seconds: %.2f m/s\n", time, velocity);

    printf("Enter initial position of third object: ");
    float initialPosition;
    scanf("%f", &initialPosition);

    printf("Enter initial velocity of third object: ");
    float initialVelocity;
    scanf("%f", &initialVelocity);

    printf("Enter angle (in degrees) of initial velocity vector relative to the positive x-axis: ");
    float theta;
    scanf("%f", &theta);
    theta = (theta * PI) / 180;

    printf("Position of third object after %.2f seconds: %.2f meters\n", time, computePosition(initialPosition, initialVelocity, acceleration, time, theta));

    return 0;
}