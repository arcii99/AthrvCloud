//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the planet gravity simulator!\n\n");

    //set up planets
    float earth_mass = 5.972 * pow(10, 24);
    float earth_radius = 6371000;
    float earth_x = 0, earth_y = 0;
    float moon_mass = 7.342 * pow(10, 22);
    float moon_radius = 1737100;
    float moon_x = 384400000, moon_y = 0;
    float spaceship_mass = 10000;
    float spaceship_radius = 10;
    float spaceship_x, spaceship_y, spaceship_vx, spaceship_vy;
    printf("You are in a spaceship near the moon. Enter your x and y coordinates:\n");
    scanf("%f %f", &spaceship_x, &spaceship_y);
    printf("Enter your x and y velocities:\n");
    scanf("%f %f", &spaceship_vx, &spaceship_vy);

    //set up simulation parameters
    float dt = 1;
    float G = 6.674 * pow(10, -11);

    //start simulation
    while (1)
    {
        //calculate spaceship acceleration from moon and earth
        float dx_moon = moon_x - spaceship_x;
        float dy_moon = moon_y - spaceship_y;
        float r_moon = sqrt(pow(dx_moon, 2) + pow(dy_moon, 2));
        float F_moon = G * spaceship_mass * moon_mass / pow(r_moon, 2);
        float ax_moon = F_moon * dx_moon / r_moon / spaceship_mass;
        float ay_moon = F_moon * dy_moon / r_moon / spaceship_mass;

        float dx_earth = earth_x - spaceship_x;
        float dy_earth = earth_y - spaceship_y;
        float r_earth = sqrt(pow(dx_earth, 2) + pow(dy_earth, 2));
        float F_earth = G * spaceship_mass * earth_mass / pow(r_earth, 2);
        float ax_earth = F_earth * dx_earth / r_earth / spaceship_mass;
        float ay_earth = F_earth * dy_earth / r_earth / spaceship_mass;

        //update spaceship position and velocity
        spaceship_x += spaceship_vx * dt;
        spaceship_y += spaceship_vy * dt;
        spaceship_vx += (ax_moon + ax_earth) * dt;
        spaceship_vy += (ay_moon + ay_earth) * dt;

        //check for collision with moon or earth
        if (r_moon <= moon_radius + spaceship_radius)
        {
            printf("You have landed on the moon!\n");
            break;
        }
        if (r_earth <= earth_radius + spaceship_radius)
        {
            printf("You have crashed into the earth!\n");
            break;
        }

        //print current position and velocity of spaceship
        printf("Your current position is (%.0f, %.0f)\n", spaceship_x, spaceship_y);
        printf("Your current velocity is (%.2f, %.2f)\n", spaceship_vx, spaceship_vy);

        //wait for next iteration
        printf("\n");
        system("PAUSE");
    }

    return 0;
}