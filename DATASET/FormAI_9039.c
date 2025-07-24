//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: creative
#include<stdio.h>
#include<math.h>

int main()
{
    float planet_mass[3]; 
    float planet_radius[3]; 
    float planet_x[3], planet_y[3], planet_z[3]; 
    float gravity_const = 6.674; 
    float delta_time = 0.001; 
    float distance, gravity_force;
    float acceleration_x, acceleration_y, acceleration_z;
    float velocity_x, velocity_y, velocity_z;
    float position_x, position_y, position_z;
    
    int i, j, n;
    
    planet_mass[0] = 6.39 * pow(10, 23); 
    planet_radius[0] = 3389500; 
    planet_x[0] = 0; planet_y[0] = 0; planet_z[0] = 0;
    
    planet_mass[1] = 5.97 * pow(10, 24); 
    planet_radius[1] = 6378000;
    planet_x[1] = 0; planet_y[1] = 0; planet_z[1] = 2.7055 * pow(10,7);
    
    planet_mass[2] = 4.867 * pow(10, 24); 
    planet_radius[2] = 2439700;
    planet_x[2] = 0; planet_y[2] = 0; planet_z[2] = 5.7835 * pow(10,7);
    
    for(n = 0; n < 100000; n++)
    {
        for(i = 0; i < 3; i++)
        {
            acceleration_x = 0; acceleration_y = 0; acceleration_z = 0;
            for(j = 0; j < 3; j++)
            {
                if(i != j)
                {
                    distance = sqrt(pow((planet_x[j] - planet_x[i]), 2) + pow((planet_y[j] - planet_y[i]), 2) + pow((planet_z[j] - planet_z[i]), 2));
                    gravity_force = (gravity_const * planet_mass[i] * planet_mass[j]) / pow(distance, 2);
                    acceleration_x += gravity_force * (planet_x[j] - planet_x[i]) / (planet_mass[i] * distance);
                    acceleration_y += gravity_force * (planet_y[j] - planet_y[i]) / (planet_mass[i] * distance);
                    acceleration_z += gravity_force * (planet_z[j] - planet_z[i]) / (planet_mass[i] * distance);
                }
            }
            
            velocity_x += acceleration_x * delta_time;
            velocity_y += acceleration_y * delta_time;
            velocity_z += acceleration_z * delta_time;
            
            position_x += velocity_x * delta_time;
            position_y += velocity_y * delta_time;
            position_z += velocity_z * delta_time;
            
            planet_x[i] = position_x;
            planet_y[i] = position_y;
            planet_z[i] = position_z;
        }
        
        printf("Position of Planet 1: (%f, %f, %f)\n", planet_x[0], planet_y[0], planet_z[0]);
        printf("Position of Planet 2: (%f, %f, %f)\n", planet_x[1], planet_y[1], planet_z[1]);
        printf("Position of Planet 3: (%f, %f, %f)\n", planet_x[2], planet_y[2], planet_z[2]);
    }
    
    return 0; 
}