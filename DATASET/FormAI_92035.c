//FormAI DATASET v1.0 Category: Physics simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mass_of_sun = 1.989 * pow(10, 30);
    int mass_of_earth = 5.972 * pow(10, 24);
    int distance = 149.6 * pow(10, 9);
    double gravitational_constant = 6.67 * pow(10, -11);
    
    printf("Welcome to the hilarious world of Physics Simulation!\n");
    printf("Today, we're going to simulate the interaction between the Sun and the Earth.\n");
    
    srand(time(NULL));
    float random_velocity = rand() % 10 + 15;
    float velocity_of_earth = random_velocity * pow(10, 3);
    float force_of_gravity = (gravitational_constant * mass_of_sun * mass_of_earth) / pow(distance, 2);
    float acceleration_of_earth = force_of_gravity / mass_of_earth;
    
    printf("The mass of the Sun is %d kg and the mass of the Earth is %d kg.\n", mass_of_sun, mass_of_earth);
    printf("The distance between them is %d m and the gravitational constant is %f m^3/(kg*s^2).\n", distance, gravitational_constant);
    printf("The Earth is moving at a speed of %f m/s.\n", velocity_of_earth);
    
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Liftoff!\n");
    sleep(1);
    
    float time = 0;
    float velocity = velocity_of_earth;
    float position = 0;
    float force = force_of_gravity;
    float acceleration = acceleration_of_earth;
    
    while(1)
    {
        printf("The Earth is currently at a distance of %f m from the Sun. ", position);
        
        if(position >= distance)
        {
            printf("The Earth has escaped the gravitational pull of the Sun! Congratulations!\n");
            break;
        }
        
        position = position + velocity * 1 + 0.5 * acceleration * pow(1, 2);
        velocity = velocity + acceleration * 1;
        force = (gravitational_constant * mass_of_sun * mass_of_earth) / pow(distance, 2);
        acceleration = force / mass_of_earth;
        time += 1;
        
        printf("The time elapsed is %f s and the speed of the Earth is %f m/s.\n", time, velocity);
        
        if(velocity >= 29800)
        {
            printf("Houston, we have a problem! The Earth is travelling too fast!\n");
            break;
        }
        
        sleep(1);
    }
    
    return 0;
}