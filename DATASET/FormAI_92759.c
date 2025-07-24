//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265

// Function to calculate the distance between two points in space
float distance(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2));
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random starting position in space
    float x = rand() % 1000 - 500;
    float y = rand() % 1000 - 500;
    float z = rand() % 1000 - 500;

    // Generate a random target position in space
    float target_x = rand() % 1000 - 500;
    float target_y = rand() % 1000 - 500;
    float target_z = rand() % 1000 - 500;

    // Calculate the distance between the starting position and the target position
    float dist = distance(x, y, z, target_x, target_y, target_z);

    // Choose a random angle and velocity for the spaceship
    float angle = rand() % 360;
    float velocity = rand() % 10 + 1;

    // Calculate the x, y, and z components of the velocity vector
    float vel_x = velocity * sin(angle * PI / 180);
    float vel_y = velocity * cos(angle * PI / 180);
    float vel_z = sqrt(pow(velocity, 2) - pow(vel_x, 2) - pow(vel_y, 2));

    // Initialize the current position and time
    float current_x = x;
    float current_y = y;
    float current_z = z;
    float time = 0;

    // Loop until the spaceship reaches the target
    while (distance(current_x, current_y, current_z, target_x, target_y, target_z) > 0.1)
    {
        // Calculate the new position of the spaceship
        current_x += vel_x;
        current_y += vel_y;
        current_z += vel_z;

        // Calculate the new distance between the spaceship and the target
        dist = distance(current_x, current_y, current_z, target_x, target_y, target_z);

        // Calculate the new velocity vector components based on gravitational forces
        float force = 1000 / pow(dist, 2);
        vel_x += force * (target_x - current_x) / dist;
        vel_y += force * (target_y - current_y) / dist;
        vel_z += force * (target_z - current_z) / dist;

        // Increment the time
        time += 1;

        // Print the current position and time
        printf("Time: %f, Position: (%f, %f, %f)\n", time, current_x, current_y, current_z);
    }

    // Print the final time and position
    printf("Target reached in %f seconds at position (%f, %f, %f)!\n", time, current_x, current_y, current_z);

    return 0;
}