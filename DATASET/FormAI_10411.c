//FormAI DATASET v1.0 Category: Physics simulation ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

int main(){
    double distance = 10; //initial distance from origin
    double velocity = 20; //initial velocity
    double acceleration = -9.8; //acceleration due to gravity
    double time = 0; //initial time
    double dt = 0.01; //time step

    while(distance > 0){ //loop until object hits the ground
        printf("Time: %lf s \t Distance: %lf m\n", time, distance); //print current time and distance

        velocity += acceleration*dt; //calculate new velocity 
        distance += velocity*dt; //calculate new distance
        time += dt; //increment time
    }

    printf("Time: %lf s \t Distance: %lf m\n", time, distance); //print final time and distance when object hits the ground

    return 0;
}