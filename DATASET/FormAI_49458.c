//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define constants
#define GRAVITY -9.81
#define MAX_VELOCITY 100
#define MIN_VELOCITY 10
#define MAX_DISTANCE 500
#define MIN_DISTANCE 50
#define MAX_ANGLE 90
#define MIN_ANGLE 10

// Define struct for the projectile
struct Projectile {
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
    double time;
};

// Function to simulate projectile motion
struct Projectile simulateProjectile(double initialVelocity, double angle) {
    // Generate random distance and determine initial velocity vectors
    srand(time(0));
    double distance = (rand() % (MAX_DISTANCE - MIN_DISTANCE + 1)) + MIN_DISTANCE;
    double velocityX = initialVelocity * cos(angle);
    double velocityY = initialVelocity * sin(angle);
    
    // Initialize and calculate projectile struct values
    struct Projectile ball;
    ball.positionX = 0;
    ball.positionY = 0;
    ball.velocityX = velocityX;
    ball.velocityY = velocityY;
    ball.time = 0;
    
    while(ball.positionY >= 0) {
        // Calculate time and position
        ball.time += 0.01;
        ball.positionX += ball.velocityX * 0.01;
        ball.positionY += ball.velocityY * 0.01 + 0.5 * GRAVITY * pow(0.01, 2);
        
        // Calculate new velocity
        ball.velocityX += 0;
        ball.velocityY += GRAVITY * 0.01;
        
        // Limit velocity so it doesn't get too high
        if(ball.velocityY > MAX_VELOCITY) {
            ball.velocityY = MAX_VELOCITY;
        }
        
        // Break loop if projectile has reached the target
        if(ball.positionX >= distance) {
            break;
        }
    }
    
    return ball;
}

int main() {
    // Generate random initial velocity and angle
    srand(time(0));
    double initialVelocity = (rand() % (MAX_VELOCITY - MIN_VELOCITY + 1)) + MIN_VELOCITY;
    double angle = (rand() % (MAX_ANGLE - MIN_ANGLE + 1)) + MIN_ANGLE;
    
    // Simulate projectile motion
    struct Projectile ball = simulateProjectile(initialVelocity, angle);
    printf("Projectile reached target at %.2f seconds with a final velocity of %.2f m/s.\n", ball.time, sqrt(pow(ball.velocityX, 2) + pow(ball.velocityY, 2)));
    
    return 0;
}