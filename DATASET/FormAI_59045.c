//FormAI DATASET v1.0 Category: Physics simulation ; Style: statistical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 100000    //number of iterations
#define BOLTZMANN 1.38E-23  //Boltzmann constant in J/K
#define MASS 9.11E-31   //mass of electron in kg
#define TEMP 300    //room temperature in K

int main()
{
    srand(time(0));    //seeds random number generator with current time
   
    double vel[N], pos[N], acc[N];  //arrays to store velocity, position and acceleration
    
    //initial conditions (all electrons start at x=0 with random y positions)
    for(int i = 0; i < N; i++)
    {
        vel[i] = 0; //initial velocity is 0
        pos[i] = 0; //all electrons start at x=0
        acc[i] = 0; //initial acceleration is 0
    }
    
    double force = 0, dt = 1E-9;    //force acting on electrons and time step interval
    
    for(int i = 0; i < N; i++)
    {
        force = -(rand() % 2 + 1) * (BOLTZMANN * TEMP / MASS);    //random force between -2kT/m and -kT/m
        acc[i] = force / MASS;  //calculating acceleration
    }
    
    double drift_velocity = 0;  //variable to store drift velocity
    
    //simulate electron motion
    for(int i = 0; i < N; i++)
    {
        vel[i] += acc[i] * dt;  //update velocity
        pos[i] += vel[i] * dt;  //update position
        drift_velocity += vel[i];   //calculate total drift velocity
    }
    
    drift_velocity /= N;   //calculate average drift velocity
    
    printf("Average drift velocity: %e m/s", drift_velocity); //output result in scientific notation
    
    return 0;
}