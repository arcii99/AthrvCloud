//FormAI DATASET v1.0 Category: Physics simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

//Input the values of variables
float mass = 10.0;
float displacement = 5.0;
float spring_constant = 2.0;
float initial_velocity = 0.0;
float time_step = 0.01;
float total_time = 1.0;

//Initialize variables
float position = displacement;
float velocity = initial_velocity;
float acceleration, force;
float time = 0.0;

//Display initial position and velocity
printf("Initial position: %.2f \n", position);
printf("Initial velocity: %.2f \n", velocity);

//Open output file to write data-points to
FILE *out_file;
out_file = fopen("spring_motion.dat","w");

//Make the spring oscillate for the specified amount of time
while(time < total_time){

    //Calculate the force exerted by the spring
    force = -spring_constant * position;

    //Calculate the acceleration of the mass
    acceleration = force / mass;

    //Calculate the new velocity of the mass
    velocity += acceleration * time_step;

    //Calculate the new position of the mass
    position += velocity * time_step;

    //Write the current position and time to the output file
    fprintf(out_file, "%.2f %.2f \n", time, position);

    //Increment time
    time += time_step;
}

//Close the output file
fclose(out_file);

//Display final position and velocity
printf("Final position: %.2f \n", position);
printf("Final velocity: %.2f \n", velocity);

return 0;
}