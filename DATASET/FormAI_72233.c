//FormAI DATASET v1.0 Category: Physics simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

// The Case of the Missing Pendulum

int main()
{
    printf("Welcome, Dr. Watson, to my latest simulation of the physics of pendulums.\n\n");
    printf("As you know, a pendulum consists of a weight suspended from a string or rod, which swings back and forth due to gravity.\n");
    printf("These oscillations can be described by a number of parameters, including the length of the pendulum, the size of the weight, and the strength of gravity.\n");
    printf("However, in this particular case, we are investigating a mystery - the pendulum has gone missing!\n\n");
    
    printf("We will begin our investigation by simulating the motion of a simple pendulum with the following parameters:\n");
    printf("Length: 1 meter\nWeight: 1 kilogram\nGravity: 9.8 m/s^2\n\n");
    
    double length = 1.0;
    double weight = 1.0;
    double gravity = 9.8;
    double angle = 0.2; // initial angle in radians
    double velocity = 0.0; // initial velocity in m/s
    
    double time_step = 0.001;
    double total_time = 10.0;
    int num_steps = (int) (total_time / time_step);
    
    double time = 0.0;
    double acceleration;
    double position;
    
    printf("Beginning simulation...\n\n");
    
    for (int i = 0; i < num_steps; i++) {
        acceleration = -gravity / length * sin(angle);
        velocity += acceleration * time_step;
        angle += velocity * time_step;
        time += time_step;
        position = length * sin(angle);
        
        printf("Time: %.3f seconds \t Angle: %.3f radians \t Position: %.3f meters\n", time, angle, position);
    }
    
    printf("\nSimulation finished.\n\n");
    
    printf("But wait! It appears that the pendulum was not actually missing - it was simply hidden from view by a layer of dust!\n");
    printf("I propose that we perform a second simulation, with the same parameters as before, but with an additional force of air resistance.\n");
    printf("This will help us to understand the effects of such forces on the motion of the pendulum, and perhaps explain why it appeared to be missing.\n\n");
    
    double drag = 0.02; // air resistance coefficient
    
    angle = 0.2;
    velocity = 0.0;
    
    printf("Beginning second simulation...\n\n");
    
    for (int i = 0; i < num_steps; i++) {
        acceleration = -gravity / length * sin(angle) - drag / weight * velocity;
        velocity += acceleration * time_step;
        angle += velocity * time_step;
        time += time_step;
        position = length * sin(angle);
        
        printf("Time: %.3f seconds \t Angle: %.3f radians \t Position: %.3f meters\n", time, angle, position);
    }
    
    printf("\nSecond simulation finished.\n\n");
    printf("As you can see, the force of air resistance has a significant impact on the motion of the pendulum, causing it to slow down and eventually come to a stop.\n");
    printf("This explains why it appeared to be missing - its motion was too slow for us to see!\n");
    
    return 0;
}